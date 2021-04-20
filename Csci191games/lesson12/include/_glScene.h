#ifndef _GLSCENE_H
#define _GLSCENE_H

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
#include <_particles.h>

using namespace std;

class _glScene
{
    public:
        _glScene();
        virtual ~_glScene();

        GLint initGL();
        GLint drawScene();
        void resizeGLScene(int, int);

        float screenWidth, screenHeight;

        _model *modelTeapot = new _model();
        _input *kbMS = new _input();
        _texture *modelTex = new _texture();
        _parallax *background = new _parallax();
        _parallax *backgroundtwo = new _parallax();
        _player *myPly = new _player();
        _timer *timer = new _timer();
        _texture *texEnms = new _texture();
        _sounds *snds = new _sounds();
        _fonts *fnts = new _fonts();
        _particles *p = new _particles();

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
