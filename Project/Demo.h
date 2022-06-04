#ifndef DEMO_H
#define DEMO_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Text.h"
#include "player.h"

namespace Engine {
	class Demo :
		public Engine::Game
	{
	public:
		Demo(Setting* setting);
		~Demo();
		virtual void Init();
		virtual void Load();
		virtual void Update();
		virtual void Render();
	private:
		Texture* bgTexture;
		Sprite* bgSprite;

		Texture* titleTexture;
		Sprite* titleSprite;

		Texture* promptTexture;
		Sprite* promptSprite;

		Player* mack;
		Texture* mackTextureIdle;
		Texture* mackTextureRun;
		Texture* mackTextureAttack;
		Texture* mackTextureHit;
		Texture* mackTextureDead;

		Player* ken;
		Texture* kenTextureIdle;
		Texture* kenTextureRun;
		Texture* kenTextureAttack;
		Texture* kenTextureHit;
		Texture* kenTextureDead;

		int game_state;

		Music* music = NULL;

		

		/*Texture* promptTexture;
		Sprite* promptSprite;
		Texture* crateTexture = NULL;
		Texture* bartTexture = NULL;
		Sprite* crateSprite = NULL;
		Sprite* crateSprite2 = NULL;
		Sprite* bartSprite = NULL;
		Music* music = NULL;;
		Sound* sound = NULL;
		Text* text = NULL;*/
		int count;
	};
}
#endif

