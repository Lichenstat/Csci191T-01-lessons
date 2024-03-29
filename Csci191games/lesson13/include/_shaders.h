#ifndef _SHADERS_H
#define _SHADERS_H
#define GLEW_STATIC

#include <string>
#include <fstream>
#include <iostream>
#include <GL/glew.h>

using namespace std;

class _shaders
{
    public:
        _shaders();
        virtual ~_shaders();

        void loadFiles(char *, string &);
        unsigned vs, fs, program;

        unsigned int loadShader(string &, unsigned int);
        void initShader(char *, char *);
        void cleanUp();

    protected:

    private:
};

#endif // _SHADERS_H
