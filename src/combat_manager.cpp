#include "../include/combat_manager.h"

/*
--------------
    Functions
--------------
*/

void CombatManager::HandleEnemyPlayerCollision(
    Player *player,
    std::vector<Enemy*>& enemies)
{

    unsigned counter=0; 
    for(auto *enemy: enemies)
    {

        //Enemy-Player collision 
        if(enemy->GetBounds().intersects(player->GetBounds()))
        {
            //Player takes damage
            player->LoseHp(enemies.at(counter)->GetDamage());

            //Delete enemy
            delete enemies.at(counter);
            enemies.erase(enemies.begin()+counter); 
        }
        ++counter;
    }

}


void CombatManager::HandleBulletEnemyCollisions(
    std::vector<Bullet*>& bullets,
    std::vector<Enemy*>& enemies,
    WorldManager *world)
{

    for(int i=0; i<enemies.size(); ++i)
    { 
        bool enemy_deleted=false;

        for(size_t k=0; k < bullets.size() && enemy_deleted==false; ++k)
        {
            if(enemies[i]->GetBounds().intersects(bullets[k]->GetBounds()))
            {
                //Enemy takes damage
                enemies[i]->LoseHp(bullets[k]->GetDamage());

                if(enemies[i]->GetHp()==0)
                {
                    //Increase points
                    world->AddPoints(enemies[i]->GetPoints());

                    //Increment asteroid counter if it's an Asteroid
                    if (Asteroid* asteroid = dynamic_cast<Asteroid*>(enemies[i])) 
                    {
                        Asteroid::IncrementAsteroidsDestroyed();
                    }

                    //Delete Enemy
                    delete enemies[i];
                    enemies.erase(enemies.begin() + i);

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
    std::vector<Enemy*>& enemies,
    std::vector<Bullet*>& bullets,
     WorldManager *world)
{
    HandleEnemyPlayerCollision(player, enemies);
    HandleBulletEnemyCollisions(bullets,enemies,world);
}