#include "Tower.h"

Tower::Tower(int x, int y )
{

		src = {0,0,20,20};
		dest = {x,y,20,20};
		text = loadTexture("towerImg.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		statstext = loadTexture("stats.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		healthBar = loadTexture("healthBar.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		storm = loadTexture("stormImage.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		volcano = loadTexture("volcanoImage.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		flood = loadTexture("floodImage.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		eathq = loadTexture("earthqImage.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		health = 100;
		timeSinceAttack = 0;
		displayStats = true;
		stormProof = false;
		volcanoProof = false;
		floodProof = false;
		earthquakeProof = false;
}

void Tower::Draw()
{
	Renderer::GetInstance()->DrawImageNoOffset(&src, &dest, text, 0, &offset);

	if (displayStats)
	{
		SDL_Rect src1, dest1;
		src1 = {0,0,105,50};
		dest1 = { dest.x + 20, dest.y, 105, 50 };
		Renderer::GetInstance()->DrawImageNoOffset(&src1, &dest1, statstext, 0, &offset);
		src1 = { 0, 0, 95, 10 };
		dest1 = { dest.x + 25, dest.y + 5, health * 0.95f, 10 };
		Renderer::GetInstance()->DrawImageNoOffset(&src1, &dest1, healthBar, 0, &offset);
		if (!stormProof)
		{
			src1 = { 0, 0, 20, 20 };
			dest1 = { dest.x + 25, dest.y + 20, 20, 20 };
			Renderer::GetInstance()->DrawImageNoOffset(&src1, &dest1, storm, 0, &offset);
		}
		if (!volcanoProof)
		{
			src1 = { 0, 0, 20, 20 };
			dest1 = { dest.x + 50, dest.y + 20, 20, 20 };
			Renderer::GetInstance()->DrawImageNoOffset(&src1, &dest1, volcano, 0, &offset);
		}
		
		if (!floodProof)
		{
			src1 = { 0, 0, 20, 20 };
			dest1 = { dest.x + 75, dest.y + 20, 20, 20 };
			Renderer::GetInstance()->DrawImageNoOffset(&src1, &dest1, flood, 0, &offset);
		}
		
		if (!earthquakeProof)
		{
			src1 = { 0, 0, 20, 20 };
			dest1 = { dest.x + 100, dest.y + 20, 20, 20 };
			Renderer::GetInstance()->DrawImageNoOffset(&src1, &dest1, eathq, 0, &offset);
		}
		

	}
}
void Tower::update(float time)
{
	timeSinceAttack += time;
	if (timeSinceAttack >= 1)
	{
		//do attack here 
		timeSinceAttack = 0;
	}
}
void Tower::Disaster(int identifier)
{
	if (identifier == 1 && !stormProof)//storm
	{
		health -= 20;
	}
	else if (identifier == 2 && !volcanoProof)//storm
	{
		health -= 20;
	}
	else if(identifier == 3 && !floodProof)//storm
	{
		health -= 20;
	}
	else if(identifier == 4 && !earthquakeProof)//storm
	{
		health -= 20;
	}
}


SDL_Texture* Tower::loadTexture(std::string path, SDL_Renderer* gRenderer){
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