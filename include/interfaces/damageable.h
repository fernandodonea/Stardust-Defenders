#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

class Damageable 
{
    public:
        //Destructor
        virtual ~Damageable() = default;

        //Functions
        virtual void LoseHp(int value)=0;
};


#endif // DAMAGEABLE_H