#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "HUD.h"
#include "ParticleSystem.h"

using namespace sf;

class Engine {
private:

	//Initial instance of TextureHolder
	TextureHolder th;

	//Create a Particle System
	ParticleSystem m_PS;

	//Character constructors for Thomas and Bob
	Thomas m_Thomas;
	Bob m_Bob;

	//A class to manage all the levels
	LevelManager m_LM;

	//Create a Sound Manager
	SoundManager m_SM;

	//Create the HUD
	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;
	
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

	//Declare a shader for the background
	Shader m_RippleShader;

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

	//The vertex array for the new level design
	VertexArray m_VALevel;

	//The 2D array with the map for the level; a pointer to a pointer
	int** m_ArrayLevel = NULL;

	//Texture for the background and the level tiles
	Texture m_TextureTiles;

	//PRIVATE FUNCTIONS FOR INTERNAL CLASS USE ONLY
	void input();
	void update(float dtAsSeconds);
	void draw();

	//Load a new level
	void loadLevel();

	//Run will call all the private functions
	bool detectCollisions(PlayableCharacter& character);

	//Make a vector of the best places to emit sounds from
	void populateEmitters(vector <Vector2f>& vSoundEmitters, int** arrayLevel);

	//A vector of Vector2f for the fire emitter locations
	vector <Vector2f> m_FireEmitters;

public:

	//The default Engine constructor, which will be overwritten
	Engine();

	//Run() will call all the private functions
	void run();
};