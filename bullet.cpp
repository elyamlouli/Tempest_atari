#include "bullet.hpp"

Bullet::Bullet()
{

}
Bullet::~Bullet()
{

}

void Bullet::draw_bullet(SDL_Renderer * renderer,float x0,float y0,int x_,int y_,int coef, int radius)
{
    SDL_SetRenderDrawColor(renderer, 255,250,42,0);
    float x = static_cast<float> (radius);
	float y = 0;
	float radiusError = 1 - x;
	while (x >= y) {
		SDL_RenderDrawLine(renderer, x_+(x + x0)*coef, y_+(y + y0)*coef,x_+( -x + x0)*coef,y_+( y + y0)*coef);
		SDL_RenderDrawLine(renderer, x_+(y + x0)*coef, y_+(x + y0)*coef, x_+(-y + x0)*coef, y_+(x + y0)*coef);
		SDL_RenderDrawLine(renderer, x_+(-x + x0)*coef,y_+( -y + y0)*coef,x_+( x + x0)*coef,y_+( -y + y0)*coef);
		SDL_RenderDrawLine(renderer, x_+(-y + x0)*coef,y_+( -x + y0)*coef,x_+( y + x0)*coef,y_+( -x + y0)*coef);
		y++;
		if (radiusError < 0)
			radiusError += 2 * y + 1;
		else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
    std::cout<<"hi"<<std::endl;
}
