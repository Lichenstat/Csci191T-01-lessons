This is the code base to be used in the creation of the final game:

If your reading this then just note what parts you have added onto the file
that way we won't get so confused with eachothers parts wer plan on making

Max's parts:
_object_max.h/.cpp		I used this to create various objects
_objectinteract_max.h/.cpp  	then I used this to update their information using different seperate static cases (it includes gl_push,gl_pop matrix with its functionality so no need to include that in scene if oyu are using my object type)
_movement_max.h/.cp		This was used for updating the movement of various things in relation to the world
_hitbox_max.h/.cpp		a simple hitbox class for calculating the hitbox of objects in relation to one another (note the hitbox is kinda buggy, it works but is slightly miscalcualted)
_healthpack_max.h/.cpp		a simple in game object that can be interacted with
_animate_max.h/.cpp		a simple class to animate various objects in the game

Emmanuel's parts:
Testing a push from me.

Eric's parts:

Don's parts: