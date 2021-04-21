#include "_player_max.h"

_player_max::_player_max()
{
    //ctor
    playerHealth = 80.0;
    movementSoundPlaying = false;
}

_player_max::~_player_max()
{
    //dtor
}

void _player_max::initialize()
{
    _objectinteract_max::initialize(player, "player", 0.35, 0.5, 0.0, -0.25, 0.0, 0.0, "images/player.png", 8.0, 9.0);
    _animate_max::movementCycle(player, 1, 1, 9);
    //player->obj.hbsize = .05;
}

void _player_max::draw()
{
    _objectinteract_max::draw(player);
    player->obj.touched = false;
}

void _player_max::animate()
{
    //_animate_max::animate(player);
    //_animate_max::movementCycle(player, 1, 4, 9);

}

void _player_max::movements(string direction, float speed)  // player movements (animation frames
{
    _animate_max::direction(player, speed);             // player direction of movement
    if(speed != 0)
    {
        _animate_max::movementCycle(player, 1, 8, 2);       // if player is running
        if(!movementSoundPlaying)
        {
            movementSoundPlaying = true;
            movementSounds->playMusic("sounds/sfx/running on gravel.mp3");
        }
    }
    if(speed == 0)
    {
        _animate_max::movementCycle(player, 1, 4, 9);       // if player is standing
        movementSounds->stopAllSounds();
        movementSoundPlaying = false;
    }
    if(direction == "jump")
    {
        _animate_max::movementCycle(player, 1, 8, 5);       // if player is jumping
        movementSounds->stopAllSounds();

        //_movement::jump(player, 1.0, 1.0);
    }

}

void _player_max::interact(_object_max * curObj)
{
    if(curObj->obj.exist)
    {
        if(curObj->obj.touched && string(curObj->obj.type) == "healthpack")
        {
            //cout << "healthpack sensed" << endl;
            if(playerHealth < 100)
            {
                curObj->obj.exist = false;
                itemSounds->playSounds("sounds/sfx/hiss.mp3");
                float curmissinghealth = 100.0 - playerHealth;
                if(curmissinghealth < 20.0)
                    playerHealth += curmissinghealth;
                else
                    playerHealth += 20.0;

                cout << "Picked up health, current health is " << playerHealth << endl;
            }
       }
    }
}
