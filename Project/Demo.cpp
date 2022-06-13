#include "Demo.h"

using namespace Engine;

Demo::Demo(Setting* setting) :Game(setting)
{

}


Demo::~Demo()
{
	delete bgTexture;
	delete bgSprite;
	delete titleTexture;
	delete titleSprite;
	delete promptTexture;
	delete promptSprite;
	delete music;
}

void Demo::Init()
{
	count = 0;
	game_state = 0;

	bgTexture = new Texture("bg.png");
	titleTexture = new Texture("title.png");
	promptTexture = new Texture("prompt.png");

	bgSprite = new Sprite(bgTexture, defaultSpriteShader, defaultQuad);
	titleSprite = new Sprite(titleTexture, defaultSpriteShader, defaultQuad);
	promptSprite = new Sprite(promptTexture, defaultSpriteShader, defaultQuad);

	titleSprite->SetScale(6.5f);
	titleSprite->SetPosition(setting->screenWidth / 2 - titleSprite->GetScaleWidth() / 2, 300.0f);
	promptSprite->SetPosition(setting->screenWidth / 2 - promptSprite->GetScaleWidth() / 2, 160.0f);

	inputManager->AddInputMapping("Start", SDLK_RETURN);
	inputManager->AddInputMapping("Exit", SDLK_ESCAPE);
	inputManager->AddInputMapping("Mack-Right", SDLK_d);
	inputManager->AddInputMapping("Mack-Left", SDLK_a);
	inputManager->AddInputMapping("Mack-Attack", SDLK_s);
	inputManager->AddInputMapping("Ken-Right", SDLK_l);
	inputManager->AddInputMapping("Ken-Left", SDLK_j);
	inputManager->AddInputMapping("Ken-Attack", SDLK_k);

	music = new Music("theme.ogg");
	music->SetVolume(40);
	music->Play(true);
}

void Demo::Load()
{	
	mackTextureIdle = new Texture("mack-idle.png");
	mackTextureRun = new Texture("mack-run.png");
	mackTextureAttack = new Texture("mack-attack1.png");
	mackTextureHit = new Texture("mack-hit.png");
	mackTextureDead = new Texture("mack-dead.png");
	Sprite* mack_idle = new Sprite(mackTextureIdle, defaultSpriteShader, defaultQuad);
	mack_idle->SetNumFrames(8);
	mack_idle->SetScale(4.2f);
	Sprite* mack_run = new Sprite(mackTextureRun, defaultSpriteShader, defaultQuad);
	mack_run->SetNumFrames(8);
	Sprite* mack_attack = new Sprite(mackTextureAttack, defaultSpriteShader, defaultQuad);
	mack_attack->SetNumFrames(6);
	Sprite* mack_hit = new Sprite(mackTextureHit, defaultSpriteShader, defaultQuad);
	mack_hit->SetNumFrames(4);
	mack_hit->SetScale(4.2f);
	Sprite* mack_dead = new Sprite(mackTextureDead, defaultSpriteShader, defaultQuad);
	mack_dead->SetNumFrames(6);
	mack = new Player(mack_idle, 0, -190.0f, 60);
	mack->setSprite(mack_idle, mack_run, mack_attack, mack_hit, mack_dead);

	kenTextureIdle = new Texture("ken-idle.png");
	kenTextureRun = new Texture("ken-run.png");
	kenTextureAttack = new Texture("ken-attack.png");
	kenTextureHit = new Texture("ken-hit.png");
	kenTextureDead = new Texture("ken-dead.png");
	Sprite* ken_idle = new Sprite(kenTextureIdle, defaultSpriteShader, defaultQuad);
	ken_idle->SetNumFrames(4);
	Sprite* ken_run = new Sprite(kenTextureRun, defaultSpriteShader, defaultQuad);
	ken_run->SetNumFrames(8);
	Sprite* ken_attack = new Sprite(kenTextureAttack, defaultSpriteShader, defaultQuad);
	ken_attack->SetNumFrames(4);
	Sprite* ken_hit = new Sprite(kenTextureHit, defaultSpriteShader, defaultQuad);
	ken_hit->SetNumFrames(3);
	Sprite* ken_dead = new Sprite(kenTextureDead, defaultSpriteShader, defaultQuad);
	ken_dead->SetNumFrames(7);
	ken = new Player(ken_idle, 1100.0f, -165.0f, 100);
	ken->setSprite(ken_idle, ken_run, ken_attack, ken_hit, ken_dead);
	ken->setFlipHitbox(true);

	healthbarTexture = new Texture("healthbar.png");
	healthTexture = new Texture("health.png");
	healthbar = new Sprite(healthbarTexture, defaultSpriteShader, defaultQuad);
	health1 = new Sprite(healthTexture, defaultSpriteShader, defaultQuad);
	health2 = new Sprite(healthTexture, defaultSpriteShader, defaultQuad);
	healthbar->SetScale(10.0f);
	healthbar->SetPosition(setting->screenWidth / 2 - healthbar->GetScaleWidth() / 2, 900.0f);
	health1->SetScale(10.0f);
	health1->SetPosition((setting->screenWidth / 2 - health1->GetScaleWidth() / 2) - 355.0f, 940.0f);
	health2->SetScale(10.0f);
	health2->SetPosition((setting->screenWidth / 2 - health2->GetScaleWidth() / 2) + 895.0f, 940.0f);

	mackWinTexture = new Texture("mack-win.png");
	mackWin = new Sprite(mackWinTexture, defaultSpriteShader, defaultQuad);
	mackWin->SetPosition(setting->screenWidth / 2 - mackWin->GetScaleWidth() / 2, 440.0f);
	kenWinTexture = new Texture("ken-win.png");
	kenWin = new Sprite(kenWinTexture, defaultSpriteShader, defaultQuad);
	kenWin->SetPosition(setting->screenWidth / 2 - kenWin->GetScaleWidth() / 2, 440.0f);

	mackControlTexture = new Texture("mack-control.png");
	mackControl = new Sprite(mackControlTexture, defaultSpriteShader, defaultQuad);
	mackControl->SetScale(0.4f);
	mackControl->SetPosition((setting->screenWidth / 2 - mackControl->GetScaleWidth() / 2) - 520.0f, 840.0f);
	kenControlTexture = new Texture("ken-control.png");
	kenControl = new Sprite(kenControlTexture, defaultSpriteShader, defaultQuad);
	kenControl->SetScale(0.4f);
	kenControl->SetPosition((setting->screenWidth / 2 - kenControl->GetScaleWidth() / 2) + 520.0f, 840.0f);


	startSound = new Sound("start.ogg");
	startSound->SetVolume(70);
	startSound->Play(false);

	endSound = new Sound("end.ogg");
	endSound->SetVolume(70);
	count = 0;

	music = new Music("bg_music.ogg");
	music->SetVolume(40);
	music->Play(true);
}

void Demo::Update()
{
	if (inputManager->IsKeyReleased("Start")) {
		if (game_state != 1) {
			game_state = 1;
			Load();
		}
		return;
	}

	if (inputManager->IsKeyReleased("Exit")) {
		if (game_state != 0) {
			game_state = 0;
			music = new Music("theme.ogg");
			music->Play(true);
		}
		else {
			state = State::EXIT;
		}
		return;
	}

	if (game_state == 0) {
		if (count == 240) {
			count = 0;
		}
		else {
			count++;
		}
	}

	if (game_state == 1) {
		float gametime = GetGameTime();
		mack->setGameTime(gametime);
		ken->setGameTime(gametime);
		mack->update(inputManager, "Mack", ken);
		ken->update(inputManager, "Ken", mack);


		health1->SetSize(55.0f * mack->getHealth() / 100, 4.0f);
		health2->SetSize(-56.0f * ken->getHealth() / 100, 4.0f);
		health2->SetRotation(180.0f);

		if (mack->getX() + 75.0f > ken->getX() + 75.0f) {
			mack->flip(true);
			mack->setFlipHitbox(true);
		}
		else {
			mack->flip(false);
			mack->setFlipHitbox(false);
		}

		if (ken->getX() + 75.0f < mack->getX() + 75.0f) {
			ken->flip(true);
			ken->setFlipHitbox(false);
		}
		else {
			ken->flip(false);
			ken->setFlipHitbox(true);
		}

		if (mack->getDead() || ken->getDead()) {
			if (count == 2) {
				count = 2;
			}
			else {
				count = 1;
			}
		}
	}
	
}

void Demo::Render()
{
	bgSprite->Draw();
	switch (game_state) {
		case 0:
			titleSprite->Draw();
			if (count >= 120 && count <= 200) {
			}
			else {
				promptSprite->Draw();
			}
			break;
		case 1:
			mack->draw();
			ken->draw();
			healthbar->Draw();
			health1->Draw();
			health2->Draw();
			mackControl->Draw();
			kenControl->Draw();
;
			if (mack->getDead()) {
				kenWin->Draw();
				if (count != 2) {
					music->Stop();
					endSound->Play(false);
					count = 2;
				}
				return;
			}
			if (ken->getDead()) {
				mackWin->Draw();
				if (count != 2) {
					music->Stop();
					endSound->Play(false);
					count = 2;
				}
				return;
			}
			break;
	}
}


int main(int argc, char** argv) {
	Setting* setting = new Setting();
	Game* game = new Demo(setting);
	game->Run();
	delete setting;
	delete game;

	return 0;
}
