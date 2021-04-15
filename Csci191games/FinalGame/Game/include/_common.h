#ifndef _COMMON_H
#define _COMMON_H

typedef struct
{
    float x;
    float y;
    float z;

}vec3;

typedef struct
{
    float x;
    float y;

}vec2;

typedef struct
{
    char letter;
    float xMin, xMax, yMin, yMax;
    float offset;
    float fontSize;
} charSet;

// information of objects for use in setting/checking/updating various things
typedef struct
{
    char *type,                 // object type (healthpack, player, etc.)
         *image;                // image string for the object
    unsigned int id;            // Id of the object (unsigned address of object pointer)
    bool  exist,                // does the object currently exist? (true, false)
          touched;              // is the object currently being touched? (true, false)
    float xMin,                 // position of matching texture to vertices
          xMax,
          yMin,
          yMax,
          angle,                // object angle of rotation (in degrees)
          hbsize;               // object hitbox size (as a radian, implies hitbox is a circle)
    vec3  vert[4],              // object vertices (x, y, z)
          scale,                // object scale (x, y, z)
          pos,                  // object position (x, y, z)
          coordrot;             // object rotation (x, y, z), along x, y, z coordinates of a vector respectively
    vec2  frames;               // object frames that exist (x, y)

}objInfo_max;

#endif // _COMMON_H
