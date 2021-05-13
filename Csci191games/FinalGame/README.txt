Final game README.txt submission for group virtual boys:

Max's parts:
common.h (modified)		Modified the common.h file to include a objInfo_max struct
_input.h/.cpp (modified)	Modified the input to include _object_max type
_object_max.h/.cpp		I used this to create various objects
_objectinteract_max.h/.cpp  	then I used this to update their information using different seperate static cases (it includes gl_push,gl_pop matrix with its functionality so no need to include that in scene if you are using my object type)
_movement_max.h/.cpp		This was used for updating the movement of various things in relation to the world
_movement_jump.h/.cpp		used to calculate the jump movements for the player
_hitbox_max.h/.cpp		a simple hitbox class for calculating the hitbox of objects in relation to one another (note the hitbox is kinda buggy, it works but is slightly miscalcualted)
_healthpack_max.h/.cpp		a simple in game object that can be interacted with
_animate_max.h/.cpp		a simple class to animate various objects in the game
_hud.h/.cpp			a simple hud to display various info about the players current condition
_healthbar.h/.cpp		a graphical healthbar that updates using players current health
_mine.h/.cpp			a mine enemy to dodge and kill in the game, if if touches the player it explodes
_turret.h/.cpp			a turret enemy to shoot at the player in the game, the bullet does damage if it touches the player

In creation of the game it was important to have a solid and abstract base to go off of when creating items/objects for the game. 
The whole point of the _object_max class was to be able to make an object and then interact with it using _objectinteract_max, then make
seperate classes for each individual item (like player and turret, etc.) so that objects can all interact being based off the same basic struct via
static cases and the functions in their own classes. Basically after that I just made parts for the game such as healthpacks, turrets, etc. 
and added player/object updates to movements in relation to the game world and made sure that objects/items could all interact with one another properly.

Emmanuel's parts:
	I plan on working on the different environments and make sure the platforms work with collision. 
	So the platforms worked with collision; however, I could not get a jump to work while on the platform, 
	so platforms have been omitted from the project. I worked on getting the levels properly set up with 
	the different scenes, turret placement, and mines placement. Also, set up the switching levels mechanism.

Eric's parts:			
_collision			I used this for our physics for characters, enemies, and projectiles. These functions will check to see if the player or weapons are 					touching something else. These will also check to see if the weapons hit the enemies. 
_weapons			The weapon class will involve the weapons themselves, their damage, and the projectiles.
				We have 4 weapons that we can use. Pistol, grenade launcher, laser gun, and shock rifle.
				Pistol: Very weak, straight forward weapon. Character will start with this every stage. It will take multiple shots for this weapon to 					destroy enemies.
				Grenade Launcher: The grenade launcher will have gravity/acceration applied to the projectile. Very strong weapon and can single shot 					enemies but the the weapon is much harder to use than the rest of the weapons. The angle will make the flying mines a hassle to	 				   destroy.
				Laser Gun: Basically an upgraded pistol. Fires fast, straight and does a lot more damage than that of the pistol.
				Shock Rifle: Best weapon in the game. Will destroy everything when it touches the enemies. Very fast attack speed and will go through 					eveything. Also spreads into 3 shots.
_input				Ive added the mouse down and angle controles for our weapon here.
				Controls added: anglesForShots, weaponPickUp, keyPressed (movement of weapons), mouseClick(shoot)
				anglesForShots: Will calculate a general angle for the projetiles. Is not completely accurate because monitor pixels are an issue. 				    There are also anglesForShockShotOne and Two. These will calculate what angles that the spread will have for our shock rifle.
				anglesForShots-> Command is "left click"
				weaponPickUp: pickup the weapon if you are touching the weapon on the floor.
				weaponPickUp-> Command is "Space"
				keyPressed (movement of weapons): This keyPressed was made to allow projectiles and weapons that fall on the 	floor to move 					 according to the player
				keyPressed-> Commands "left", "right", and "up"
				mouseClick (shoot): This was made to fire our weapon. Will use the angle caluculated by anglesForShots
				mouseClick -> Commands "left click"

Don's parts:
Menu				Created a landing/menu/help/credit pages with keyboard click. Emmanuel helped me with the mouse clicking implementation.
Key/Menu			Press N for new game, H for help, C for credit, E for exit. ESC or Back Button at help/credit page back to menu page.
Pausing				Press ESC during game play to pause the game. Emmanuel contributed with game states to suit our implementations.
