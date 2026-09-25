InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_PleaseConfirmDifficulty::
	lockall
	msgbox InsideOfTruck_Text_PleaseConfirmDifficulty, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, EventScript_ExampleScript_Text_Choice1, EventScript_ExampleScript_Text_Choice2, EventScript_ExampleScript_Text_Choice3
	switch VAR_RESULT
	case 0, EventScript_SetEasyDifficulty
	case 1, EventScript_SetNormalDifficulty
	case 2, EventScript_SetHardDifficulty
	case MULTI_B_PRESSED, InsideOfTruck_EventScript_PleaseConfirmDifficulty
IoT_EventScript_ExampleScriptContinue:
	msgbox IoT_Text_DoYouWantFreeRareCandies, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, IoT_EventScript_GiveFreeRareCandies
	releaseall
	end

EventScript_SetEasyDifficulty:
	setvar VAR_GAME_DIFFICULTY, DIFFICULTY_EASY
	setvar VAR_LEVEL_CAP, 67
	setvar VAR_EV_CAP, 1
	goto IoT_EventScript_ExampleScriptContinue

EventScript_SetNormalDifficulty:
	setvar VAR_GAME_DIFFICULTY, DIFFICULTY_NORMAL
	setvar VAR_EV_CAP, 1
	setvar VAR_LEVEL_CAP, 0
	goto IoT_EventScript_ExampleScriptContinue

EventScript_SetHardDifficulty:
	setvar VAR_GAME_DIFFICULTY, DIFFICULTY_HARD
	setflag FLAG_DIFFICULTY_HARD
	setvar VAR_LEVEL_CAP, 0
	setvar VAR_EV_CAP, 0
	goto IoT_EventScript_ExampleScriptContinue

IoT_EventScript_GiveFreeRareCandies::
	addpcitem ITEM_RARE_CANDY, 999
	return

InsideOfTruck_Text_PleaseConfirmDifficulty:
	.string "Please select the difficulty\n"
	.string "level for your adventure.\p"
	.string "It will affect all of the major\n"
	.string "battles in your campaign.\l"
	.string "As well as these configurations:\p"
	.string "{COLOR LIGHT_GREEN}EASY{COLOR DARK_GRAY}: No level caps, No EV caps\n"
	.string "{COLOR BLUE}NORMAL{COLOR DARK_GRAY}: Level caps, No EV caps\l"
	.string "{COLOR RED}HARD{COLOR DARK_GRAY}: Level caps and EV caps\p"
	.string "Select the difficulty as you desire.$"

EventScript_ExampleScript_Text_Choice1:
	.string "EASY$"

EventScript_ExampleScript_Text_Choice2:
	.string "NORMAL$"

EventScript_ExampleScript_Text_Choice3:
	.string "HARD$"

InsideOfTruck_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto InsideOfTruck_EventScript_PleaseConfirmDifficulty
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto InsideOfTruck_EventScript_PleaseConfirmDifficulty
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo:
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

IoT_Text_DoYouWantFreeRareCandies:
	.string "Do you want rare candies for your\n"
	.string "adventure?$"
