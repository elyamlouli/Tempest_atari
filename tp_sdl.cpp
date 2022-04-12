#include <SDL.h>
#include <assert.h>

#include <iostream>
#include "menu.hpp"
#include "game.hpp"


Uint8 color[4] = {255,255,0,255};
int last_x;
int last_y;
static int start = 0;

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
		SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
		menu->hershey(renderer, "TEMPEST", 200, 450, 3);
        menu->start(renderer,75,500,210,81);
        menu->quit(renderer,500,500,210,81);
        menu->circle(renderer,150,400,200);
        menu->circle(renderer,50,400,200);
        menu->couloirs(renderer,400,200,50,150,4);

		SDL_RenderPresent(renderer);
		
	}
	SDL_Quit();
	if(start ==1)
		{
			SDL_Window* window_game = SDL_CreateWindow("Test_SDL_GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
						  SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
			SDL_Renderer* renderer_game = SDL_CreateRenderer(window_game, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
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

					}
				}
				//
			}

		}
	

	return 0;
}
