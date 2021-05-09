#ifndef _TURRET_H
#define _TURRET_H

#include <_object_max.h>
#include <_objectinteract_max.h>
#include <_hitbox_max.h>
#include <_movement_max.h>
#include <_animate_max.h>
#include <_sounds.h>


class _turret
{
    public:
        _turret();
        virtual ~_turret();

        float health;           // turret health
        float damage;           // damage that turret does
        bool activated;         // turret activated or not

        _object_max * turretParts[3];
        _object_max * turretbase = new _object_max();
        _object_max * turrethead = new _object_max();
        _object_max * turretbarrel = new _object_max();

        _sounds * sounds = new _sounds();

        void initialize();
        void draw();
        void animate();
        void interact(_object_max *);

    protected:

    private:
};

#endif // _TURRET_H
