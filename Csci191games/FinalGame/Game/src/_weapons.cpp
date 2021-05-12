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
    active = false;
    srand(time(NULL));
    onlyOnceP = 0;
    onlyOnceG = 0;
    onlyOnceB = 0;
    onlyOnceS = 0;

}

_weapons::~_weapons()
{
    //dtor
}
void _weapons::projInit(float x, float y)
{
    projPos.x = 15.0;
    projPos.y = -5.0;
    projPos.z = -9.0;
    projScale.x = 0.2;
    projScale.y = 0.2;
    projScale.z = 1.0;

    weaponPos.x = 15.0;
    weaponPos.y = -5.0;
    weaponPos.z = -9.0;
    weaponScale.x = 0.3;
    weaponScale.y = 0.3;
    weaponScale.z = 1.0;

    framesX = x;
    framesY = y;
    xMin = 0.0;
    xMax = 1.0/framesX;
    yMin = 0.0;
    yMax = 1.0/framesY;
}

//math----
float _weapons::xDisplace()
{
    if(active){
        projPos.z = 1.0;
        if(xClicker < 767.5){
            projPos.x = projPos.x - abs(cos(angle) * vel);
        }
        else{
            projPos.x = projPos.x + abs(cos(angle) * vel);
        }
    }
    return projPos.x;
}

float _weapons::yDisplace()
{
    if(active){
        if(yClicker > 685)
            projPos.y = projPos.y - abs(sin(angle) * vel) - abs(sin(angle) * (accel * tick * tick) / 2.0);
        else
            projPos.y = projPos.y + abs(sin(angle) * vel) - abs(sin(angle) * (accel * tick * tick) / 2.0);
    }

    return projPos.y;
}

void _weapons::toOrigin(_object_max* ply)   //out of bounds function
{
    if(projPos.x < -5.0 || projPos.x > 5.0 || (projPos.y - 0.01) < -2.5 || projPos.y > (3.5)){
        if(projPos.y - 0.01 < -2.5 && action == GRENADELAUNCHER){
            snds->playSounds("sounds/boomNoise.mp3");
            tick = 0.0;
        }
        projPos.x = ply->obj.pos.x;
        projPos.y = ply->obj.pos.y - 0.1;
        projPos.z = -9.0;
        active = false;
    }
}

void _weapons::hitToOrigin(_object_max* ply)
{
    if(active){
        if(action == GRENADELAUNCHER){
            snds->playSounds("sounds/boomNoise.mp3");
        }
        active = false;
    }
    tick = 0.0;
    projPos.x = ply->obj.pos.x;
    projPos.y = ply->obj.pos.y - 0.1;
    projPos.z = -9.0;
}

//end of math----
void _weapons::weaponAction(_object_max* ply)
{
    if(active){
        switch(action){
            case PISTOL:
                tick = 0.0;
                projPos.x = xDisplace();
                projPos.y = yDisplace();
                toOrigin(ply);
                break;
            case GRENADELAUNCHER:
                xMin += 1/framesX;  //This our frame changing and allows our ball to roll.
                xMax += 1/framesX;
                projPos.x = xDisplace();
                projPos.y = yDisplace();
                if(active){
                    tick = tick + 0.1;
                }
                toOrigin( ply);
                break;
            case BEAM:
                tick = 0.0;
                projPos.x = xDisplace();
                projPos.y = yDisplace();
                toOrigin(ply);
                break;
            case SHOCKRIFLE:
                tick = 0.0;
                projPos.x = xDisplace();
                projPos.y = yDisplace();
                toOrigin(ply);
                break;
        }
    }
    else{
        hitToOrigin(ply);
    }
}

void _weapons::drawProj()
{
    glPushMatrix();
        glTranslatef(projPos.x, projPos.y, projPos.z);
        glRotatef(rotateAngle, 0.0f, 0.0f, 1.0f);
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
    glPopMatrix();
}

void _weapons::drawShock()
{
    glPushMatrix();
        glTranslatef(projPos.x, projPos.y, projPos.z);
        glRotatef(rotateAngle, 0.0f, 0.0f, 1.0f);
        glScalef(projScale.x, projScale.y, projScale.z);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 1);
            glVertex3f(vert[3].x, vert[3].y, vert[3].z);
            glTexCoord2f(1, 1);
            glVertex3f(vert[2].x, vert[2].y, vert[2].z);
            glTexCoord2f(1, 0);
            glVertex3f(vert[1].x, vert[1].y, vert[1].z);
            glTexCoord2f(0, 0);
            glVertex3f(vert[0].x, vert[0].y, vert[0].z);
        glEnd();
    glPopMatrix();
}

void _weapons::drawWeapon()
{
    glPushMatrix();
        glTranslatef(weaponPos.x, weaponPos.y, weaponPos.z);
        glScalef(weaponScale.x, weaponScale.y, weaponScale.z);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 1);
            glVertex3f(vert[0].x, vert[0].y, vert[0].z);
            glTexCoord2f(1, 1);
            glVertex3f(vert[1].x, vert[1].y, vert[1].z);
            glTexCoord2f(1, 0);
            glVertex3f(vert[2].x, vert[2].y, vert[2].z);
            glTexCoord2f(0, 0);
            glVertex3f(vert[3].x, vert[3].y, vert[3].z);
        glEnd();
    glPopMatrix();
}


void _weapons::weaponSpawn(_object_max* obj, _weapons* wpn)
{
    int randomSpawner = rand()%101 + 1;
    if(obj->obj.exist == false){
        switch(weaponHold){
            case P:
            if(randomSpawner < 50 && onlyOnceP == 0){
                wpn->weaponPos.x = obj->obj.pos.x;
                wpn->weaponPos.y = obj->obj.pos.y;
                wpn->weaponPos.z = 1.0;
                onlyOnceP++;
                drawWeapon();
            }
            break;
            case G:
            if(randomSpawner < 50 && onlyOnceG == 0){
                wpn->weaponPos.x = obj->obj.pos.x;
                wpn->weaponPos.y = obj->obj.pos.y;
                wpn->weaponPos.z = 1.0;
                onlyOnceG++;
                drawWeapon();
            }
            break;
            case B:
            if(randomSpawner < 50 && onlyOnceB == 0){
                wpn->weaponPos.x = obj->obj.pos.x;
                wpn->weaponPos.y = obj->obj.pos.y;
                wpn->weaponPos.z = 1.0;
                onlyOnceB++;
                drawWeapon();
            }
            break;
            case S:
            if(randomSpawner < 50 && onlyOnceS == 0){
                wpn->weaponPos.x = obj->obj.pos.x;
                wpn->weaponPos.y = obj->obj.pos.y;
                wpn->weaponPos.z = 1.0;
                onlyOnceS++;
                drawWeapon();
            }
            break;
        }
    }
}

float _weapons::weaponFall()
{;
    vel = -0.075;
    if(weaponPos.y - 0.1 >= -2.4){
        weaponPos.y = weaponPos.y + vel;
    }
    return weaponPos.y;
}

void _weapons::explode()
{
    if(projPos.z == -9.0){
        xMin = 0.0;
        xMax = 1.0/framesX;
        yMin = 0.0;
        yMax = 1.0/framesY;
    }
    if(projPos.z != -9.0){
        xMin += 1/framesX;
        xMax += 1/framesX;
        if(xMax == 1.0){
            xMin = 0;
            xMax = 1/framesX;
            yMin += 1/framesY;
            yMax += 1/framesY;
        }
        if(yMax == 1.0 && xMax == 1.0){
            projPos.z == -9.0;
        }
    }
}



