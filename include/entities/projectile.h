#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class Projectile : public Entity {
protected:
    int m_damage;
    sf::Vector2f m_direction;

public:
    //Constructor and destructor
    Projectile()=default;
    virtual ~Projectile();


    //Getters
    const int& GetDamage() const;
    
    //Functions
    bool IsOutOfScreen();
    void Update() override;
};

#endif // PROJECTILE_H