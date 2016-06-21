#include <string>
#include "Wave.h"
#include "WaveControl.h"

WaveControl::WaveControl()
{
	
}

void WaveControl::CreateWave()
{
	int min = 1;
	int max = 6;
	int appearLane = min + (rand() % (int)(max - min + 1));

	Waves.push_back(new Wave(appearLane));
}


