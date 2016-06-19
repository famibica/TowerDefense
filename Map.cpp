#include <string>
#include "Map.h"

Map::Map(int level)
{
	if (level == 1)
	{
		if (!BackgroundTexture.loadFromFile("C:/ImagensProjetoTD/ground.png"))
			throw "Failure!";
		else
			BackgroundSprite.setTexture(BackgroundTexture);
	}
}

void Map::MoveTo(sf::Vector2f new_position)
{
	// impl.
}

bool Map::GetIsDead()
{
	return isDead;
}