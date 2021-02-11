#include "_glScene.h"
#include <_glLight.h>

_glScene::_glScene()
{
    //ctor
}

_glScene::~_glScene()
{
    //dtor
}

GLint _glScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_COLOR_MATERIAL);
    _glLight myLight(GL_LIGHT0);
}

GLint _glScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.6f, 0.1f, 0.2f, 0.3f); // change this if you want to change color of scene
    glLoadIdentity();

    glTranslated(0, 0, -8);     // place in the scene
    glColor3f(1.0, 0.3, 0.2);   // set a color to the object

    glPushMatrix();             // group my object
    glutSolidTeapot(1.5);       // draw object
    glPopMatrix();              // exit the group

}

void _glScene::resizeGLScene(int width, int height)
{
    float aspectRatio = (float)width/(float)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspectRatio, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
