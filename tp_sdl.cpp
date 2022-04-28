#include <SDL.h>
#include <assert.h>

#include <ctime>
#include <random>
#include <algorithm>
#include <string>
#include <iostream>

#include "./menu.hpp"
#include "./game.hpp"
#include "./blaster.hpp"
#include "./bullet.hpp"
#include "./tube.hpp"
#include "./enemy.hpp"
#include "./audio.hpp"



#define RAND_MAXIMUM 5


Uint8 color[4] = {255,255,0,255};
int last_x;
int last_y;
static int start = 0;
int tubeQuad_[4][2]={{256, 60}, {316, 73}, {264, 257},{256, 255}};
static int quad=0;


int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
	{
		std::cerr<<"Pb init SDL"<< std::endl;
		return 0;
	}

	SDL_Window* window = SDL_CreateWindow("Test_SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
						  SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
	
    
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    Menu *menu = new Menu(renderer);
	Games * game = new Games();
	game->lives.push_back(new Score());
	game->lives.push_back(new Score());
	game->lives.push_back(new Score());
	game->lives.push_back(new Score());
	//Sound* CollisionSound= new Sound("/home/oumayma/Documents/mp3/shoot.mp3");
	assert (renderer != NULL);

	bool quit = false;
	bool quit_game = false;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_s:
						std::cout << "you clicked s"<<std::endl;
						//Mix_PausedMusic() ? Mix_ResumeMusic() : Mix_PauseMusic();
						start =1;
						
						
						quit=true;
						break;
					case SDLK_q:
						std::cout << "you clicked q"<<std::endl;
						quit = true;
						break;
					default :
						break;

				}
				
			}
		}
		
		
		SDL_SetRenderDrawColor(renderer, 0,0,0,255);
		SDL_RenderClear(renderer);
		
		SDL_SetRenderDrawColor(renderer, 0,0,255,0);
		
		
		menu->hershey(renderer, "Level 1", 350, 70, 1);
		SDL_SetRenderDrawColor(renderer, 255,0,0,0);
		menu->hershey(renderer, "Type s to START", 270, 250, 1);
		SDL_SetRenderDrawColor(renderer, 255,250,42,0);
		menu->hershey(renderer, "<- -> To move", 265, 300, 1);
		menu->hershey(renderer, "Space To shoot", 273, 350, 1);
		SDL_SetRenderDrawColor(renderer, 255,0,0,0);
		menu->hershey(renderer, "FLIPPERS AREHARMLESS MID-FLIP", 150, 400, 1);
		menu->hershey(renderer, "ENEMY BULLETS ARE DESTRUCTIBLE", 150, 450, 1);
		SDL_RenderPresent(renderer);
		
	}
	SDL_Quit();
	if(start ==1)
		{
			
			SDL_Window* window_game = SDL_CreateWindow("Test_SDL_GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 800,
						  SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
			SDL_Renderer* renderer_game = SDL_CreateRenderer(window_game, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
			Menu * menu2 = new Menu(renderer_game);
			Blaster * blaster = new Blaster();
			Forme f = Tube_Circle;
			Tube * tube= new Tube(Tube_Circle);
			
			
			tube->affect_quads(Tube_Circle);

			std::random_device rd;  //Will be used to obtain a seed for the random number engine
    		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    		std::uniform_int_distribution<> distrib(1, 15);
			game->enemies.push_back(new Enemy(distrib(gen),0));
			game->enemies.push_back(new Enemy(distrib(gen),1));
			game->enemies.push_back(new Enemy(distrib(gen),2));
			game->enemies.push_back(new Enemy(distrib(gen),3));
			int i=1;
			Utils *utils=new Utils();
			while(!quit_game)
			{
				SDL_Event event_g;
				while (!quit_game && SDL_PollEvent(&event_g))
				{
					switch (event_g.type)
					{
						case SDL_QUIT:
							quit_game = true;
							break;
						
						/*case SDL_MOUSEMOTION:
							std::cout <<event_g.motion.x<<","<<event_g.motion.y<<'\n';
							break;*/
						case SDL_KEYDOWN:
							switch(event_g.key.keysym.sym)
							{
								case SDLK_RIGHT:
									//CollisionSound->PlaySound();
									std::cout<<"right"<<std::endl;
									if(quad <= 15) 
									{
										if(quad==15)
										{
											quad=0;
											blaster->move_r(renderer_game,quad,tube->tube_quads,2,-5,2,10);
										}
										else
										{
											quad++;
											
											blaster->move_r(renderer_game,quad,tube->tube_quads,2,-5,2,10);

										}
										
										
									}
									break;
								case SDLK_LEFT:
									if(quad <= 15) 
									{
										if(quad==0)
										{
											quad=15;
											blaster->move_l(renderer_game,quad,tube->tube_quads,2,-5,2,10);
										}
										else
										{
											quad--;
											blaster->move_l(renderer_game,quad,tube->tube_quads,2,-5,2,10);

										}
									}
									break;
								case SDLK_RETURN:
									game->bullets.push_back(new Bullet(quad));
									break;
							}
					}


				}
				SDL_SetRenderDrawColor(renderer_game, 0,0,0,255);
				SDL_RenderClear(renderer_game);
				SDL_SetRenderDrawColor(renderer_game, 0,0,255,0);
				menu2->hershey(renderer_game,"Level 1",300,30,1);
				//blaster->defineTubeQuads();
				blaster->drawTubeQuads(renderer_game,2,-5,2);
				blaster->drawblaster(renderer_game,tube->tube_quads[quad],2,-5,2,10);
				SDL_SetRenderDrawColor(renderer_game, 54,244,11,0);
				menu2->hershey(renderer_game,std::to_string(game->score->get_score()),100,30,1);
				int i=10;

				for(auto &live:game->lives)
				{
					live->draw_live(renderer_game,2,10+i,50);
					i=i+50;
					
				}
				
				float velocity_coef=0.005;
				/********generate ennemies******/
				for(auto & enemy:game->enemies)
				{
					
					if(enemy->get_id()<2)
					{
						
						
						enemy->move(tube->tube_quads[enemy->get_quad()],2,velocity_coef);

						if(enemy->get_profondeur()<=1 && enemy->get_profondeur()>0 ) {
								enemy->draw_flipper(renderer_game);
							
						}
						else if(enemy->get_profondeur()==0)
						{
							
								utils->time++;
								utils->vivants--;
								
								enemy->move_circle(renderer_game,2);
								
								printf("i : %i\n",enemy->get_i());
							
							/*
									enemy = nullptr;
									delete enemy;
									utils->time++;
									utils->vivants--;*/
	
	
						}
						
						printf("float : %f\n",enemy->get_profondeur());
						
					}
					else 
					{
						if(utils->time ==2)
						{
							enemy->move(tube->tube_quads[enemy->get_quad()],2,velocity_coef);
							if(enemy->get_profondeur() ==0)
							{
								enemy->move_circle(renderer_game,2);
								
										/*enemy = nullptr;
										delete enemy;*/
										utils->time++;
										utils->vivants--;
							}
							else{
								enemy->draw_flipper(renderer_game);	
							}
						}
					}
				}
				game->enemies.erase(std::remove(game->enemies.begin(), game->enemies.end(), nullptr), game->enemies.end());
				/****************************generate bullets****************/
				std::vector<float> vec = utils->mid_two_points(tube->tube_quads[quad][0][0],tube->tube_quads[quad][0][1],tube->tube_quads[quad][1][0],tube->tube_quads[quad][1][1]);
				for( auto &bullet:game->bullets)
				{
					std::vector<float> middle = utils->mid_two_points(tube->tube_quads[bullet->quad][2][0]*2,tube->tube_quads[bullet->quad][2][1]*2,tube->tube_quads[bullet->quad][3][0]*2,tube->tube_quads[bullet->quad][3][1]*2); 
					float prev_dist = bullet->dist;
					float dist = utils->distance(bullet->P.first,bullet->P.second,middle[0],middle[1]);
					bullet->dist = dist;
					bullet->move(tube->tube_quads[bullet->quad],2,velocity_coef);
					//std::cout<<"bullet"<<bullet->profondeur<<std::endl;
					
					if (prev_dist-dist< 0 && prev_dist != -1 )
					{
						if( bullet->get_bullet()==true)
						{
							
							bullet->set_bullet(false);
							delete bullet;
							bullet = nullptr;
						}
						
					}
					else {
						if(bullet->get_bullet()==true)
							bullet->draw_bullet(renderer_game,5);
					}
				}
				game->bullets.erase(std::remove(game->bullets.begin(), game->bullets.end(), nullptr), game->bullets.end());

				/***************explode****************/
				game->explode(utils);

				SDL_RenderPresent(renderer_game);
			}
			SDL_Quit();
		}

	return 0;
}
