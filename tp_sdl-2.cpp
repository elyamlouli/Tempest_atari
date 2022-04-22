#include <SDL.h>
#include <assert.h>

#include <iostream>
#include "menu.hpp"
#include "game.hpp"
#include "blaster.hpp"
#include "bullet.hpp"
#include <algorithm>
#include "tube.hpp"
#include "enemy.hpp"
#include <ctime>
#define RAND_MAXIMUM 17


Uint8 color[4] = {255,255,0,255};
int last_x;
int last_y;
static int start = 0;
int tubeQuad_[4][2]={{256, 60}, {316, 73}, {264, 257},{256, 255}};
static int quad=0;


int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr<<"Pb init SDL"<< std::endl;
		return 0;
	}

	SDL_Window* window = SDL_CreateWindow("Test_SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
						  SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
	
    
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    Menu *menu = new Menu(renderer);
	//Games * game = new Games();
	//Text text(renderer,"/usr/share/fonts/X11/Type1/c0632bt_.pfb",30,"Rendering text",{255,0,0,255});
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
        /*menu->start(renderer,75,500,210,81);
        menu->quit(renderer,500,500,210,81);
        /*menu->circle(renderer,150,400,200);
        menu->circle(renderer,50,400,200);
        menu->couloirs(renderer,400,200,50,150,4);
		menu->draw_tubes(renderer,150,0,1);*/

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
			std::vector<Bullet *> bullets;
			std::vector<Enemy *> enemies;
			std::srand(std::time(nullptr));
			int variable_ran = std::rand()%RAND_MAXIMUM;
			enemies.push_back(new Enemy(variable_ran ));
			variable_ran = std::rand()%RAND_MAXIMUM;
			enemies.push_back(new Enemy(variable_ran ));
			
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
									bullets.push_back(new Bullet(quad));
									/*
									std::cout << "enter"<<std::endl;
									std::vector<float> vec = utils->mid_two_points(tube->tube_quads[quad][0][0],tube->tube_quads[quad][0][1],tube->tube_quads[quad][1][0],tube->tube_quads[quad][1][1]);
									std::cout<<"xPos : "<<vec[0]<<"yPos : "<<vec[1]<<std::endl;

									bullet->draw_bullet(renderer_game,vec[0],vec[1],2,-5,1,1);*/
									
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
				
				float velocity_coef=0.0003;
				
				for(auto & enemy:enemies)
				{
					
					if(enemy->get_time() <= 10)
					{
						
						enemy->move(tube->tube_quads[enemy->get_quad()],2,velocity_coef);
						if(enemy->get_profondeur() <=0)
						{
							
							delete enemy;
							enemy = nullptr;
						}
						else{
							enemy->draw_flipper(renderer_game);
							
						}
					}
					
					
					

				}
				enemies.erase(std::remove(enemies.begin(), enemies.end(), nullptr), enemies.end());
				
	
					std::vector<float> vec = utils->mid_two_points(tube->tube_quads[quad][0][0],tube->tube_quads[quad][0][1],tube->tube_quads[quad][1][0],tube->tube_quads[quad][1][1]);
					//std::cout<<"xPos : "<<vec[0]<<"yPos : "<<vec[1]<<std::endl;
				for( auto &bullet:bullets)
				{
					std::vector<float> middle = utils->mid_two_points(tube->tube_quads[bullet->quad][2][0]*2,tube->tube_quads[bullet->quad][2][1]*2,tube->tube_quads[bullet->quad][3][0]*2,tube->tube_quads[bullet->quad][3][1]*2); 
					float prev_dist = bullet->dist;
					float dist = utils->distance(bullet->P.first,bullet->P.second,middle[0],middle[1]);
					bullet->dist = dist;
					bullet->move(tube->tube_quads[bullet->quad],2,velocity_coef);
					std::cout<<prev_dist-dist<<std::endl;
					if (prev_dist-dist< 0 && prev_dist != -1)
					{
						delete bullet;
						bullet = nullptr;
					}
					else {
						bullet->draw_bullet(renderer_game,5);
					}
				}
				bullets.erase(std::remove(bullets.begin(), bullets.end(), nullptr), bullets.end());
				
				
				SDL_RenderPresent(renderer_game);
			}
			SDL_Quit();

		}
	
		
	return 0;
}
