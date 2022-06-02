#include "Setting.h"

using namespace Engine;

Setting::Setting()
{
	// default setting
	this->screenWidth = 1920;
	this->screenHeight = 1080;
	this->vsync = false;
	this->timeScale = 1;
	this->windowFlag = WindowFlag::WINDOWED;
	this->targetFrameRate = 0;
	this->windowTitle = "Untitled";
}

Setting::~Setting()
{
}
