#ifndef _INPUT_H
#define _INPUT_H

#include <windows.h>
#include <_model.h>
#include <_parallax.h>
#include <_player.h>
#include <_skybox.h>

class _input
{
    public:
        _input();
        virtual ~_input();
        void keyPressed(_model*);   //kick off when you press a key
        void keyPressed(_player*);  //kick off when you press a key

        void moveEnv(_parallax *, float);
        void keyUp(_player *);
        void keyUp();

        void mouseDown(_model*, float, float);
        void mouseUp();
        void mouseWheel(_model*, float);
        void mouseWheel(_skybox *, float);

        void mouseMove(_model*, float, float);
        void mouseMove(_skybox *, float, float);

        float prevMouseX;
        float prevMouseY;
        bool mouseTranslation;
        bool mouseRotate;

        WPARAM wParam;

    protected:

    private:
};

#endif // _INPUT_H
