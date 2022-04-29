#include <SDL.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <memory>
#include <random>
#include <string>
#include "../include/audio.hpp"
#include "../include/tube.hpp"
#include "../include/enemy.hpp"
#include "../include/menu.hpp"
#include "../include/game.hpp"
#include "../include/blaster.hpp"
#include "../include/bullet.hpp"


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
	//if(game->score->get_score()<0)
	//if(game->score->get_nbLives()==0)
	game->game_over();
	

	return 0;
}
