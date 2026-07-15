SilverIsland_MapScripts::
	.byte 0

SilverCave_EventScript_FerryAttendant::
    lock
    faceplayer
    msgbox SilverCave_Text_WouldYouLikeToTakeTheFerry, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SilverCave_EventScript_Cancel
    message SilverCave_Text_WhereWouldYouLikeToGo
    waitmessage
    multichoice 18, 8, MULTI_FERRY_SELECTION, FALSE
    switch VAR_RESULT
    case 0, SilverCave_EventScript_WarpSlateport
    case 1, SilverCave_EventScript_WarpBattleFrontier
    case 2, SilverCave_EventScript_WarpLilycove
    case 7, SilverCave_EventScript_Cancel
    case MULTI_B_PRESSED, SilverCave_EventScript_Cancel
    release
    end

SilverCave_EventScript_WarpSlateport::
	msgbox SilverCave_Harbor_Text_SlateportItIs, MSGBOX_DEFAULT
    closemessage
	fadescreen FADE_TO_BLACK
    warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
    waitstate
    release
    end

SilverCave_EventScript_WarpLilycove::
	msgbox SilverCave_Harbor_Text_LilycoveItIs, MSGBOX_DEFAULT
    closemessage
	fadescreen FADE_TO_BLACK
    warp MAP_SLATEPORT_CITY_HARBOR, 7, 11
    waitstate
    release
    end


SilverCave_EventScript_WarpBattleFrontier::
	msgbox SilverCave_Harbor_Text_BattleFrontierItIs, MSGBOX_DEFAULT
    closemessage
    warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
    waitstate
    release
    end

SilverCave_EventScript_Cancel::
    msgbox SilverCave_Text_PleaseSailWithUsAnotherTime, MSGBOX_DEFAULT
    release
    end


SilverCave_EventScript_Archie::
	lock
	faceplayer
    msgbox SilverCave_Text_ItsMyHome, MSGBOX_NPC
    release
    end

SilverCave_EventScript_MaleGrunt::
	lock
	faceplayer
    msgbox SilverCave_Text_MyBrother, MSGBOX_NPC
    release
    end

SilverCave_EventScript_GF::
	lock
	faceplayer
    msgbox SilverCave_Text_Huh, MSGBOX_NPC
    release
    end

SilverIsland_EventScript_Sign::
    msgbox SilverIsland_Text_Sign, MSGBOX_SIGN
    end

SilverCave_Text_WouldYouLikeToTakeTheFerry:
	.string "Would you like to take the Ferry?$"


SilverCave_Text_WhereWouldYouLikeToGo:
	.string "Perfect! where would you like to go?$"


SilverCave_Harbor_Text_BattleFrontierItIs:
	.string "BATTLE FRONTIER it is, then!$"

SilverCave_Harbor_Text_SlateportItIs:
	.string "SLATEPORT CITY it is, then!$"


SilverCave_Harbor_Text_LilycoveItIs:
	.string "LILYCOVE CITY it is, then!$"

SilverCave_Text_PleaseSailWithUsAnotherTime:
	.string "Please sail with us another time!$"

SilverCave_Text_ItsMyHome:
	.string "Oh hello {PLAYER}!\n"
	.string "Yes, I live in this island.\p"
	.string "Feel free to explore!$"

SilverCave_Text_MyBrother:
	.string "Hello, I'm Bruce.\n"
	.string "I am the brother of Archie.\p"
	.string "The girl there is my GF.$"

SilverCave_Text_Huh:
	.string "I am happy\n"
	.string "to live with my BF!$"

SilverIsland_Text_Sign:
    .string "Silver Island:\n"
    .string "OWNED BY TEAM AQUA!$"

