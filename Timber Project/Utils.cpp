#include "Utils.h"

random_device Utils::rd;
mt19937 Utils::gen(Utils::rd());

void Utils::SetOrigin(Text& obj, Origins origin)
{
	FloatRect rect = obj.getLocalBounds();
	obj.setOrigin(rect.width * 0.5f * ((int)origin % 3), rect.height * 0.5f * ((int)origin / 3));
}

void Utils::SetOrigin(Sprite& obj, Origins origin)
{
	FloatRect rect = obj.getLocalBounds();
	obj.setOrigin(rect.width * 0.5f * ((int)origin % 3), rect.height * 0.5f * ((int)origin / 3));
}

void Utils::SetOrigin(Transformable& obj, Origins origin, FloatRect rect)
{
	obj.setOrigin(rect.width * 0.5f * ((int)origin % 3), rect.height * 0.5f * ((int)origin / 3));
}

int Utils::Range(int min, int maxExclude)
{
	return (gen() % (maxExclude - min)) + min;
}

float Utils::Range(float min, float max)
{
	uniform_real_distribution<> dist(min, max);
	return dist(gen);
}
