#ifndef _PLAYER_H
#define _PLAYER_H

#include <_common.h>
#include <_texture.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;
// using namespace cout, endl;

class _player
{
    public:
        _player();
        virtual ~_player();

        enum {STAND, WALK, RUN, JUMP};

        int actionTrigger;

        vec3 playerPos;                 // player position settings
        vec3 playerScale;               // size of the player
        vec3 vert[4];                   // rectangle that we draw player on

        void playerInit(float, float);  // initialization of the player
                                        // pass x # of frames, pass y # of frames
        void drawPlayer();              // rendering the player
        void actions();                 // actions

        float xMin, xMax, yMin, yMax;
        float framesX, framesY;

        _texture *plyImage = new _texture();

    protected:

    private:
};

#endif // _PLAYER_H
