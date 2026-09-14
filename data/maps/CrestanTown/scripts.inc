CrestanTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TheDepths_OnLoad
	.byte 0


TheDepths_OnLoad::
	goto_if_set FLAG_HIDE_RED, TheDepths_LockRedRoomWay
	end

TheDepths_LockRedRoomWay::
	setmetatile 17, 28, METATILE_Lavaridge_TopLeftWall, TRUE
	setmetatile 18, 28, METATILE_Lavaridge_TopMiddleWall, TRUE
	setmetatile 19, 28, METATILE_Lavaridge_TopMiddleWall, TRUE
	setmetatile 20, 28, METATILE_Lavaridge_TopMiddleWall, TRUE
	setmetatile 21, 28, METATILE_Lavaridge_TopRightWall, TRUE
	setmetatile 17, 29, METATILE_Lavaridge_Top, TRUE
	setmetatile 18, 29, METATILE_Lavaridge_Top, TRUE
	setmetatile 19, 29, METATILE_Lavaridge_Top, TRUE
	setmetatile 20, 29, METATILE_Lavaridge_Top, TRUE
	setmetatile 21, 29, METATILE_Lavaridge_Top, TRUE
	setmetatile 17, 30, METATILE_Lavaridge_Top, TRUE
	setmetatile 18, 30, METATILE_Lavaridge_Top, TRUE
	setmetatile 19, 30, METATILE_Lavaridge_Top, TRUE
	setmetatile 20, 30, METATILE_Lavaridge_Top, TRUE
	setmetatile 21, 30, METATILE_Lavaridge_Top, TRUE
	end
