#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"

using namespace sf;

class Engine {
private:

	//Initial instance of TextureHolder
	TextureHolder th;

	Thomas m_Thomas;
	Bob m_Bob;
	
	//For drawing the map
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	//Unchanging force of gravity
	const int GRAVITY = 300;

	//Main window for game
	RenderWindow m_Window;

	//The main view, including splitscreens
	View m_MainView;
	View m_RightView;
	View m_LeftView;

	//The background views
	View m_BGMainView;
	View m_BGRightView;
	View m_BGLeftView;

	//The HUD view, displayed above all others
	View m_HUDView;

	//The background sprite and texture
	Texture m_BackgroundTexture;
	Sprite m_BackgroundSprite;

	//Is game currently in the PLAYING state
	bool m_Playing = false;

	//Is character 1 or 2 the current focus?
	bool m_Character1 = true;

	//Start game in fullscreen mode
	bool m_SplitScreen = false;

	//How much time is left in the current level?
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	//Is it time for a new/first level?
	bool m_NewLevelRequired = true;

	//PRIVATE FUNCTIONS FOR INTERNAL CLASS USE ONLY
	void input();
	void update(float dtAsSeconds);
	void draw();

public:

	//The default Engine constructor, which will be overwritten
	Engine();

	//Run() will call all the private functions
	void run();
};