#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Enemy.h"
#include "Level.h"
#include "Wave.h"
#include "Cannon.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600, 32), "Tower Defense", sf::Style::Default);

	sf::RectangleShape shape(sf::Vector2f(100, 1000));
	shape.setFillColor(sf::Color::Green);

	Map* mapa = new Map(1);
	Wave* wave = new Wave();
	Cannon* cannon = new Cannon();

	window.setFramerateLimit(120);

	while (window.isOpen()) //When the window is open the game is rolling
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);//Get mouse position at this exact time

		sf::Event event;
		while (window.pollEvent(event))//if any event happens it will loop here
		{
			if (event.type == sf::Event::Closed)//se clicar no X, fecha a janela
				window.close();
			if (event.type == sf::Event::MouseMoved) //when the mouse moves update the cannon position
				cannon->MoveTo(mousePosition);
		}

		
		wave->MoveTo();
		
		window.clear();
		window.draw(mapa->BackgroundSprite);
		window.draw(shape);
		for (int i = 0; i < wave->WaveMaxSize; i++)
		{
			window.draw(wave->EnemyWave[i]->EnemySprite);
		}
		window.draw(cannon->CannonSprite);
		window.display();
	}

	return 0;
}