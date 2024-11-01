#pragma once

#include "Enemy.h"
#include "Bullet.h"
#include "Score.h"
#include "Player.h"

#include <memory>
#include <vector>

class Collision
{
public:
	static void enemy_bullet_collision(std::vector<Enemy>& enemies, std::vector<Bullet>& bullets, std::shared_ptr<Score>& score);
	static void player_bullet_collision(std::shared_ptr<Player>& player, std::vector<Bullet>& bullets, std::shared_ptr<Score>& score);
};
