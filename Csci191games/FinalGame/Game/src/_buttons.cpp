#include "_buttons.h"

_buttons::_buttons()
{
    //ctor
    vert[0].x = -0.5; vert[0].y = -0.5;vert[0].z = -1.0;
    vert[1].x = 0.5; vert[1].y = -0.5;vert[1].z = -1.0;
    vert[2].x = 0.5; vert[2].y = 0.5;vert[2].z = -1.0;
    vert[3].x = -0.5; vert[3].y = 0.5;vert[3].z = -1.0;

    framesX = 1;
    framesY = 1;

    xMin = 0.0;
    xMax = 1/framesX;
    yMin = 0.0;
    yMax = 1/framesY;
}

_buttons::~_buttons()
{
    //dtor
}

void _buttons::drawButton(float xPos,float yPos,float zPos,float xScale,float yScale,float zScale)
{
    glTranslatef(xPos, yPos, zPos);
    glScalef(xScale,yScale,zScale);

    glBegin(GL_QUADS);
        // wrapping a quadrant, will divide sprite by sprite frames
        glTexCoord2f(xMin, yMax);
        glVertex3f(vert[0].x, vert[0].y, vert[0].z);
        glTexCoord2f(xMax, yMax);
        glVertex3f(vert[1].x, vert[1].y, vert[1].z);
        glTexCoord2f(xMax, yMin);
        glVertex3f(vert[2].x, vert[2].y, vert[2].z);
        glTexCoord2f(xMin, yMin);
        glVertex3f(vert[3].x, vert[3].y, vert[3].z);
    glEnd();

}
