#include "Demo.h"

using namespace Engine;

Demo::Demo(Setting* setting) :Game(setting)
{

}


Demo::~Demo()
{
	delete crateTexture;
	delete bartTexture;
	delete crateSprite;
	delete crateSprite2;
	delete bartSprite;
	delete music;
	delete text;
}

void Demo::Init()
{
	count = 0;

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

	music = new Music("bensound-funkyelement.ogg");
	music->SetVolume(40);
	music->Play(true);
}

void Demo::Update()
{
	if (inputManager->IsKeyReleased("Start")) {
		state = State::EXIT;
		return;
	}

	if (count == 240) {
		count = 0;
	}
	else {
		count++;
	}



	/*bartSprite->Update(GetGameTime());
	bartSprite->SetEnableAnimation(xspeed == 0 ? false : true);
	bartSprite->SetPosition(bartSprite->GetX() + xspeed * GetGameTime(),
	bartSprite->GetY() + yspeed * GetGameTime());*/


}

void Demo::Render()
{
	bgSprite->Draw();
	titleSprite->Draw();
	if (count >= 120 && count <= 200) {
	}
	else {
		promptSprite->Draw();
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
