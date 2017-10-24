#include <image_sfml.h>



Image::Image(std::string& filename,int width,int height)
{
	
	if (!texture.loadFromFile(filename))
	{
		// error...
	}
	texture.setSmooth(true);
	texture.setRepeated(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect::Rect(0, 0, width, height));
	sprite.setScale(1.f,1.f);
	
}

Image::~Image()
{

}
void Image::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}


sf::Sprite Image::getSprite()
{
	return sprite;
}
