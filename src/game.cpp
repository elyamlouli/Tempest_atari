#include "../include/game.hpp"
#include <algorithm>
static int quad = 0;
static int start = 0;

//SDLApp *app;
static void SDL_DelRes(SDL_Window   *r) { SDL_DestroyWindow(r);   }
static void SDL_DelRes(SDL_Renderer *r) { SDL_DestroyRenderer(r); }
static void SDL_DelRes(SDL_Texture  *r) { SDL_DestroyTexture(r);  }
static void SDL_DelRes(SDL_Surface  *r) { SDL_FreeSurface(r);     }
template <typename T>
std::shared_ptr<T> sdl_shared(T *t) {
    return std::shared_ptr<T>(t, [](T *t) { SDL_DelRes(t); });
}

Games::Games()
{
    score = std::shared_ptr<Score>(new Score());
    menu = std::shared_ptr<Menu>(new Menu());
    Forme f = Tube_Circle;
    blaster = std::shared_ptr<Blaster>(new Blaster());
    tube = std::shared_ptr<Tube>(new Tube(f));
    utils = std::shared_ptr<Utils>(new Utils());
    //CollisionSound= new Sound("/home/oumayma/Documents/mp3/shoot.mp3");
}
Games::~Games()
{
    this->lives.erase(std::remove(this->lives.begin(), this->lives.end(), nullptr), this->lives.end());
}
void Games::menu_jeu(SDL_Renderer *renderer, int quad)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
    this->menu->hershey(renderer, "Level 1", 300, 30, 1);
    this->blaster->drawTubeQuads(renderer, 2, -5, 2);
    this->blaster->drawblaster(renderer, this->tube->tube_quads[quad], 2, -5, 2, 10);
    SDL_SetRenderDrawColor(renderer, 54, 244, 11, 0);
    this->menu->hershey(renderer, std::to_string(this->score->get_score()), 100, 30, 1);
}
void Games::draw_lives(SDL_Renderer *renderer)
{
    int i = 10;

    for (auto &live : this->lives)
    {
        live->draw_live(renderer, 2, 10 + i, 50);
        i = i + 50;
    }
}
void Games::generate_enemies(SDL_Renderer *renderer, float velocity_coef)
{
    for (auto &enemy : this->enemies)
    {

        if (enemy->get_id() < 4)
        {

            enemy->move(this->tube->tube_quads[enemy->get_quad()], 2, velocity_coef);
            if (enemy->get_profondeur() == 0)
            {
                if (enemy->get_quad() == quad)
                {
                    this->score->set_score(this->score->get_score() - 150);
                    delete lives[lives.size() - 1];
                    lives.erase(lives.begin() + (lives.size() - 1));
                    score->set_nbLives(score->get_nbLives() - 1);
                }
                enemy = nullptr;
                delete enemy;
                this->utils->set_time(this->utils->get_time() + 1);
                
            }
            else
            {
                enemy->draw_flipper(renderer);
            }
        }

        else if(enemy->get_id() >=4&& enemy->get_id() <=6)
        {
            if (this->utils->get_time() == 4 || this->utils->get_time() == 5||this->utils->get_time() == 6)
            {
                enemy->move(this->tube->tube_quads[enemy->get_quad()], 2, velocity_coef);
                if (enemy->get_profondeur() == 0)
                {
                    if (enemy->get_quad() == quad)
                    {
                        this->score->set_score(this->score->get_score() - 150);
                        delete lives[lives.size() - 1];
                        lives.erase(lives.begin() + (lives.size() - 1));
                        score->set_nbLives(score->get_nbLives() - 1);
                    }
                    enemy = nullptr;
                    delete enemy;
                    this->utils->set_time(this->utils->get_time() + 1);
                    
                }
                else
                {
                    enemy->draw_flipper(renderer);
                }
            }
        }
        else if(enemy->get_id() >=7 && enemy->get_id() <=8){
            if(this->utils->get_time() == 7||this->utils->get_time() == 8)
            {
                enemy->move(this->tube->tube_quads[enemy->get_quad()], 2, velocity_coef);
                if (enemy->get_profondeur() == 0)
                {
                    if (enemy->get_quad() == quad)
                    {
                        this->score->set_score(this->score->get_score() - 150);
                        delete lives[lives.size() - 1];
                        lives.erase(lives.begin() + (lives.size() - 1));
                        score->set_nbLives(score->get_nbLives() - 1);
                    }
                    enemy = nullptr;
                    delete enemy;
                    this->utils->set_time(this->utils->get_time() + 1);
                    
                }
                else
                {
                    enemy->draw_flipper(renderer);
                }
            }

            }
            else{
                if(this->utils->get_time() == 9||this->utils->get_time() == 10)
            {
                enemy->move(this->tube->tube_quads[enemy->get_quad()], 2, velocity_coef);
                if (enemy->get_profondeur() == 0)
                {
                    if (enemy->get_quad() == quad)
                    {
                        this->score->set_score(this->score->get_score() - 150);
                        delete lives[lives.size() - 1];
                        lives.erase(lives.begin() + (lives.size() - 1));
                        score->set_nbLives(score->get_nbLives() - 1);
                    }
                    enemy = nullptr;
                    delete enemy;
                    this->utils->set_time(this->utils->get_time() + 1);
                    
                }
                else
                {
                    enemy->draw_flipper(renderer);
                }

            }

            }

        }
    

    this->enemies.erase(std::remove(this->enemies.begin(), this->enemies.end(), nullptr), this->enemies.end());
}

void Games::generate_bullets(SDL_Renderer *renderer, float velocity_coef)
{
    for (auto &bullet : this->bullets)
    {
        std::vector<float> middle = this->utils->mid_two_points(this->tube->tube_quads[bullet->quad][2].first * 2, this->tube->tube_quads[bullet->quad][2].second * 2, this->tube->tube_quads[bullet->quad][3].first * 2, this->tube->tube_quads[bullet->quad][3].second * 2);
        float prev_dist = bullet->dist;
        float dist = this->utils->distance(bullet->get_P().first, bullet->get_P().second, middle[0], middle[1]);
        bullet->dist = dist;
        bullet->move(this->tube->tube_quads[bullet->quad], 2, velocity_coef);
        if (prev_dist - dist < 0 && prev_dist != -1)
        {
            if (bullet->get_bullet() == true)
            {

                bullet->set_bullet(false);
                delete bullet;
                bullet = nullptr;
            }
        }
        else
        {
            if (bullet->get_bullet() == true)
                bullet->draw_bullet(renderer, 5);
        }
    }
    this->bullets.erase(std::remove(this->bullets.begin(), this->bullets.end(), nullptr), this->bullets.end());
}
void Games::menu_principal(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
    this->menu->hershey(renderer, "Level 1", 350, 70, 1);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    this->menu->hershey(renderer, "Type s to START", 270, 250, 1);
    SDL_SetRenderDrawColor(renderer, 255, 250, 42, 0);
    this->menu->hershey(renderer, "<- -> To move", 265, 300, 1);
    this->menu->hershey(renderer, "Space To shoot", 273, 350, 1);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    this->menu->hershey(renderer, "FLIPPERS AREHARMLESS MID-FLIP", 150, 400, 1);
    this->menu->hershey(renderer, "ENEMY BULLETS ARE DESTRUCTIBLE", 150, 450, 1);
    SDL_RenderPresent(renderer);
}
void Games::explode(std::shared_ptr<Utils> utils)
{

    int enemy_viants_id[15];
    double enemies_profondeur[15];
    for (int i = 0; i < 15; i++)
    {
        enemy_viants_id[i] = -1;
        enemies_profondeur[i] = -1;
    }
    for (int i = 0; i < enemies.size(); i++)
    {
        int id = enemies[i]->get_quad();
        if (enemy_viants_id[id] == -1)
        {
            enemy_viants_id[id] = i;
            enemies_profondeur[id] = enemies[i]->get_profondeur();
        }
        else
        {
            if (enemies_profondeur[id] <= enemies[i]->get_profondeur())
            {
                enemy_viants_id[id] = i;
                enemy_viants_id[id] = enemies[i]->get_profondeur();
            }
        }
    }
    bool bullet_id[15];
    for (int i = 0; i < 15; i++)
    {
        bullet_id[i] = true;
    }
    for (auto &bullet : bullets)
    {
        if (bullet->get_bullet() == true)
        {
            int id = bullet->quad;

            // s'ils se trouvent sur le meme quad
            if ((enemy_viants_id[id] != -1) && bullet_id[id] && (bullet->get_profondeur() + enemies_profondeur[id]) >= 0.85 && (bullet->get_profondeur() + enemies_profondeur[id]) < 1)
            {
                bullet_id[id] = false;
                //if (enemies[enemy_viants_id[id]]->get_alive() == true)
                //{
                    //enemies[enemy_viants_id[id]]->set_alive(false);
                    enemies[enemy_viants_id[id]] = nullptr;
                    delete enemies[enemy_viants_id[id]];
                    this->utils->set_time(this->utils->get_time() + 1);
                    delete bullet;
                    bullet = nullptr;
                //}
                score->set_score(score->get_score() + 150);
            }
        }
    }

    bullets.erase(std::remove(bullets.begin(), bullets.end(), nullptr), bullets.end());
    enemies.erase(std::remove(enemies.begin(), enemies.end(), nullptr), enemies.end());
}

void Games::jouer(float velocity_coef)
{
    bool quit_game = false;
    auto window_game(sdl_shared(SDL_CreateWindow("Test_SDL_GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 800,
                                                                    SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI)));
    auto renderer_game(sdl_shared( SDL_CreateRenderer(window_game.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)));
    this->tube->affect_quads(Tube_Circle);
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 15);
    this->enemies.push_back(new Enemy(distrib(gen), 0));
    this->enemies.push_back(new Enemy(distrib(gen), 1));
    this->enemies.push_back(new Enemy(distrib(gen), 2));
    this->enemies.push_back(new Enemy(distrib(gen), 3));
    this->enemies.push_back(new Enemy(distrib(gen), 4));
    this->enemies.push_back(new Enemy(distrib(gen), 5));
    this->enemies.push_back(new Enemy(distrib(gen), 6));
    this->enemies.push_back(new Enemy(distrib(gen), 7));
    this->enemies.push_back(new Enemy(distrib(gen), 8));
    this->enemies.push_back(new Enemy(distrib(gen), 9));
    this->enemies.push_back(new Enemy(distrib(gen), 10));
    while (!quit_game)
    {
        SDL_Event event_g;
        while (!quit_game && SDL_PollEvent(&event_g))
        {
            switch (event_g.type)
            {
            case SDL_QUIT:
                quit_game = true;
                break;
            case SDL_KEYDOWN:
                switch (event_g.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    
                    //CollisionSound->PlaySound();
                    //CollisionSound->SetupDevice();
                    
                    std::cout << "right" << std::endl;
                    if (quad <= 15)
                    {
                        if (quad == 15)
                        {
                            quad = 0;
                            this->blaster->move_r(renderer_game.get(), quad, this->tube->tube_quads, 2, -5, 2, 10);
                        }
                        else
                        {
                            quad++;

                            this->blaster->move_r(renderer_game.get(), quad, this->tube->tube_quads, 2, -5, 2, 10);
                        }
                    }
                    break;
                case SDLK_LEFT:
                    if (quad <= 15)
                    {
                        if (quad == 0)
                        {
                            quad = 15;
                            this->blaster->move_l(renderer_game.get(), quad, this->tube->tube_quads, 2, -5, 2, 10);
                        }
                        else
                        {
                            quad--;
                            this->blaster->move_l(renderer_game.get(), quad, this->tube->tube_quads, 2, -5, 2, 10);
                        }
                    }
                    break;
                case SDLK_SPACE:
                    this->bullets.push_back(new Bullet(quad));
                    break;
                }
            }
        }
        this->menu_jeu(renderer_game.get(), quad);
        this->generate_enemies(renderer_game.get(), velocity_coef);
        this->draw_lives(renderer_game.get());
        this->generate_bullets(renderer_game.get(), velocity_coef);
        this->explode(this->utils);
        SDL_RenderPresent(renderer_game.get());
        //if(this->score->get_score()<0)
        if(this->score->get_nbLives()<=0 || this->score->get_score()>=500)
        {
            quit_game=true;
        }
        else if(enemies.size()==0)
            quit_game=true;

    }
    SDL_Quit();
}

int Games::genere_menu()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        std::cerr << "Pb init SDL" << std::endl;
        return 0;
    }

    auto window(sdl_shared(SDL_CreateWindow("Test_SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI)));

    auto renderer(sdl_shared(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)));

    this->lives.push_back(new Score(1));
    this->lives.push_back(new Score(2));
    this->lives.push_back(new Score(3));
    this->lives.push_back(new Score(4));
    // Sound* CollisionSound= new Sound("/home/oumayma/Documents/mp3/shoot.mp3");
    assert(renderer.get() != NULL);

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
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_s:
                    std::cout << "you clicked s" << std::endl;

                    start = 1;

                    quit = true;
                    break;
                case SDLK_q:
                    std::cout << "you clicked q" << std::endl;
                    quit = true;
                    break;
                default:
                    break;
                }
            }
        }
        this->menu_principal(renderer.get()); // affiche la page principal
        
    }
       
    
    SDL_Quit();    
    return start;
}
void Games::game_over()
{
    auto window_game(sdl_shared(SDL_CreateWindow("Test_SDL_GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 800,
                                                                    SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI)));
    auto renderer_game(sdl_shared( SDL_CreateRenderer(window_game.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)));
    bool quit_game=false;
    
    while (!quit_game)
    {
        SDL_Event event;
        while (!quit_game && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit_game = true;
                break;
            }
            
        }
        SDL_SetRenderDrawColor(renderer_game.get(), 255, 0, 0, 0);

        if(this->score->get_score()>=500)
        {
            this->menu->hershey(renderer_game.get(), "WON LEVEL 1 !!!", 310, 480, 2);

        }
            
        else if(this->score->get_nbLives()<=0)
            this->menu->hershey(renderer_game.get(), "GAME OVER !", 310, 480, 2);
        else
            this->menu->hershey(renderer_game.get(), "GAME OVER !", 310, 480, 2);

        SDL_RenderPresent(renderer_game.get());
        
        
        
    }    
    SDL_Quit();

    

}