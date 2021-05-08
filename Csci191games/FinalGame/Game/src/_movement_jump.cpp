#include "_movement_jump.h"

_movement_jump::_movement_jump()
{
    //ctor
    origPos.x = 0.0;
    origPos.y = 0.0;
    jumpPeak = 0;
    jumpLocation = 0;
    jumpHeight = 0;
    jumpSpeed = 0;
    currentlyJumping = false;
    negvrtx = 0;
    posvrtx = 0;
}

_movement_jump::~_movement_jump()
{
    //dtor
}

void _movement_jump::jump(_object_max * curObj, float height, float speed)
{
    if(!currentlyJumping)
    {
        origPos.x = curObj->obj.pos.x;
        origPos.y = curObj->obj.pos.y;
        posvrtx = sqrt(height/1);
        negvrtx = -posvrtx;
        jumpLocation = negvrtx;
        jumpPeak = height;
        jumpSpeed = speed;
        movSnd->playSounds("sounds/sfx/jump up.mp3");
        //cout << posvrtx << " " << negvrtx << endl;
        //cout << jumpLocation << " " << jumpSpeed << endl;
    }
}

void _movement_jump::jumpLoop(_object_max * curObj)
{
    if(currentlyJumping)
    {
        //cout << jumpLocation << " " << jumpHeight << endl
        float ojh = jumpHeight;
        jumpHeight = sqrt(fabs(-1 * pow((jumpLocation - 0),2) + jumpPeak));     // y = a(x - h)^2 + k (parabola)
        if(jumpLocation <= 0)                               // hard coded frames for player animation, change later if time allots
            _animate_max::singleFrame(curObj, 4, 5);
        if(jumpLocation > 0)
            _animate_max::singleFrame(curObj, 7, 5);
        jumpLocation += jumpSpeed;
        _movement_max::moveVertical(curObj, jumpHeight - ojh);
        if(jumpLocation > posvrtx)
        {
            currentlyJumping = false;
            movSnd->playSounds("sounds/sfx/jump landing.mp3");
            _animate_max::singleFrame(curObj, 1, 9);    // hard coded animation stand for player, fix later if can
        }
        /*
        if(jumpLocation < -25 || jumpLocation > 25)
        {
            _movement_max::moveVertical(curObj, origPos.y);
            //_movement_max::moveHorizontal(curObj, origPos.y);
            currentlyJumping = false;
        }
        */
    }
}
