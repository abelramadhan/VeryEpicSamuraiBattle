#ifndef PLAYER_H
#define PLAYER_H

#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Input.h"
#include "BoundingBox.h"

namespace Engine {
	class Player
	{
	public:
		Player(Sprite* idle, float x, float y, int animDur);
		~Player();
		void setSprite(Sprite* idle, Sprite* run, Sprite* attack, Sprite* hit, Sprite* dead);
		void takeHit();
		void setFlipHitbox(bool isFlip);
		bool getDead();
		int getHealth();
		float getX();
		void flip(bool isFlip);
		void switchAnim(Sprite* sprite);
		void setGameTime(float gametime);
		void update(Input* inputManager, string player, Player* enemy);
		void draw();
	private:
		int health;
		int attackDmg;
		bool isDead;
		bool isHit;
		bool flipHitbox;
		float x, y;
		float gametime;
		BoundingBox* hitbox;
		BoundingBox* attackHitbox;
		Sprite* current;
		Sprite* idle;
		Sprite* run;
		Sprite* attack;
		Sprite* hit;
		Sprite* dead;
	};
}
#endif
