#ifndef _MOVEMENT_MAX_H
#define _MOVEMENT_MAX_H

#include <cmath>
#include <_object_max.h>
#include <_objectinteract_max.h>

// class to implement manual movements for objects of various kinds (player walking, items moving towards player, ect)
class _movement_max
{
    public:
        virtual ~_movement_max();

        static void moveHorizontal(_object_max *, float);              // move horizontally in a given direction (object, speedX)
        static void moveVertical(_object_max *, float);                // move vertically in a given direction (object, speedY)
        static void moveDegree(_object_max *,float, float);            // move at a degree in a given direction (object, speedX, speedY)
        static void moveTwordsObject(_object_max *, _object_max*, float);  // move towards a given object in general (object, toObjest, speed)

    protected:

    private:
        _movement_max();
};

#endif // _MOVEMENT_MAX_H
