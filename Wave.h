#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <memory>

class Wave
{
public:
	Wave(int);
	~Wave(){}

	void MoveTo();
	bool WaveGetIsDead();
	sf::Vector2f GetPosition();
	int WaveMaxSize = 5;
	std::vector<Enemy*> EnemyWave;
	float lane;

private:
	sf::Vector2f position;
	bool isWaveDead;
};