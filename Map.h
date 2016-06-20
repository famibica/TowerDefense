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

private:
	sf::Texture BackgroundTexture;
	sf::Texture BackgroundCongressTexture;
	sf::Texture WaterPumpTexture;
	sf::Texture CongressFloorTexture;
};