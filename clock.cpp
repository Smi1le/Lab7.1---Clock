#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cmath>
#include <vector>
#include <math.h>
#include "clock.h"

using namespace std;
using namespace sf;

void createClock(myClock &clock) {
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	clock.window = new RenderWindow(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Clock", sf::Style::Default, settings);

	clock.hourHand = new RectangleShape(Vector2f(SIZE_HOUR_HAND));
	createHand(*clock.hourHand, SIZE_HOUR_HAND);	
	clock.hourHand->setFillColor(Color::Green);

	clock.minuteHand = new RectangleShape(Vector2f(SIZE_MINUTE_HAND));
	createHand(*clock.minuteHand, SIZE_MINUTE_HAND);
	clock.minuteHand->setFillColor(Color::Yellow);

	clock.secondHand = new RectangleShape(Vector2f(SIZE_SECOND_HAND));
	createHand(*clock.secondHand, SIZE_SECOND_HAND);
	clock.secondHand->setFillColor(Color::Blue);

	clock.circle = new CircleShape(RADIUS);
	clock.circle->setPointCount(NUMBER_POINTS_POLYGON);
	clock.circle->setOrigin(RADIUS, RADIUS);
	clock.circle->setPosition(WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2);
	clock.circle->setOutlineThickness(4);
	clock.circle->setOutlineColor(Color::Black);
	
	clock.delimiter = new RectangleShape;
	clock.delimiter->setFillColor(Color::Black);

}


void createHand(RectangleShape &shape, Vector2f size) {
	shape.setOrigin(size.x / 2, size.y);
	shape.setPosition(WINDOW_SIZE.x / 2.0f, WINDOW_SIZE.y / 2.0f);
}

void initPosition(myClock & clock) {
	for (int i = 0; i < 12; i++) {
		float x = WINDOW_SIZE.x / 2 + RADIUS * cos(i * 30 * M_PI / 180);
		float y = WINDOW_SIZE.y / 2 + RADIUS * sin(i * 30 * M_PI / 180);
		float angle = (i + 3) * 30;
		clock.positionDelimiter.push_back(Vector3f(x, y, angle));
	}
}

void drawDivides(myClock & clock) {
	for (int i = 0; i < 12; ++i) {
		float x = clock.positionDelimiter[i].x;
		float y = clock.positionDelimiter[i].y;
		float angle = clock.positionDelimiter[i].z;
		if (i % 3 == 0) {
			clock.delimiter->setSize(Vector2f(SIZE_BIG_DIVIDE));
			clock.delimiter->setOrigin(SIZE_BIG_DIVIDE.x / 2, 0);

		}
		else {
			clock.delimiter->setSize(Vector2f(SIZE_SMALL_DIVIDE));
			clock.delimiter->setOrigin(SIZE_SMALL_DIVIDE.x / 2, 0);
		}
		clock.delimiter->setPosition(x, y);
		clock.delimiter->setRotation(angle);
		clock.window->draw(*clock.delimiter);
	}
}