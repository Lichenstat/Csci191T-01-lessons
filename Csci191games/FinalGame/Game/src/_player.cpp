#include "_player.h"

_player::_player()
{
    //ctor

    vert[0].x = -0.5; vert[0].y = -0.5;vert[0].z = -1.0;
    vert[1].x = 0.5; vert[1].y = -0.5;vert[1].z = -1.0;
    vert[2].x = 0.5; vert[2].y = 0.5;vert[2].z = -1.0;
    vert[3].x = -0.5; vert[3].y = 0.5;vert[3].z = -1.0;
}

_player::~_player()
{
    //dtor
}

void _player::playerInit(float X, float Y)
{
    playerPos.x = 0.0;
    playerPos.y = 0.0;
    playerPos.z = -1.0;

    playerScale.x = 0.5;
    playerScale.y = 0.5;
    playerScale.z = 1.0;

    framesX = X;
    framesY = Y;

    xMin = 0.0;
    xMax = 1/framesX;
    yMin = 0.0;
    yMax = 1/framesY;
}

void _player::drawPlayer()
{
    glTranslatef(playerPos.x, playerPos.y, playerPos.z);
    glScalef(playerScale.x, playerScale.y, playerScale.z);
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

void _player::actions()
{
    switch(actionTrigger)
    {
        case STAND:
            xMin = xMin;
            xMax = xMax;
        break;

        case WALK:
            xMin += 1/framesX;
            xMax += 1/framesX;
            cout << "walking" << endl;
        break;

        case RUN:
            cout << "running" << endl;
        break;

        case JUMP:

        break;
    }
}
