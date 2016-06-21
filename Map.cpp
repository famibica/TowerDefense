#include <string>
#include "Map.h"
#include "Wave.h"
#include "WaveControl.h"
#include "Enemy.h"

Map::Map(int level)
{
	if (level == 1)
	{
		if (!BackgroundTexture.loadFromFile("C:/ImagensProjetoTD/ground.png"))
			throw "Failure!";
		else
			BackgroundSprite.setTexture(BackgroundTexture);

		if (!BackgroundCongressTexture.loadFromFile("C:/ImagensProjetoTD/congresso.png"))
			throw "Failure!";
		else
			BackgroundCongressSprite.setTexture(BackgroundCongressTexture);
			
		if (!WaterPumpTexture.loadFromFile("C:/ImagensProjetoTD/water_pump.png"))
			throw "Failure!";
		else
		{
			BackgroundWaterPumpSprite.setTexture(WaterPumpTexture);
			BackgroundWaterPumpSprite.setPosition(70.0f,330.0f);
		}

		if (!CongressFloorTexture.loadFromFile("C:/ImagensProjetoTD/congresso_floor.png"))
			throw "Failure!";
		else
			BackgroundCongressFloorSprite.setTexture(CongressFloorTexture);

		if (!HeartTexture.loadFromFile("C:/ImagensProjetoTD/heart.png"))
			throw "Failure!";
		else
		{
			HeartSprite.setTexture(HeartTexture);
			HeartSprite.setPosition(5.0f, 530.0f);
		}	

		if (!BackgroundLoseTexture.loadFromFile("C:/ImagensProjetoTD/perdeu.png"))
			throw "Failure!";
		else
			BackgroundLoseSprite.setTexture(BackgroundLoseTexture);

		if (!BackgroundWinTexture.loadFromFile("C:/ImagensProjetoTD/ganhou.png"))
			throw "Failure!";
		else
			BackgroundWinSprite.setTexture(BackgroundWinTexture);
	}
}