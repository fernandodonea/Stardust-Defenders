#include "../include/asteroid.h"

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
        Asteroid_Normal::movement_speed,
        Asteroid_Normal::hp, Asteroid_Normal::hp_max,
        Asteroid_Normal::damage,
        Asteroid_Normal::points,
        Asteroid_Normal::size}}, 
    {2, {
        Asteroid_Fast::movement_speed,
        Asteroid_Fast::hp, Asteroid_Fast::hp_max,
        Asteroid_Fast::damage,
        Asteroid_Fast::points,
        Asteroid_Fast::size}}, 
    {3, {
        Asteroid_Tank::movement_speed,
        Asteroid_Tank::hp, Asteroid_Tank::hp_max,
        Asteroid_Tank::damage,
        Asteroid_Tank::points,
        Asteroid_Tank::size}}
};

//Private functions
void Asteroid::_InitVariables()
{

    this->m_movement_speed=enemy_types[this->m_type].movement_speed;

    this->m_hp_max=enemy_types[this->m_type].hp_max;
    this->m_hp=enemy_types[this->m_type].hp;

    this->m_damage=enemy_types[this->m_type].damage;
    this->m_points=enemy_types[this->m_type].points;

    this->m_size=enemy_types[this->m_type].size;

}



//Constructor and Destructor
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

//Functions
void Asteroid::Update()
{
   Move(down);
}
