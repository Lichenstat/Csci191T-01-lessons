#ifndef _PLAYER_H
#define _PLAYER_H

#include <_common.h>
#include <_texture.h>
#include <GL/gl.h>

class _player
{
    public:
        _player();
        virtual ~_player();

        vec3 playerPos;     // player position settings
        vec3 playerScale;   // size of the player
        vec3 vert[4];       // rectangle that we draw player on

        void playerInit();  // initialization of the player
        void drawPlayer();  // rendering the player
        void actions();     // actions

        _texture *plyImage = new _texture();

    protected:

    private:
};

#endif // _PLAYER_H
