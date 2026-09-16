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
IoT_EventScript_ExampleScriptContinue:
	releaseall
	end

EventScript_SetEasyDifficulty:
	setvar VAR_GAME_DIFFICULTY, DIFFICULTY_EASY
	setvar B_EXP_CAP_TYPE, EXP_CAP_NONE
	setvar B_RARE_CANDY_CAP, FALSE
	goto IoT_EventScript_ExampleScriptContinue

EventScript_SetNormalDifficulty:
	setvar VAR_GAME_DIFFICULTY, DIFFICULTY_NORMAL
	goto IoT_EventScript_ExampleScriptContinue

EventScript_SetHardDifficulty:
	setvar VAR_GAME_DIFFICULTY, DIFFICULTY_HARD
	setflag FLAG_DIFFICULTY_HARD
	goto IoT_EventScript_ExampleScriptContinue

InsideOfTruck_Text_PleaseConfirmDifficulty:
	.string "Please confirm the difficulty\n"
	.string "level for your adventure.$"

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

