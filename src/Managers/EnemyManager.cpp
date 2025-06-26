#include "EnemyManager.h"

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
