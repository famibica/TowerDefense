#pragma once
#include <SFML/Graphics.hpp>

class Bullets
{
public:
	Bullets(float, sf::Vector2f, sf::Vector2f);
	~Bullets(){}

	const float PI = 3.14159265;
	sf::Sprite BulletsSprite;
	void MoveTo();
	void SetTexture();
	sf::Vector2f GetPosition();
	void SetInitialPosition(sf::Vector2f, float, sf::Vector2f);
	bool draw = true;

private:
	sf::Vector2f FinalPosition;
	sf::Texture BulletsTexture;
	sf::Vector2f ResultVector;
	float angle;
};