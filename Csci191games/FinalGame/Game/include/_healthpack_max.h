#ifndef _HEALTHPACK_MAX_H
#define _HEALTHPACK_MAX_H

#include <_object_max.h>
#include <_objectinteract_max.h>
#include <_movement_max.h>
#include <_animate_max.h>
#include <_hitbox_max.h>

class _healthpack_max
{
    public:
        _healthpack_max();
        virtual ~_healthpack_max();

        _object_max *healthpack  = new _object_max();           // make a new object (in this case a healthpack)

        //float healing;                                  // amount of healing a healthpack provides

        void initialize();                              // initialize healthpack with various features
        void draw();                                    // draw the healthpack and have it interact with what object
        void animate();                                 // animate the healthpack
        void interact(_object_max *);                   // interaction of some kind (jn this case hitbox interaction)
        //void attract(_object_max *);                    // healthpack goes towards object

    protected:

    private:

};

#endif // _HEALTHPACK_MAX_H
