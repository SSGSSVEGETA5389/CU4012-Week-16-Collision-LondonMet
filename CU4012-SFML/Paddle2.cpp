#include "Paddle2.h"

Paddle2::Paddle2()
{
}

Paddle2::~Paddle2()
{


}

void Paddle2::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		//input->setKeyUp(sf::Keyboard::W);
		move(0, -0.1);

	}
	if (input->isKeyDown(sf::Keyboard::S))

	{
		//input->setKeyUp(sf::Keyboard::S);
		move(0, 0.1);


	}

}

void Paddle2::CollisionResponse(GameObject* collider)
{
	collider->setVelocity(-collider->getVelocity());

}
