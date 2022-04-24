#include "menu.hpp"
#include "simplex.h"


int Tube_Circle[34][2]= { 
    256, 60, 316, 73, 368, 108, 403, 160, 416, 221, 403, 281, 368, 334, 315, 368, 256, 381, 195, 368, 143, 334, 108, 281, 95, 221, 108, 160, 143, 108, 195, 73, 256, 60,
    256, 255, 264, 257, 273, 262, 277, 270, 280, 279, 277, 289, 273, 296, 264, 301, 256, 303, 247, 301, 238, 296, 234, 289, 231, 279, 234, 270, 238, 262, 247, 257, 256, 255,  
};


Menu::Menu(SDL_Renderer * renderer):renderer(renderer)
{    
}
Menu::~Menu()
{    
}
void Menu::hershey(SDL_Renderer * renderer, std::string str, int start_x, int start_y, int coeff) {
    for (int i = 0 ; i < str.size() ; i++) {
        int code_ascii = int(str[i]);
        int nb_points = simplex[code_ascii-32][0];
        int x_space = simplex[code_ascii-32][1];

        int old_x = start_x + simplex[code_ascii-32][2] * coeff;
        int old_y = start_y - simplex[code_ascii-32][3] * coeff;
        int new_x = 0;
        int new_y = 0;
        for (int j = 4 ; j <= (2*nb_points) ; j+=2) {
            new_x = simplex[code_ascii-32][j];
            new_y = simplex[code_ascii-32][j+1];

            if (new_x == -1 && new_y == -1) {
                j += 2;
                old_x = start_x + simplex[code_ascii-32][j] * coeff;
                old_y = start_y - simplex[code_ascii-32][j+1] * coeff;
            }
            else {
				new_x = start_x + new_x * coeff;
				new_y = start_y - new_y * coeff;
                SDL_RenderDrawLine(renderer, old_x, old_y, new_x, new_y);

                old_x = new_x;
                old_y = new_y;
            }
        }
		start_x += x_space * coeff;
    }
}
void Menu::start(SDL_Renderer * renderer,int x,int y,int w,int h)
{
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y =y ;
    rectangle.w =w ;
    rectangle.h = h;
    SDL_RenderDrawRect(renderer,&rectangle);
    this->hershey(renderer,"START",x+15, y+60,2);
}
void Menu::quit(SDL_Renderer * renderer,int x,int y,int w,int h)
{
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y =y ;
    rectangle.w =w ;
    rectangle.h = h;
    SDL_RenderDrawRect(renderer,&rectangle);
    this->hershey(renderer,"QUIT",x+30, y+60,2);

}
void Menu::circle(SDL_Renderer * renderer, int rayon,int centreX,int centreY)
{
    const int32_t diameter = (rayon * 2);

   int32_t x = (rayon - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}
void Menu::couloirs(SDL_Renderer * renderer,int x,int y,int rayon1,int rayon2,int nb_couloirs)
{
    
    SDL_RenderDrawLine(renderer,x+rayon1,y,x+rayon2,y);
    SDL_RenderDrawLine(renderer,x-rayon1,y,x-rayon2,y);
    SDL_RenderDrawLine(renderer,x,y+rayon1,x,y+rayon2);
    SDL_RenderDrawLine(renderer,x,y-rayon1,x,y-rayon2);
    SDL_RenderDrawLine(renderer,x+rayon1*std::cos(pi/4),y+rayon1* std::sin(pi/4),x+rayon2*std::cos(pi/4),y+rayon2* std::sin(pi/4));
    SDL_RenderDrawLine(renderer,x+rayon1*std::cos(-pi/4),y+rayon1*std::sin(-pi/4),x+rayon2*std::cos(-pi/4),y+rayon2*std::sin(-pi/4));
    SDL_RenderDrawLine(renderer,x-rayon1*std::cos(-pi/4),y+rayon1* std::sin(-pi/4),x-rayon2*std::cos(-pi/4),y+rayon2* std::sin(-pi/4));
    SDL_RenderDrawLine(renderer,x-rayon1*std::cos(-pi/4),y-rayon1*std::sin(-pi/4),x-rayon2*std::cos(-pi/4),y-rayon2*std::sin(-pi/4));
    

}
void Menu::draw_tubes(SDL_Renderer * renderer, int start_x, int start_y, int coeff)
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

int Menu::first_interface( SDL_Renderer *renderer)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr<<"Pb init SDL"<< std::endl;
		return 0;
	}
	bool quit = false;
    this->renderer = renderer;
	assert (renderer != NULL);

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
						
						quit=true;
                        return 1;
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
		
		
		this->hershey(renderer, "Level 1", 350, 70, 1);
		SDL_SetRenderDrawColor(renderer, 255,0,0,0);
		this->hershey(renderer, "Type s to START", 270, 250, 1);
		SDL_SetRenderDrawColor(renderer, 255,250,42,0);
		this->hershey(renderer, "<- -> To move", 265, 300, 1);
		this->hershey(renderer, "Space To shoot", 273, 350, 1);
		SDL_SetRenderDrawColor(renderer, 255,0,0,0);
		this->hershey(renderer, "FLIPPERS AREHARMLESS MID-FLIP", 150, 400, 1);
		this->hershey(renderer, "ENEMY BULLETS ARE DESTRUCTIBLE", 150, 450, 1);


		SDL_RenderPresent(renderer);
		
	}
    SDL_Quit();
}

