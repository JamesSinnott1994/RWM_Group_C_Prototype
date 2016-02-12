#include "TowerManager.h"

bool TowerManager::instanceFlag = false;
TowerManager* TowerManager::instance = NULL;

TowerManager* TowerManager::GetInstance(){
	if (!instanceFlag)
	{
		instance = new TowerManager;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

TowerManager::TowerManager(){

}

void TowerManager::addTower(int team, float x, float y) {
	if (team == 1)
		Team_1_towers.push_back(new Tower(x, y,1));
	if (team == 2)
		Team_2_towers.push_back(new Tower(x, y,2));
}

void TowerManager::Draw() {
	/*Call Draw on objects here*/
	for each(Tower * t in Team_1_towers) {
		t->Draw(TeamsOneMinions, 1);
	}
	for each(Tower * t in Team_2_towers) {
		t->Draw(TeamsTwoMinions, 2);
	}
}

void TowerManager::Update(float time)
{
	for (list<Tower*>::iterator it = Team_1_towers.begin(); it != Team_1_towers.end();) {
		(*it)->update(time);
		if ((*it)->getAlive()) {
			if ((*it)->getTeam() == 2)
			{
				Team_2_towers.push_back(*it);
				it = Team_1_towers.erase(it);
			}
			else
			{
				it++;
			}
		}
		else {
			it = Team_1_towers.erase(it);
		}
	}
	for (list<Tower*>::iterator it = Team_2_towers.begin(); it != Team_2_towers.end();) {
		(*it)->update(time);
		if ((*it)->getAlive()) {
			if ((*it)->getTeam() == 1)
			{
				Team_1_towers.push_back(*it);
				it = Team_2_towers.erase(it);
			}
			else
			{
				it++;
			}
		}
		else {
			it = Team_2_towers.erase(it);
		}
	}
}

bool TowerManager::mouseClicked(SDL_Point mouse) {
	bool temp = false;
	for each(Tower * t in Team_1_towers)
	{
		temp =  t->mouseClicked(mouse, TeamsOneMinions);
		if (temp)
		{
			return temp;
		}
	}
	return temp;
}

bool TowerManager::KeyBoardClicked(SDL_Point mouse) 
{
	bool temp = false;
	for each(Tower * t in Team_2_towers) 
	{
		temp = t->mouseClicked(mouse, TeamsTwoMinions);
		if (temp)
		{
			return temp;
		}
	}
	return temp;
}

void TowerManager::DisasterOccured(int type) {
	for each(Tower * t in Team_1_towers) {
		t->Disaster(type);
	}
	for each(Tower * t in Team_2_towers) {
		t->Disaster(type);
	}
}

bool TowerManager::collidingWithTower(SDL_Rect pos, int team) 
{
	if (team == 1) 
	{
		for each(Tower * t in Team_1_towers) 
		{
			if (t->collidingWithTower(pos)) 
			{
				// t->AddNumMinions();***************
				t->NoOfMinions += 1;
				return true;
			}
		}
	}
	
	else if (team == 2) 
	{
		for each(Tower * t in Team_2_towers) 
		{
			if (t->collidingWithTower(pos)) 
			{
				// t->AddNumMinions();***************
				t->NoOfMinions += 1;
				return true;
			}
		}
	}
}

void TowerManager::attackTurret(int team, int damage, SDL_Rect minionPos) {
	if (team == 1) {
		for each  (Tower* t in Team_2_towers){
			if (t->colliding(minionPos, 150)) {
				t->setDamage(damage);
				break;
			}
		}
	}
	else if (team == 2)
	{
		for each  (Tower* t in Team_1_towers){

			if (t->colliding(minionPos, 150))
			{
				t->setDamage(damage);
				break;
			}
		}
	}
}