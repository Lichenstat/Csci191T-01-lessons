#include "_skybox.h"

_skybox::_skybox()
{
    //ctor
    rotations.x = 0.0;
    rotations.y = 0.0;
    rotations.z = 0.0;

    translation.x = 0.0;
    translation.y = 0.0;
    translation.z = 0.0;
}

_skybox::~_skybox()
{
    //dtor
}

void _skybox::loadTexture()
{
    // front skybox
    walls->loadTexture("images/skybox/front.jpg");
    tex[0] = walls->tex;
    // backside skybox
    walls->loadTexture("images/skybox/back.jpg");
    tex[1] = walls->tex;
    // top skybox
    walls->loadTexture("images/skybox/top.jpg");
    tex[2] = walls->tex;
    // bottom skybox
    walls->loadTexture("images/skybox/bottom.jpg");
    tex[3] = walls->tex;
    // left skybox
    walls->loadTexture("images/skybox/left.jpg");
    tex[4] = walls->tex;
    // right skybox
    walls->loadTexture("images/skybox/right.jpg");
    tex[5] = walls->tex;
}

void _skybox::drawBox()
{
    glPushMatrix();
    glDisable(GL_NORMALIZE);
    glDisable(GL_LIGHTING);
    glRotatef(rotations.x, 1, 0, 0);
    glRotatef(rotations.y, 0, 1, 0);
    glRotatef(rotations.z, 0, 0, 1);

    glTranslatef(translation.x, translation.y, translation.z);


    //front wall
    glBindTexture(GL_TEXTURE_2D, tex[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, 1.0, 1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, -1.0, 1.0);
    glEnd();

    //back wall
    glBindTexture(GL_TEXTURE_2D, tex[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, 1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, -1.0, -1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, 1.0, -1.0);
    glEnd();

    //top wall
    glBindTexture(GL_TEXTURE_2D, tex[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, 1.0, 1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 1.0, -1.0);
    glEnd();

    //bottom wall
    glBindTexture(GL_TEXTURE_2D, tex[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, -1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
    glEnd();

    //right wall
    glBindTexture(GL_TEXTURE_2D, tex[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, -1.0, -1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(1.0, 1.0, 1.0);
    glEnd();

    //left wall
    glBindTexture(GL_TEXTURE_2D, tex[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, 1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, 1.0, 1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, -1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, -1.0, -1.0);
    glEnd();

    glEnable(GL_NORMALIZE);
    glDisable(GL_LIGHTING);
    glPopMatrix();
}
