#ifndef _BUTTONS.H
#define _BUTTONS_H

#include <_common.h>
#include <_texture.h>
class _buttons
{
    public:
        _buttons();
        virtual ~_buttons();

        vec3 vert[4];   //box where we draw

        void drawButton(float,float,float,float,float,float);

        float xMin, xMax, yMin, yMax;
        float framesX, framesY;

        _texture *startGBtnTex = new _texture();
        _texture *helpBtnTex = new _texture();
        _texture *exitBtnTex = new _texture();
        _texture *backBtnTex = new _texture();
        _texture *creditBtnTex = new _texture();

    protected:

    private:
};

#endif // _BUTTONS.h
