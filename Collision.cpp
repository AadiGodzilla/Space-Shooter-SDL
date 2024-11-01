#include "Collision.h"

#include <iostream>
#include <vector>

#include "Score.h"

void Collision::enemy_bullet_collision(
	std::vector<Enemy>& enemies, 
	std::vector<Bullet>& bullets, 
	std::shared_ptr<Score>& score
)
{
	std::vector<int> enemies_to_remove, bullets_to_remove;

	if (!enemies.empty() && !bullets.empty())
	{
		for (int i = bullets.size() - 1; i >= 0; --i) 
		{
			for (int j = enemies.size() - 1; j >= 0; --j)
			{
				if (SDL_HasIntersection(enemies[j].rect(), bullets[i].rect()) && bullets[i].get_dir())
				{
					enemies[j].destroy();
					bullets[i].destroy();
					enemies_to_remove.push_back(j);
					bullets_to_remove.push_back(i);
					score->add_score();
					break;
				}
			}
		}
	}

	for (int i = bullets_to_remove.size() - 1; i >= 0; --i)
		bullets.erase(bullets.begin() + bullets_to_remove[i]);

	for (int i = enemies_to_remove.size() - 1; i >= 0; --i)
		enemies.erase(enemies.begin() + enemies_to_remove[i]);
}

void Collision::player_bullet_collision(
	std::shared_ptr<Player>& player, 
	std::vector<Bullet>& bullets, 
	std::shared_ptr<Score>& score
)
{
	std::vector<int> bullets_to_remove;

	for (int i = bullets.size() - 1; i >= 0; --i)
	{
		if (SDL_HasIntersection(bullets[i].rect(), player->rect()) && !bullets[i].get_dir())
		{
			bullets_to_remove.push_back(i);
			player->hit();
			if (player->get_hp() <= 0)
			{
				player.reset();
				score->reset_score();
				break;
			}
		}
	}

	for (int i = bullets_to_remove.size() - 1; i >= 0; --i)
		bullets.erase(bullets.begin() + bullets_to_remove[i]);
}
