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
-------------------------------
    Constructor and destructor
-------------------------------
*/
Alien::Alien()
{

}
Alien::Alien(sf::Texture* texture,float pos_x, float pos_y)
{
    _InitVariables();
    _InitSprite(texture,pos_x,pos_y,this->m_size);
    
}
Alien::~Alien()
{

}


/*
---------------
    Functions
---------------
*/
void Alien::DecideNextMove() {

    //Pick a new position different from the current one
    AlienPos newPos = m_currentPos;
    while (newPos == m_currentPos) {
        int r = rand() % 3;
        if (r == 0) newPos = AlienPos::Left;
        else if (r == 1) newPos = AlienPos::Center;
        else newPos = AlienPos::Right;
    }

    switch (newPos) {
        case AlienPos::Left:
            m_targetX = ALIEN_LEFT_X;
            break;
        case AlienPos::Center:
            m_targetX = ALIEN_CENTER_X;
            break;
        case AlienPos::Right:
            m_targetX = ALIEN_RIGHT_X;
            break;
    }
    m_state = MoveState::Moving;
    m_currentPos = newPos;
}


void Alien::MoveToTarget() {
    //Calculate the difference between target and current position
    float dx = m_targetX - GetPosition().x;
    
    if (std::abs(dx) < m_movement_speed) {
        SetPosition(m_targetX, GetPosition().y);
        m_state = MoveState::Idle;
        m_idleFrames = 0; // Reset idle frame counter
    } else {
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
            m_idleFrames++;
            if (m_idleFrames >= m_idleFramesMax) {
                m_idleFrames = 0;
                DecideNextMove();
            }
            break;
        case MoveState::Moving:
            MoveToTarget();
            break;
    }
}