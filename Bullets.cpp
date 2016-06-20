#include <string>
#include "Bullets.h"
#include "Cannon.h"
#include <cmath>

Bullets::Bullets(float rotation, sf::Vector2f cannonPosition, sf::Vector2f originCannon)
{
	angle = rotation;
	BulletsTexture.loadFromFile("C:/ImagensProjetoTD/shoot.png");
	BulletsSprite.setTexture(BulletsTexture);
	BulletsSprite.setRotation(rotation);
	SetInitialPosition(cannonPosition, rotation, originCannon);
	//BulletsSprite.setPosition(125.0f, 335.0f); Calculate the actual position of the Cannon and 
	//BulletsSprite.setPosition
}

void Bullets::MoveTo()
{
	//move the bullet using his actual position
	sf::Vector2f actual_position = BulletsSprite.getPosition();
	BulletsSprite.setPosition(actual_position.x + 3.0f*cos(angle*(PI / 180)), actual_position.y + 3.0f*sin(angle*(PI / 180)));

}

sf::Vector2f Bullets::GetPosition()
{
	// impl.
	return BulletsSprite.getPosition();
}

void Bullets::SetInitialPosition(sf::Vector2f cannonPosition, float rotation, sf::Vector2f originCannon)
{
	/*
	Point A (base)
	Point B (where the gun is)
	W(xb-xa, yb-ya)
	
	W[x] = cos(angulo)*W[x] - sen(angulo)*W[y];
	W[y] = sen(angulo)*W[x] + cos(angulo) *W[y];
	*/

	FinalPosition.x = (cannonPosition.x + 100.0f) - (cannonPosition.x);
	FinalPosition.y = (cannonPosition.y -4.5) - (cannonPosition.y);

	ResultVector.x = cos(angle*(PI / 180))*FinalPosition.x - sin(angle*(PI / 180))*FinalPosition.y;
	ResultVector.y = sin(angle*(PI / 180))*FinalPosition.x + cos(angle*(PI / 180))*FinalPosition.y;
	
	BulletsSprite.setPosition(ResultVector.x + cannonPosition.x, ResultVector.y + cannonPosition.y);
}