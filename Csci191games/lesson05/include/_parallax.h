#ifndef _PARALLAX_H
#define _PARALLAX_H

#include <string>
#include <GL/gl.h>

using namespace std;

class _parallax
{
    public:
        _parallax();
        virtual ~_parallax();
        void renderBack(float, float);      // render background
        void parallaxInit(char *);
        void scroll(bool, string, float);

        float xMax, xMin, yMax, yMin;

    protected:

    private:
};

#endif // _PARALLAX_H
