#ifndef _INPUT_H
#define _INPUT_H

#include <windows.h>
#include <_model.h>
#include <_parallax.h>
#include <_player.h>
#include <_sounds.h>

// Max's h files
#include <_object_max.h>
#include <_objectinteract_max.h>
#include <_animate_max.h>
#include <_player_max.h>
//-----------

// Eric's h files
#include <_weapons.h>
//-----------

class _input
{
    public:
        _input();
        virtual ~_input();
        void keyPressed(_model*);   //kick off when you press a key
        void keyPressed(_player*);  //kick off when you press a key
        void keyPressed(_sounds *);

        void moveEnv(_parallax *, float);
        void keyUp(_player *);
        void keyUp();

        // Max's additions to include file
        void moveObj(_object_max *, float);        // object defined movements
        void moveObj(_object_max * [], float);
        void movePly(_player_max *, float);        // player defined movements
        //--------

        // Eric's
        float anglesForShots(_weapons*, float, float);
        void mouseDown(_weapons*, float, float);                // firing our weapons
        //--------

        void mouseDown(_model*, float, float);
        void mouseUp();
        void mouseWheel(_model*, float);
        void mouseMove(_model*, float, float);

        float prevMouseX;
        float prevMouseY;
        bool mouseTranslation;
        bool mouseRotate;

        WPARAM wParam;

    protected:

    private:
};

#endif // _INPUT_H
