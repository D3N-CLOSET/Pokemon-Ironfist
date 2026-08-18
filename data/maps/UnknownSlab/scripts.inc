UnknownSlab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UnknownSlab_OnTransition
	.byte 0

UnknownSlab_OnTransition:
	setflag FLAG_VISITED_UNKNOWN_CAVE
	end
