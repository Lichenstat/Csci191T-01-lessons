#ifndef _MINE_H
#define _MINE_H

#include <_object_max.h>
#include <_objectinteract_max.h>
#include <_movement_max.h>
#include <_hitbox_max.h>
#include <_animate_max.h>
#include <_sounds.h>

class _mine
{
    public:
        _mine();
        virtual ~_mine();

        _object_max * mine = new _object_max(); // mine is an object
        _sounds * sounds = new _sounds();       // sounds for mine
        int deathFrames;

        float health;                           // mine health
        float damage;                           // mine damaged (unused for now)
        float speed;                            // mine speed (movement)
        bool activated;                         // mine activated or not
        bool dead;                              // if mine is dead or not

        void initialize();                      // initialize
        void draw();                            // draw mine
        void animate();                         // animate mine
        void interact(_object_max *);           // to interact with mine

    protected:

    private:
};

#endif // _MINE_H
