SilverIsland_Depths_2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Depths_OnLoad
	.byte 0

Depths_OnLoad:
	goto_if_set FLAG_HIDE_RED, Depths_LockRedRoomWay
	end

Depths_LockRedRoomWay::
	setmetatile 17, 29, METATILE_Lavaridge_TopLeftWall, TRUE
	setmetatile 18, 29, METATILE_Lavaridge_TopMiddleWall, TRUE
	setmetatile 19, 29, METATILE_Lavaridge_TopMiddleWall, TRUE
	setmetatile 20, 29, METATILE_Lavaridge_TopMiddleWall, TRUE
	setmetatile 21, 29, METATILE_Lavaridge_TopRightWall, TRUE
	setmetatile 17, 30, METATILE_Lavaridge_Top, TRUE
	setmetatile 18, 30, METATILE_Lavaridge_Top, TRUE
	setmetatile 19, 30, METATILE_Lavaridge_Top, TRUE
	setmetatile 20, 30, METATILE_Lavaridge_Top, TRUE
	setmetatile 21, 30, METATILE_Lavaridge_Top, TRUE
	end
