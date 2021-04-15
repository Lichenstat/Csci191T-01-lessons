#include "_animate_max.h"

_animate_max::_animate_max()
{
    //ctor
}

_animate_max::~_animate_max()
{
    //dtor
}

void _animate_max::animate(_object_max *curObj)                             // animate the object using frame placement
{
    glPushMatrix();
    curObj->obj.xMin += 1/curObj->obj.frames.x;                             // update minimum location X col on sprite sheet
    curObj->obj.xMax += 1/curObj->obj.frames.x;                             // update maximum location X col on sprite sheet
    curObj->obj.yMin += 1/curObj->obj.frames.y;                             // update minimum location Y row on sprite sheet
    curObj->obj.yMax += 1/curObj->obj.frames.y;                             // update maximum location Y row on sprite sheet
    glPopMatrix();
}

void _animate_max::direction(_object_max *curObj, float direction)          // update the direction of the image ( direction < 0 turns the image "left", direction > 0 turns the image right)
{
    if(direction < 0)
    {
        curObj->obj.vert[0].x =  0.5;
        curObj->obj.vert[1].x =  -0.5;
        curObj->obj.vert[2].x =  -0.5;
        curObj->obj.vert[3].x =  0.5;
    }
    if(direction > 0)
    {
        curObj->obj.vert[0].x =  -0.5;
        curObj->obj.vert[1].x =  0.5;
        curObj->obj.vert[2].x =  0.5;
        curObj->obj.vert[3].x =  -0.5;
    }
}

void _animate_max::movementCycle(_object_max *curObj, float startX, float endX, float onY)
{
    if((endX/curObj->obj.frames.x) <= curObj->obj.xMax)          // if frames on going x on sprite sheet meet max frame count, restart max frames at 0
    {
        curObj->obj.xMin = 0;
        curObj->obj.xMax = 0;
    }

    curObj->obj.xMin = curObj->obj.xMax;                         // cycle through desired frames along x axis (matrix style)
    curObj->obj.xMax += startX/curObj->obj.frames.x;
    curObj->obj.yMin = (onY-1)/curObj->obj.frames.y;
    curObj->obj.yMax = onY/curObj->obj.frames.y;

}

void _animate_max::jump(_object_max *curObj, float onXMin, float onXMax, float onYMin, float onYMax)
{

}
