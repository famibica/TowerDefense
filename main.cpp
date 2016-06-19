#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Enemy.h"
#include "Level.h"
#include "Wave.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 600, 32), "Tower Defense", sf::Style::Default);

	sf::RectangleShape shape(sf::Vector2f(100, 1000));
	shape.setFillColor(sf::Color::Green);

	Map* mapa = new Map(1);
	Wave* wave = new Wave();
	window.setFramerateLimit(120);

	while (window.isOpen()) //When the window is open the game is rolling
	{
		sf::Event event;
		while (window.pollEvent(event))//if any event happens it will loop here
		{
			if (event.type == sf::Event::Closed)//se clicar no X, fecha a janela
				window.close();
			//if (event.type == sf::Event::MouseButtonPressed)//working when clicking mouse
				
		}

		
		wave->MoveTo();

		window.clear();
		window.draw(mapa->BackgroundSprite);
		window.draw(shape);
		for (int i = 0; i < wave->WaveMaxSize; i++)
		{
			window.draw(wave->EnemyWave[i].EnemySprite);
		}
		window.display();
	}

	return 0;
}