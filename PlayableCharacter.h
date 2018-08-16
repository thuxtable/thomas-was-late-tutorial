#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter {

protected:

	//Sprite
	Sprite m_Sprite;

	//Duration of jump
	float m_JumpDuration;

	//Is character currently falling or jumping
	bool m_IsJumping;
	bool m_IsFalling;

	//Which direction is the character moving
	bool m_LeftPressed;
	bool m_RightPressed;

	//How long has the jump lasted
	float m_TimeThisJump;

	//Has the player just initiated a jump?
	bool m_JustJumped;

private:

	//The constant gravity variable affecting the player
	float m_Gravity;

	//Character move speed
	float m_Speed = 400;

	//Character position
	Vector2f m_Position;

	//Where are the character's various body parts?
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	//Texture
	Texture m_Texture;

public:

	//Spawns the character on the map
	void spawn(Vector2f startPosition, float gravity);

	//This is a pure virtual function for handling input for each sub-class object
	bool virtual handleInput() = 0;

	//Player's location
	FloatRect getPosition();

	//Getter functions for player's hit box
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	//Getter function for sprite
	Sprite getSprite();

	//Stop player's movement when input has ceased or to prevent moving through a "solid" tile; for collisions
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	//Return center of character
	Vector2f getCenter();

	//Position and movement updater; to be called once per frame
	void update(float elapsedTime);

};