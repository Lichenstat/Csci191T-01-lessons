#include "_movement_max.h"

_movement_max::_movement_max()
{
    //ctor
}

_movement_max::~_movement_max()
{
    //dtor
}

void _movement_max::moveHorizontal(_object_max *curObj, float speedX)                         // move horizontally at some speed
{
    _objectinteract_max::updateRelativePosition(curObj, speedX, 0);
}

void _movement_max::moveVertical(_object_max *curObj, float speedY)                           // move vertically at some speed
{
    _objectinteract_max::updateRelativePosition(curObj, 0, speedY);
}

void _movement_max::moveDegree(_object_max *curObj, float degree, float speed)                // move towards a certain degree at a certain speed
{
    //cos ( degree * PI / 180.0 )
    //sin ( degree * PI / 180.0 )
    //cout << "X dir: " << (cos(degree*(3.14159/180.0)))*speed << "| Y dir: " << (sin(degree*(3.14159/180.0)))*speed << endl; //" | Normalized: " << sqrt(pow(cos(degree),2)+ pow(sin(degree),2))<<endl;
    _objectinteract_max::updateRelativePosition(curObj, (cos(degree*(3.14159/180.0)))*speed, (sin(degree*(3.14159/180.0)))*speed);
}

void _movement_max::moveTwordsObject(_object_max *curObj, _object_max *toObj, float speed)      // get two objects and get a desired traveling degree from the curObj to the toObj, then update the new curObj position using the curObj, moveDegree, and a speed
{
    //vec2 tank;
    //vec2 bot;
    //tank.x = 1; tank.y = 1;
    //bot.x =  3; bot.y =  -3;
    //float fy = bot.y - tank.y;
    //float fx = bot.x - tank.x;
    //(toObj->obj.pos.y - curObj->obj.pos.y)
    //(toObj->obj.pos.x - curObj->obj.pos.x)

    //if(fx < 0)
    if((toObj->obj.pos.x - curObj->obj.pos.x) < 0)
    {
        //cout << "degree: " << (atan((fy)/(fx)))*(180/3.14159)+180 << endl;
        moveDegree(curObj, (atan((toObj->obj.pos.y - curObj->obj.pos.y)/(toObj->obj.pos.x - curObj->obj.pos.x)))*(180/3.14159)+180, speed);
    }
    else
    {
        //cout << "degree: " << (atan((fy)/(fx)))*(180/3.14159) << endl;
        moveDegree(curObj, (atan((toObj->obj.pos.y - curObj->obj.pos.y)/(toObj->obj.pos.x - curObj->obj.pos.x)))*(180/3.14159), speed);
    }
}
