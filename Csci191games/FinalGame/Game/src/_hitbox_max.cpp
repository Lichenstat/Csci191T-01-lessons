#include "_hitbox_max.h"

_hitbox_max::_hitbox_max()
{
    //ctor
}

_hitbox_max::~_hitbox_max()
{
    //dtor
}

float _hitbox_max::calculateAngleBetweenObjects(_object_max* curObj, _object_max* toObj)            // calculate an angle(degree) between 2 objects
{
    if((toObj->obj.pos.x - curObj->obj.pos.x) < 0)
    {
        //cout << "degree: " << (atan((fy)/(fx)))*(180/3.14159)+180 << endl;
        return (atan((toObj->obj.pos.y - curObj->obj.pos.y)/(toObj->obj.pos.x - curObj->obj.pos.x)))*(180/3.14159)+180;
    }
    else
    {
        //cout << "degree: " << (atan((fy)/(fx)))*(180/3.14159) << endl;
        return (atan((toObj->obj.pos.y - curObj->obj.pos.y)/(toObj->obj.pos.x - curObj->obj.pos.x)))*(180/3.14159);
    }
}

float _hitbox_max::calculateDistance(_object_max *fromObj, _object_max *toObj)
{
    float x1 = fromObj->obj.pos.x - toObj->obj.pos.x;
    float y1 = fromObj->obj.pos.y - toObj->obj.pos.y;
    return(sqrt((x1*x1)+(y1*y1)));
}

void _hitbox_max::calculateHitbox(_object_max* curObj, float degree)        // calculate ellipse hitbox radian in conjunction to some degree
{
    float top = curObj->obj.scale.x*curObj->obj.scale.y;
    float fh = pow(curObj->obj.scale.x,2)*(pow(sin(degree),2));
    float sh = pow(curObj->obj.scale.y,2)*(pow(cos(degree),2));
    float bottom = sqrt(fh + sh);
    curObj->obj.hbsize = (top / bottom);

    if(string(curObj->obj.type) == "player")
    {
        curObj->obj.hbsize = curObj->obj.hbsize/6;                  // the /6 is added to help scale the player hitboxe (radius) a bit since the scale is based on scale of object and player size can be huge
    }

/*
    curObj->obj.hbsize = (curObj->obj.scale.x*curObj->obj.scale.y)
                         /
                         sqrt(pow(curObj->obj.scale.x,2)*(pow(sin(degree),2))
                         +    (pow(curObj->obj.scale.y,2)*(pow(cos(degree),2))));
                         */
}

void _hitbox_max::calculateRelativeHitbox(_object_max *firstObj, _object_max *secondObj)        // calculate the relative hitbox radius between 2 objects
{
    calculateHitbox(firstObj, calculateAngleBetweenObjects(firstObj, secondObj));
    calculateHitbox(secondObj, calculateAngleBetweenObjects(secondObj, firstObj));
}

void _hitbox_max::calculateHit(_object_max *firstObj, _object_max *secondObj)                   // find out if the radius vector magnitudes intersect so you can give info about the object being touched
{

    if(
        sqrt(
          pow((secondObj->obj.pos.x - firstObj->obj.pos.x),2)
          +
          pow((secondObj->obj.pos.y - firstObj->obj.pos.y),2)
        )
          <= (firstObj->obj.hbsize + secondObj->obj.hbsize)
    )
       {
           firstObj->obj.touched = true;
           secondObj->obj.touched = true;
       }
    else
    {
        firstObj->obj.touched = false;
        secondObj->obj.touched = false;
    }
}
