#ifndef CLOUD_H
#define CLOUD_H
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#define HORIZONTAL_SPEED 1.f
class Cloud
{
public:
	Cloud(b2World& world,b2Vec2 size, b2Vec2 position);
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	
private:
	b2Body* cloudBody;
	b2Vec2 linearVelocity = b2Vec2(HORIZONTAL_SPEED, 0.f);
	sf::Sprite cloudSprite;
	sf::Texture texture;
};


#endif