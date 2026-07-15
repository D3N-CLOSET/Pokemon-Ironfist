Pacifidlog_Gauntlet_MapScripts::
	.byte 0


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
