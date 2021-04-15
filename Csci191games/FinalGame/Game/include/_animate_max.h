#ifndef _ANIMATE_MAX_H
#define _ANIMATE_MAX_H

#include <_object_max.h>

class _animate_max
{
    public:
        virtual ~_animate_max();

        static void animate(_object_max *);                                     // animate the object at hand
        static void direction(_object_max *, float);                            // direction to flip sprite in (left is < 0, right is > 0)
        static void movementCycle(_object_max *, float, float, float);          // get a movement cycle from the sprite sheet (xMin, xMax, yMin, yMax) defined by matrix on spritesheet
        static void jump(_object_max *, float ,float, float, float);            // get jump cycle from sprite sheet

    protected:

    private:
        _animate_max();
};

#endif // _ANIMATE_MAX_H
