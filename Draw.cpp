#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
	//Rub out the last frame
	m_Window.clear(Color::White);

	if (!m_SplitScreen)
	{
		//Switch to background view
		m_Window.setView(m_BGMainView);
		
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		
		//Switch to m_MainView
		m_Window.setView(m_MainView);

		//Draw Thomas and Bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
	}
	else
	{
		//Split-screen view is active

		//First draw Thomas' side of the screen

		//Switch to background view
		m_Window.setView(m_BGLeftView);
		
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		
		//Switch to m_LeftView
		m_Window.setView(m_LeftView);

		//Draw Bob, then Thomas, in that order, to comport with the screen sides
		m_Window.draw(m_Bob.getSprite());
		m_Window.draw(m_Thomas.getSprite());

		//Now draw Bob's side of the screen

		//Switch to background view
		m_Window.setView(m_BGRightView);
		
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		
		//Switch to m_RightView
		m_Window.setView(m_RightView);

		//Draw Thomas, then Bob, in that order, to comport with the screen sides
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

	}

	//Draw the HUD; switch to m_HudView
	m_Window.setView(m_HUDView);
	
	//Show everything we have just drawn
	m_Window.display();
}