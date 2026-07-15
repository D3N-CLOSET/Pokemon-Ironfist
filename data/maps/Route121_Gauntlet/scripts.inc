Route121_Gauntlet_MapScripts::
	.byte 0

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

