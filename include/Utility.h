#ifndef UTILITY_H
#define UTILITY_H
#include <SFML/Graphics.hpp>

 class Utility 
 {

public: Utility();
		float getGravity();
		unsigned int getWindowPixelHeight();
		unsigned int getWindowPixelWidth();
		unsigned int getFramerate();
		float getVelocityIterations();
		float getPositionIterations();
		float getPixelPerMeter();

		float pixel2Meter(float pixel);
		float meter2Pixel(float meter);
		sf::Vector2i pixel2Meter(int pixelX, int pixelY);
		sf::Vector2i meter2Pixel(int meterX, int meterY);


private:
	const float PIXEL_PER_METER = 64.f;
	const float GRAVITY = 9.8f;
	unsigned int WINDOW_PIXEL_HEIGHT = 800;
	unsigned int WINDOW_PIXEL_WIDTH = 1000;
	unsigned int FRAMERATE = 60;
	const float VELOCITY_ITERATIONS = 8.f;
	const float POSITION_ITERATIONS = 3.f;
};








#endif