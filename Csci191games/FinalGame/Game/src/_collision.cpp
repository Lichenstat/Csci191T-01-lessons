#include "_collision.h"

_collision::_collision()
{
    //ctor
}

_collision::~_collision()
{
    //dtor
}
bool _collision::enemyHitPlayer(_player_max* ply, float plyPos, float enmsPos)
{
    if(plyPos - enmsPos < 0.01){
        ply->playerHealth  = ply->playerHealth - 10;
        return true;
    }
    return false;
}

//we can use this to check if the character is on the floor or if they hop, they can get back down correctly
bool _collision::linearCollision(float objPos, float wall)
{
    if(objPos-wall < 0.01){
        return true;
    }
    return false;
}












/*
bool _collision::isLinearCollision(float x1, float x2)
{
    if(fabs(x1-x2<0.1))return true;
   return false;
}

bool _collision::isRadialCollision(float x1, float x2, float y1, float y2, float r1, float r2)
{
    if(sqrt(pow(x1-x2,2)+pow(y1-y2,2))<r1+r2)return true;
    return false;
}
*/
