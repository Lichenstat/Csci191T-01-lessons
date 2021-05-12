#ifndef _WEAPONS_H
#define _WEAPONS_H

#include <_player.h>
#include <_object_max.h>
#include <_objectinteract_max.h>
#include <_hitbox_max.h>
#include <_texture.h>
#include <_common.h>
#include <_timer.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <GL/gl.h>
#include <_sounds.h>
class _weapons
{
    public:
        _weapons();
        virtual ~_weapons();
        void weaponSpawn(_object_max*, _weapons*);

        //weapons we will be trying to use -> these are the projectiles
        enum{PISTOL, GRENADELAUNCHER, BEAM, SHOCKRIFLE};
        //These are the actual weapons
        enum{P, G, B, S};
        void weaponAction(_object_max* ply);   // This is basically going to be their bullet physics
        int action;
        int weaponHold;
        int weaponDmg;      // This is going to be the amount of damage they can do

        //drawing our projectiles and weapons and their positions
        void drawProj();
        void drawShock();
        void drawWeapon();
        _texture *proj = new _texture();
        void projInit(float, float);
        vec3 projPos;
        vec3 projScale;
        _texture *weaponSkin = new _texture();
        vec3 weaponPos;
        vec3 weaponScale;
        vec3 vert[4];
        float xMin, xMax, yMin, yMax;   // number of frames
        float framesX, framesY;   //number of frames
        bool active;



        //Physics, variables and equations for our projectiles
        float vel;              //Velocity
        float accel;            //Acceleration
        GLfloat angle;
        GLfloat rotateAngle;
        float xDisplace();      //Delta X
        float yDisplace();      //Delta Y
        float tick;             //time in ticks
        float weaponFall();
        int onlyOnceP;
        int onlyOnceG;
        int onlyOnceB;
        int onlyOnceS;
        void toOrigin(_object_max*);
        void hitToOrigin(_object_max*);
        float xClicker;
        float yClicker;

        _sounds* snds = new _sounds();

        void explode();
    protected:

    private:
};

#endif // _WEAPONS_H
