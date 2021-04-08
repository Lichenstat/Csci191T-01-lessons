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
    zpos = -2.0;
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
        case 'a':
            chr[cCnt].xMin = 0;
            chr[cCnt].xMax = 1.0/13.0;  // 13 because character length is 13 wide
            chr[cCnt].yMin = 3.0/7.0 + 0.5;
            chr[cCnt].yMax = 4.0/7.0 + 0.5;
        break;

        case 'A':
            chr[cCnt].xMin = 0;
            chr[cCnt].xMax = 1.0/13.0;  // 13 because character length is 13 wide
            chr[cCnt].yMin = 3.0/7.0;
            chr[cCnt].yMax = 4.0/7.0;
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

    glBegin(GL_QUADS);
    for(int i = 0; i < cCnt; i++)
    {
        glTexCoord2f(chr[cCnt].xMin, chr[cCnt].yMax);
        glVertex3f(0, 0, 0);
        glTexCoord2f(chr[cCnt].xMin, chr[cCnt].yMax);
        glVertex3f(0, 0, 0);
        glTexCoord2f(chr[cCnt].xMin, chr[cCnt].yMax);
        glVertex3f(0, 0, 0);
        glTexCoord2f(chr[cCnt].xMin, chr[cCnt].yMax);
        glVertex3f(0, 0, 0);
    }

    glEnd();

    glPopMatrix();


}


