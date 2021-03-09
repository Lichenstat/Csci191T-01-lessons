#include "_player.h"

_player::_player()
{
    //ctor

    vert[0].x = 0.0; vert[0].y = 0.0;vert[0].z = -1.0;
    vert[1].x = 1.0; vert[1].y = 0.0;vert[1].z = -1.0;
    vert[2].x = 1.0; vert[2].y = 1.0;vert[2].z = -1.0;
    vert[3].x = 0.0; vert[3].y = 1.0;vert[3].z = -1.0;

}

_player::~_player()
{
    //dtor
}

void _player::playerInit()
{
    playerPos.x = -1.0;
    playerPos.y = -0.5;
    playerPos.z = -1.0;

    playerScale.x = 1.0;
    playerScale.y = 1.0;
    playerScale.z = 1.0;
}

void _player::drawPlayer()
{
    glTranslatef(playerPos.x, playerPos.y, playerPos.z);
    glScalef(playerScale.x, playerScale.y, playerScale.z);
    glBegin(GL_QUADS);

        // wrapping a quadrant
        glTexCoord2f(0.0, 1.0);
        glVertex3f(vert[0].x, vert[0].y, vert[0].z);
        glTexCoord2f(1.0, 1.0);
        glVertex3f(vert[1].x, vert[1].y, vert[1].z);
        glTexCoord2f(1.0, 0.0);
        glVertex3f(vert[2].x, vert[2].y, vert[2].z);
        glTexCoord2f(0.0, 1.0);
        glVertex3f(vert[3].x, vert[3].y, vert[3].z);
    glEnd();
}

void _player::actions()
{

}
