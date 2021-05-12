#ifndef _PLAYER_MAX_H
#define _PLAYER_MAX_H

#include <vector>
#include <algorithm>

#include <_object_max.h>
#include <_objectinteract_max.h>
#include <_movement_jump.h>
#include <_animate_max.h>
#include <_sounds.h>

class _player_max
{
    public:
        _player_max();
        virtual ~_player_max();

        _object_max *player = new _object_max();
        _sounds * movementSounds = new _sounds();               // sounds
        bool movementSoundPlaying;                              // check if a movement sound is playing already
        _sounds * itemSounds = new _sounds();
        float deathFrames;                                      // how many frames are the death animation
        _movement_jump * jumping = new _movement_jump();        // to create a vertical jump

        vector<unsigned int> id;                                // object id's to check killcount
        int killCount;                                          // player killcount

        float playerHealth;             // amount of health a player currently has
        bool onPlatform;

        void initialize();              // initialize player
        void draw();                    // draw player
        void animate();                 // animate player
        void movements(string, float);  // the various movements that are going to be done for the player (as well as movement animations)
        void interact(_object_max *);   // various items to himself (healthpack in this case)

    protected:

    private:
};

#endif // _PLAYER_MAX_H
