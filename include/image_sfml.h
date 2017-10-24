#ifndef IMAGE_H
#define IMAGE_H

#include <SFML/Graphics.hpp>

class Image
{
public:
	Image(std::string&,int,int);
	~Image();
	sf::Sprite getSprite();
	void setPosition(float,float);
	void draw(sf::RenderWindow&,bool);
private:
	sf::Texture texture;
	sf::Sprite sprite;

};

#endif