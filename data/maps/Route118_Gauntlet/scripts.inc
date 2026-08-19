Route118_Gauntlet_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Mauville_Gauntlet_OnTransition
	.byte 0

Mauville_Gauntlet_OnTransition:
	cleartrainerflag TRAINER_SYRUS
	cleartrainerflag TRAINER_COBALT
	cleartrainerflag TRAINER_HOLMES
	cleartrainerflag TRAINER_LILY_HARP
	cleartrainerflag TRAINER_JUSTINIAN
	cleartrainerflag TRAINER_LERA
	cleartrainerflag TRAINER_DICKSON
	cleartrainerflag TRAINER_HUNT
	end

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

Route118_Gauntlet_EventScript_Hitler::
	faceplayer
	trainerbattle_single TRAINER_HOLMES, Gauntlet_Text_IntroHitler, Gauntlet_Text_Defeat_1
	msgbox Gauntlet_Text_PostBattleDih, MSGBOX_AUTOCLOSE
	end

Route118_Gauntlet_EventScript_LilyHarp::
	faceplayer
	trainerbattle_double TRAINER_LILY_HARP, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_2, Gauntlet_Text_NotEnoughMons
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

Route118_Gauntlet_EventScript_Dickson::
	faceplayer
	trainerbattle_single TRAINER_HUNT, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_3
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route118_Gauntlet_EventScript_Hunt::
	faceplayer
	trainerbattle_double TRAINER_HUNT, Gauntlet_Text_Intro, Gauntlet_Text_Defeat_5, Gauntlet_Text_NotEnoughMons
	msgbox Gauntlet_Text_PostBattle, MSGBOX_AUTOCLOSE
	end



Route118_Gauntlet_Text_ItsAsh:
	.string "Oh hello there!\p"
	.string "I am Ash Ketchum, from Pallet Town.\p"
	.string "Me and May run these Gauntlets.\p"
	.string "It's supposed to help you in\n"
	.string "your training.\p"
	.string "Actually, we were forced by the Dev.\p"
	.string "We spend 6 hrs per day in this game,\n"
	.string "to keep these facilities running.\p"
	.string "Don't worry about us though,\n"
	.string "salary is good. def not min wage.\p"
	.string "Anyways these Facilities are divided\n"
	.string "two sections. One to the right and\l"
	.string "one to the left.\p"
	.string "The left section leads to Singles.\n"
	.string "While the right one leads to Doubles.\p"
	.string "Each section is divided into two tiers.\n"
	.string "Low-Tier with Lower levelled trainers;\p"
	.string "And High-Tier with Higher levelled trainers\p"
	.string "Enjoy battling!$"

Route118_Gauntlet_Text_ItsMay:
	.string "Oh man...\n"
	.string "I met Ash after such a long time.\p"
	.string "We last met during Wallace Cup.\n"
	.string "Hey, don't tell Ash that..\l"
	.string "that I have a crush on him.\p"
	.string "Oh wait why am I even telling you that!\n"
	.string "Go enjoy battling!\p"
	.string "(Please don't kill me Amourshippers)$"
