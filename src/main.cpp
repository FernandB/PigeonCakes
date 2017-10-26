#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <Utility.h>
#include <Cloud.h>
#include <random>
#include <ctime>
#define ARRAY_SIZE 5
#define CLOUD_HEIGHT 135.f
#define CLOUD_WIDTH 244.f
#define SKY_HEIGHT 400
#define GROUND_HEIGHT 200

int getRandomValue()
{
	
	return rand() % (ARRAY_SIZE - 1);
}

b2Vec2 random_pos_cloud()
{

	float pos_x[ARRAY_SIZE]{ 10.f,100.f,230.f,300.f,500.f };
	float pos_y[ARRAY_SIZE]{ 10.f,250.f,111.f,210.f,130.f };
	int randomX = getRandomValue();
	int randomY = getRandomValue();
	float posX=pos_x[randomX];
	float posY=pos_y[randomY];
	return b2Vec2(Utility().pixel2Meter(posX), Utility().pixel2Meter(posY));
	

}


int main()
{
	srand(time(nullptr));
	b2Vec2 gravity(0, Utility().getGravity()); //normal earth gravity, 9.8 m/s/s straight down!

	b2World myWorld = b2World(gravity);

	sf::RenderWindow window(sf::VideoMode(Utility().getWindowPixelWidth(), Utility().getWindowPixelHeight()), "PigeonCakes");
	window.setFramerateLimit(Utility().getFramerate());
	

	/*the player
	Image pigeon(std::string("data/pigeonTest.png"), 200.f, 300.f);
	b2PolygonShape player;
	player.SetAsBox(50.f, 20.f);
	b2BodyDef playerDef;
	playerDef.type = b2_dynamicBody;
	playerDef.gravityScale = 0;
	playerDef.position = b2Vec2(0.f, 200.f);
	playerDef.linearVelocity = b2Vec2(100.f, 0.f);
	b2Body* playerBody = myWorld->CreateBody(&playerDef);
	b2FixtureDef playerFixtureDef;
	playerFixtureDef.shape = &player;
	playerFixtureDef.friction = 0;
	playerFixtureDef.restitution = 0;
	b2Fixture* playerFixture = playerBody->CreateFixture(&playerFixtureDef);
	*/
	//the scenery
	/*sf::View scene;
	scene.setSize(Utility().getWindowPixelWidth(), Utility().getWindowPixelHeight());
	scene.setCenter(sf::Vector2f(400.f, 300.f));
	*/
	
	Cloud cloud1(myWorld,b2Vec2(Utility().pixel2Meter(CLOUD_WIDTH), Utility().pixel2Meter(CLOUD_HEIGHT)),random_pos_cloud());
	Cloud cloud2(myWorld, b2Vec2(Utility().pixel2Meter(CLOUD_WIDTH), Utility().pixel2Meter(CLOUD_HEIGHT)), random_pos_cloud());
	Cloud cloud3(myWorld, b2Vec2(Utility().pixel2Meter(CLOUD_WIDTH), Utility().pixel2Meter(CLOUD_HEIGHT)), random_pos_cloud());
	cloud1.draw(window);
	cloud2.draw(window);
	cloud3.draw(window);

	//the ennemies
	
	
	while (window.isOpen())
	{
		myWorld.Step(Utility().getFramerate(), Utility().getVelocityIterations(), Utility().getPositionIterations());
		sf::Event event;
		sf::Vector2f delta_move;
		while (window.pollEvent(event))
		{

			//Manage inputs
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
				
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
		
		window.clear();
		//the scenery update
		cloud1.update(window);
		cloud2.update(window);
		cloud3.update(window);
	
		window.display();
	}		
		
	

	system("pause");
	return 0;
}

