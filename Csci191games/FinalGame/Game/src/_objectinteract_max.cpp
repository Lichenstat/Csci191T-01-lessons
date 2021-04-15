#include "_objectinteract_max.h"

_objectinteract_max::_objectinteract_max()
{
    //ctor
}

_objectinteract_max::~_objectinteract_max()
{
    //dtor
}

void _objectinteract_max::initialize(_object_max *curObj, char *type, float scaleX, float scaleY, float posX, float posY, float angle, float coordrotZ, char *image, float framesX, float framesY) // initialize the object with desired values
{
    curObj->obj.type = type;
    curObj->obj.id = (unsigned int)&curObj;
    changeScale(curObj, scaleX, scaleY);
    changePosition(curObj, posX, posY);
    changeAngle(curObj, angle, coordrotZ);
    changeImage(curObj, image, framesX, framesY);
}

void _objectinteract_max::changeScale(_object_max *curObj, float scaleX, float scaleY) // change the scale of the object
{
    curObj->obj.scale.x = scaleX;
    curObj->obj.scale.y = scaleY;
}

void _objectinteract_max::changePosition(_object_max *curObj, float posX, float posY)  // change the position of the object
{
    curObj->obj.pos.x = posX;
    curObj->obj.pos.y = posY;
}

void _objectinteract_max::changeAngle(_object_max *curObj, float angle, float coordrotZ)   // change the angle of the object
{
    curObj->obj.angle = angle;                                              // set angle
    curObj->obj.coordrot.z = coordrotZ;                                     // set coordinate z to anything greater than 0 to activate
}

void _objectinteract_max::changeImage(_object_max *curObj, char *image, float framesX, float framesY)  // change the image of the given object
{
    curObj->obj.image = image;
    curObj->objImage->loadTexture(curObj->obj.image);                       // load texture
    curObj->obj.frames.x = framesX;
    curObj->obj.frames.y = framesY;
    curObj->obj.xMin = 0.0;                                                 // measurements setting for sprite sheet of an object
    curObj->obj.xMax = 1/curObj->obj.frames.x;
    curObj->obj.yMin = 0.0;
    curObj->obj.yMax = 1/curObj->obj.frames.y;
}

void _objectinteract_max::updateRelativePosition(_object_max * curObj, float moveX, float moveY)    // update relative position of object to screen translation
{
    curObj->obj.pos.x += moveX;
    curObj->obj.pos.y += moveY;
}

void _objectinteract_max::draw(_object_max *curObj)                                  // draw the object given for every update
{
    glPushMatrix();
    //glTranslatef(curObj->obj.pos.x, curObj->obj.pos.y, curObj->obj.pos.z);
    //glScalef(curObj->obj.scale.x, curObj->obj.scale.y, curObj->obj.scale.z);
    //glRotatef(curObj->obj.angle, curObj->obj.coordrot.x, curObj->obj.coordrot.y, curObj->obj.coordrot.z);
    glBindTexture(GL_TEXTURE_2D, curObj->objImage->tex);                    // bind the image to the object
    curObj->objDraw();
    glPopMatrix();
}

void _objectinteract_max::deleteObject(_object_max *curObj)
{
    if(curObj->obj.exist == false)
        delete(curObj);
}
