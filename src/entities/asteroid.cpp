#include "../include/entities/asteroid.h"

struct enemy_data
{
    float movement_speed;
    int hp,hp_max;
    int damage, points;
    float size;
};
std::map<int, enemy_data> enemy_types
{
    {1, {
        Const_Asteroid_Normal::movement_speed,
        Const_Asteroid_Normal::hp, Const_Asteroid_Normal::hp_max,
        Const_Asteroid_Normal::damage,
        Const_Asteroid_Normal::points,
        Const_Asteroid_Normal::size}}, 
    {2, {
        Const_Asteroid_Fast::movement_speed,
        Const_Asteroid_Fast::hp, Const_Asteroid_Fast::hp_max,
        Const_Asteroid_Fast::damage,
        Const_Asteroid_Fast::points,
        Const_Asteroid_Fast::size}}, 
    {3, {
        Const_Asteroid_Tank::movement_speed,
        Const_Asteroid_Tank::hp, Const_Asteroid_Tank::hp_max,
        Const_Asteroid_Tank::damage,
        Const_Asteroid_Tank::points,
        Const_Asteroid_Tank::size}}
};

//initialise static variable
int Asteroid::m_asteroids_destroyed=0;

/*
----------------------
    Private function
----------------------
*/
void Asteroid::_InitVariables()
{

    this->m_movement_speed=enemy_types[this->m_type].movement_speed;

    this->m_hp_max=enemy_types[this->m_type].hp_max;
    this->m_hp=enemy_types[this->m_type].hp;

    this->m_damage=enemy_types[this->m_type].damage;
    this->m_points=enemy_types[this->m_type].points;

    this->m_size=enemy_types[this->m_type].size;

}


/*
--------------------------------
    Constructors and Destructor
--------------------------------
*/
Asteroid::Asteroid()
{

}
Asteroid::Asteroid(int type,sf::Texture* texture,float pos_x, float pos_y)
{
    this->m_type=type;
    this->_InitVariables(); 
    _InitSprite(texture,pos_x,pos_y,this->m_size);
    

} 
Asteroid::~Asteroid()
{
    
}


/*
------------
    Getter
------------
*/
int Asteroid::GetAsteroidsDestroyed()
{
    return m_asteroids_destroyed;
}

/*
------------
    Setter
------------
*/
void Asteroid::IncrementAsteroidsDestroyed()
{
    m_asteroids_destroyed++;
}



/*
------------
    Setter
-----------
*/
void Asteroid::Update()
{
   Move(down);
}
