#include "_input.h"

_input::_input()
{
    //ctor
    float prevMouseX;
    float PrevMouseY;
    bool mouseTranslation;
    bool mouseRotate;
}

_input::~_input()
{
    //dtor
}

void _input::keyPressed(_model* mdl)
{
    switch(wParam)
    {
    case VK_LEFT:
        mdl->rotateY += 1.0;
        break;
    case VK_RIGHT:
        mdl->rotateY -= 1.0;
        break;
    }
}

void _input::keyPressed(_player* ply)
{
    switch(wParam)
    {
    case VK_LEFT:
        ply -> actionTrigger = ply -> RUN;  // do action according to your sprite
        break;

    case VK_RIGHT:
        ply -> actionTrigger = ply -> WALK;
        //ply -> playerPos.x += .0015;        // moving player across the screen
        break;
    }
}

void _input::moveEnv(_parallax* plx, float speed)
{
    switch(wParam)
    {
    case VK_LEFT:
            plx->xMax -= speed;
            plx->xMin -= speed;
        break;
    case VK_RIGHT:
            plx->xMax += speed;
            plx->xMin += speed;
        break;
        case VK_UP:
            plx->yMax += speed;
            plx->yMin += speed;
        break;
    case VK_DOWN:
            plx->yMax -= speed;
            plx->yMin -= speed;
        break;
    }
}

void _input::keyUp()
{
    switch (wParam)
    {
    default:
        break;
    }
}

void _input::keyUp(_player *ply)
{
    ply -> actionTrigger = ply -> STAND;
}

void _input::mouseDown(_model* mdl, float x, float y)
{
    prevMouseX -x;
    prevMouseY -y;

    switch(wParam)
    {
        case MK_LBUTTON:
            mouseRotate = true;
            break;

        case MK_RBUTTON:
            mouseTranslation = true;
            break;

        default:
            break;
    }

}

void _input::mouseUp()
{
    mouseRotate = false;
    mouseTranslation = false;
}

void _input::mouseWheel(_model* mdl, float delta)
{
    mdl->zoom += delta/100;
}

void _input::mouseWheel(_skybox *sky, float delta)
{
    sky->translation.z += delta/100;
}

void _input::mouseMove(_skybox *sky, float x, float y)
{
    if(mouseRotate){
        sky->rotations.y += (x-prevMouseX)/3;
        sky->rotations.x += (y-prevMouseY)/3;
    }
    if(mouseTranslation){
        sky->translation.x += (x-prevMouseX)/100;
        sky->translation.y -= (y-prevMouseY)/100;
    }
    prevMouseX = x;
    prevMouseY = y;
}


void _input::mouseMove(_model* mdl, float x, float y)
{
    if(mouseRotate){
        mdl->rotateY += (x-prevMouseX)/3;
        mdl->rotateX += (y-prevMouseY)/3;
    }
    if(mouseTranslation){
        mdl->xPos += (x-prevMouseX)/100;
        mdl->yPos -= (y-prevMouseY)/100;
    }
    prevMouseX = x;
    prevMouseY = y;
}
