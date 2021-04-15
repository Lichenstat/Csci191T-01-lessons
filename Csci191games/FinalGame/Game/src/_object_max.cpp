#include "_object_max.h"

_object_max::_object_max()
{
    //ctor

    obj.scale.x = 1.0;                                              // scale of object to be used
    obj.scale.y = 1.0;
    obj.scale.z = 1.0;

    obj.pos.x = 0.0;                                                // position of object to be used
    obj.pos.y = 0.0;
    obj.pos.z = -1.0; //-1.0

    obj.angle = 0.0;                                                // coordrotation of object to be used
    obj.coordrot.x = 0.0;
    obj.coordrot.y = 0.0;
    obj.coordrot.z = 0.0;

    obj.image = "images/missingtexture.png";                        // set default image if no image is given

    obj.frames.x = 1;                                               // default frames for object
    obj.frames.y = 1;

    obj.hbsize = 0.25;                                               // hitbox default size (as radian)

    obj.touched = false;                                            // some extra object information
    obj.exist = true;
    obj.type = "unknown";

    obj.vert[0].x = -0.5; obj.vert[0].y = -0.5;obj.vert[0].z = -1.0;// setting object vertices for image projection
    obj.vert[1].x = 0.5; obj.vert[1].y = -0.5;obj.vert[1].z = -1.0;
    obj.vert[2].x = 0.5; obj.vert[2].y = 0.5;obj.vert[2].z = -1.0;
    obj.vert[3].x = -0.5; obj.vert[3].y = 0.5;obj.vert[3].z = -1.0;
}

_object_max::~_object_max()
{
    //dtor
}

void _object_max::objDraw()                                             // draw the object at hand
{
    glTranslatef(obj.pos.x, obj.pos.y, obj.pos.z);
    glScalef(obj.scale.x, obj.scale.y, obj.scale.z);
    glRotatef(obj.angle, obj.coordrot.x, obj.coordrot.y, obj.coordrot.z);
    //glColor3f(128.0, 0.0, 128.0);
    glBegin(GL_QUADS);
        // wrapping a quadrant, will divide sprite by sprite frames
        glTexCoord2f(obj.xMin, obj.yMax);
        glVertex3f(obj.vert[0].x, obj.vert[0].y, obj.vert[0].z);
        glTexCoord2f(obj.xMax, obj.yMax);
        glVertex3f(obj.vert[1].x, obj.vert[1].y, obj.vert[1].z);
        glTexCoord2f(obj.xMax, obj.yMin);
        glVertex3f(obj.vert[2].x, obj.vert[2].y, obj.vert[2].z);
        glTexCoord2f(obj.xMin, obj.yMin);
        glVertex3f(obj.vert[3].x, obj.vert[3].y, obj.vert[3].z);
    glEnd();
}
