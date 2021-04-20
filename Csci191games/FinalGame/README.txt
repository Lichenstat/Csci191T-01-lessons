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

I plan on updating the player to world movements and adding an enemy or two to show in the presentaitons.

Emmanuel's parts:
I plan on working on the different enviroments, and make sure the platforms work with collision.

Eric's parts:			
_collision			I used this for our physics for characters, enemies, and projectiles. We can include this for our character to be able to jump.
_weapons			The weapon class will involve the weapons themselves, their damage, and the projectiles.
				The projectiles will have their own speeds and acceraltions. Beams, lighting, fire, and melee attacks will not have gravity applied to them
				The pistols and grenade launchers will have gravity/acceration applied to them. Pistols will only have a small angle.

Don's parts:
