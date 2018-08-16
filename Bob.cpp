#include "stdafx.h"
#include "TextureHolder.h"
#include "Bob.h"

Bob::Bob() {
	//Add Bob's sprite texture
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bob.png"));

	//Bob's specific jump duration
	m_JumpDuration = 0.25;
}

//Necessarily overridden pure virutal function
bool Bob::handleInput() {
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			//Start a jump if not already jumping and only if standing on ground (i.e. not already falling)
			if (!m_IsJumping && !m_IsFalling) {
				m_IsJumping = true;
				m_TimeThisJump = 0;
				m_JustJumped = true;
			}
		}
		else {
			m_IsJumping = false;
			m_IsFalling = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			m_LeftPressed = true;
		}
		else {
			m_LeftPressed = false;
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			m_RightPressed = true;
		}
		else {
			m_RightPressed = false;
		}

		return m_JustJumped;
}