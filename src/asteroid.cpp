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
    //spawn rate
    int x=rand()%100+1;
    if(x>=1 && x<=60)
        this->type=1;
    else if(x>60 && x<=90)
        this->type=2;
    else if(x>90 && x<=100)
        this->type=3;

    this->movement_speed=enemy_types[this->type].movement_speed;

    this->hp_max=enemy_types[this->type].hp_max;
    this->hp=enemy_types[this->type].hp;

    this->damage=enemy_types[this->type].damage;
    this->points=enemy_types[this->type].points;

    this->size=enemy_types[this->type].size;

}
void Asteroid::_InitTexture()
{
    //Load texture from file
    std::string file_name="resources/textures/asteroid_";
    file_name+=std::to_string(this->type)+".png";

    if(!this->texture.loadFromFile(file_name))
    {
        std::cout<<"ERROR:ASTEROID::_INITTEXTURE: Could not load texture file"<<"\n";
    }
}
void Asteroid::_InitSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(this->size,this->size); 
}


//Constructor and Destructor
Asteroid::Asteroid()
{

}
Asteroid::Asteroid(float pos_x, float pos_y)
{
    this->_InitVariables(); 
    this->_InitTexture();
    this->_InitSprite();
    
    this->sprite.setPosition(pos_x,pos_y);

} 
Asteroid::~Asteroid()
{
    
}

//Functions
void Asteroid::Update()
{
   Move(down);
}
