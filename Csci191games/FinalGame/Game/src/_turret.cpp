#include "_turret.h"

_turret::_turret()
{
    //ctor
    health = 50.0;
    damage = 25.0;
    dead = false;
    activated = false;
    turretParts[0] = turretbase;
    turretParts[1] = turretbarrel;
    turretParts[2] = turrethead;
}

_turret::~_turret()
{
    //dtor

}

void _turret::initialize()
{
    _objectinteract_max::initialize(turretbarrel, "turretbarrel", 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, "images/enemies/barrelclean.png", 1.0, 1.0);
    _objectinteract_max::initialize(turrethead, "turrethead", 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, "images/enemies/turretheadclean.png", 7.0, 1.0);
    _objectinteract_max::initialize(turretbase, "turretbase", 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, "images/enemies/turretbaseclean.png", 1.0, 1.0);
}

void _turret::draw()
{
    _objectinteract_max::draw(turretParts);
    if(health <= 0)
    {
        if(!dead)
        {
            dead = true;
            turretbarrel->obj.exist = false;
            turrethead->obj.exist = false;
            _objectinteract_max::changeImage(turretbase, "images/enemies/turretbasedirty.png", 1.0, 1.0);
        }
    }
}

void _turret::animate()
{
    _animate_max::animate(turrethead);
}

void _turret::interact(_object_max * curObj)
{
    if(turretbarrel->obj.exist)
    {
        _hitbox_max::calculateRelativeHitbox(turrethead, curObj);
        _hitbox_max::calculateRelativeHitbox(turretbase, curObj);
        //_hitbox_max::calculateHit(turrethead, curObj);
        //_hitbox_max::calculateHit(turretbase, curObj);
        if(_hitbox_max::calculateDistance(turrethead, curObj) < 4)
        {
            if(!activated && !dead)  // if turret is in range of player play sound once
            {
                sounds->playSounds("sounds/sfx/babeep.mp3");
            }
            activated = true;
            _objectinteract_max::changeAngle(turretbarrel, _hitbox_max::calculateAngleBetweenObjects(curObj, turretbarrel), 1.0);   // and aim towards player
        }
        else
        {
            _animate_max::singleFrame(turrethead, 1, 1);
            activated = false;  // else if player is out of range, deactivate
        }
    }

}
