#include "Tower.h"
#include "Renderer.h"
#include <SDL_image.h>


Tower::Tower(int x, int y )
{

		src = {0,0,20,20};
		dest = {x,y,20,20};
		text = loadTexture("towerImg.png", Renderer::GetInstance()->Get_SDL_RENDERER());

}

void Tower::Draw()
{
	Renderer::GetInstance()->DrawImageNoOffset(&src, &dest, text, 0, &offset);
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