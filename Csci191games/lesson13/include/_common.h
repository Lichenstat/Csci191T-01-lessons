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

#endif // _COMMON_H
