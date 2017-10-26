#include "Utility.h"

Utility::Utility()
{
}

float Utility::getGravity()
{
	return GRAVITY;
}

unsigned int Utility::getWindowPixelHeight()
{
	return WINDOW_PIXEL_HEIGHT;
}

unsigned int Utility::getWindowPixelWidth()
{
	return WINDOW_PIXEL_WIDTH;
}

unsigned int Utility::getFramerate()
{
	return FRAMERATE;
}

float Utility::getVelocityIterations()
{
	return VELOCITY_ITERATIONS;
}

float Utility::getPositionIterations()
{
	return POSITION_ITERATIONS;
}

float Utility::getPixelPerMeter()
{
	return PIXEL_PER_METER;
}

float Utility::pixel2Meter(float pixel)
{
	return pixel/PIXEL_PER_METER;
}

float Utility::meter2Pixel(float meter)
{
	return meter*PIXEL_PER_METER;
}

sf::Vector2i Utility::pixel2Meter(int pixelX, int pixelY)
{
	return sf::Vector2i(pixel2Meter(pixelX),pixel2Meter(pixelY));
}

sf::Vector2i Utility::meter2Pixel(int meterX, int meterY)
{
	return sf::Vector2i(meter2Pixel(meterX),meter2Pixel(meterY));
}
