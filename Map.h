#pragma once
#include <SFML/Graphics.hpp>

class Map
{
public:
	Map(int level);
	~Map(){}

	sf::Sprite BackgroundSprite;
	sf::Sprite BackgroundCongressSprite;
	sf::Sprite BackgroundWaterPumpSprite;
	sf::Sprite BackgroundCongressFloorSprite;
	sf::Sprite BackgroundLoseSprite;
	sf::Sprite BackgroundWinSprite;
	sf::Sprite HeartSprite;

private:
	sf::Texture BackgroundTexture;
	sf::Texture BackgroundLoseTexture;
	sf::Texture BackgroundCongressTexture;
	sf::Texture WaterPumpTexture;
	sf::Texture CongressFloorTexture;
	sf::Texture BackgroundWinTexture;
	sf::Texture HeartTexture;
};