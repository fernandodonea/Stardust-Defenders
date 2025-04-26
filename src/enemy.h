#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
    private:
        sf::CircleShape shape;

        int type;
        float speed;

        int hp;
        int hp_max;

        int damage;
        unsigned points;

        //Private functions
        void _InitShape();
        void _InitVariables();

    public:
        //Constructor and Destructor
        Enemy();
        Enemy(float pos_x, float pos_y);
        virtual ~Enemy();

        //Accesors
        const sf::FloatRect GetBounds() const;

        //Functions
        void Update();
        void Render(sf::RenderTarget* target);
     
};






#endif // ENEMY_H