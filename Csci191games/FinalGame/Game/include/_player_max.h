#ifndef _PLAYER_MAX_H
#define _PLAYER_MAX_H

#include <_object_max.h>
#include <_objectinteract_max.h>
#include <_movement_max.h>
#include <_animate_max.h>

class _player_max
{
    public:
        _player_max();
        virtual ~_player_max();

        _object_max *player = new _object_max();

        float playerHealth;             // amount of health a player currently has

        void initialize();              // initialize player
        void draw();                    // draw player
        void animate();
        void movements(string, float);  // the various movements that are going to be done for the player

        void attract(_object_max *);        // attracts various items to himself (healthpack in this case)

    protected:

    private:
};

#endif // _PLAYER_MAX_H
