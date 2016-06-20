#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy();
	~Enemy(){}

	Enemy(int level);

	sf::Sprite EnemySprite;
	void MoveTo();
	void TestHit();
	void SetTexture();
	bool GetIsDead();
	int InitialLife = 10;
	sf::Vector2f GetPosition();


private:
	sf::Texture EnemyTexture;
	sf::Vector2f position;
	bool isDead;
};