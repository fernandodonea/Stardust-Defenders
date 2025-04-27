#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
    private:
        sf::CircleShape shape;
        unsigned point_count;
        int type;
        float speed;

        int hp;
        int hp_max;

        int damage;
        unsigned points;

        //Private functions
        void _InitVariables();
        void _InitShape();

    public:
        //Constructor and Destructor
        Enemy();
        Enemy(float pos_x, float pos_y);
        virtual ~Enemy();

        //Accesors
        const sf::FloatRect GetBounds() const;
        const unsigned GetPoints() const;

        //Functions
        void Update();
        void Render(sf::RenderTarget* target);
     
};






#endif // ENEMY_H