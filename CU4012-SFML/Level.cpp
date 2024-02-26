#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTex.loadFromFile("gfx/Beach_Ball.png");

	ball1.setTexture(&ballTex);
	ball1.setSize(sf::Vector2f(100, 100));
	ball1.setPosition(sf::Vector2f(100, 100));
	ball1.setVelocity(250, 500);

	/*ball2.setTexture(&ballTex);
	ball2.setSize(sf::Vector2f(100, 100));
	ball2.setPosition(sf::Vector2f(500, 100));
	ball2.setVelocity(-100, 0);*/

	CollisionSquare[0].setSize(sf::Vector2f(50, 50)); 
	CollisionSquare[0].setCollisionBox(sf::FloatRect(0, 0, 50, 50)); 
	CollisionSquare[0].setPosition(0, 200);
	CollisionSquare[0].setVelocity(100, 0);
	CollisionSquare[0].setFillColor(sf::Color::Red); 

	CollisionSquare[1].setSize(sf::Vector2f(50, 50));
	CollisionSquare[1].setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	CollisionSquare[1].setPosition(700, 200);
	CollisionSquare[1].setVelocity(-100, 0);
	CollisionSquare[1].setFillColor(sf::Color::Blue); 

	//Paddle 1
	p1.setSize(sf::Vector2f(50, 150));
	p1.setCollisionBox(sf::FloatRect(0, 0, 50, 150));
	p1.setPosition(0, 200);
	p1.setInput(input); 
	
	p1.setFillColor(sf::Color::Red);

	//Paddle 2 

	p2.setSize(sf::Vector2f(50, 150));
	p2.setCollisionBox(sf::FloatRect(0, 0, 50, 150));
	p2.setPosition(1000, 200);
	
	p2.setFillColor(sf::Color::Blue);
	p2.setInput(input);
	


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	p1.handleInput(dt);
	p2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	// ball2.update(dt);

	//if (Collision::checkBoundingCircle(&ball1))
	//{
	//	
	//	// ball2.CollisionResponse(&ball1);
	//}

	for (int i = 0; i < 2; i++)
	{
		CollisionSquare[i].update(dt); 

		

	}
	if (Collision::checkBoundingBox(&CollisionSquare[0], &CollisionSquare[1]))
	{
		CollisionSquare[0].CollisionResponse(&CollisionSquare[1]);
		CollisionSquare[1].CollisionResponse(&CollisionSquare[0]);

	}

	if (Collision::checkBoundingBox(&p1, &ball1))
	{
		p1.CollisionResponse(&ball1);

	}
	if (Collision::checkBoundingBox(&p2, &ball1))
	{
		p2.CollisionResponse(&ball1);

	}

}

// Render level
void Level::render()
{
	beginDraw();
	//Uncomment below to render the ball in 
	window->draw(ball1);

	/*window->draw(ball2);
	
	for (int i = 0; i < 2; i++)
	{
		window->draw(CollisionSquare[i]);

	}*/
	window->draw(p1);
	window->draw(p2);

	endDraw();
}
