#include "_player_max.h"

_player_max::_player_max()
{
    //ctor
    playerHealth = 100.0;
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
    }
    if(speed == 0)
    {
        _animate_max::movementCycle(player, 1, 4, 9);       // if player is standing
    }
    if(direction == "jump")
    {
        _animate_max::movementCycle(player, 1, 8, 5);       // if player is jumping
        //_movement::jump(player, 1.0, 1.0);
    }

}

void _player_max::attract(_object_max * curObj)
{
    _movement_max::moveTwordsObject(curObj, player, .0005);
}
