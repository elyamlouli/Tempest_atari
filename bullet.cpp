#include "bullet.hpp"

Bullet::Bullet(int quad)
{
	this->utils = new Utils();
	this->profondeur =1;
	this->quad = quad;
	this->dist = -1;
	vivant_bullet=true;

}
Bullet::~Bullet()
{

}
void Bullet::set_bullet(bool b)
{
	this->vivant_bullet=b;
}
bool Bullet::get_bullet()
{
	return this->vivant_bullet;
}


void Bullet::draw_bullet(SDL_Renderer * renderer, int radius)
{

    SDL_SetRenderDrawColor(renderer, 255,250,42,0);
    float x = static_cast<float> (radius);
	float y = 0;
	float radiusError = 1 - x;
	while (x >= y) {
		SDL_RenderDrawLine(renderer, (x + this->P.first), (y + this->P.second),( -x + this->P.first),( y + this->P.second));
		SDL_RenderDrawLine(renderer, (y + this->P.first), (x + this->P.second), (-y + this->P.first), (x + this->P.second));
		SDL_RenderDrawLine(renderer, (-x + this->P.first),( -y + this->P.second),( x + this->P.first),( -y + this->P.second));
		SDL_RenderDrawLine(renderer, (-y + this->P.first),( -x + this->P.second),( y + this->P.first),( -x + this->P.second));
		y++;
		if (radiusError < 0)
			radiusError += 2 * y + 1;
		else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}

		/*
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
    std::cout<<"hi"<<std::endl;*/
}
void Bullet::move(int tubeQuad[4][2],int scale,float velocity_coef)
{
	this->P = this->utils->find_position(tubeQuad,0,0,scale,this->profondeur,true);

	profondeur -= velocity_coef;


}
