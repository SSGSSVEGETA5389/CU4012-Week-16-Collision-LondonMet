#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include <string>
#include <iostream>
#include "Circle.h"


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
	Circle ball2; 

	sf::Texture ballTex; 
};