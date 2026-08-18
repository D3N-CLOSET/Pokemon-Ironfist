SilverIsland_Forest_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SilverIsland_Forest_OnTransition
	.byte 0

SilverIsland_Forest_OnTransition:
    setflag FLAG_VISITED_SILVER_FOREST
    end

SilverForest_EventScript_Sign::
    msgbox SilverForest_Text_Sign, MSGBOX_SIGN
    end

SilverForest_Text_Sign:
    .string "Silver Forest$"
