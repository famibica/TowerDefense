#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Wave
{
public:
	Wave();
	~Wave(){}

	void MoveTo();
	bool WaveGetIsDead();
	sf::Vector2f GetPosition();
	int WaveMaxSize = 5;
	std::vector <Enemy> EnemyWave;

private:
	sf::Vector2f position;
	bool isWaveDead;

};