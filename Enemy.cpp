#include <string>
#include "Enemy.h"
#include "Wave.h"

Enemy::Enemy()
{
	EnemyTexture.loadFromFile("C:/Users/matheusbica/Desktop/enemy.png");
	EnemySprite.setTexture(EnemyTexture);
}

void Enemy::MoveTo()
{
	// impl.
	sf::Vector2f posicao = EnemySprite.getPosition();
	
	EnemySprite.setPosition(posicao.x - 0.5f, posicao.y);
}

void Enemy::TestHit()
{
	//test if it hitted the tower
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

void Enemy::SetTexture()
{
	EnemyTexture.loadFromFile("C:/Users/matheusbica/Desktop/enemy.png");
	EnemySprite.setTexture(EnemyTexture);
}
