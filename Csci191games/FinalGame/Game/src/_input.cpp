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

void _input::keyPressed(_sounds* snds)
{
    switch(wParam)
    {
    case VK_SPACE:
        snds->playSounds("sounds/exmpl.wav");
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
            //plx->yMax -= speed;
            //plx->yMin -= speed;
        break;
    case VK_DOWN:
            //plx->yMax += speed;
            //plx->yMin += speed;
        break;
    }
}

// Max's additions to input
void _input::moveObj(_object_max *curObj, float speed)
{
    switch(wParam)
    {
    case VK_LEFT:
             _objectinteract_max::updateRelativePosition(curObj, speed, 0);

        break;
    case VK_RIGHT:
             _objectinteract_max::updateRelativePosition(curObj, -speed, 0);
             //curObj->xMin +=speed;
        break;

    case VK_UP:
             //_objectinteract::updateRelativePosition(curObj, 0, -speed);
             //curObj->yMin -=speed;

        break;
    case VK_DOWN:
             //_objectinteract::updateRelativePosition(curObj, 0, speed);
             //curObj->yMin +=speed;
        break;
    }
}

void _input::moveObj(_object_max * curObjs[], float speed)
{
    for(int i = 0; i < sizeof(curObjs) - 1; i++)
    {
        moveObj(curObjs[i], speed);
    }
}

void _input::movePly(_player_max *curObj, float speed)
{
    switch(wParam)
    {
    case VK_LEFT:
             curObj->movements("left", -speed);
        break;
    case VK_RIGHT:
             curObj->movements("right", speed);
        break;

    case VK_UP:
            curObj->movements("jump", speed);
        break;
    case VK_DOWN:

        break;
    }
}
//----------

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


//Eric's weapon function
//We have to get our angle from input because it would give us the x and y for angles
float _input::anglesForShots(_weapons* wpn, float x, float y)
{
    float degree;
    prevMouseX = x;
    prevMouseY = y;
    if(x > 767.5){
        degree = atan((700 - prevMouseY)/(prevMouseX-767.5)); //quad 1
        if(y >= 701){
            degree = 0.01;
        }
    }
    if(x <= 767.5){  // left half of the screen
        degree = -atan((700 - prevMouseY)/(767.5 - prevMouseX)); //quad 2
        if(y >= 701){
            degree = -0.01;
        }
    }
    wpn->angle = degree;
}

void _input::mouseDown(_weapons* wpn, float x, float y)
{
    prevMouseX = x;
    prevMouseY = y;
    switch(wParam)
    {
        case MK_LBUTTON:
            wpn->action = wpn->GRENADELAUNCHER; //two test weapons
            break;
        case MK_RBUTTON:
            wpn->action = wpn->BEAM;
            break;
        default:
            break;
    }
}
//-------------------
