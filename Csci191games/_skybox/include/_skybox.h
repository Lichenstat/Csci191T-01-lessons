#ifndef _SKYBOX_H
#define _SKYBOX_H

#include <_common.h>
#include <_texture.h>
#include <GL/gl.h>

class _skybox
{
    public:
        _skybox();
        virtual ~_skybox();

        void loadTexture();
        void drawBox();

        vec3 dim;           // dimensions for width (x) and height (y)
        vec3 rotations;     // rotate x, rotate y, rotate z axis
        vec3 translation;   // translate x, translate y, translate z

        _texture *walls = new _texture();

        GLuint tex[6];


    protected:

    private:
};

#endif // _SKYBOX_H
