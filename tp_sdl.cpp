#include <SDL.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <memory>
#include <random>
#include <string>
#include "audio.hpp"
#include "tube.hpp"
#include "enemy.hpp"
#include "menu.hpp"
#include "game.hpp"
#include "blaster.hpp"
#include "bullet.hpp"


int last_x;
int last_y;

int main(int argc, char** argv)
{
	auto game = std::shared_ptr<Games> (new Games());
	int start=game->genere_menu();
	if(start ==1)
		{
			float velocity_coef=0.005;
			game->jouer(velocity_coef);
		}
	if(game->score->get_score()<0)
		game->game_over();
	

	return 0;
}
