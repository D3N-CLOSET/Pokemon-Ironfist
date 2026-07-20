Pacifidlog_Gauntlet_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Pacifidlog_Gauntlet_OnTransition
	.byte 0

Pacifidlog_Gauntlet_OnTransition:
	cleartrainerflag TRAINER_MINITOON
	cleartrainerflag TRAINER_MOONFALLX
	cleartrainerflag TRAINER_LIGMA
	cleartrainerflag TRAINER_BALLS
	cleartrainerflag TRAINER_DRISHA
	cleartrainerflag TRAINER_FORREST
	cleartrainerflag TRAINER_SHUCKS
	cleartrainerflag TRAINER_RIPETHAN
	end

Route121_Gauntlet_EventScript_Minitoon::
	faceplayer
	trainerbattle_single TRAINER_MINITOON, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_4
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_MoonFallX::
	faceplayer
	trainerbattle_double TRAINER_MOONFALLX, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_1, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Ligma::
	faceplayer
	trainerbattle_single TRAINER_LIGMA, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_4
	msgbox Gauntlet_Text_PostBattleDih, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Balls::
	faceplayer
	trainerbattle_double TRAINER_BALLS, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_1, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattleDih, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Drisha::
	faceplayer
	trainerbattle_single TRAINER_DRISHA, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_5
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Forrest::
	faceplayer
	trainerbattle_double TRAINER_FORREST, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_2, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Shucks::
	faceplayer
	trainerbattle_single TRAINER_SHUCKS, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_5
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route121_Gauntlet_EventScript_Ripethan::
	faceplayer
	trainerbattle_double TRAINER_RIPETHAN, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_2, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end
