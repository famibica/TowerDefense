#include <string>
#include "Wave.h"
#include "Enemy.h"

Wave::Wave(int appearLane)
{
	switch (appearLane){
	case 1:
		lane = 7.5f;
		break;
	case 2:
		lane = 105.0f;
		break;
	case 3:
		lane = 202.5f;
		break;
	case 4:
		lane = 300.0f;
		break;
	case 5:
		lane = 397.5f;
		break;
	case 6:
		lane = 495.0f;
		break;
	}

	for (int i = 0; i < WaveMaxSize; i++)
	{	
		int min = 1;
		int max = 3;
		int level = min + (rand() % (int)(max - min + 1));

		EnemyWave.push_back(new Enemy(level));
		//EnemyWave[i]->.SetTexture();	
		EnemyWave[i]->EnemySprite.setPosition(1000.0f+((1+i)*+80.0f), lane);
	}
}

void Wave::MoveTo()
{
	for (int i = 0; i < WaveMaxSize; i++)
	{
		EnemyWave[i]->MoveTo();
	}
	//EnemySprite.setPosition(posicao.x - 0.5f, posicao.y);
}

bool Wave::WaveGetIsDead()
{
	return isWaveDead;
}

sf::Vector2f Wave::GetPosition()
{
	// impl.
	return position;
}

