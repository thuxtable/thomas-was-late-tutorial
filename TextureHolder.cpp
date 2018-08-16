#include "stdafx.h"
#include "TextureHolder.h"
#include <assert.h>

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	//Get a reference to m_Textures using m_S_Instance
	auto& m = m_s_Instance->m_Textures;
	//Here, auto is the equivalent of map<string, Texture>

	//Create an iterator to hold a key-value-pair (kvp) and search for the required kvp using the passed in file name
	auto keyValuePair = m.find(filename);
	//Here, auto is equivelant of map<string, Texture>::iterator


	//Searchg for the a matching kvp
	if (keyValuePair != m.end())
	{
		//If yes, return the second part of the kvp, the texture
		return keyValuePair->second;
	}
	else
	{
		//File name not found; create a new key value pair using the filename
		auto& texture = m[filename];
		//oad the texture from file in the usual way
		texture.loadFromFile(filename);

		//Return the texture to the calling code
		return texture;
	}
}