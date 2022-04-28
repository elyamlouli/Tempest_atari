#include "./game.hpp"

Games::Games()
{
    score = new Score();
}
Games::~Games()
{
}
void Games::explode(Utils *utils)
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
            if ((enemy_viants_id[id] != -1) && bullet_id[id] && (bullet->profondeur + enemies_profondeur[id]) >= 0.85 && (bullet->profondeur + enemies_profondeur[id]) < 1)
            {
                bullet_id[id] = false;
                // std::cout << "lol\n";
                if (enemies[enemy_viants_id[id]]->get_alive() == true)
                {
                    enemies[enemy_viants_id[id]]->set_alive(false);
                    enemies[enemy_viants_id[id]] = nullptr;
                    delete enemies[enemy_viants_id[id]];
                    utils->vivants--;
                    utils->time++;
                    delete bullet;
                    bullet = nullptr;
                }
                score->set_score(score->get_score() + 150);
            }
        }
    }

    bullets.erase(std::remove(bullets.begin(), bullets.end(), nullptr), bullets.end());
    enemies.erase(std::remove(enemies.begin(), enemies.end(), nullptr), enemies.end());
}
