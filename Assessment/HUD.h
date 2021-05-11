#pragma once
#include "SDL.h"
#include <vector>
#include "Text.h"
#include "ImageLoader.h"
#include "Renderer.h"
#include "SoundManager.h"

using namespace std;

class HUD
{
public:
	HUD(Renderer* r);

	~HUD();
	void AddText(Text* t);
	void AddImage(SDL_Texture* texture);// Image* image);

	void CreateHUD(SDL_Renderer* r);
	void DisplayHUD();

	void MoveText(Text* t, int newX, int newY);
	void MoveImage();// Image* image, int newX, int newY);

	vector<Text*> activeTexts; 		//vector of texts to add to and access?
	vector<SDL_Texture*> activeImages;		//vector of imagesto add to and access?
	void ChangeHealth(SoundManager* sfxMan,int change);
	void ChangeGold(SoundManager* sfxMan,int change);
private:
	void DisplayHealth();

	Renderer* renderer;
	SDL_Renderer* sdl_rend;

	ImageLoader* imageLoader;
	
	SDL_Texture* weaponIcon;
	SDL_Texture* heartIcon;
	SDL_Texture* blankHeart;

	int heartSize = 30;
	int lives = 3;
	int gold = 0;

	SDL_Rect weaponRect { 0, 515, 125, 125 };
	SDL_Rect livesRect1 { 750, 0, heartSize, heartSize};
	SDL_Rect livesRect2 { 700, 0, heartSize, heartSize};
	SDL_Rect livesRect3 { 650, 0, heartSize, heartSize};

	const string weaponIconPath = "Assets/sword.bmp";
	const string heartImagePath = "Assets/heart.bmp";
	const string blankHeartPath = "Assets/blankheart.bmp";

	Text* moneyText;
	Text* healthText;
	Text* weaponText;

	string money = "Gold: " + to_string(gold);
	string health = "Lives: ";
	string weaponName = "Diamond Sword";
};

