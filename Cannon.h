#pragma once
#include <SFML/Graphics.hpp>

class Cannon
{
public:
	Cannon();
	~Cannon(){}

	sf::Sprite CannonSprite;
	void MoveTo(sf::Vector2i);
	void SetTexture();
	sf::Vector2f GetPosition();

private:
	sf::Texture CannonTexture;
	sf::Vector2f position;
};