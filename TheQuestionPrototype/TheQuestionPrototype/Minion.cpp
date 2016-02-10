#include "Minion.h"
#include "Renderer.h"
#include <SDL_image.h>



Minion::Minion(int x, int y, int teamColour)
{
	m_x = x;
	m_y = y;
	team = teamColour;
	m_width = 50;
	m_height = 70;
	m_alive = true;
	m_health = 100;
	m_attackSpeed = 1;
	m_moveSpeed = 1;
	m_attackPower = 5;
	m_selected = false;
	m_selectCheck = false;
	recentlyMoved = false;

	src = { 0, 0, m_width, m_height };
	dest = { m_x, m_y, m_width, m_height };
	text = loadTexture("minion.png", Renderer::GetInstance()->Get_SDL_RENDERER());
}

Minion::~Minion()
{
}

void Minion::Draw()
{
	dest = { m_x, m_y, m_width, m_height };
	Renderer::GetInstance()->DrawImageNoOffset(&src, &dest, text, 0, &offset);
}

SDL_Texture* Minion::loadTexture(std::string path, SDL_Renderer* gRenderer){
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

void Minion::Update(int mouseX, int mouseY, float t)
{	
	time += t;
	if (m_alive == true)
	{
		if (time > 1)
		{
			recentlyMoved = false;
			time = 0;
		}

		if (m_selectCheck == false)
		{
			Move(mouseX,mouseY);
			
		}
		//Selected(mouseX, mouseY);
		
	}
}
void Minion::Move(int mouseX, int mouseY)
{
	if (m_selected == true)
	{
		m_x = mouseX - (m_width/2);
		m_y = mouseY - (m_height / 2);
		std::cout << m_x << "," << m_y << std::endl;
		m_selected = false;
		m_selectCheck = false;
		recentlyMoved = true;
	}
	
}
void Minion::Selected(int mouseX, int mouseY)
{
	if ((mouseX > m_x && mouseX < m_x + m_width) && (mouseY > m_y && mouseY < m_y + m_height))
		{
			if (recentlyMoved == false)
			{
				if (m_selectCheck == false)
				{
					m_selected = true;
					m_selectCheck = true;
					printf("Selected ");
				}
			}
		}
		else
		{
			if (m_selectCheck == true)
			{
				Move(mouseX, mouseY);
				m_selected = false;
				m_selectCheck = false;
				printf("Unselected ");
			}
		
		}	
}

SDL_Rect Minion::getRect()
{
	return dest;
}