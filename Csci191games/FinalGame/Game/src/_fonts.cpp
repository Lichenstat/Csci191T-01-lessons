#include "_fonts.h"

_fonts::_fonts()
{
    //ctor
    cCnt = 0;
    rotateX = 0;
    rotateY = 0;
    rotateZ = 0;

    xpos = 1.5;
    ypos = 0.5;
    zpos = -1.0;
}

_fonts::~_fonts()
{
    //dtor
}
void _fonts::initFonts(char* filename)
{
    charTex->loadTexture(filename);
}

void _fonts::buildFont(char* str)
{
    for(int i=0; i < strlen(str); i++)
    {
        switch(str[i])
        {
        case 'a':                       // this is all set for the specific font sheet given in images
            chr[cCnt].xMin = 0;
            chr[cCnt].xMax = 1.0/13.0;  // 13 because character length is 13 wide
            chr[cCnt].yMin = 2.3/8.0;
            chr[cCnt].yMax = 3.3/8.0;
        break;

        case 'A':
            chr[cCnt].xMin = 0;
            chr[cCnt].xMax = 1.0/13.0;  // 13 because character length is 13 wide
            chr[cCnt].yMin = 0.0/7.0;
            chr[cCnt].yMax = 1.0/7.0;
        break;
        }
        cCnt++;
    }
}

void _fonts::setPosition(int, int)
{
    //place xpos, ypos, zpos
}

void _fonts::drawFonts()
{

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, charTex->tex);

    for(int i = 0; i < cCnt; i++)
    {
        glLoadIdentity();
        glTranslatef(xpos+i, ypos, zpos);
        //glScalef(3.0, 3.0, 1.0);
        glBegin(GL_QUADS);
        glTexCoord2f(chr[i].xMax, chr[i].yMin);
        glVertex3f(1.0, 1.0, 0);
        glTexCoord2f(chr[i].xMin, chr[i].yMin);
        glVertex3f(0.0, 1.0, 0);
        glTexCoord2f(chr[i].xMin, chr[i].yMax);
        glVertex3f(0.0, 0.0, 0);
        glTexCoord2f(chr[i].xMax, chr[i].yMax);
        glVertex3f(1.0, 0.0, 0);
        glEnd();
    }

    glPopMatrix();

}


