#ifndef _PLATFROMS_H
#define _PLATFROMS_H

#include <_object_max.h>
#include <_objectinteract_max.h>
#include <_hitbox_max.h>

class _platfroms
{
    public:
        _platfroms();
        virtual ~_platfroms();

         _object_max *platform  = new _object_max();

        void initialize();
        void draw();
        void interact(_object_max *);

    protected:

    private:
};

#endif // _PLATFROMS_H
