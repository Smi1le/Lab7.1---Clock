#pragma once

#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cmath>
#include <vector>

#include "config.h"

struct myClock {
	sf::RenderWindow *window;
	sf::CircleShape *clock;
	sf::RectangleShape *secondHand;
	sf::RectangleShape *minuteHand;
	sf::RectangleShape *hourHand;
	sf::RectangleShape *delimiter;
	sf::CircleShape *shapeMinutes;
	std::vector<sf::Vector3f> positionDelimiter;
	sf::CircleShape *circle;
};


void createClock(myClock &clock);
void createHand(sf::RectangleShape &shape, sf::Vector2f size);
void drawDivides(myClock & clock);
void initPosition(myClock & clock);
