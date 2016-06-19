#include <string>
#include "Wave.h"
#include "Enemy.h"

Wave::Wave()
{
	for (int i = 0; i < WaveMaxSize; i++)
	{
		EnemyWave.push_back(Enemy());
		EnemyWave[i].SetTexture();
		EnemyWave[i].EnemySprite.setPosition(1000.0f+((1+i)*+80.0f), 500.0f);
	}
}

void Wave::MoveTo()
{
	for (int i = 0; i <= WaveMaxSize; i++)
	{
		EnemyWave[i].MoveTo();
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

