#include "Player.h"

using namespace Engine;

Player::Player(Sprite* idle) {
	this->health = 100;
	this->attackDmg = 20;
	this->isDead = false;
	this->isHit = false;
	this->x = 0;
	this->y = -190.0f;
	this->current = idle;
	this->hitbox = new BoundingBox();
	this->hitbox->SetMinY(this->y + (-330.0f));
	this->hitbox->SetMaxY(this->y + 100.0f);
	this->attackHitbox = new BoundingBox();
	this->attackHitbox->SetMinY(this->y + (-330.0f));
	this->attackHitbox->SetMaxY(this->y + 100.0f);
	this->current->SetAnimationDuration(60);

}

Player::~Player() {
	
}

void Engine::Player::setSprite(Sprite* idle, Sprite* run, Sprite* attack, Sprite* hit, Sprite* dead)
{
	this->idle = idle;
	this->run = run;
	this->attack = attack;
	this->hit = hit;
	this->dead = dead;
}

void Engine::Player::switchAnim(Sprite* anim)
{
	this->current = anim;
}

void Engine::Player::draw()
{	
	this->current->SetPosition(this->x, this->y);
	this->current->Draw();
}

void Engine::Player::setGameTime(float gametime) {
	this->gametime = gametime;
	this->current->Update(gametime);
	this->current->SetEnableAnimation(true);
}

void Engine::Player::takeHit() {
	this->isHit = true;
	this->health = health - 20;
	if (health <= 0) {
		isDead = true;
	}
}

void Engine::Player::update(Input* inputManager) {


	float xspeed = 0;
	this->hitbox->SetMinX(this->x + 30.0f);
	this->hitbox->SetMaxX(this->x + 60.0f);
	this->hitbox->SetMinX(this->x + 30.0f);
	this->hitbox->SetMaxX(this->x + 60.0f);
	

	if (this->current == this->attack && this->current->isPlaying()) {
		return;
	}

	this->switchAnim(idle);

	if (this->isDead) {
		this->switchAnim(hit);
		if (this->current->GetFrameIndex() >= 4) {
			this->switchAnim(dead);
			if (this->current->GetFrameIndex() >= 6) {
				this->current->SetFrameIndex(5);
			}
		}
		return;
	}

	if (inputManager->IsKeyPressed("Mack-Right")) {
		this->switchAnim(run);
		xspeed = 0.4f;
	}

	if (inputManager->IsKeyPressed("Mack-Left")) {
		this->switchAnim(run);
		xspeed = -0.4f;
	}

	if (this->isHit) {
		this->switchAnim(hit);
		if (this->current->GetFrameIndex() >= 4 && this->current->isPlaying()) {
			this->isHit = false;
			this->current->SetFrameIndex(0);
		}
	} else if (inputManager->IsKeyReleased("Mack-Attack")) {
		this->switchAnim(attack);
		if (!current->isPlaying()) {
			current->SetFrameIndex(0);
		}
	}

	this->x = this->x + xspeed * gametime;
	this->current->SetPosition(x, this->y);
}
