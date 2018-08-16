#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter {
public:
	//Thomas' specific constructor
	Thomas();

	//The overridden input handler for Thomas
	bool virtual handleInput();
};