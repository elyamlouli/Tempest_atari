#include <SDL.h>
#include <assert.h>
#include <iostream>

int Tube_Circle[34][2]= { 
    256, 60, 316, 73, 368, 108, 403, 160, 416, 221, 403, 281, 368, 334, 315, 368, 256, 381, 195, 368, 143, 334, 108, 281, 95, 221, 108, 160, 143, 108, 195, 73, 256, 60,
    256, 255, 264, 257, 273, 262, 277, 270, 280, 279, 277, 289, 273, 296, 264, 301, 256, 303, 247, 301, 238, 296, 234, 289, 231, 279, 234, 270, 238, 262, 247, 257, 256, 255,  
};

void drawTubes(SDL_Renderer * renderer, int start_x, int start_y, int coeff)
{
    int old_x = start_x + Tube_Circle[0][0]*coeff;  
    int old_y = start_y + Tube_Circle[0][1]*coeff;
    int old_u = start_x + Tube_Circle[17][0]*coeff;  
    int old_v = start_y + Tube_Circle[17][1]*coeff;
    int new_x = start_x + Tube_Circle[1][0]*coeff; 
    int new_y = start_y + Tube_Circle[1][1]*coeff;
    int new_u = start_x + Tube_Circle[18][0]*coeff;  
    int new_v = start_y + Tube_Circle[18][1]*coeff;
    SDL_RenderDrawLine(renderer, old_x, old_y, new_x, new_y);
    SDL_RenderDrawLine(renderer, old_x, old_y, old_u, old_v);
    SDL_RenderDrawLine(renderer, old_u, old_v, new_u, new_v);
    SDL_RenderDrawLine(renderer, new_x, new_y, new_u, new_v);
    for (int i = 2; i <= 16; i++)
    {
        old_x = new_x;
        old_y = new_y;
        old_u = new_u;
        old_v = new_v;
        new_x = start_x + Tube_Circle[i][0]*coeff;
        new_y = start_y + Tube_Circle[i][1]*coeff;
        new_u = start_x + Tube_Circle[i+17][0]*coeff;
        new_v = start_y + Tube_Circle[i+17][1]*coeff;
        SDL_RenderDrawLine(renderer, old_x, old_y, new_x, new_y);
        SDL_RenderDrawLine(renderer, old_x, old_y, old_u, old_v);
        SDL_RenderDrawLine(renderer, old_u, old_v, new_u, new_v);
        SDL_RenderDrawLine(renderer, new_x, new_y, new_u, new_v);
    }
}
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
	//Text text(renderer,"/usr/share/fonts/X11/Type1/c0632bt_.pfb",30,"Rendering text",{255,0,0,255});
	assert (renderer != NULL);

	bool quit = false;
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
			}
		}
		SDL_SetRenderDrawColor(renderer, 0,0,0,255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        drawTubes(renderer, 50,20,3);
		//draw(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_Quit();

	return 0;
}
