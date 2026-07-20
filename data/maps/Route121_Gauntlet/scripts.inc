Route121_Gauntlet_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Lilycove_Gauntlet_OnTransition
	.byte 0

Lilycove_Gauntlet_OnTransition:
	cleartrainerflag TRAINER_BORRIS
	cleartrainerflag TRAINER_HIYA
	cleartrainerflag TRAINER_DHONI
	cleartrainerflag TRAINER_NIGHT
	cleartrainerflag TRAINER_STERLING
	cleartrainerflag TRAINER_JOE
	cleartrainerflag TRAINER_HILDA
	cleartrainerflag TRAINER_ROGAN
	end

Route121_Gauntlet_EventScript_Borris::
	faceplayer
	trainerbattle_single TRAINER_BORRIS, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_3
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Hiya::
	faceplayer
	trainerbattle_double TRAINER_HIYA, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_6, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Dhoni::
	faceplayer
	trainerbattle_single TRAINER_DHONI, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_3
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Night::
	faceplayer
	trainerbattle_double TRAINER_NIGHT, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_6, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattleSus, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Sterling::
	faceplayer
	trainerbattle_single TRAINER_STERLING, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_1
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Joe::
	faceplayer
	trainerbattle_double TRAINER_JOE, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_5, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE,
	end

Route121_Gauntlet_EventScript_Hilda::
	faceplayer
	trainerbattle_single TRAINER_HILDA, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_1
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Rogan::
	faceplayer
	trainerbattle_double TRAINER_ROGAN, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_5, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE,
	end
