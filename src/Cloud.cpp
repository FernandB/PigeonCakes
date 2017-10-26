#include "Cloud.h"
#include "Utility.h"
#include <iostream>
Cloud::Cloud(b2World& world,b2Vec2 size, b2Vec2 position)
{
	
	
	if (!texture.loadFromFile("data/cloud.png"))
	{
		std::cout << "Erreur de chargement de l'image";
	}
	
	cloudSprite = sf::Sprite(texture);
	//cloudSprite.setTextureRect(area);
	cloudSprite.setScale(1.f,1.f);
	b2PolygonShape shape;
	shape.SetAsBox(size.x / 2, size.y / 2);
	b2BodyDef cloudBodyDef;
	cloudBodyDef.linearVelocity = linearVelocity;
	cloudBodyDef.fixedRotation = true;
	cloudBodyDef.gravityScale = 0;
	cloudBodyDef.type = b2_dynamicBody;
	cloudBodyDef.position = b2Vec2(Utility().meter2Pixel(position.x), Utility().meter2Pixel(position.y));
	cloudBody = world.CreateBody(&cloudBodyDef);
	
	b2FixtureDef cloudFixtureDef;
	cloudFixtureDef.restitution = 0;
	cloudFixtureDef.density = 0;
	cloudFixtureDef.friction = 0;
	cloudFixtureDef.shape = &shape;
	b2Fixture* cloudFixture = cloudBody->CreateFixture(&cloudFixtureDef);
	


	
}

void Cloud::update(sf::RenderWindow & window)
{
	cloudSprite.setPosition(cloudBody->GetPosition().x, cloudBody->GetPosition().y);
	window.draw(cloudSprite);

}

void Cloud::draw(sf::RenderWindow & window)
{
	window.draw(cloudSprite);
}


