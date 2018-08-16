#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter {
public:
	//Bob's specific constructor
	Bob();

	//The overridden input handler function for Bob
	bool virtual handleInput();
};