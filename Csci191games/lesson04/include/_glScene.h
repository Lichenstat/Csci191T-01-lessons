#ifndef _GLSCENE_H
#define _GLSCENE_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <_model.h>
#include <_input.h>

using namespace std;

class _glScene
{
    public:
        _glScene();
        virtual ~_glScene();

        GLint initGL();
        GLint drawScene();
        void resizeGLScene(int, int);

        _model *modelTeapot = new _model();
        _input *kbMS = new _input();

        int winMSG(HWND, UINT, WPARAM, LPARAM);
        WPARAM wParam;

    protected:

    private:
};

#endif // _GLSCENE_H
