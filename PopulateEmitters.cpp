#include "stdafx.h"
#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::populateEmitters(vector <Vector2f>& vSoundEmitters, int** arrayLevel) {
	
	//Ensure the vector is empty
	vSoundEmitters.empty();

	//Keep track of the previous emitter, so that not too many are made
	FloatRect previousEmitter;

	//Search for fire in the level
	for (int x = 0; x < (int)m_LM.getLevelSize().x; x++) {
		for (int y = 0; y < (int)m_LM.getLevelSize().y; y++) {
			if (arrayLevel[y][x] == 2) {
				//Skip over any fire tiles too near the previous emitter
				if (!FloatRect(x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE).intersects(previousEmitter)) {
					//Add the coordinates of this water block
					vSoundEmitters.push_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));

					previousEmitter.left = x * TILE_SIZE;
					previousEmitter.top = y * TILE_SIZE;
					previousEmitter.width = TILE_SIZE * 6;
					previousEmitter.height = TILE_SIZE * 6;
				}
			}
		}
	}

	return;
}