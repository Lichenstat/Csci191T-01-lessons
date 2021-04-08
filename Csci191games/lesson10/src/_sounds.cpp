#include "_sounds.h"

_sounds::_sounds()
{
    //ctor
    sndEng->drop();
}

_sounds::~_sounds()
{
    //dtor
}

void _sounds::playMusic(char* fileName)
{
    sndEng->play2D(fileName, true);         // true for repeating sound
}

void _sounds::playSounds(char* fileName)
{
    sndEng->play2D(fileName, false, false); // play sound only once
}

void _sounds::pauseSound(char* fileName)
{
    sndEng->play2D(fileName, true, false);
}

void _sounds::stopAllSounds()
{

}

int _sounds::initSounds()
{
    if(!sndEng)
    {
        cout<<"Could not start Sound Engine \n";
        return 0;
    }
    return 1;
}
