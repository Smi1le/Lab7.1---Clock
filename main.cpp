#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#include "clock.h"
#include <random>

using namespace std;
using namespace sf;

void processEvents(RenderWindow & window) {
	Event event;
	while (window.pollEvent(event))
	{
		if ((event.type == Event::Closed) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
			window.close();
	}
}

void update(myClock & clock, SYSTEMTIME & sysTime) {
	GetSystemTime(&sysTime);
	clock.secondHand->setRotation(float(sysTime.wSecond * 6));
	clock.minuteHand->setRotation(float((sysTime.wMinute) * 6));
	clock.hourHand->setRotation(float((sysTime.wHour + 3) * 30));
}

void drawing(RenderWindow & window, myClock & clock) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 256);
	int rangeRed = dist(gen);
	int rangeGreen = dist(gen);
	int rangeBlue = dist(gen);
	window.clear(Color::Color(rangeRed, rangeGreen, rangeBlue));
	window.draw(*clock.circle);
	window.draw(*clock.hourHand);
	window.draw(*clock.minuteHand);
	window.draw(*clock.secondHand);
	drawDivides(clock);
	window.display();
}

void memoryCleaning(myClock & clock) {
	delete clock.circle;
	delete clock.hourHand;
	delete clock.minuteHand;
	delete clock.secondHand;
	delete clock.delimiter;
	delete clock.window;
}



int main(){

	myClock *clock = new myClock;
	createClock(*clock);
	initPosition(*clock);
	

	RenderWindow & window = *clock->window;

	SYSTEMTIME time;
	while (window.isOpen()){

		processEvents(window);
		update(*clock, time);
		drawing(window, *clock);

	}
	memoryCleaning(*clock);
	delete clock;
	return 0;
}