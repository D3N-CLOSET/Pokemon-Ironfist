CaveOfOrigin_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CaveOfOrigin_Entrance_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_Entrance_OnTransition
	.byte 0

CaveOfOrigin_Entrance_OnTransition:
	setflag FLAG_VISITED_CAVE_OF_ORIGIN
	end

CaveOfOrigin_Entrance_OnResume:
	setescapewarp MAP_SOOTOPOLIS_CITY, 31, 17
	end

