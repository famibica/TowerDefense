#include <string>
#include "Player.h"

Player::Player()
{

}

bool Player::GetIsDead()
{
	return isDead;
}

bool Player::SetIsDead(bool kill)
{
	if (kill == true)
		isDead = true;

	return isDead;
}
