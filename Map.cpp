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
	}
}