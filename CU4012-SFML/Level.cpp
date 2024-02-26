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
	ball1.setVelocity(100, 0);

	ball2.setTexture(&ballTex);
	ball2.setSize(sf::Vector2f(100, 100));
	ball2.setPosition(sf::Vector2f(500, 100));
	ball2.setVelocity(-100, 0);

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
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	ball2.update(dt);

	if (Collision::checkBoundingCircle(&ball1, &ball2))
	{
		ball1.CollisionResponse(&ball2); 
		ball2.CollisionResponse(&ball1);
	}

	for (int i = 0; i < 2; i++)
	{
		CollisionSquare[i].update(dt); 

		

	}
	if (Collision::checkBoundingBox(&CollisionSquare[0], &CollisionSquare[1]))
	{
		CollisionSquare[0].CollisionResponse(&CollisionSquare[1]);
		CollisionSquare[1].CollisionResponse(&CollisionSquare[0]);

	}

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);
	
	for (int i = 0; i < 2; i++)
	{
		window->draw(CollisionSquare[i]);

	}
	endDraw();
}
