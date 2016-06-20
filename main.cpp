#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Map.h"
#include "Enemy.h"
#include "Level.h"
#include "Wave.h"
#include "Shoot.h"
#include "Bullets.h"
#include "Cannon.h"

int main()
{
	//Play sound
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("C:/ImagensProjetoTD/Brazil8bits.wav"))
		return -1;
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	//Render window
	sf::RenderWindow window(sf::VideoMode(1000, 600, 32), "Tower Defense", sf::Style::Default);

	//Instantiate Map, Wave and Cannon positions and textures/sprites
	Map* mapa = new Map(1);
	Wave* wave = new Wave();
	Cannon* cannon = new Cannon();
	Shoot* shoot = new Shoot();

	//set framerate limit to 120
	window.setFramerateLimit(120);

	while (window.isOpen()) //When the window is open the game is rolling
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);//Get mouse position at this exact time

		sf::Event event; //Create an event listenner
		while (window.pollEvent(event))//if any event happens it will loop here
		{
			if (event.type == sf::Event::Closed)//se clicar no X, fecha a janela
				window.close();
			if (event.type == sf::Event::MouseMoved) //when the mouse moves update the cannon position
				cannon->MoveTo(mousePosition); //Move the cannon(Dilminha) to where the mouse points)
			if (event.type == sf::Event::MouseButtonPressed)
			{
				shoot->AllBullets.push_back(new Bullets(cannon->GetRotation(), cannon->GetPosition(), cannon->CannonSprite.getOrigin()));
			}				
		}

		//move bullets
		for (int i = 0; i < shoot->AllBullets.size(); i++)
		{
			shoot->AllBullets[i]->MoveTo();
		}

		//move the wave
		wave->MoveTo();
		
		//Draw all elements to the screen and update
		window.clear();
		window.draw(mapa->BackgroundSprite);
		for (int i = 0; i < wave->WaveMaxSize; i++)
		{
			window.draw(wave->EnemyWave[i]->EnemySprite);
		}
		for (int i = 0; i < shoot->AllBullets.size(); i++)
		{
			window.draw(shoot->AllBullets[i]->BulletsSprite);
		}
		window.draw(mapa->BackgroundCongressFloorSprite);
		window.draw(mapa->BackgroundCongressSprite);
		window.draw(mapa->BackgroundWaterPumpSprite);
		window.draw(cannon->CannonSprite);
		window.display();
	}

	return 0;
}