#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <image_sfml.h>
#include <iostream>
#include <random>
#include <ctime>
#define ARRAY_SIZE 5
#define CLOUD_HEIGHT 135
#define CLOUD_WIDTH 244
#define WIDTH 800
#define HEIGHT 600
#define SKY_HEIGHT 400
#define GROUND_HEIGHT 200
#define SECONDS 60.f
#define VELOCITY_ITERATIONS 8  
#define POSITION_ITERATIONS 3
#define GRAVITY 200
#define HEIGHT_LIMIT 400.f
int getRandomValue()
{
	
	return rand() % (ARRAY_SIZE - 1);
}

void drawCloud(sf::RenderWindow& window, sf::Sprite sprite)
{

	int pos_x[ARRAY_SIZE]{ 10,100,230,300,500 };
	int pos_y[ARRAY_SIZE]{ 10,250,111,210,130 };
	int randomX = getRandomValue();
	int randomY = getRandomValue();

		sprite.setPosition(pos_x[randomX], pos_y[randomY]);
	
	window.draw(sprite);

}


int main()
{
	srand(time(nullptr));
	b2Vec2 gravity(0, GRAVITY); //normal earth gravity, 9.8 m/s/s straight down!

	b2World* myWorld = new b2World(gravity);

	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "PigeonCakes");
	window.setFramerateLimit(SECONDS);
	
	//the scenery
	Image sky(std::string("data/sky.png"),WIDTH,SKY_HEIGHT);
	sky.setPosition(0.f, 0.f);
	Image ground(std::string("data/ground.png"),WIDTH,GROUND_HEIGHT);
	ground.setPosition(0.f, HEIGHT - GROUND_HEIGHT);


	
	Image cloud(std::string("data/cloud.png"), CLOUD_WIDTH, CLOUD_HEIGHT);
	Image cloud2(std::string("data/cloud.png"), CLOUD_WIDTH, CLOUD_HEIGHT);
	Image cloud3(std::string("data/cloud.png"), CLOUD_WIDTH, CLOUD_HEIGHT);


	sf::View scene;
	scene.setSize(WIDTH, HEIGHT);
	scene.setCenter(sf::Vector2f::Vector2(400.f, 300.f));
	sf::View sceneTemp=scene;
	//the player
	b2PolygonShape player;

	//the ennemies
	

	while (window.isOpen())
	{
		myWorld->Step(SECONDS, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
		sf::Event event;
		sf::Vector2f delta_move;
		while (window.pollEvent(event))
		{

			//Manage inputs
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{


				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{


				}

			}
			else
			{

			}

		}
		//setposition


		//the scenery drawing
		
		window.clear();
		window.draw(sky.getSprite());
		window.draw(ground.getSprite());
		//if player enter the next scene
		drawCloud(window, cloud.getSprite());
		drawCloud(window, cloud2.getSprite());
		drawCloud(window, cloud3.getSprite());
		//end if
		window.display();
	}		
		
	
	delete myWorld;

	system("pause");
	return 0;
}

