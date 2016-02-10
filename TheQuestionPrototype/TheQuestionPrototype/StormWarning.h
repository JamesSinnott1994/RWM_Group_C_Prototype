#ifndef STORMWARNING_H
#define STORMWARNING_H

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class StormWarning
{
private:
	static bool instanceFlag;
	static StormWarning* instance;

	float secondsPassed;
	const int countdown = 0;
	bool disasterToOccur;
	float timeToDisaster;
	int disasterType;
	float onSecond;

	StormWarning::StormWarning()
	{
		secondsPassed = 0;
		disasterToOccur = false;
		disasterType = 1;
		onSecond = 0;
	}

public:
	static StormWarning* GetInstance();
	~StormWarning()
	{
		instanceFlag = false;
		
	}

	void Init();
	void Update(float ftime);
};

#endif