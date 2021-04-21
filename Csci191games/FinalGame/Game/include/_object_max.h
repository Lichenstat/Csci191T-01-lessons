#ifndef _OBJECT_MAX_H
#define _OBJECT_MAX_H

#include <_common.h>
#include <_texture.h>
#include <GL/gl.h>
#include <iostream>
#include <typeinfo>

using namespace std;

// Object class to be used when needing to create an object of various kinds
class _object_max
{
    public:
        _object_max();                                          // default constructor
        virtual ~_object_max();

        objInfo_max obj;                                        // information on the object

        void objDraw();                                         // rendering the object

        _texture *objImage = new _texture();

    protected:

    private:

};

#endif // _OBJECT_MAX_H
