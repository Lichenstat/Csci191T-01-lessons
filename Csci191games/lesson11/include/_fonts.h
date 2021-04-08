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

        void initFonts(char *);
        void buildFont(char *);
        void setPosition(int, int);
        void drawFonts();
        charSet chr[1024];
        int cCnt;

        float rotateX;
        float rotateY;
        float rotateZ;

        float xpos, ypos, zpos;

        _texture *charTex = new _texture();


    protected:

    private:
};

#endif // _FONTS_H
