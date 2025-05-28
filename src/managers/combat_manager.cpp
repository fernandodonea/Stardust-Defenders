#include "../include/managers/combat_manager.h"

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


void CombatManager::HandleLaserPlayerCollision(
    Player *player,
    std::vector<Projectile*>& lasers
)
{
    unsigned counter=0; 
    for(auto *laser: lasers)
    {

        //Enemy-Player collision 
        if(laser->GetBounds().intersects(player->GetBounds()))
        {
            //Player takes damage
            player->LoseHp(lasers.at(counter)->GetDamage());

            //Delete enemy
            delete lasers.at(counter);
            lasers.erase(lasers.begin()+counter); 
        }
        ++counter;
    }

}


//Handles the collision between bullets and enemies
void CombatManager::HandleBulletEnemyCollisions(
    std::vector<Projectile*>& projectiles,
    std::vector<Enemy*>& enemies,
    WorldManager *world)
{

    for(int i=0; i<enemies.size(); ++i)
    { 
        bool enemy_deleted=false;

        for(size_t k=0; k < projectiles.size() && enemy_deleted==false; ++k)
        {
            //Enemy-Bullet collision
            if(enemies[i]->GetBounds().intersects(projectiles[k]->GetBounds()))
            {
                //Enemy takes damage
                enemies[i]->LoseHp(projectiles[k]->GetDamage());

                if(enemies[i]->GetHp()<=0)
                {
                    //Increase points
                    world->AddPoints(enemies[i]->GetPoints());

                    //Increment asteroid counter if its an Asteroid
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
                delete projectiles[k];
                projectiles.erase(projectiles.begin() + k); 
                
            }
        }
    }

}



void CombatManager::Update(
    Player *player,
    std::vector<Enemy*>& enemies,
    std::vector<Projectile*>& projectiles,
    std::vector<Projectile*>& lasers,
     WorldManager *world)
{
    HandleEnemyPlayerCollision(player, enemies);
    HandleLaserPlayerCollision(player,lasers);
    HandleBulletEnemyCollisions(projectiles,enemies,world);
}