#include "../include/game.h"

namespace Game_Engine
{



//Private Functions
void Game::_InitWindow()
{
    this->window=new sf::RenderWindow(sf::VideoMode(1024,728),"Stardust Defenders",
    sf::Style::Close | sf::Style::Titlebar);

    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::_InitTextures()
{
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("resources/textures/cyan-bullet.png");
} 
 
void Game::_InitGUI()
{
    //Load font
    if(!this->font.loadFromFile("resources/fonts/Dosis.ttf"))
        std::cout<<"ERROR::GAME::_INITGUI:: Failed to load font"<<"\n";

    //Init point text
    this->point_text.setFont(this->font);
    this->point_text.setCharacterSize(36);
    this->point_text.setFillColor(sf::Color::White);
    this->point_text.setString("");
}

void Game::_InitWorld()
{
    //Load background
    if(!this->world_background_texture.loadFromFile("resources/textures/starry_background.png"))
        std::cout<<"ERROR::GAME::_INITWORLD: Failed to load background"<<"\n";

    this->world_background.setTexture(this->world_background_texture);
}

void Game::_InitSystems()
{
    this->points=0;
}

void Game::_InitPlayer()
{
    this->player = new Player();
}

void Game::_InitEnemies()
{
    this->spawn_timer_max=50.f;
    this->spawn_timer=this->spawn_timer_max;
}



//Constructors and destructors
Game::Game()
{
    this->_InitWindow();
    this->_InitTextures();
    this->_InitGUI();
    this->_InitWorld();
    this->_InitSystems();
    this->_InitPlayer();
    this->_InitEnemies();
}

Game::~Game()
{
    delete this->window;
    delete this->player;

    //Delete texture to avoid memory leak
    for(auto &i : this->textures)
    {
        delete i.second;
    }

    // Delete any bullets left
    for(auto *i: this->bullets)
    {
        delete i;
    }

    // Delete enemies
    for(auto *i: this->enemies)
    {
        delete i;
    }
} 


 
//Functions
void Game::Run()
{
    while(this->window->isOpen())
    {
        this->Update();
        this->Render();
    }

}


void Game::UpdatePollEvents()
{
    sf::Event ev;
    while(this->window->pollEvent(ev))
    {
        if(ev.Event::type==sf::Event::Closed)
            this->window->close();
        if(ev.Event::KeyPressed && ev.Event::key.code==sf::Keyboard::Escape)
            this->window->close();
    }
    

}
void Game::UpdateInput()
{
    //Move player
    //Left
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->Move(-1.f,0.f);
    //Right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->Move(1.f,0.f);
    //Up
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->Move(0.f,-1.f);
    //Down
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->Move(0.f,1.f);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->CanAttack())
    {
        this->bullets.push_back(
            new Bullet(
                this->textures["BULLET"],
                this->player->GetPosition().x + this->player->GetBounds().width/2.f,
                this->player->GetPosition().y,
                0.f,-1.f,8.f
            )
        );
    }
}


void Game::UpdateGUI()
{
    std::stringstream ss;

    ss<<"Points:"<<this->points<<"\n"; 


    this->point_text.setString(ss.str());

}

void Game::UpdateWorld()
{

}
void Game::UpdateCollision()
{
    //Left world collision
    if(this->player->GetBounds().left<0.f)
    {
        this->player->SetPosition(
            0.f,
            this->player->GetBounds().top
        );
    }
    //Right world collision
    else if(this->player->GetBounds().left+this->player->GetBounds().width > this->window->getSize().x)
    {
        this->player->SetPosition(
            this->window->getSize().x - this->player->GetBounds().width,
            this->player->GetBounds().top
        );
    }
    //Top world collision
    if(this->player->GetBounds().top<0.f)
    {
        this->player->SetPosition(
            this->player->GetBounds().left,
            0.f
        );
    }
    //Bottom world collision
    else if(this->player->GetBounds().top+this->player->GetBounds().height > this->window->getSize().y)
    {
        this->player->SetPosition(
            this->player->GetBounds().left,
            this->window->getSize().y - this->player->GetBounds().height
        );
    }
}


void Game::UpdateBullets()
{
    unsigned counter=0;

    for(auto *bullet: this->bullets)
    {
        bullet->Update();

        // Bullet culling (top of the screen)
        if(bullet->GetBounds().top + bullet->GetBounds().height < 0.f)
        {
            //Delete bullet
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin()+counter);
            --counter;
        }

        ++counter;
    }
}
void Game::UpdateEnemies()
{
    //Spawning
    this->spawn_timer+=0.5f;
    if(this->spawn_timer >= this->spawn_timer_max)
    {
        this->enemies.push_back(new Enemy(rand()%this->window->getSize().x-20.f, -100.f));
        this->spawn_timer=0.f;
    }

    //Update 
    unsigned counter=0; 
    for(auto *enemy: this->enemies)
    {
        enemy->Update();

        // Enemy culling (Bottom of the screen)
        if(enemy->GetBounds().top > this->window->getSize().y)
        {
            //Delete Enemy
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin()+counter);
            --counter; 
        }
        else if(enemy->GetBounds().intersects(this->player->GetBounds()))
        {
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin()+counter);
            --counter; 
        }

        ++counter;
    }
}

void Game::UpdateCombat()
{
    for(int i=0; i<this->enemies.size(); ++i)
    { 
        bool enemy_deleted=false;

        for(size_t k=0; k<this->bullets.size() && enemy_deleted==false; ++k)
        {
            if(this->enemies[i]->GetBounds().intersects(this->bullets[k]->GetBounds()))
            {
                //Increase points
                this->points+=this->enemies[i]->GetPoints();

                //Delete Enemy
                delete this->enemies[i];
                this->enemies.erase(this->enemies.begin() + i);

                //Delete Bullet
                delete this->bullets[k];
                this->bullets.erase(this->bullets.begin() + k); 

                enemy_deleted=true;
                
            }
        }
    }
}

void Game::Update()
{
    this->UpdatePollEvents();
    this->UpdateInput();

    this->UpdateCollision();


    this->player->Update();

    this->UpdateBullets();
    this->UpdateEnemies();
    this->UpdateCombat();

    this->UpdateGUI();

    this->UpdateWorld();
}



void Game::RenderGUI()
{
    this->window->draw(this->point_text);
}

void Game::RenderWord()
{
    this->window->draw(this->world_background);
}

void Game::Render()
{
    this->window->clear();

    //Draw world
    this->RenderWord();


    //Render de player
    this->player->Render(*this->window);

    //Render the bullets
    for(auto *bullet: this->bullets)
    {
        bullet->Render(this->window);
    }

    //Render the enemies
    for(auto *enemy: this->enemies)
    {
        enemy->Render(this->window);
    }

    this->RenderGUI();


    this->window->display();

}



}//namespace Game_Engine