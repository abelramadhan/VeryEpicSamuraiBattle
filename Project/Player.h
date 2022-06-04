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
		Player(Sprite* idle);
		~Player();
		void setPosition(int x, int y);
		void setSprite(Sprite* idle, Sprite* run, Sprite* attack, Sprite* hit, Sprite* dead);
		void move(int xSpeed);
		void takeHit();
		void switchAnim(Sprite* sprite);
		void setGameTime(float gametime);
		void update(Input* inputManager);
		void draw();
	private:
		int health;
		int attackDmg;
		bool isDead;
		bool isHit;
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
