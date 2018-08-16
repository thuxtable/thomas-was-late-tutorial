#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired) {
		//Spawn Thomas and Bob in a new level
		m_Thomas.spawn(Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(Vector2f(100, 0), GRAVITY);

		//Ensure .spawn() is called only once
		m_TimeRemaining = 10;
		m_NewLevelRequired = false;
	}

	if (m_Playing)
	{
		//Update Thomas and Bob
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		//Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		//Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}

	}//End if playing

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

}