#include "GameTimer.h"

GameTimer* GameTimer::Instance = nullptr;

GameTimer::GameTimer()
{
	if (Instance == nullptr) Instance = this;
	startTime = std::chrono::high_resolution_clock::now();
	prevTime = startTime;
}

void GameTimer::Update()
{
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - prevTime);
	timer += static_cast<float>(duration.count()) / 1000;
	prevTime = end;
}