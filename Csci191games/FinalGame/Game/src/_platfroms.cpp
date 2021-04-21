#include "_platfroms.h"

_platfroms::_platfroms()
{
    //ctor
}

_platfroms::~_platfroms()
{
    //dtor
}

void _platfroms::initialize()
{
    _objectinteract_max::initialize(platform, "platform,", 1.0, 1.0, 0.0, -1.0, 0.0, 0.0, "images/levelOne/platformOne.png", 1.0, 1.0);
}

void _platfroms::draw()
{
    _objectinteract_max::draw(platform);
}

void _platfroms::interact(_object_max* curObj)
{
    _hitbox_max::calculateRelativeHitbox(platform, curObj);
    _hitbox_max::calculateHit(platform, curObj);
    if(platform->obj.touched == true)
    {
        cout << "hit platform" << endl;
    }
}
