SageIsland_Entrance_MapScripts::
	.byte 0

SageIsland_EventScript_FerryAttendant::
    lock
    faceplayer
    msgbox SageIsland_Text_WouldYouLikeToTakeTheFerry, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SageIsland_EventScript_Cancel
    message SageIsland_Text_WhereWouldYouLikeToGo
    waitmessage
    multichoice 18, 8, MULTI_FERRY_SELECTION, FALSE
    switch VAR_RESULT
    case 0, SageIsland_EventScript_WarpLilycove
	case 1, SageIsland_EventScript_WarpSlateport
    case 8, SageIsland_EventScript_Cancel
    case MULTI_B_PRESSED, SageIsland_EventScript_Cancel
    release
    end

SageIsland_EventScript_WarpSlateport::
	msgbox SageIsland_Harbor_Text_SlateportItIs, MSGBOX_DEFAULT
    closemessage
    warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
    waitstate
    release
    end

SageIsland_EventScript_WarpLilycove::
	msgbox SageIsland_Harbor_Text_LilycoveItIs, MSGBOX_DEFAULT
    closemessage
    warp MAP_LILYCOVE_CITY_HARBOR, 7, 11
    waitstate
    release
    end


SageIsland_EventScript_WarpBattleFrontier::
	msgbox SageIsland_Harbor_Text_BattleFrontierItIs, MSGBOX_DEFAULT
    closemessage
    warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
    waitstate
    release
    end

SageIsland_EventScript_Cancel::
    msgbox SageIsland_Text_PleaseSailWithUsAnotherTime, MSGBOX_DEFAULT
    release
    end


SageIsland_Text_WouldYouLikeToTakeTheFerry:
	.string "Would you like to take the Ferry?$"


SageIsland_Text_WhereWouldYouLikeToGo:
	.string "Perfect! where would you like to go?$"


SageIsland_Harbor_Text_BattleFrontierItIs:
	.string "BATTLE FRONTIER it is, then!$"

SageIsland_Harbor_Text_SlateportItIs:
	.string "SLATEPORT CITY it is, then!$"

SageIsland_Harbor_Text_LilycoveItIs:
	.string "LILYCOVE CITY it is, then!$"

SageIsland_Text_PleaseSailWithUsAnotherTime:
	.string "Please sail with us another time!$"
