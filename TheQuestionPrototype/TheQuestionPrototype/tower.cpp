#include "Tower.h"
#include "MinionManager.h"
#include "GoldManager.h"

Tower::Tower(int x, int y , int team)
{
		m_team = team;
		src = {0,0,20,20};
		if (team == 2)
		{
			src = { 20, 0, 20, 20 };
		}
		dest = {x,y,50,100};
		text = loadTexture("towerImg.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		statstext = loadTexture("stats.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		healthBar = loadTexture("healthBar.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		storm = loadTexture("stormImage.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		volcano = loadTexture("volcanoImage.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		flood = loadTexture("floodImage.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		eathq = loadTexture("earthqImage.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		radius = loadTexture("radius.png", Renderer::GetInstance()->Get_SDL_RENDERER());
		health = 100;
		timeSinceAttack = 0;
		displayStats = false;
		stormProof = false;
		volcanoProof = false;
		floodProof = false;
		earthquakeProof = false;
		last_mouse_clicked_time = SDL_GetTicks();
		alive = true;

		NoOfMinions = 0;
}

void Tower::Draw(int noOfMinions, int team)
{
	Renderer::GetInstance()->DrawImageNoOffset(&src, &dest, text, 0, &offset);

	/*if (team == 1)
		NoOfTeam1Minions = noOfMinions;
	else
		NoOfTeam2Minions = noOfMinions;*/
	SDL_Rect src1, dest1;
	src1 = { 0, 0, 300, 300 };
	if (m_team == 2)
	{
		src1 = { 300, 0, 300, 300 };
	}
	dest1 = { dest.x - 125, dest.y -100, 300, 300 };
	Renderer::GetInstance()->DrawImageNoOffset(&src1, &dest1, radius, 0, &offset);


	if (displayStats)
	{
		SDL_Rect src3, dest3;
		SDL_Rect src2, dest2;
		
		src1 = {0,0,105,50};
		src2 = { 0, 0, 105, 50 };
		dest1 = { dest.x + 20, dest.y, 105, 100 };
		dest2 = { dest.x + 20, dest.y, 105, 100 };
		Renderer::GetInstance()->DrawImageNoOffset(&src1, &dest1, statstext, 0, &offset);
		src1 = { 0, 0, 95, 10 };
		dest1 = { dest.x + 25, dest.y + 5, health * 0.95f, 10 };
		Renderer::GetInstance()->DrawImageNoOffset(&src1, &dest1, healthBar, 0, &offset);
		if (!stormProof)
		{
			src1 = { 0, 0, 20, 20 };
			dest1 = { dest.x + 25, dest.y + 20, 20, 20 };
			src3 = { 0, 0, 20, 20 };
			dest3 = { dest.x + 50, dest.y + 20, 20, 20 };
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
		
	

		rect = dest;
		rect.x += 0;
		rect.y += 50;
		rect.w = 20;
		rect.h = 20;

		// Draw number of minions
		for (int i = 0; i < NoOfMinions; i++)
		{
			rect.x += 25;

			SDL_SetRenderDrawColor(Renderer::GetInstance()->Get_SDL_RENDERER(), 0, 0, 0, 255);// Grey
			SDL_RenderFillRect(Renderer::GetInstance()->Get_SDL_RENDERER(), &rect);
		}
	}
}

void Tower::update(float time) {
	timeSinceAttack += time;
	if (timeSinceAttack >= 1){
		//do attack here 

		MinionManager::GetInstance()->attackMinion(m_team, 30, dest);
		timeSinceAttack = 0;
	}

	if (health <= 0){
		cout << "game paused switch to other game mode " << endl;
		system("pause");
		cout << "press 1 to switch team 2 to destroy tower" << endl;
		int result = 0;
		cin >> result ;
		if (result == 1)
		{
			if (m_team == 2)
			{
				m_team = 1;
			}
			else if (m_team == 1)
			{
				m_team = 2;
			}
			health = 100;
			src = { 0, 0, 20, 20 };
			if (m_team == 2)
			{
				src = { 20, 0, 20, 20 };
			}
		}
		else 
		{
			alive = false;
		}
		
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

bool Tower::mouseClicked(SDL_Point mouse, int noOfMinions)
{
	bool click = false;
	// Remove minions
		if (NoOfMinions > 0
			&& mouse.x > rect.x && mouse.x < rect.x + rect.w
			&& mouse.y > rect.y && mouse.y < rect.y + rect.h)
		{
			std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
			NoOfMinions -= 1;
			click = true;
		}

	
		if (mouse.x < dest.x + dest.w && mouse.x > dest.x
			&&mouse.y < dest.y + dest.h && mouse.y > dest.y)
		{
			displayStats = !displayStats;
		}
		else if (!stormProof &&
			mouse.x < dest.x +45 && mouse.x > dest.x + 25
			&&mouse.y < dest.y + 40 && mouse.y > dest.y +20 &&
			GoldManager::GetInstance()->getGold(m_team) >= 100)
		{
			stormProof = true;
			GoldManager::GetInstance()->addGold(-100, m_team);
		}
		else if (!volcanoProof &&
			mouse.x < dest.x + 75 && mouse.x > dest.x + 50
			&& mouse.y < dest.y + 40 && mouse.y > dest.y + 20 &&
			GoldManager::GetInstance()->getGold(m_team) >= 100)
		{
			volcanoProof = true;
			GoldManager::GetInstance()->addGold(-100, m_team);
		}
		else if (!floodProof &&
			mouse.x < dest.x + 95 && mouse.x > dest.x + 75
			&& mouse.y < dest.y + 40 && mouse.y > dest.y + 20 &&
			GoldManager::GetInstance()->getGold(m_team) >= 100)
		{
			floodProof = true;
			GoldManager::GetInstance()->addGold(-100, m_team);
		}
		else if (!earthquakeProof &&
			mouse.x < dest.x + 125 && mouse.x > dest.x + 100
			&& mouse.y < dest.y + 40 && mouse.y > dest.y + 20 &&
			GoldManager::GetInstance()->getGold(m_team) >= 100)
		{
			earthquakeProof = true;
			GoldManager::GetInstance()->addGold(-100, m_team);
		}

		return click;

}

bool Tower::collidingWithTower(SDL_Rect pos)
{
	if (dest.x < pos.x + pos.w && dest.x + dest.w > pos.x 
		&& dest.y < pos.y + pos.h && dest.y + dest.h > pos.y)
	{
		return true;
	}
	return false;
}

void Tower::setDamage(int dmg){
	health -= dmg;
}

bool Tower::colliding(SDL_Rect pos, int rad) {
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