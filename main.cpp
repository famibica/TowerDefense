#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include "Map.h"
#include "Enemy.h"
#include "Level.h"
#include "Wave.h"
#include "Shoot.h"
#include "Bullets.h"
#include "Cannon.h"
#include "Player.h"
#include "WaveControl.h"

int main()
{
	
	//Play sound
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("C:/ImagensProjetoTD/Brazil8bits.wav"))
		return -1;
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	//Loading Fonts
	sf::Font font;
	if (!font.loadFromFile("C:/ImagensProjetoTD/ka1.ttf"))
	{
		throw "Failure to load font!";
	}

	sf::Text text;
	text.setFont(font); //setting font
	text.setPosition(90.0f, 540.0f);
	text.setColor(sf::Color::Black);

	//Render window
	sf::RenderWindow window(sf::VideoMode(1000, 600, 32), "Tower Defense", sf::Style::Default);

	//Instantiate Map, Wave and Other Entity's positions and textures/sprites
	Map* mapa = new Map(1);
	Cannon* cannon = new Cannon();
	Shoot* shoot = new Shoot();
	Player* player = new Player();
	WaveControl* waveControl = new WaveControl();

	sf::Clock clock; //start a timer

	//set framerate limit to 120
	window.setFramerateLimit(120);
	sf::Event event; //Create an event listenner

	while (window.isOpen()) //When the window is open the game is rolling
	{
		sf::Time elapsedTime = clock.getElapsedTime();

		if (elapsedTime.asSeconds() > 3)
		{
			waveControl->CreateWave();
			clock.restart();
		}
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);//Get mouse position at this exact time

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

		//Check Collisions, Enemy, Base, etc
		for (int x = 0; x < waveControl->Waves.size(); x++)
		{	
			for (int i = 0; i < waveControl->Waves[x]->EnemyWave.size(); i++)
			{
				if (waveControl->Waves[x]->EnemyWave[i]->GetIsDead() == false)
				{
					if (waveControl->Waves[x]->EnemyWave[i]->EnemySprite.getGlobalBounds().intersects(mapa->BackgroundCongressFloorSprite.getGlobalBounds()))
					{
						waveControl->Waves[x]->EnemyWave[i]->SetIsDead(true);
						player->InitialLife = player->InitialLife - 10;
					}
				}
				for (int j = 0; j < shoot->AllBullets.size(); j++)
				{
					if ((shoot->AllBullets[j]->draw == true) && (waveControl->Waves[x]->EnemyWave[i]->GetIsDead() == false))
					{
						if (waveControl->Waves[x]->EnemyWave[i]->EnemySprite.getGlobalBounds().intersects(shoot->AllBullets[j]->BulletsSprite.getGlobalBounds()))
						{
							shoot->AllBullets[j]->draw = false;
							waveControl->Waves[x]->EnemyWave[i]->InitialLife = waveControl->Waves[x]->EnemyWave[i]->InitialLife - 5;
							if (waveControl->Waves[x]->EnemyWave[i]->InitialLife == 0)
							{
								player->enemiesKilled = player->enemiesKilled +1;
								waveControl->Waves[x]->EnemyWave[i]->SetIsDead(true);
							}
						}
					}
				}

			}
		}

		//move the waves
		for (int x = 0; x < waveControl->Waves.size(); x++)
		{
			for (int i = 0; i < waveControl->Waves[x]->EnemyWave.size(); i++)
			{
				waveControl->Waves[x]->EnemyWave[i]->MoveTo();
			}
		}
		
		//Draw all elements to the screen and update
		window.clear();
		window.draw(mapa->BackgroundSprite);
		//move the waves
		for (int x = 0; x < waveControl->Waves.size(); x++)
		{
			for (int i = 0; i < waveControl->Waves[x]->EnemyWave.size(); i++)
			{
				if (waveControl->Waves[x]->EnemyWave[i]->GetIsDead() == false)
				{
					window.draw(waveControl->Waves[x]->EnemyWave[i]->EnemySprite);
				}
			}
		}
		for (int i = 0; i < shoot->AllBullets.size(); i++)
		{
			if (shoot->AllBullets[i]->draw == true)
				window.draw(shoot->AllBullets[i]->BulletsSprite);
		}

		window.draw(mapa->BackgroundCongressFloorSprite);
		window.draw(mapa->BackgroundCongressSprite);
		window.draw(mapa->BackgroundWaterPumpSprite);
		window.draw(mapa->HeartSprite);
		window.draw(cannon->CannonSprite);
		//check if player is dead
		if (player->InitialLife <= 0)
		{
				window.draw(mapa->BackgroundLoseSprite);
		}
		else
		{
			std::stringstream ss;
			ss << player->InitialLife;
			std::string life = ss.str();
			if (life == "")
			{
				life = "00.0";
			}

			text.setString(life);
			window.draw(text);

			if (player->enemiesKilled > 50)
			{
				window.draw(mapa->BackgroundWinSprite);
			}
			
		}
		
		window.display();
	}

	return 0;
}