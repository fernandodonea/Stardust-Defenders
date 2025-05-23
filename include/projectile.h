#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class Projectile : public Entity {
protected:
    int m_damage;
    sf::Vector2f m_direction;

public:
    // Getters
    const int& GetDamage() const;
    
    // Core functionality
    void Update() override;
};

#endif // PROJECTILE_H