#include "../include/combat_manager.h"

/*
--------------
    Functions
--------------
*/

void CombatManager::HandleEnemyPlayerCollision(
    Player *player,
    std::vector<Asteroid*>& asteroids)
{

    unsigned counter=0; 
    for(auto *enemy: asteroids)
    {

        //Enemy-Player collision 
        if(enemy->GetBounds().intersects(player->GetBounds()))
        {
            //Player takes damage
            player->LoseHp(asteroids.at(counter)->GetDamage());

            //Delete enemy
            delete asteroids.at(counter);
            asteroids.erase(asteroids.begin()+counter); 
        }
        ++counter;
    }

}


void CombatManager::HandleBulletEnemyCollisions(
    std::vector<Bullet*>& bullets,
    std::vector<Asteroid*>& asteroids,
    WorldManager *world)
{

    for(int i=0; i<asteroids.size(); ++i)
    { 
        bool enemy_deleted=false;

        for(size_t k=0; k < bullets.size() && enemy_deleted==false; ++k)
        {
            if(asteroids[i]->GetBounds().intersects(bullets[k]->GetBounds()))
            {
                //Enemy takes damage
                asteroids[i]->LoseHp(bullets[k]->GetDamage());

                if(asteroids[i]->GetHp()==0)
                {
                    //Increase points
                    world->AddPoints(asteroids[i]->GetPoints());

                    //Delete Enemy
                    delete asteroids[i];
                    asteroids.erase(asteroids.begin() + i);

                    enemy_deleted=true;
                }


                //Delete Bullet
                delete bullets[k];
                bullets.erase(bullets.begin() + k); 
                
            }
        }
    }

}



void CombatManager::Update(
    Player *player,
    std::vector<Asteroid*>& asteroids,
    std::vector<Bullet*>& bullets,
     WorldManager *world)
{
    HandleEnemyPlayerCollision(player, asteroids);
    HandleBulletEnemyCollisions(bullets,asteroids,world);
}