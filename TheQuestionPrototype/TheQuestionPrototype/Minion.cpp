#include "Minion.h"

Minion::Minion(int x, int y, int teamColour) : m_x(x), m_y(y), m_team(teamColour) {
	m_width = 50;
	m_height = 70;
	m_alive = true;
	m_health = 100;
	m_attackSpeed = .75;
	m_moveSpeed = 1;
	m_attackPower = 5;
	m_selected = false;
	m_selectCheck = false;
	recentlyMoved = false;

	InTower = false;

	if (m_team == 1)
		src = { 0, 0, m_width, m_height };
	else if (m_team == 2)
		src = { m_width, 0, m_width, m_height };

	dest = { m_x, m_y, m_width, m_height };
	text = loadTexture("minion.png", Renderer::GetInstance()->Get_SDL_RENDERER());
	healthBar = loadTexture("healthBar.png", Renderer::GetInstance()->Get_SDL_RENDERER());
}

Minion::~Minion()
{
}

void Minion::Draw()
{
	if (m_alive == true && !InTower)
	{
		SDL_Rect src1, dest1;
		src1 = { 0, 0, 95, 10 };
		dest1 = { dest.x + 25, dest.y + 5, m_health * 0.95f, 10 };
		Renderer::GetInstance()->DrawImageNoOffset(&src1, &dest1, healthBar, 0, &offset);
		dest = { m_x, m_y, m_width, m_height };
		Renderer::GetInstance()->DrawImageNoOffset(&src, &dest, text, 0, &offset);
	}
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

void Minion::Update(int mouseX, int mouseY, float t) {
	time += t;
	timeSinceAttack += t;
	if (m_alive == true) {
		if (m_health <= 0) {
			m_alive = false;
		}

		if (time > 1) {
			recentlyMoved = false;
			time = 0;
		}

		if (m_selectCheck == false) {
			Move(mouseX,mouseY);
		}

		if (timeSinceAttack >= m_attackSpeed){
			TowerManager::GetInstance()->attackTurret(m_team, 10, SDL_Rect{m_x, m_y, dest.w, dest.h} );
			timeSinceAttack = 0;
		}
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
	if (!InTower)
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
}

SDL_Rect Minion::getRect()
{
	return dest;
}

void Minion::setRect(SDL_Rect pos)
{
	m_x = pos.x;
	m_y = pos.y;

	dest.x = m_x;
	dest.y = m_y;
}

void Minion::Disaster(int identifier)
{
	if (identifier == 1)//storm
	{
		m_health -= 20;
	}
	else if (identifier == 2)//volcano
	{
		m_health -= 20;
	}
	else if (identifier == 3)//flood
	{
		m_health -= 20;
	}
	else if (identifier == 4)//earthq
	{
		m_health -= 20;
	}
}

bool Minion::colliding(SDL_Rect pos , int rad)
{
	SDL_Point m_pos = { dest.x + dest.w / 2, dest.y - dest.h / 2 };
	SDL_Point tower_pos = { pos.x + pos.w / 2, pos.y - pos.h / 2 };

	SDL_Point direction = { m_pos.x - tower_pos.x, m_pos.y - tower_pos.y };
	float length = sqrt(direction.x*direction.x + direction.y*direction.y);

	if (length < rad)
	{
		return true;
	}
	return false;
}

void Minion::doDamage(int dmg)
{
	m_health -= dmg;
}