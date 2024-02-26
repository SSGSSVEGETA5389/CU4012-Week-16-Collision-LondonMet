#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include <string>
#include <iostream>
#include "Circle.h"
#include "Squares.h"
#include "Paddle1.h"
#include "Paddle2.h"


class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.

	Circle ball1;
	

	sf::Texture ballTex;

	//AABB 

	Squares CollisionSquare[2];
	

//Pong

	Paddle1 p1; 
	Paddle2 p2; 
};