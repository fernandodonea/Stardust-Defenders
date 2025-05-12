#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class Projectile : public Entity {
protected:
    int damage;
    sf::Vector2f direction;

public:
    Projectile();
    virtual ~Projectile();

    // Getters
    const int& GetDamage() const;
    
    // Core functionality
    void Update() override;
};

#endif // PROJECTILE_H