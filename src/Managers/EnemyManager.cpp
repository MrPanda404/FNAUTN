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

std::unordered_map<int, const sf::Vector2i*> EnemyManager::getPosAndIDs()
{
	std::unordered_map<int, const sf::Vector2i*> posAndIDs;

	for (auto& enemy : enemies) {
		posAndIDs.insert(enemy->GetPosAndID());

		std::cout << enemy.get()->GetPosAndID().first + " - " << enemy.get()->GetPosAndID().second << std::endl;
	}

	return posAndIDs;
}
