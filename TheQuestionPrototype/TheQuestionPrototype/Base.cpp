#include "Base.h"

bool Base::instanceFlag = false;
Base* Base::instance = NULL;

Base* Base::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new Base;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void Base::Init(int width, int height)
{
	src = { 0, 0, 280, 151 };
	dest = { width/2, 0, 280/2, 151/2 };
	text = loadTexture("base2.png", Renderer::GetInstance()->Get_SDL_RENDERER());
}

void Base::Update()
{

}

void Base::Draw()
{
	Renderer::GetInstance()->DrawImageNoOffset(&src, &dest, text, 0, &offset);
}

SDL_Texture* Base::loadTexture(std::string path, SDL_Renderer* gRenderer){
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

SDL_Rect Base::getRect() {
	return dest;
}

void Base::createMinion() {
	std::cout << "creating a minion at the base" << std::endl;
}

__int8 Base::getHealth(){
	return health;
}

void Base::setHealth(int pHealth){
	health = pHealth;
}