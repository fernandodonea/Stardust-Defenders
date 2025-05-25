#include "../include/entities/alien.h"


/*
----------------------
    Private function
----------------------
*/
void Alien::_InitVariables()
{
    this->m_movement_speed=Const_Alien::movement_speed;

    this->m_hp_max=Const_Alien::hp_max;
    this->m_hp=Const_Alien::hp;

    this->m_damage=Const_Alien::damage;
    this->m_points=Const_Alien::points;

    this->m_size=Const_Alien::size;
}



/*
-----------------
    Constructor 
-----------------
*/
Alien::Alien(sf::Texture* texture,float pos_x, float pos_y)
{
    _InitVariables();
    _InitSprite(texture,pos_x,pos_y,this->m_size);
    
}



/*
---------------
    Functions
---------------
*/
void Alien::DecideNextMove() 
{

    //Pick a new position different from the current one
    AlienPos newPos = m_currentPos;
    while (newPos == m_currentPos) {
        int r = rand() % 3;
        if (r == 0) newPos = AlienPos::Left;
        else if (r == 1) newPos = AlienPos::Center;
        else newPos = AlienPos::Right;
    }

    //Set the target position based on the new position
    switch (newPos) {
        case AlienPos::Left:
            m_target_x = ALIEN_LEFT_X;
            break;
        case AlienPos::Center:
            m_target_x = ALIEN_CENTER_X;
            break;
        case AlienPos::Right:
            m_target_x = ALIEN_RIGHT_X;
            break;
    }
    m_state = MoveState::Moving;
    m_currentPos = newPos;
}



void Alien::MoveToTarget() 
{
    //Calculate the difference between target and current position
    float dx = m_target_x - GetPosition().x;
    
    if (std::abs(dx) < m_movement_speed) 
    {
        SetPosition(m_target_x, GetPosition().y);
        m_state = MoveState::Idle;
        m_idle_frames = 0; // Reset idle frame counter
    } 
    else 
    {
        if(dx>0)
            Move(right);
        else 
            Move(left);
    }
}

void Alien::Update()
{
    switch (m_state) {
        case MoveState::Idle:
            m_idle_frames++;
            if (m_idle_frames >= m_idleframes_max) 
            {
                m_idle_frames = 0;
                DecideNextMove();
            }
            break;
        case MoveState::Moving:
            MoveToTarget();
            break;
    }
}