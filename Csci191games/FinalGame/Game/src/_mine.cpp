#include "_mine.h"

_mine::_mine()
{
    damage = 20.0;      // set damage of mine
    activated = false;
    //ctor
}

_mine::~_mine()
{
    //dtor
}

void _mine::initialize()
{
    _objectinteract_max::initialize(mine, "mine", 0.5, 0.5, 0.0, 0.0, 0.0, 0.0, "images/enemies/mine.png", 7.0, 1.0);
}

void _mine::draw()
{
    _objectinteract_max::draw(mine);
}

void _mine::animate()
{
    _animate_max::animate(mine);
}

void _mine::interact(_object_max * curObj)
{
    if(mine->obj.exist)
    {
        _hitbox_max::calculateRelativeHitbox(mine, curObj);
        _hitbox_max::calculateHit(mine, curObj);
        if(_hitbox_max::calculateDistance(mine, curObj) < 4)
        {

            if(!activated)  // if mine is in range of player play sound once
            {
              sounds->playSounds("sounds/sfx/beeping.mp3") ;
            }
            activated = true;
            _movement_max::moveTwordsObject(mine, curObj, .0025);   // and move towards player
        }
        else
        {
            activated = false;  // else if player is out of range, deactivate
        }
    }
    if(!mine->obj.exist)
    {
        _objectinteract_max::changeImage(mine, "images/invisible.png", 1, 1);
    }
}

