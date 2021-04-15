#ifndef _OBJECTINTERACT_MAX_H
#define _OBJECTINTERACT_MAX_H

#include <_object_max.h>

// interaction class to have the ability to interact with various objects
class _objectinteract_max
{
    public:
        virtual ~_objectinteract_max();

        static void initialize(_object_max *, char *, float, float, float, float, float, float, char *, float, float);        // initialize object using (scaleX, scaleY, translationX, translationY, angle, coordrotZ, image, frames X, frames Y)
        static void changeScale(_object_max *, float, float);                                           // change the objects size if need be (size X, size Y)
        static void changePosition(_object_max *, float, float);                                        // change the objects position (translation) if need be (pos X, pos Y)
        static void changeAngle(_object_max *, float, float);                                           // change the objects angle if need be (angle, z coord (as far as i can tell coordrotZ > 0 just means a rotation in terms with the Z axis is enabled))
        static void changeImage(_object_max *, char *, float, float);                                   // change the objects image if need be (image, frames X, frames Y)
        static void updateRelativePosition(_object_max *, float, float);                                // change the relative position of objects (useful for movements in relation to player)
        static void draw(_object_max *);                                                                // draw the object every update possible
        static void deleteObject(_object_max *);                                                        // delete the object if necessary

    protected:

    private:
        _objectinteract_max();
};

#endif // _OBJECTINTERACT_MAX_H
