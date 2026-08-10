MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	.byte 0

MtPyre_Exterior_OnTransition:
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 12, MtPyre_Exterior_EventScript_EnterFromSummit
	return

MtPyre_Exterior_EventScript_EnterFromSummit::
	setweather WEATHER_FOG_HORIZONTAL
	return

MtPyre_Exterior_EventScript_FogTrigger::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

MtPyre_Exterior_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	doweather
	end

MtPyre_Exterior_ES_SkyHiker::
	lock
	faceplayer
	goto_if_defeated TRAINER_HIKER_SKY, MtPyre_Exterior_ES_HikerDefeated
	special TrySkyBattle
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NotEligibleForSkyBattles
	setflag FLAG_SYS_SKY_BATTLE
	trainerbattle_single TRAINER_HIKER_SKY, MtPyre_Exterior_T_HikerIntro, MtPyre_Exterior_T_HikerDefeat, MtPyre_Exterior_ES_HikerDefeated
	msgbox MtPyre_Exterior_T_HikerPostBattle, MSGBOX_DEFAULT
	clearflag FLAG_SYS_SKY_BATTLE
	release
	end

MtPyre_Exterior_ES_HikerDefeated::
	clearflag FLAG_SYS_SKY_BATTLE
	msgbox MtPyre_Exterior_T_HikerPostBattle, MSGBOX_NPC
	release
	end

MtPyre_Exterior_T_HikerIntro:
	.string "EEEEEEEEYYY!\p"
	.string "This view is amazing! It makes me\n"
	.string "want to have a SKY BATTLE!\p"
	.string "HEY! YOU! YES YOU!\p"
	.string "LETS'S have a SKY BATTLE! C'MON!$"

MtPyre_Exterior_T_HikerDefeat:
	.string "EEEEEKK!\p"
	.string "Your power just gave me some\n"
	.string "GOOSEBUMPS!$"

MtPyre_Exterior_T_HikerPostBattle:
	.string "I GOT DISTRACTED BY THE AMAZING\n"
	.string "VIEW OF MT PYRE!$"
