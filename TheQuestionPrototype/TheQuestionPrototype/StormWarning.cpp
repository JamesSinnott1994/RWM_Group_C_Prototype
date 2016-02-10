#include "StormWarning.h"
#include "TowerManager.h"
#include "MinionManager.h"

bool StormWarning::instanceFlag = false;
StormWarning* StormWarning::instance = NULL;

StormWarning* StormWarning::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new StormWarning;
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void StormWarning::Update(float ftime)
{
	if (!disasterToOccur)
		secondsPassed += ftime;

	if (secondsPassed >= 5)
	{
		disasterType = rand()% 4 + 1;
		string type = "type";
		if (disasterType == 1)
		{
			type = "Storm";
		}
		else if (disasterType == 2)
		{
			type = "Volcano";
		}
		else if (disasterType == 3)
		{
			type = "Flood";
		}
		else if (disasterType == 4)
		{
			type = "Earthquake";
		}
		std::cout << "A natural disaster is about to occur! : " << type << std::endl;
		secondsPassed = 0;
		disasterToOccur = true;
		timeToDisaster = 10;
	}
	if (disasterToOccur)
	{
		timeToDisaster -= ftime;

		if (timeToDisaster >= 0)
		{
			onSecond += ftime;
			if (onSecond >= 1)
			{
				std::cout << " Disaster in " << timeToDisaster << std::endl;
				onSecond = 0;
			}
		}
		else
		{
			std::cout << "Disaster occuring" << std::endl;
			TowerManager::GetInstance()->DisasterOccured(disasterType);
			MinionManager::GetInstance()->DisasterOccured(disasterType);
			disasterToOccur = false;
		}
	}
}