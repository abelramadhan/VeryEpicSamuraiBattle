#ifndef DEMO_H
#define DEMO_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Text.h"

namespace Engine {
	class Demo :
		public Engine::Game
	{
	public:
		Demo(Setting* setting);
		~Demo();
		virtual void Init();
		virtual void Update();
		virtual void Render();
	private:
		Texture* bgTexture;
		Sprite* bgSprite;

		Texture* titleTexture;
		Sprite* titleSprite;

		Texture* promptTexture;
		Sprite* promptSprite;
		Texture* crateTexture = NULL;
		Texture* bartTexture = NULL;
		Sprite* crateSprite = NULL;
		Sprite* crateSprite2 = NULL;
		Sprite* bartSprite = NULL;
		Music* music = NULL;;
		Sound* sound = NULL;
		Text* text = NULL;
		int count;
	};
}
#endif

