#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;

class TextureManager
{
	static unordered_map<string, sf::Texture> textures;
	static unordered_map<string, sf::Font> fonts;
	static void LoadTexture(string textureName);
	static void LoadFont(string fontName);
public:
	static sf::Texture& GetTexture(string textureName);
	static sf::Font& GetFont(string fontName);
	static void Clear(); // call this once, at the end of main()
};


