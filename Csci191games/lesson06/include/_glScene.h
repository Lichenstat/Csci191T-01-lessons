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

        int winMSG(HWND, UINT, WPARAM, LPARAM);
        WPARAM wParam;

    protected:

    private:
};

#endif // _GLSCENE_H
