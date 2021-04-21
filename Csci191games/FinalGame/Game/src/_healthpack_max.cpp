#include "_healthpack_max.h"

_healthpack_max::_healthpack_max()
{
    //ctor
    healing = 20.0;                                              // set healing amount
    /*
    healthpack->obj.type = "healthpack";                         // setting desired healthpack information
    healthpack->obj.id = (unsigned int) &healthpack;

    healthpack->obj.scale.x = 0.25;
    healthpack->obj.scale.y = 0.25;

    healthpack->obj.pos.x = 0.0;
    healthpack->obj.pos.y = 0.0;

    healthpack->obj.angle = 0.0;
    healthpack->obj.coordrot.z = 0.0;

    healthpack->obj.image = "images/healthpack.png";
    healthpack->obj.frames.x = 7;
    healthpack->obj.frames.y = 1;
    */
}

_healthpack_max::~_healthpack_max()
{
    //dtor
}

void _healthpack_max::initialize()
{
    _objectinteract_max::initialize(healthpack, "healthpack", 0.25, 0.25, 0.0, -3.0, 0.0, 0.0, "images/items/healthpack.png", 7.0, 1.0);
    //healthpack->obj.hbsize = .05;
}

void _healthpack_max::draw()
{
    _objectinteract_max::draw(healthpack);
}

void _healthpack_max::animate()
{
    _animate_max::animate(healthpack);
}

void _healthpack_max::interact(_object_max *curObj)
{
    if(healthpack->obj.exist){
        _hitbox_max::calculateRelativeHitbox(healthpack, curObj);
        _hitbox_max::calculateHit(healthpack, curObj);
        //_movement_max::moveTwordsObject(healthpack, curObj, .0025);
    }
    if(!healthpack->obj.exist)
        {
            _objectinteract_max::changeImage(healthpack, "images/invisible.png", 1, 1);
        }
}

/*
void _healthpack_max::attract(_object_max * curObj)
{
    _movement_max::moveTwordsObject(healthpack, curObj, .01);
}
*/
