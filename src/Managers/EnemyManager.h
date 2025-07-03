#pragma once
#include <vector>
#include <memory>
#include <unordered_map>

#include "Enemy.h"

typedef std::unique_ptr<Enemy> EnemyRef;

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager() = default;
	void AddEnemy(EnemyRef enemyRef);
	void StartAll();
	void UpdateAll();

	std::unordered_map<int, const sf::Vector2i*> GetPosAndIDs();
	std::unordered_map<int, const bool*> GetMovedAndID();
	std::unordered_map<int, const int*> GetLastRoomAndID();
	void ResetMoved();
private:
	std::vector<EnemyRef> enemies;
};

