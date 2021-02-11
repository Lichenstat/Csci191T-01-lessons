#ifndef _GLSCENE_H
#define _GLSCENE_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

class _glScene
{
    public:
        _glScene();
        virtual ~_glScene();

        GLint initGL();
        GLint drawScene();
        void resizeGLScene(int, int);

    protected:

    private:
};

#endif // _GLSCENE_H
