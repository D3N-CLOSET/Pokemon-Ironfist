SilverIsland_Depths_2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Depths_OnLoad
	.byte 0

Depths_OnLoad:
	goto_if_set FLAG_HIDE_RED, Depths_LockRedRoomWay
	end

Depths_LockRedRoomWay::
	setmetatile 17, 29, METATILE_0x27F, TRUE
	setmetatile 18, 29, METATILE_0x269, TRUE
	setmetatile 19, 29, METATILE_0x269, TRUE
	setmetatile 20, 29, METATILE_0x269, TRUE
	setmetatile 21, 29, METATILE_0x27E, TRUE
	setmetatile 17, 30, METATILE_0x3A2, TRUE
	setmetatile 18, 30, METATILE_0x3A2, TRUE
	setmetatile 19, 30, METATILE_0x3A2, TRUE
	setmetatile 20, 30, METATILE_0x3A2, TRUE
	setmetatile 21, 30, METATILE_0x3A2, TRUE
	end
