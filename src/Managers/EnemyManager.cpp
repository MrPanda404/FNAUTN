#include "EnemyManager.h"
#include <iostream>

EnemyManager::EnemyManager()
{
}

void EnemyManager::AddEnemy(EnemyRef enemyRef)
{
	enemies.push_back(std::move(enemyRef));
}

void EnemyManager::StartAll()
{
	for (auto& enemy : enemies) {
		enemy->Start();
	}
}

void EnemyManager::UpdateAll()
{
	for (auto& enemy : enemies) {
		enemy->Update();
	}
}

std::unordered_map<int, const sf::Vector2i*> EnemyManager::GetPosAndIDs()
{
	std::unordered_map<int, const sf::Vector2i*> posAndIDs;

	for (auto& enemy : enemies) {
		posAndIDs.insert(enemy->GetPosAndID());

		std::cout<<enemy->GetPosAndID().second->x << " - " << enemy->GetPosAndID().second->y<< " (EnemyManager.cpp)" << std::endl;
	}

	return posAndIDs;
}

std::unordered_map<int, const bool*> EnemyManager::GetMovedAndID()
{
	std::unordered_map<int, const bool*> movedList;
	for (auto& enemy : enemies) {
		movedList.insert(enemy->GetMovedAndID());
	}

	return movedList;
}

std::unordered_map<int, const int*> EnemyManager::GetLastRoomAndID()
{
	std::unordered_map<int, const int*> lastRoomReference;
	for (auto& enemy : enemies) {
		lastRoomReference.insert(enemy->GetLastRoomAndID());
	}

	return lastRoomReference;
}

void EnemyManager::ResetMoved()
{
	for (auto& enemy : enemies) {
		enemy->ResetMoved();
	}
}
