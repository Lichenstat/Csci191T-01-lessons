#ifndef _MOVEMENT_JUMP_H
#define _MOVEMENT_JUMP_H

#include <_object_max.h>
#include <_objectinteract_max.h>
#include <_movement_max.h>
#include <_animate_max.h>           // remove later if there is a better way to animate jumping for player
#include <_sounds.h>

class _movement_jump
{
    public:
        _movement_jump();
        virtual ~_movement_jump();

        vec2 origPos;               // original position of the object
        float jumpPeak;             // peak of jump height
        float jumpLocation;         // jump location(x distance along parabola, the bigger the number the bigger the distance, the bigger the y vertex location changes)
        float jumpHeight;           // jump height
        float jumpSpeed;            // jump speed
        bool currentlyJumping;      // bool to tell if something is currently jumping
        float negvrtx, posvrtx;     // positive and negative vertex on x axis

        _sounds * movSnd = new _sounds();   // sounds for movement of jump on landing (get rid of later if possible, not best placement for class)

        void jump(_object_max *, float, float);     // set jump height and speed of object to jump
        void jumpLoop(_object_max *);// loop through jumping sequence after setting jump

    protected:

    private:
};

#endif // _MOVEMENT_JUMP_H
