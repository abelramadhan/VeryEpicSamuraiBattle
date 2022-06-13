#include "Player.h"

using namespace Engine;

Player::Player(Sprite* idle, float x, float y, int animDur) {
	this->health = 100;
	this->attackDmg = 20;
	this->isDead = false;
	this->isHit = false;
	this->x = x;
	this->y = y;
	this->current = idle;
	this->hitbox = new BoundingBox();
	this->hitbox->SetMinY(this->y + (-190.0f));
	this->hitbox->SetMaxY(this->y + 200.0f);
	this->attackHitbox = new BoundingBox();
	this->attackHitbox->SetMinY(this->y + (-190.0f));
	this->attackHitbox->SetMaxY(this->y + 200.0f);
	this->current->SetAnimationDuration(animDur);
	this->flipHitbox = false;
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
	if (this->current != hit && this->current != attack) {
		this->isHit = true;
		if (health > 0) {
			this->health = health - 20;
		}
		if (health <= 0) {
			isDead = true;
		}
	}
}

void Engine::Player::setFlipHitbox(bool isFlip) {
	this->flipHitbox = isFlip;
}

bool Engine::Player::getDead() {
	return this->isDead;
}

int Engine::Player::getHealth() {
	return this->health;
}

float Engine::Player::getX() {
	return this->x;
}

void Engine::Player::flip(bool isFlip) {
	this->current->SetFlipHorizontal(isFlip);
}

void Engine::Player::update(Input* inputManager, string player, Player* enemy) {


	float xspeed = 0;

	this->hitbox->SetMinX(this->x + 50.0f);
	this->hitbox->SetMaxX(this->x + 100.0f);

	if (!flipHitbox) {
		this->attackHitbox->SetMinX(this->x + 100.0f);
		if (player == "mack") {
			this->attackHitbox->SetMaxX(this->x + 450.0f);
		}
		else {
			this->attackHitbox->SetMaxX(this->x + 420.0f);
		}
	}
	else {
		this->attackHitbox->SetMaxX(this->x - 30.0f);
		if (player == "mack") {
			this->attackHitbox->SetMinX(this->x - 380.0f);
		}
		else {
			this->attackHitbox->SetMinX(this->x - 350.0f);
		}
	}
	
	if (this->current == this->attack && this->current->isPlaying()) {
		if (this->current->GetFrameIndex() == this->current->GetNumFrames() - 1) {
			if (this->attackHitbox->CollideWith(enemy->hitbox)) {
				enemy->takeHit();
			}
		}	
		return;
	}

	this->switchAnim(idle);

	if (this->isDead) {
		this->switchAnim(hit);
		if (this->current->GetFrameIndex() >= this->hit->GetNumFrames()) {
			this->switchAnim(dead);
			if (this->current->GetFrameIndex() >= this->dead->GetNumFrames()) {
				this->current->SetFrameIndex(this->current->GetNumFrames()-1);
			}
		}
		return;
	}

	if (inputManager->IsKeyPressed(player+"-Right")) {
		this->switchAnim(run);
		xspeed = 0.4f;
	}

	if (inputManager->IsKeyPressed(player + "-Left")) {
		this->switchAnim(run);
		xspeed = -0.4f;
	}

	if (this->isHit) {
		this->switchAnim(hit);
		if (this->current->GetFrameIndex() >= this->current->GetNumFrames() && this->current->isPlaying()) {
			this->isHit = false;
			this->current->SetFrameIndex(0);
		}
	} else if (inputManager->IsKeyReleased(player + "-Attack")) {
		this->switchAnim(attack);
		if (!current->isPlaying()) {
			current->SetFrameIndex(0);
		}
	}

	this->x = this->x + xspeed * gametime;
	this->current->SetPosition(x, this->y);

}
