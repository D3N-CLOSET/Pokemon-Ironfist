SilverIsland_Depths_MapScripts::
	.byte 0

Red_EventScript_Red::
    lock
    trainerbattle_single TRAINER_RED, Red_Text_Intro, Red_Text_Defeat
    msgbox Red_Text_RedPostBattle, MSGBOX_DEFAULT
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
    .string "...........$"

Red_Text_Defeat:
    .string "...........$"

Red_Text_RedPostBattle:
    .string "...............\n"
    .string "...............\l"
    .string "...............\p"
    .string "The person seems to be unfazed\n"
    .string "of your interaction.$"

Red_Text_DoYouWantToFightAgain:
    .string "...........$"

Red_Text_RematchIntro:
    .string "...........$"

Red_Text_RematchDefeat:
    .string "...........$"


SilverDepths_EventScript_Sign::
    msgbox SilverDepths_Text_Sign, MSGBOX_SIGN
    end

SilverDepths_Text_Sign:
    .string "Silver Depths$"

Maxie_Text_HeKickedMyAss:
    .string "Oh hi {PLAYER},\n"
    .string "I came here to visit Archie and he\l"
    .string "let me train here.\p"
    .string "But that kid came outta nowhere and\n"
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
