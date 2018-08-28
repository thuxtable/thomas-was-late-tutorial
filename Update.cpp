#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired) {
		//Load a level
		loadLevel();
	}

	if (m_Playing)
	{
		//Update Thomas and Bob
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		//Detect collisions to see if characters have reached the goal tile
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob)) {
			//New level is required
			m_NewLevelRequired = true;

			//Play the reach goal sound here
			m_SM.playReachGoal();
		}
		else {
			//Run Bob's collision detection
			detectCollisions(m_Bob);
		}

		//Let Bob and Thomas jump on each others' heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead())) {
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead())) {
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

		//Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		//Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}

	}//End if playing

	//Check if fire sound needs to be played
	vector<Vector2f>::iterator it;

	//Iterate through the vector of Vector2f objects
	for (it = m_FireEmitters.begin(); it != m_FireEmitters.end(); it++) {
		//Where is this emitter?
		float posX = (*it).x;
		float posY = (*it).y;

		//Is the player near the emitter? Within a 500px rectangle
		FloatRect localRect(posX - 250, posY - 250, 500, 500);

		//Is the player inside localRect?
		if (m_Thomas.getPosition().intersects(localRect)) {
			//Play the sound and pass the location too
			m_SM.playFire(Vector2f(posX, posY), m_Thomas.getCenter());
		}
	}

	//Set the appropriate player view for splitscreen or fullscreen
	if (m_SplitScreen) {
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else {
		//Center full screen around appropriate character
		if (m_Character1) {
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else {
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}

	//Time to update the HUD, incremented since last time HUD updated
	m_FramesSinceLastHUDUpdate++;

	//Update the HUD every 500 frames
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate) {
		//Update game HUD text
		stringstream ssTime;
		stringstream ssLevel;

		//Update the time text
		ssTime << (int)m_TimeRemaining;
		m_Hud.setTime(ssTime.str());

		//Update the level text
		ssLevel << "Level:" << m_LM.getCurrentLevel();
		m_Hud.setLevel(ssLevel.str());

		m_FramesSinceLastHUDUpdate = 0;
	}

	//Update the particles
	if (m_PS.running()) {
		m_PS.update(dtAsSeconds);
	}

} //End of the update function