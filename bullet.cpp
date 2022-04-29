#include "bullet.hpp"

Bullet::Bullet(int quad)
{
	utils = std::shared_ptr<Utils>(new Utils());
	this->profondeur = 1;
	this->quad = quad;
	this->dist = -1;
	vivant_bullet = true;
}
Bullet::~Bullet()
{
}
void Bullet::set_bullet(bool b)
{
	this->vivant_bullet = b;
}
bool Bullet::get_bullet()
{
	return this->vivant_bullet;
}

void Bullet::draw_bullet(SDL_Renderer *renderer, int radius)
{

	SDL_SetRenderDrawColor(renderer, 255, 250, 42, 0);
	float x = static_cast<float>(radius);
	float y = 0;
	float radiusError = 1 - x;
	while (x >= y)
	{
		SDL_RenderDrawLine(renderer, (x + this->P.first), (y + this->P.second), (-x + this->P.first), (y + this->P.second));
		SDL_RenderDrawLine(renderer, (y + this->P.first), (x + this->P.second), (-y + this->P.first), (x + this->P.second));
		SDL_RenderDrawLine(renderer, (-x + this->P.first), (-y + this->P.second), (x + this->P.first), (-y + this->P.second));
		SDL_RenderDrawLine(renderer, (-y + this->P.first), (-x + this->P.second), (y + this->P.first), (-x + this->P.second));
		y++;
		if (radiusError < 0)
			radiusError += 2 * y + 1;
		else
		{
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}
void Bullet::move(std::array<std::pair<int,int>,4> tubeQuad, int scale, float velocity_coef)
{
	this->P = this->utils->find_position(tubeQuad, 0, 0, scale, this->profondeur);

	profondeur -= velocity_coef;
}

void Bullet::set_P(std::pair<double, double> p)
{
	this->P = p;
}

std::pair<double, double> Bullet::get_P()
{
	return this->P;
}

float Bullet::get_profondeur()
{
	return this->profondeur;
}

void Bullet::set_profondeur(float p)
{
	this->profondeur = p;
}
