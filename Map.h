#pragma once
#include <SFML/Graphics.hpp>

class Map
{
public:
	Map(int level);
	~Map(){}

	sf::Texture Background;
	sf::Sprite BackgroundSprite;

	void MoveTo(sf::Vector2f new_position);

	bool GetIsDead();

	sf::Vector2f GetPosition();

private:
	sf::Texture BackgroundTexture;
	sf::Vector2f position;
	bool isDead;

};