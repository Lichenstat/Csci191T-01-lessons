#ifndef _HUD_H
#define _HUD_H

#include <_object_max.h>
#include <_objectinteract_max.h>

class _hud
{
    public:
        _hud();
        virtual ~_hud();

        // creation of the healthbar
        _object_max * healthbarBack = new _object_max();
        _object_max * healthbarMiddle = new _object_max();
        _object_max * healthbarFront = new _object_max();
        float hbxscale;         // heathbar x scale

        void initialize();      // initialize hud objects
        void draw();            // draw hud items
        void interact(float);   // to interact with hud items (health)

    protected:

    private:
};

#endif // _HUD_H
