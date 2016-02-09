#ifndef STORMWARNING_H
#define STORMWARNING_H

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

class StormWarning
{
private:
	static bool instanceFlag;
	static StormWarning* instance;

	float secondsPassed;
	const int countdown = 0;
	bool disasterToOccur;

	StormWarning::StormWarning()
	{
		secondsPassed = 0;
	}

public:
	static StormWarning* GetInstance();
	~StormWarning()
	{
		instanceFlag = false;
		disasterToOccur = false;
	}

	void Init();
	void Update(float ftime);
};

#endif