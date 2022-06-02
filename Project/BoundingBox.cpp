#include "BoundingBox.h"
#include <GLM/glm.hpp>
#include <iostream>

using namespace Engine;
using namespace std;


bool BoundingBox::CollideWith(BoundingBox* other)
{
	return minX < other->GetMinX() && maxX > other->GetMinX() &&
		minY < other->GetMaxY() && maxY > other->GetMinY();
}

void Engine::BoundingBox::SetMinX(float minX)
{
	this->minX = minX;
}

void Engine::BoundingBox::SetMaxX(float maxX)
{
	this->maxX = maxX;
}

void Engine::BoundingBox::SetMinY(float minY)
{
	this->minY = minY;
}

void Engine::BoundingBox::SetMaxY(float maxY)
{
	this->maxY = maxY;
}


float BoundingBox::GetMinX()
{
	return this->minX;
}

float BoundingBox::GetMinY()
{
	return this->minY;
}

float BoundingBox::GetMaxX()
{
	return this->maxX;
}

float BoundingBox::GetMaxY()
{
	return this->maxY;
}
