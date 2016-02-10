#include "Base.h"

Base::Base(SDL_Point pos, int team )
{
	m_team = team;
	health = 500;
	src = { 0, 0, 280, 151 };
	dest = { pos.x , pos.y, 280,151 };
	text = loadTexture("base2.png", Renderer::GetInstance()->Get_SDL_RENDERER());
	if (team == 2)
	{
		src = { 280, 0, 280, 151 };
	}
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

int Base::getHealth(){
	return health;
}

void Base::setHealth(int pHealth){
	health = pHealth;
}