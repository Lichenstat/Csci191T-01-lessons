#include "_fonts.h"

_fonts::_fonts()
{
    //ctor
    cCount = 0;
    rotateX = 0;
    rotateY = 0;
    rotateZ = 0;

    xPos = 0.0;
    yPos = 2.0;
    zPos = -0.9; //This is zoom
}

_fonts::~_fonts()
{
    //dtor
}
void _fonts::initFonts(char* fileName)
{
    charTex->loadTexture(fileName);     //(fonts/font2.png)
}

void _fonts::buildFont(char* str)
{
    for(int i = 0; i < strlen(str); i++){
        switch(str[i]){
            case 'A':
                chr[cCount].xMin = 0;
                chr[cCount].xMax = 1.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'B':
                chr[cCount].xMin = 1.0/12.0;
                chr[cCount].xMax = 2.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'C':
                chr[cCount].xMin = 2.0/12.0;
                chr[cCount].xMax = 3.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'D':
                chr[cCount].xMin = 3.0/12.0;
                chr[cCount].xMax = 4.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'E':
                chr[cCount].xMin = 4.0/12.0;
                chr[cCount].xMax = 5.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'F':
                chr[cCount].xMin = 5.0/12.0;
                chr[cCount].xMax = 6.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'G':
                chr[cCount].xMin = 6.0/12.0;
                chr[cCount].xMax = 7.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'H':
                chr[cCount].xMin = 7.0/12.0;
                chr[cCount].xMax = 8.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'I':
                chr[cCount].xMin = 8.0/12.0;
                chr[cCount].xMax = 9.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'J':
                chr[cCount].xMin = 9.0/12.0;
                chr[cCount].xMax = 10.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'K':
                chr[cCount].xMin = 10.0/12.0;
                chr[cCount].xMax = 11.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'L':
                chr[cCount].xMin = 11.0/12.0;
                chr[cCount].xMax = 12.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 0;
                chr[cCount].yMax = 1.0/8.0;
                break;
            case 'M':
                chr[cCount].xMin = 0;
                chr[cCount].xMax = 1.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'N':
                chr[cCount].xMin = 1.0/12.0;
                chr[cCount].xMax = 2.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'O':
                chr[cCount].xMin = 2.0/12.0;
                chr[cCount].xMax = 3.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'P':
                chr[cCount].xMin = 3.0/12.0;
                chr[cCount].xMax = 4.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'Q':
                chr[cCount].xMin = 4.0/12.0;
                chr[cCount].xMax = 5.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'R':
                chr[cCount].xMin = 5.0/12.0;
                chr[cCount].xMax = 6.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'S':
                chr[cCount].xMin = 6.0/12.0;
                chr[cCount].xMax = 7.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'T':
                chr[cCount].xMin = 7.0/12.0;
                chr[cCount].xMax = 8.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'U':
                chr[cCount].xMin = 8.0/12.0;
                chr[cCount].xMax = 9.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'V':
                chr[cCount].xMin = 9.0/12.0;
                chr[cCount].xMax = 10.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'W':
                chr[cCount].xMin = 10.0/12.0;
                chr[cCount].xMax = 11.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'X':
                chr[cCount].xMin = 11.0/12.0;
                chr[cCount].xMax = 12.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 1.0/8.0;
                chr[cCount].yMax = 2.0/8.0;
                break;
            case 'Y':
                chr[cCount].xMin = 0;
                chr[cCount].xMax = 1.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'Z':
                chr[cCount].xMin = 1.0/12.0;
                chr[cCount].xMax = 2.0/12.0;    //Positions of the fonts on my sprite sheet
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;


            case 'a':
                chr[cCount].xMin = 2.0/12.0;
                chr[cCount].xMax = 3.0/12.0;
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'b':
                chr[cCount].xMin = 3.0/12.0;
                chr[cCount].xMax = 4.0/12.0;
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'c':
                chr[cCount].xMin = 4.0/12.0;
                chr[cCount].xMax = 5.0/12.0;
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'd':
                chr[cCount].xMin = 5.0/12.0;
                chr[cCount].xMax = 6.0/12.0;
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'e':
                chr[cCount].xMin = 6.0/12.0;
                chr[cCount].xMax = 7.0/12.0;
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'f':
                chr[cCount].xMin = 7.0/12.0;
                chr[cCount].xMax = 8.0/12.0;
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'g':
                chr[cCount].xMin = 8.0/12.0;
                chr[cCount].xMax = 9.0/12.0;
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'h':
                chr[cCount].xMin = 9.0/12.0;
                chr[cCount].xMax = 10.0/12.0;
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'i':
                chr[cCount].xMin = 10.0/12.0;
                chr[cCount].xMax = 11.0/12.0;
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'j':
                chr[cCount].xMin = 11.0/12.0;
                chr[cCount].xMax = 12.0/12.0;
                chr[cCount].yMin = 2.0/8.0;
                chr[cCount].yMax = 3.0/8.0;
                break;
            case 'k':
                chr[cCount].xMin = 0;
                chr[cCount].xMax = 1.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 'l':
                chr[cCount].xMin = 1.0/12.0;
                chr[cCount].xMax = 2.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 'm':
                chr[cCount].xMin = 2.0/12.0;
                chr[cCount].xMax = 3.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 'n':
                chr[cCount].xMin = 3.0/12.0;
                chr[cCount].xMax = 4.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 'o':
                chr[cCount].xMin = 4.0/12.0;
                chr[cCount].xMax = 5.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 'p':
                chr[cCount].xMin = 5.0/12.0;
                chr[cCount].xMax = 6.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 'q':
                chr[cCount].xMin = 6.0/12.0;
                chr[cCount].xMax = 7.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 'r':
                chr[cCount].xMin = 7.0/12.0;
                chr[cCount].xMax = 8.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 's':
                chr[cCount].xMin = 8.0/12.0;
                chr[cCount].xMax = 9.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 't':
                chr[cCount].xMin = 9.0/12.0;
                chr[cCount].xMax = 10.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 'u':
                chr[cCount].xMin = 10.0/12.0;
                chr[cCount].xMax = 11.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 'v':
                chr[cCount].xMin = 11.0/12.0;
                chr[cCount].xMax = 12.0/12.0;
                chr[cCount].yMin = 3.0/8.0;
                chr[cCount].yMax = 4.0/8.0;
                break;
            case 'w':
                chr[cCount].xMin = 0;
                chr[cCount].xMax = 1.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case 'x':
                chr[cCount].xMin = 1.0/12.0;
                chr[cCount].xMax = 2.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case 'y':
                chr[cCount].xMin = 2.0/12.0;
                chr[cCount].xMax = 3.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case 'z':
                chr[cCount].xMin = 3.0/12.0;
                chr[cCount].xMax = 4.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;

            case '0':
                chr[cCount].xMin = 4.0/12.0;
                chr[cCount].xMax = 5.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case '1':
                chr[cCount].xMin = 5.0/12.0;
                chr[cCount].xMax = 6.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case '2':
                chr[cCount].xMin = 6.0/12.0;
                chr[cCount].xMax = 7.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case '3':
                chr[cCount].xMin = 7.0/12.0;
                chr[cCount].xMax = 8.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case '4':
                chr[cCount].xMin = 8.0/12.0;
                chr[cCount].xMax = 9.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case '5':
                chr[cCount].xMin = 9.0/12.0;
                chr[cCount].xMax = 10.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case '6':
                chr[cCount].xMin = 10.0/12.0;
                chr[cCount].xMax = 11.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case '7':
                chr[cCount].xMin = 11.0/12.0;
                chr[cCount].xMax = 12.0/12.0;
                chr[cCount].yMin = 4.0/8.0;
                chr[cCount].yMax = 5.0/8.0;
                break;
            case '8':
                chr[cCount].xMin = 0;
                chr[cCount].xMax = 1.0/12.0;
                chr[cCount].yMin = 5.0/8.0;
                chr[cCount].yMax = 6.0/8.0;
                break;
            case '9':
                chr[cCount].xMin = 1.0/12.0;
                chr[cCount].xMax = 2.0/12.0;
                chr[cCount].yMin = 5.0/8.0;
                chr[cCount].yMax = 6.0/8.0;
                break;

            case '.':
                chr[cCount].xMin = 2.0/12.0;
                chr[cCount].xMax = 3.0/12.0;
                chr[cCount].yMin = 5.0/8.0;
                chr[cCount].yMax = 6.0/8.0;
                break;
            case ',':
                chr[cCount].xMin = 3.0/12.0;
                chr[cCount].xMax = 4.0/12.0;
                chr[cCount].yMin = 5.0/8.0;
                chr[cCount].yMax = 6.0/8.0;
                break;
            case '?':
                chr[cCount].xMin = 6.0/12.0;
                chr[cCount].xMax = 7.0/12.0;
                chr[cCount].yMin = 5.0/8.0;
                chr[cCount].yMax = 6.0/8.0;
                break;
            case '!':
                chr[cCount].xMin = 7.0/12.0;
                chr[cCount].xMax = 8.0/12.0;
                chr[cCount].yMin = 5.0/8.0;
                chr[cCount].yMax = 6.0/8.0;
                break;
            case '&':
                chr[cCount].xMin = 0;
                chr[cCount].xMax = 1.0/12.0;
                chr[cCount].yMin = 6.0/8.0;
                chr[cCount].yMax = 7.0/8.0;
                break;
            case ' ':
                chr[cCount].xMin = 6.0/12.0;
                chr[cCount].xMax = 7.0/12.0;
                chr[cCount].yMin = 7.0/8.0;
                chr[cCount].yMax = 8.0/8.0;
                break;

        }
        cCount++;
    }
}

void _fonts::setPosition(int, int)
{
    //place xPos, yPos, and zPos
}

void _fonts::drawFonts()
{
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, charTex->tex);
        for(int i = 0; i < cCount; i++){
            glLoadIdentity();
            glTranslatef(xPos+i/13.0 * 2, yPos, zPos);
            glScalef(2,2,0);

            glBegin(GL_QUADS);
            glTexCoord2f(chr[i].xMin, chr[i].yMax);
            glVertex3f(0, 0, 0);

            glTexCoord2f(chr[i].xMax, chr[i].yMax);
            glVertex3f(1.0/12.0, 0, 0);

            glTexCoord2f(chr[i].xMax, chr[i].yMin);
            glVertex3f(1.0/12.0, 1.0/8.0, 0);

            glTexCoord2f(chr[i].xMin, chr[i].yMin);
            glVertex3f(0, 1.0/8.0, 0);
            glEnd();
            }

    glPopMatrix();
}
