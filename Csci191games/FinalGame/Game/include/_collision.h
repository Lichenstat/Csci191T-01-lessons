#ifndef _COLLISION_H
#define _COLLISION_H

#include <_enemies.h>
#include <_player_max.h>
#include <_timer.h>

class _collision
{
    public:
        _collision();
        virtual ~_collision();

        bool enemyHitPlayer(_player_max*, float, float);
        bool linearCollision(float, float);

        _enemies *enms = new _enemies();
        _player_max *ply = new _player_max();
        _timer *time = new _timer();

    protected:

    private:
};

#endif // _COLLISION_H
