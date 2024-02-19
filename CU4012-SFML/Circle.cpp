#include "Circle.h"

Circle::~Circle()
{
}

void Circle::update(float dt)
{
}

void Circle::CollisionResponse(GameObject* collider)
{
}

void Circle::update(float dt)
{
}

void Circle::update(float dt)
{
	move(velocity * dt);

	if (getPosition().x < 0)

	{
		move(velocity * dt);

		if (getPosition().x < 0)
		{
			setPosition(0, getPosition().y); velocity.x = -velocity.x;
		}
		if (getPosition().x > 750)
		{
			setPosition(750, getPosition().y);
			velocity.x = -velocity.x;
		}


}
