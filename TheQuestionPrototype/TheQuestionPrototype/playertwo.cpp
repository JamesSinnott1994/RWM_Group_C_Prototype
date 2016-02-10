#include "playertwo.h"

bool playertwo::instanceFlag = false;
playertwo* playertwo::instance = NULL;

playertwo* playertwo::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new playertwo;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void playertwo::Init()
{
	x = 50;
	y = 50;
	w = 10;
	h = 10;
	mouse = loadTexture("mouse.png", Renderer::GetInstance()->Get_SDL_RENDERER());

}

void playertwo::Update()
{
	// Move mouse
	if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_UP))
	{
		y -= 0.05f;
	}
	if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_DOWN))
	{
		y += 0.05f;
	}
	if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_LEFT))
	{
		x -= 0.05f;
	}
	if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_RIGHT))
	{
		x += 0.05f;
	}

	// Select minion
	/*if (KeyBoardInput::GetInstance()->isKeyPressed(SDLK_TAB))
	{

	}*/
}

void playertwo::Draw()
{
	//SDL_Rect outerRect = { x, y, w, h };
	//SDL_SetRenderDrawColor(Renderer::GetInstance()->Get_SDL_RENDERER(), 187, 122, 87, 255);// Brown
	//SDL_RenderFillRect(Renderer::GetInstance()->Get_SDL_RENDERER(), &outerRect);

	SDL_Rect src = { 0, 0, 10, 10 };
	SDL_Rect rect = { x, y, w, h };
	SDL_Point offset = { 0, 0 };
	Renderer::GetInstance()->DrawImageNoOffset(&src, &rect, mouse, 0, &offset);
}

SDL_Rect playertwo::getRect()
{
	SDL_Rect rect = { x, y, w, h };

	return rect;
}

SDL_Texture* playertwo::loadTexture(std::string path, SDL_Renderer* gRenderer){
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL){
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}