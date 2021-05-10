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

bool _collision::projHit(_weapons* proj, _object_max* obj)
{
    if(((proj->projPos.x - 0.3) < obj->obj.pos.x) && ((proj->projPos.x + 0.3) > obj->obj.pos.x) &&
       ((proj->projPos.y - 0.3) < obj->obj.pos.y) && ((proj->projPos.y + 0.3) > obj->obj.pos.y) &&
        (obj->obj.exist)){
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

bool _collision::touchingWeapon(_weapons* wpn, _object_max* ply)
{
    if(ply->obj.pos.x - wpn->weaponPos.x < 0.4 && ply->obj.pos.x - wpn->weaponPos.x > -0.1 &&
       ply->obj.pos.y - wpn->weaponPos.y < 0.4 && ply->obj.pos.y - wpn->weaponPos.y > -0.1){
        return true;
    }
    return false;
}



