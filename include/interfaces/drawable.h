#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

class Drawable
{
    public:
        //Destructor
        virtual ~Drawable()=default;

        //Functions
        virtual void Render(sf::RenderTarget& target)=0;
};

#endif // DRAWABLE_H