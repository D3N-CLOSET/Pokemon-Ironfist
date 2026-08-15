SilverIsland_Depths_MapScripts::
	.byte 0

Red_EventScript_Red::
    lock
    goto_if_set FLAG_DEFEATED_RED, Red_EventScript_RedRematchBeginning
    trainerbattle_single TRAINER_RED, Red_Text_Intro, Red_Text_Defeat
    setflag FLAG_DEFEATED_RED
    msgbox Red_Text_RedPostBattle, MSGBOX_NPC
    release
    end

Red_EventScript_RedRematchBeginning::
    msgbox Red_Text_DoYouWantToFightAgain, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, Red_EventScript_RedRematch
    release
    end

Red_EventScript_RedRematch:
    cleartrainerflag TRAINER_RED
    trainerbattle_single TRAINER_RED, Red_Text_RematchIntro, Red_Text_RematchDefeat
    release
    end

Red_EventScript_RedPostBattle::
    msgbox Red_Text_RedPostBattle, MSGBOX_AUTOCLOSE
    release
    end

Maxie_EventScript_Hi::
    lock
    faceplayer
    msgbox Maxie_Text_HeKickedMyAss, MSGBOX_NPC
    release
    end

Magma_EventScript_Boy::
    lock
    faceplayer
    msgbox Magma_Text_Boy, MSGBOX_NPC
    release
    end

Magma_EventScript_Girl::
    lock
    faceplayer
    msgbox Magma_Text_Girl, MSGBOX_NPC
    release
    end

Red_Text_Intro:
	.string "....\p"
	.string "(So you are the new Hoenn champion huh?\l"
	.string "It's Time to test your true strength.)$"

Red_Text_Defeat:
	.string "....\n"
	.string "(Impressive)$"

Red_Text_RedPostBattle:
	.string "....\p"
	.string "(I should not had underestimated your\n"
	.string "strength.)$"

Red_Text_DoYouWantToFightAgain:
    .string "....\p"
    .string "(Do you want a rematch?)$"

Red_Text_RematchIntro:
	.string "....\p"
	.string "(Okay here we go!)$"

Red_Text_RematchDefeat:
    .string ".....\p"
    .string "(You are still stronger.)$"


SilverDepths_EventScript_Sign::
    msgbox SilverDepths_Text_Sign, MSGBOX_SIGN
    end

SilverDepths_Text_Sign:
    .string "Silver Depths$"

Maxie_Text_HeKickedMyAss:
    .string "Oh hi {PLAYER},\n"
    .string "I came here to visit Archie and he\l"
    .string "let me train here.\p"
    .string "But that guy came outta nowhere and\n"
    .string "kicked my ass.\p"
    .string "Go show him who is the boss!$"

Magma_Text_Boy:
    .string "Man that girl is so hot.\n"
    .string "I wish I could take her on a date.\p"
    .string "What? you want me to propose her?\n"
    .string "Impossible! I'd get slapped!$"

Magma_Text_Girl:
    .string "Man that boy is so handsome.\n"
    .string "I wish I could take him on a date.\p"
    .string "What? you want me to propose him?\n"
    .string "Impossible! He will run away!$"
