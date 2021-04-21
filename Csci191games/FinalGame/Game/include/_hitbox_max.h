#ifndef _HITBOX_MAX_H
#define _HITBOX_MAX_H

#include <cmath>
#include <_object_max.h>

class _hitbox_max
{
    public:
        _hitbox_max();
        virtual ~_hitbox_max();

        static float calculateAngleBetweenObjects(_object_max *, _object_max *); // calculate an angle between two objects
        static float calculateDistance(_object_max *, _object_max *);            // calculate the distance between two objects
        static void calculateHitbox(_object_max *, float);                       // calculate a hitbox elipse size (radian) in a direction using an angle and an objects xsize and ysize
        static void calculateRelativeHitbox(_object_max *, _object_max *);       // calculate the relative hitboxes for two objects
        static void calculateHit(_object_max *, _object_max *);                  // do a calculation to see if both objects hit eachother or not

    protected:

    private:
};

#endif // _HITBOX_MAX_H
