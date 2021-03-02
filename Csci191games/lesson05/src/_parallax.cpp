#include "_parallax.h"

_parallax::_parallax()
{
    //ctor
    xMax = yMax = 1.0f;
    xMin = yMin = 0.0f;
}

_parallax::~_parallax()
{
    //dtor
}

void _parallax::renderBack(float width, float height)
{
    glColor3f(0.4, 0.3, 0.0);

    glBegin(GL_POLYGON);                    //type I want to draw
    glTexCoord2f(xMin, yMin);
    glVertex3f(-width/height, -1, -8.0);    //coordinates x, y, z
    glTexCoord2f(xMax, yMin);
    glVertex3f(width/height, -1, -8.0);
    glTexCoord2f(xMax, yMax);
    glVertex3f(width/height, 1, -8.0);
    glTexCoord2f(xMin, yMax);
    glVertex3f(-width/height, 1, -8.0);
    glEnd();
}

void _parallax::parallaxInit(char* filename)
{

}

void _parallax::scroll(bool autoScroll, string dir, float speed)
{

}

