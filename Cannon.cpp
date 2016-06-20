#include <string>
#include "Cannon.h"

Cannon::Cannon()
{
	CannonTexture.loadFromFile("C:/ImagensProjetoTD/tower.png");
	CannonSprite.setTexture(CannonTexture);
	CannonSprite.setPosition(125.0f,335.0f);
	CannonSprite.setOrigin(sf::Vector2f(10, 30));
}

void Cannon::MoveTo(sf::Vector2i mousePosition)
{
	sf::Vector2f position = CannonSprite.getPosition();
	
	if (mousePosition.x > 125.0f)
	{
		const float PI = 3.14159265;

		float dx = -mousePosition.x + position.x;
		float dy = -mousePosition.y + position.y;
		
		float rotation = (atan2(dy, dx)) * 180 / PI;
		CannonSprite.setRotation(rotation + 180);
	}	
}

sf::Vector2f Cannon::GetPosition()
{
	// impl.
	return CannonSprite.getPosition();
}

float Cannon::GetRotation()
{
	// impl.
	return CannonSprite.getRotation();
}
