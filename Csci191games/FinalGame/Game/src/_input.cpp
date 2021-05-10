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
        //snds->playSounds("sounds/exmpl.wav");
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
float _input::anglesForShots(_weapons* wpn, float x, float y)
{
    if(!wpn->active){
        float degree;
        prevMouseX = x;
        prevMouseY = y;
        wpn->xClicker = x;
        wpn->yClicker = y;
        if(x > 767.5){
            degree = atan((685 - prevMouseY)/(prevMouseX - 767.5)); //Right half of screen
            wpn->rotateAngle = (degree * 180) / 3.14159265;
        }
        else if(x < 767.5){  // left half of the screen
            degree = -atan((685 - prevMouseY)/(767.5 - prevMouseX)); //Right half of screen
            wpn->rotateAngle = (180 + (degree * 180) / 3.14159265);
        }
        wpn->angle = degree;
    }

}

void _input::mouseDown(_weapons* wpn, _weapons* wpn2, float x, float y)
{
    prevMouseX = x;
    prevMouseY = y;
    switch(wParam)
    {
        case MK_LBUTTON:
            if(wpn->action == wpn->PISTOL && wpn->active == false){
                snds->playSounds("sounds/gunShot.mp3");
            }
            if(wpn->action == wpn->GRENADELAUNCHER && wpn->active == false){
                snds->playSounds("sounds/gLaunchShot.mp3");
            }
            if(wpn->action == wpn->BEAM && wpn->active == false){
                snds->playSounds("sounds/laserGunShot.mp3");
            }
            wpn->active = true;
            break;
        case MK_RBUTTON:
            wpn2->active = true;
            break;
        default:
            break;
    }
}


void _input::keyPressed(_weapons* wpn)
{
    switch(wParam)
    {
    case VK_LEFT:
        if(wpn->active){
            wpn->projPos.x += 0.06;  // do action according to your sprite

        }
        wpn->weaponPos.x += 0.06;
        break;

    case VK_RIGHT:
        if(wpn->active){
            wpn->projPos.x -= 0.06;  // do action according to your sprite

        }
        wpn->weaponPos.x -= 0.06;
        break;
    case VK_SPACE:
        if(wpn->action == wpn->PISTOL && wpn->active == false){
            snds->playSounds("sounds/gunShot.mp3");
        }
        if(wpn->action == wpn->GRENADELAUNCHER && wpn->active == false){
            snds->playSounds("sounds/gLaunchShot.mp3");
        }
        if(wpn->action == wpn->BEAM && wpn->active == false){
            snds->playSounds("sounds/laserGunShot.mp3");
        }
        if(wpn->xClicker <= 767.5){
            wpn->projPos.y += 0.1;
        }
        wpn->active = true;
        break;
    }
}

void _input::weaponPickUp(_weapons* wpn, _weapons* wpnOnPly, _object_max* ply)
{
    switch(wParam)
    {
    case VK_DOWN:
        if(col->touchingWeapon(wpn, ply)){
            if(wpn->action == wpn->PISTOL){
                wpnOnPly->toOrigin(ply);
                wpnOnPly->action = wpnOnPly->PISTOL;
                wpnOnPly->toOrigin(ply);
            }
            if(wpn->action == wpn->GRENADELAUNCHER){
                wpnOnPly->toOrigin(ply);
                wpnOnPly->action = wpnOnPly->GRENADELAUNCHER;
                wpnOnPly->toOrigin(ply);
            }
            if(wpn->action == wpn->BEAM){
                wpnOnPly->toOrigin(ply);
                wpnOnPly->action = wpnOnPly->BEAM;
                wpnOnPly->toOrigin(ply);
            }
            if(wpn->action == wpn->SHOCKRIFLE){
                wpnOnPly->toOrigin(ply);
                wpnOnPly->action = wpnOnPly->SHOCKRIFLE;
                wpnOnPly->toOrigin(ply);
            }
            wpn->weaponPos.x = 15.0;
            wpn->weaponPos.y = -5.0;
            wpn->weaponPos.z = -9.0;
        }
        break;

        break;
    }
}
//-------------------
