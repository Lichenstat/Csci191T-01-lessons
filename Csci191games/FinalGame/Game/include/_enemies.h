#ifndef _ENEMIES_H
#define _ENEMIES_H

#include <_common.h>
#include <_timer.h>
#include <GL/gl.h>

class _enemies
{
    public:
        _enemies();
        virtual ~_enemies();

        void drawEnms();        // draw enemies (render)
        void placeEnms(vec3);   // x,y,z positions (placements)
        void actionsEnms();     // movements

        vec3 posE;              // Position of enemies
        vec2 sizeE;             // size of the enem(ies)
        vec3 rotateE;           // rotate enemies (enms)

        int numberOfFrames;
        int actions;            // action trigger
        float speed;

        GLuint tex;
        bool isAlive = true;

        _timer *eT = new _timer();  // to keep animations at one speed

    protected:

    private:
        float xMax, yMax, xMin, yMin;
};

#endif // _ENEMIES_H
