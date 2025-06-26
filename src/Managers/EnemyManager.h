#pragma once
#include <vector>
#include <memory>

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
private:
	std::vector<EnemyRef> enemies;
};

