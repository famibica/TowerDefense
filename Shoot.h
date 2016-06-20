#pragma once
#include <SFML/Graphics.hpp>
#include "Bullets.h"
#include "Cannon.h"
#include <memory>

class Shoot
{
public:
	Shoot();
	~Shoot(){}

	void MoveTo();
	bool WaveGetIsDead();
	sf::Vector2f GetPosition();
	std::vector<Bullets*> AllBullets;

private:
	sf::Vector2f position;
	bool isWaveDead;
};