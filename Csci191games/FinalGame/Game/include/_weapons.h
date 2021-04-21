#ifndef _WEAPONS_H
#define _WEAPONS_H

#include <_player.h>
#include <_object_max.h>
#include <_objectinteract_max.h>
#include <_hitbox_max.h>
#include <_collision.h>
#include <_texture.h>
#include <_common.h>
#include <_timer.h>
#include <cmath>
#include <GL/gl.h>
class _weapons
{
    public:
        _weapons();
        virtual ~_weapons();

        bool pickUpWeapons(_player*, _weapons*);
        vec3 weaponPos;
        //weapons we will be trying to use
        enum{MELEE, PISTOL, GRENADELAUNCHER, FLAMETHROWER, BEAM, SHOCKRIFLE};
        void weaponAction();   // This is basically going to be their bullet physics
        int action;
        int weaponDmg;      // This is going to be the amount of damage they can do

        //drawing our projectile and their positions
        void drawProj();
        _texture *proj = new _texture();
        void projInit(float, float);
        vec3 projPos;
        vec3 projScale;
        vec3 vert[4];
        float xMin, xMax, yMin, yMax;   // number of frames
        float framesX, framesY;   //number of frames



        //Physics, variables and equations for our projectiles
        float vel;              //Velocity
        float accel;            //Acceleration
        GLfloat angle;
        float xDisplace();      //Delta X
        float yDisplace();      //Delta Y
        float tick;             //time in ticks
        _collision *col = new _collision();     //checking collisions with enemies and walls.

    protected:

    private:
};

#endif // _WEAPONS_H
