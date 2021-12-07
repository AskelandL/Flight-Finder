#include "TextureManager.h"

unordered_map<string, sf::Texture> TextureManager::textures;
unordered_map<string, sf::Font> TextureManager::fonts;

void TextureManager::LoadTexture(string fileName) {
	string path = "images/";
	path += fileName + ".png";

	textures[fileName].loadFromFile(path);
}

sf::Texture& TextureManager::GetTexture(string textureName) {
	if (textures.find(textureName) == textures.end())
		LoadTexture(textureName);

	return textures[textureName];
}

void TextureManager::Clear()
{
	textures.clear(); // get rid of all stored objects
	fonts.clear();
}

//	//	FONTS	//	//

void TextureManager::LoadFont(string fileName) {
	string path = "fonts/";
	path += fileName + ".ttf";

	fonts[fileName].loadFromFile(path);
}

sf::Font& TextureManager::GetFont(string fontName) {
	if (fonts.find(fontName) == fonts.end())
		LoadFont(fontName);

	return fonts[fontName];
}
