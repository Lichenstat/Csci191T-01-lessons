#ifndef _MAINSCENE_H
#define _MAINSCENE_H

#include <_common.h>
#include <_texture.h>
class _mainScene
{
    public:
        _mainScene();
        virtual ~_mainScene();

        vec3 startGBoxPos;                 // player position settings
        vec3 startGBoxScale;

        vec3 vert[4];   //box where we draw

        void drawStartGBox();

        float xMin, xMax, yMin, yMax;
        float framesX, framesY;

        _texture *startGBoxTex = new _texture();

    protected:

    private:
};

#endif // _MAINSCENE_H
