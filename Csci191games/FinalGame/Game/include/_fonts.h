#ifndef _FONTS_H
#define _FONTS_H

#include <iostream>
#include <string.h>
#include <_common.h>
#include <_texture.h>
using namespace std;

class _fonts
{
    public:
        _fonts();
        virtual ~_fonts();

        void initFonts(char *);     //This is where we will include our font
        void buildFont(char *);
        void setPosition(int, int); //Use pixel positions
        void drawFonts();

        charSet chr[1024];          //An array of characters, basically a string that is 1024 long
        int cCount;

        float rotateX;
        float rotateY;
        float rotateZ;              //Z is just in case
        float xPos, yPos, zPos;

        _texture *charTex = new _texture();
    protected:

    private:
};

#endif // _FONTS_H
