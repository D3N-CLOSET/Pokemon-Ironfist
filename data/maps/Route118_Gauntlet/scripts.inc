Route118_Gauntlet_MapScripts::
	.byte 0


Route118_Gauntlet_EventScript_Ash::
	faceplayer
	msgbox Route118_Gauntlet_Text_ItsAsh, MSGBOX_NPC
	end

Route118_Gauntlet_EventScript_May::
	faceplayer
	msgbox Route118_Gauntlet_Text_ItsMay, MSGBOX_NPC
	end


Route118_Gauntlet_EventScript_Syrus::
	faceplayer
	trainerbattle_single TRAINER_SYRUS, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_1
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Gauntlet_EventScript_Cobalt::
	faceplayer
	trainerbattle_double TRAINER_COBALT, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_2, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Gauntlet_EventScript_Justinian::
	faceplayer
	trainerbattle_single TRAINER_JUSTINIAN, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_3
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Gauntlet_EventScript_Lera::
	faceplayer
	trainerbattle_double TRAINER_LERA, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_5, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end


Route118_Gauntlet_Text_ItsAsh:
	.string "Oh hello there!\p"
	.string "I am Ash Ketchum, from Pallet Town.\p"
	.string "Me and May run these Gauntlets.\p"
	.string "It's supposed to help you in\n"
	.string "your training.\p"
	.string "Actually, we were forced by the Dev.\p"
	.string "We spend 6 hrs per day in this game,\p"
	.string "to keep these facilities running.\p"
	.string "Don't worry about us though, salary is good.$"

Route118_Gauntlet_Text_ItsMay:
	.string "Oh man...\p"
	.string "I met Ash after such a long time.\p"
	.string "We last met during Wallace Cup.\p"
	.string "Hey, don't tell Ash that..\p"
	.string "that I have a crush on him.\p"
	.string "Oh wait why am I even telling you that!\p"
	.string "Go enjoy battling!$"
