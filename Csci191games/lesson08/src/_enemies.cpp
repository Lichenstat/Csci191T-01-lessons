#include "_enemies.h"

_enemies::_enemies()
{
    //ctor
    posE.x = posE.y = 0.0;
    posE.z = -8.0;

    sizeE.x = 0.1;
    sizeE.y = 0.0;

    rotateE.x = rotateE.y = rotateE.z = 0.0;

    numberOfFrames = 7;
    xMin = yMin = 0.0;
    xMax = 1/numberOfFrames;
    yMax = .5;

    speed  = 0.01;
    actions = 0;
}

_enemies::~_enemies()
{
    //dtor
}

void _enemies::drawEnms()
{
    if(isAlive)
    {
        glEnable(GL_COLOR_MATERIAL);
        glColor3f(1.0, 1.0, 1.0);
        //glMaterialf();

        glBindTexture(GL_TEXTURE_2D, tex);

        glPushMatrix();
            glTranslatef(posE.x, posE.y, posE.z);
            glRotatef(rotateE.x, 1.0, 0.0, 0.0);
            glRotatef(rotateE.y, 0.0, 1.0, 0.0);
            glRotatef(rotateE.z, 0.0, 0.0, 1.0);
            glScalef(sizeE.x, sizeE.y, 1.0);

            glBegin(GL_POLYGON);
                glTexCoord2f(xMin, yMin);
                glVertex3f(1.0, 1.0, 0.0);

                glTexCoord2f(xMax, yMin);
                glVertex3f(-1.0, 1.0, 0.0);

                glTexCoord2f(xMax, yMax);
                glVertex3f(-1.0, -1.0, 0.0);

                glTexCoord2f(xMin, yMax);
                glVertex3f(1.0, -1.0, 0.0);

            glEnd();
        glPopMatrix();
        glDisable(GL_COLOR_MATERIAL);
    }
}

void _enemies::placeEnms(vec3 inPos)
{
    // initialization process
    posE.x = inPos.x;
    posE.y = inPos.y;
    posE.z = inPos.z;

    eT -> startTimer();
}

void _enemies::actionsEnms()
{
    switch(actions)
    {

    case 0:
        if(eT -> getTicks() > 60)
        {
            // this is a sprite sheet assumed to be 7x2
            xMin += 1.0/numberOfFrames;
            xMax += 1.0/numberOfFrames;
            yMin = 0.0;
            yMax = 0.5;
            eT -> resetTime();
        }
    break;

    case(1):
                if(eT -> getTicks() > 60)
        {
            // this is a sprite sheet assumed to be 7x2
            xMin += 1.0/numberOfFrames;
            xMax += 1.0/numberOfFrames;
            yMin = 0.0;
            yMax = 0.5;
            eT -> resetTime();
        }
    break;
    }
}

