SilverIsland_Depths_MapScripts::
	.byte 0

Red_EventScript_Red::
    lock
    trainerbattle_single TRAINER_RED, Red_Text_Intro, Red_Text_Defeat, Red_EventScript_SetRedFlag
    release
    end

Red_EventScript_SetRedFlag::
    setflag FLAG_DEFEATED_RED
    goto Red_EventScript_RedPostBattle

Red_EventScript_RedRematch::
    trainerbattle_single TRAINER_RED, Red_Text_RematchIntro, Red_Text_Defeat
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

Magma_EventScript_Slut::
    lock
    faceplayer
    msgbox Magma_Text_Slut, MSGBOX_NPC
    release
    end

Red_Text_Intro:
	.string "....\p"
	.string "(So you are the new\n"
	.string "Hoenn champion huh?\p"
	.string "Time to test your\n"
	.string "true strength.)$"

Red_Text_Defeat:
	.string "....\n"
	.string "(Impressive)$"

Red_Text_RedPostBattle:
	.string "....\p"
	.string "(I should not had\n"
	.string "underestimated your strength.)$"

Red_Text_RematchIntro:
	.string "....\p"
	.string "(You want to rematch?\p"
	.string "Okay here we go!)$"


SilverDepths_EventScript_Sign::
    msgbox SilverDepths_Text_Sign, MSGBOX_SIGN
    end

SilverDepths_Text_Sign:
    .string "Silver Depths$"

Maxie_Text_HeKickedMyAss:
    .string "Oh hi {PLAYER},\p"
    .string "I came here to\n"
    .string "visit Archie and he let\p"
    .string "me train here.\p"
    .string "But that guy came outta\n"
    .string "nowhere and kicked my ass.\p"
    .string "Go show him who is\n"
    .string "the boss!$"

Magma_Text_Boy:
    .string "Man that girl is so hot.\p"
    .string "I wish I could take her on\n"
    .string "a date.\p"
    .string "What? you want me to propose her?\p"
    .string "Impossible! I'd get slapped!$"

Magma_Text_Slut:
    .string "Man that boy is so handsome.\p"
    .string "I wish I could take him on\n"
    .string "a date.\p"
    .string "What? you want me to propose him?\p"
    .string "Impossible! He will run away!$"
