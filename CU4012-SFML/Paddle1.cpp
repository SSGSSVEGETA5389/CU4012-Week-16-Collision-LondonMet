#include "Paddle1.h"

Paddle1::Paddle1()
{
}

Paddle1::~Paddle1()
{


}

void Paddle1::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		//input->setKeyUp(sf::Keyboard::Up);
		move(0, -0.1);

	}
	if (input->isKeyDown(sf::Keyboard::Down))

	{
		//input->setKeyUp(sf::Keyboard::Down);
		move(0, 0.1 ); 


	}

}

void Paddle1::CollisionResponse(GameObject* collider)
{
	collider->setVelocity(-collider->getVelocity()); 
}
