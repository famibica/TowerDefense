#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player(){}

	int InitialLife = 50;
	bool GetIsDead();
	bool SetIsDead(bool);
	int enemiesKilled = 0;

private:
	bool isDead = false;
};