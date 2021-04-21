#include "_weapons.h"

_weapons::_weapons()
{
    //ctor
    vert[0].x =  0.0; vert[0].y = 0.0; vert[0].z = -2.0;
    vert[1].x =  1.0; vert[1].y = 0.0; vert[1].z = -2.0;
    vert[2].x =  1.0; vert[2].y = 1.0; vert[2].z = -2.0;
    vert[3].x =  0.0; vert[3].y = 1.0; vert[3].z = -2.0;

    vel = 0.0;
    accel = 0.0;
    tick = 0.0;
    angle = 0.0;
}

_weapons::~_weapons()
{
    //dtor
}
void _weapons::projInit(float x, float y)
{
    projPos.x = 0.00;
    projPos.y = -2.074;
    projPos.z = -1.0;

    projScale.x = 0.2;
    projScale.y = 0.2;
    projScale.z = 1.0;

    framesX = x;
    framesY = y;
    xMin = 0.0;
    xMax = 1.0/framesX;
    yMin = 0.0;
    yMax = 1.0/framesY;
}

bool _weapons::pickUpWeapons(_player* ply, _weapons* wpn)
{
    if(ply->playerPos.x - wpn->weaponPos.x <= 0.5){
        return true;
    }
    return false;
}
//math----
float _weapons::xDisplace()
{
    if(angle < 0){
        projPos.x = projPos.x - abs(cos(angle) * vel);
    }
    else{
        projPos.x = projPos.x + abs(cos(angle) * vel);
    }

    if(projPos.x < -7.0 || projPos.x > 7.0 ){
        projPos.x = 0.01;
        projPos.y = -2.074;
        tick = 0.0;
    }
    return projPos.x;
}

float _weapons::yDisplace()
{
    projPos.y = projPos.y + abs(sin(angle) * vel) - abs(sin(angle) * (accel * tick * tick) / 2.0);
    if(projPos.y - 0.01 < -2.5 || projPos.y > (3.5)){
        projPos.x = 0.00;
        projPos.y = -2.074;
        tick = 0.0;
    }
    return projPos.y;
}
//end of math----
void _weapons::weaponAction()
{
    switch(action){
        case MELEE:
            weaponDmg = 3;
            break;
        case PISTOL:
            vel = 3.0;
            accel = 1.0;
            weaponDmg = 5;
            projPos.x = xDisplace();
            projPos.y = yDisplace();
            tick = tick + 0.1;
            break;
        case GRENADELAUNCHER:
            xMin += 1/framesX;  //This our frame changing and allows our ball to roll.
            xMax += 1/framesX;
            projPos.x = xDisplace();
            projPos.y = yDisplace();
            tick = tick + 0.1;
            break;
        case FLAMETHROWER:
            weaponDmg = 13;
            projPos.x = xDisplace();
            projPos.y = yDisplace();
            tick = tick + 0.1;
            break;
        case BEAM:
            projPos.x = xDisplace();
            projPos.y = yDisplace();
            tick = tick + 0.1;
            break;
        case SHOCKRIFLE:
            vel = 3.0;
            accel = 0.0;
            weaponDmg = 20;
            projPos.x = xDisplace();
            projPos.y = yDisplace();
            tick = tick + 0.1;
            break;

    }
}

void _weapons::drawProj()
{
    glTranslatef(projPos.x, projPos.y, projPos.z);
    glScalef(projScale.x, projScale.y, projScale.z);
    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMax);
        glVertex3f(vert[0].x, vert[0].y, vert[0].z);
        glTexCoord2f(xMax, yMax);
        glVertex3f(vert[1].x, vert[1].y, vert[1].z);
        glTexCoord2f(xMax, yMin);
        glVertex3f(vert[2].x, vert[2].y, vert[2].z);
        glTexCoord2f(xMin, yMin);
        glVertex3f(vert[3].x, vert[3].y, vert[3].z);
    glEnd();
}
