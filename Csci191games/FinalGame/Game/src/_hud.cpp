#include "_hud.h"

_hud::_hud()
{
    //ctor
    hbxscale = 2.5;
}

_hud::~_hud()
{
    //dtor
}

void _hud::initialize()
{
    _objectinteract_max::initialize(healthbarBack, "healthbarBack", hbxscale, 1.8, -3.5, -3.0, 0.0, 0.0, "images/healthbar/hbback.png", 1.0, 1.0);
    _objectinteract_max::initialize(healthbarMiddle, "healthbarMiddle", hbxscale, 1.8, -4.75, -3.0, 0.0, 0.0, "images/healthbar/hbmiddle.png", 1.0, 1.0);
    _objectinteract_max::initialize(healthbarFront, "healthbarFront", hbxscale, 1.8, -3.5, -3.0, 0.0, 0.0, "images/healthbar/hbfront.png", 1.0, 1.0);
    healthbarMiddle->obj.vert[0].x =  0.5;
    healthbarMiddle->obj.vert[1].x =  0.0;
    healthbarMiddle->obj.vert[2].x =  0.0;
    healthbarMiddle->obj.vert[3].x =  0.5;
}

void _hud::draw()
{
    _objectinteract_max::draw(healthbarBack);
    _objectinteract_max::draw(healthbarMiddle);
    _objectinteract_max::draw(healthbarFront);
}

void _hud::interact(float playerHealth)
{
    if (playerHealth < 0)
        playerHealth = 0;
    float newsize = .05 * playerHealth;
    //cout << newsize << endl;
    _objectinteract_max::changeScale(healthbarMiddle, newsize, 1.8);
}

