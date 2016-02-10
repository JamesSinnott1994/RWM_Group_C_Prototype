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

void Base::Update() {
	if (health <= 0){
		std::cout << "Base" << m_team << " is dead!!!" << std::endl;
	}
}

void Base::Draw()
{
	if (health > 0)
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

void Base::doDamage(int damage){
	health -= damage;
}

bool Base::colliding(SDL_Rect pos, int rad) {
	SDL_Point m_pos = { dest.x + dest.w / 2, dest.y - dest.h / 2 };
	SDL_Point minion_pos = { pos.x + pos.w / 2, pos.y - pos.h / 2 };

	SDL_Point direction = { m_pos.x - minion_pos.x, m_pos.y - minion_pos.y };
	float length = sqrt(direction.x*direction.x + direction.y*direction.y);

	if (length < rad)
	{
		return true;
	}
	return false;
}