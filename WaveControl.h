#pragma once
#include <SFML/Graphics.hpp>
#include "Wave.h"
#include <memory>

class WaveControl
{
public:
	WaveControl();
	~WaveControl(){}

	std::vector<Wave*> Waves;
	void CreateWave();

private:
	bool isWaveDead;
};