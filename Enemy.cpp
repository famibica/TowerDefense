#include <string>
#include "Enemy.h"
#include "Wave.h"

Enemy::Enemy()
{
	//if the enemy is Boss!
	EnemyTexture.loadFromFile("C:/ImagensProjetoTD/boss.png");
	EnemySprite.setTexture(EnemyTexture);
}

Enemy::Enemy(int level)
{
	//if the enemy has level
	switch (level){
	case 1:
		EnemyTexture.loadFromFile("C:/ImagensProjetoTD/coxinha1.png");
		EnemySprite.setTexture(EnemyTexture);
		break;
	case 2:
		EnemyTexture.loadFromFile("C:/ImagensProjetoTD/coxinha2.png");
		EnemySprite.setTexture(EnemyTexture);
		break;
	case 3:
		EnemyTexture.loadFromFile("C:/ImagensProjetoTD/bolsomito.png");
		EnemySprite.setTexture(EnemyTexture);
		break;
	}
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

bool Enemy::SetIsDead(bool kill)
{
	if (kill == true)
		isDead = true;

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
