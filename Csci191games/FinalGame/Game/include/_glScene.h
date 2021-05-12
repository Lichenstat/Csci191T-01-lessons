#ifndef _GLSCENE_H
#define _GLSCENE_H

#include <vector>
#include <random>
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <_model.h>
#include <_input.h>
#include <_texture.h>
#include <_parallax.h>
#include <_player.h>
#include <_timer.h>
#include <_enemies.h>
#include <_sounds.h>
#include <_fonts.h>

//Emmanuel's files
#include <_buttons.h>
#include <_platfroms.h>
// Max's h files
#include <_healthpack_max.h>
#include <_player_max.h>
#include <_hud.h>
#include <_mine.h>
#include <_turret.h>
//--------
//Eric's files
#include <_collision.h>
#include <_weapons.h>
//-----

using namespace std;

class _glScene
{
    public:
        _glScene();
        virtual ~_glScene();

        //current game state
        enum cgs{landing, menu, startGame, help, exit, levelOne, levelTwo, levelThree, credit };
        cgs state = levelThree;

        GLint initGL();
        GLint drawScene();
        void resizeGLScene(int, int);

        float screenWidth, screenHeight;

        bool doneLoading;

        _model *modelTeapot = new _model();
        _input *kbMS = new _input();
        _texture *modelTex = new _texture();

        _parallax *mainSceneBG= new _parallax();
        _parallax *creditSceneBG = new _parallax();
        _parallax *landingBG = new _parallax();

        //levelOne background
        _parallax *lvOskyBg = new _parallax();
        _parallax *lv0groundBg = new _parallax();
        _parallax *lvOfogBg = new _parallax();
        _parallax *lvOcloudOneBg = new _parallax();
        _parallax *lvOcloudTwoBg = new _parallax();
        _parallax *lvOsmallMountainsBg = new _parallax();
        _parallax *lvObigMountainsBg = new _parallax();
        _parallax *lvOsunBg = new _parallax();
        _parallax *lvOmountainBG = new _parallax();

        //levelTwo background
        _parallax *lv1cloudOneBg = new _parallax();
        _parallax *lv1cloudTwoBg = new _parallax();
        _parallax *lv1fogBg = new _parallax();
        _parallax *lv1mountainsBg = new _parallax();
        _parallax *lv1forestBg = new _parallax();
        _parallax *lv1groundBg = new _parallax();
        _parallax *lv1bigMountainBg = new _parallax();
        _parallax *lv1skyBg = new _parallax();

        //levelThree background
        _parallax *lv2airBg = new _parallax();
        _parallax *lv2cloudOneBg= new _parallax();
        _parallax *lv2cloudTwoBg = new _parallax();
        _parallax *lv2groundBg = new _parallax();
        _parallax *lv2bigMountainBg = new _parallax();
        _parallax *lv2mediumMountainBg = new _parallax();
        _parallax *lv2smallMountainBg = new _parallax();
        _parallax *lv2skyBg = new _parallax();
        _parallax *lv2starsBg = new _parallax();

        _player *myPly = new _player();
        _timer *timer = new _timer();
        _texture *texEnms = new _texture();
        _sounds *snds = new _sounds();
        _fonts *fnts = new _fonts();

        _buttons *startGameBtn = new _buttons();
        _buttons *helpBtn = new _buttons();
        _buttons *exitBtn = new _buttons();
        _buttons *backBtn = new _buttons();
        _buttons *creditBtn = new _buttons();

        _platfroms *firstPlatform = new _platfroms();

        float inRelationToPlayer; // move objects (items) in relation to player for kbMS->moveObj items

        // Max's addition to scene
        // these healthpacks are considered the objects used for testing
        _timer *itemTimer = new _timer();
        _player_max *player1 = new _player_max();
        _hud * hud = new _hud();
        _healthpack_max *healthpack1 = new _healthpack_max();
        _healthpack_max *healthpack2 = new _healthpack_max();

        vector<_mine*> mine1;
        vector<_mine*> mine2;
        vector<_mine*> mine3;

        vector<_turret*> turret1;
        vector<_turret*> turret2;
        vector<_turret*> turret3;
        //--------

        //Eric's addiions
        _weapons* wpns = new _weapons();
        _weapons* shockBulOne = new _weapons();
        _weapons* shockBulTwo = new _weapons();
        _weapons* grenadeBoom = new _weapons();
        _weapons* pistol = new _weapons();
        _weapons* grenadelauncher = new _weapons();
        _weapons* laserGun = new _weapons();
        _weapons* shockRifle = new _weapons();
        _collision* col = new _collision();
        //-------

        _enemies enms[20];

        int winMSG(HWND, UINT, WPARAM, LPARAM);
        WPARAM wParam;

        GLdouble posmX, posmY;

        void GetOGLPos(int x, int y)    // x and y as mouse coordinates
        {
            GLint viewport[4];          // to store viewpoint values
            GLdouble modelview[16];     // to store model values
            GLdouble projection[16];    // to store projection

            GLfloat winX, winY, winZ;   // windows coordinates
            GLdouble posX, posY, posZ;  // mapped mouse coordinates (output)

            glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
            glGetDoublev(GL_PROJECTION_MATRIX, projection);
            glGetIntegerv(GL_VIEWPORT, viewport);

            winX = (float)x;
            winY = (float)viewport[3] - (float)y;

            glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

            gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

            posmX = posX;
            posmY = posY;

        }

    protected:

    private:
};

#endif // _GLSCENE_H
