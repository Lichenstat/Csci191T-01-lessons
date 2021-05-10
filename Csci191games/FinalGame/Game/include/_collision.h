#ifndef _COLLISION_H
#define _COLLISION_H

#include <_enemies.h>
#include <_player_max.h>
#include <_object_max.h>
#include <_timer.h>
#include <_weapons.h>
#include <_sounds.h>

class _collision
{
    public:
        _collision();
        virtual ~_collision();

        bool enemyHitPlayer(_player_max*, float, float);
        bool linearCollision(float, float);
        bool projHit(_weapons*, _object_max*);
        bool touchingWeapon(_weapons*, _object_max*);

        _enemies *enms = new _enemies();
        _player_max *ply = new _player_max();
        _timer *time = new _timer();
        _sounds *snds = new _sounds();

    protected:

    private:
};

#endif // _COLLISION_H
