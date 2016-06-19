#include <string>
#include "Enemy.h"

Enemy::Enemy()
{
	//Basic Enemy
	if (!EnemyTexture.loadFromFile("C:/Users/matheusbica/Desktop/enemy.png"))
		throw "Failure!";
	else
		EnemySprite.setTexture(EnemyTexture, true);	

	//EnemySprite.setPosition(1005.0f, 550.0f);
}

void Enemy::MoveTo()
{
	// impl.
	sf::Vector2f posicao = EnemySprite.getPosition();
	
	EnemySprite.setPosition(posicao.x - 0.5f, posicao.y);
}

bool Enemy::GetIsDead()
{
	return isDead;
}

sf::Vector2f Enemy::GetPosition()
{
	// impl.
	return EnemySprite.getPosition();
}
