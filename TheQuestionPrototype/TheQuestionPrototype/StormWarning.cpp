#include "StormWarning.h"

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
		std::cout << "A natural disaster is about to occur!" << std::endl;
		secondsPassed = 0;
		disasterToOccur = true;
	}

	if (disasterToOccur)
	{
		std::cout << "Disaster occuring in" << std::endl;
		for (int i = 10; i > 0; i--){
			std::cout << i << std::endl;
		}
		disasterToOccur = false;
	}
}