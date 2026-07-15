SageVillage_Gauntlet_MapScripts::
	.byte 0

Route121_Gauntlet_EventScript_D3N::
	faceplayer
	trainerbattle_single TRAINER_D3N_AR, Gauntlet_Text_IntroD3N, Gauntlet_Text_Defeat_67
	msgbox Gauntlet_Text_PostBattleDih, MSGBOX_AUTOCLOSE
	end

Gauntlet_EventScript_Single::
	msgbox Gauntlet_Text_Single, MSGBOX_SIGN
	end

Gauntlet_EventScript_Doubles::
	msgbox Gauntlet_Text_Doubles, MSGBOX_SIGN
	end


Route121_Gauntlet_EventScript_Neighbor::
	faceplayer
	trainerbattle_double TRAINER_NEIGHBOR, Gauntlet_Text_IntroNeigh, Gauntlet_Text_Defeat_69, Gauntlet_Text_NeighNotEnoughMons
	msgbox Gauntlet_Text_PostBattleDih, MSGBOX_AUTOCLOSE
	end

Gauntlet_Text_Intro::
    .string "Hello.\n"
    .string "Let's start the battle.$"

Gauntlet_Text_IntroD3N::
    .string "Hello.\p"
    .string "The name's D3N_AR,\n"
    .string "The developer of this hack.\p"
    .string "Time to dance darling.$"

Gauntlet_Text_IntroNeigh::
    .string "Hello.\n"
    .string "The name's Neighbor,\p"
    .string "I am an Elite Trainer.\p"
    .string "Show me what'chu got, k?.$"

Gauntlet_Text_PostBattle::
    .string "......$"

Gauntlet_Text_PostBattleDih::
    .string "Fahhhhh!$"

Gauntlet_Text_Single::
    .string "SINGLE BATTLES THIS WAY$"

Gauntlet_Text_Doubles::
    .string "DOUBLE BATTLES THIS WAY$"

Gauntlet_Text_Defeat_1::
    .string "Impressive!$"

Gauntlet_Text_Defeat_2::
    .string "You are strong!$"

Gauntlet_Text_Defeat_3::
    .string "Good job kid.$"

Gauntlet_Text_Defeat_4::
    .string "Cool dude.$"

Gauntlet_Text_Defeat_5::
    .string "Damn, I lost.$"

Gauntlet_Text_Defeat_6::
    .string "You got talent.$"

Gauntlet_Text_Defeat_67::
    .string "Oh my fucking balls.$"

Gauntlet_Text_Defeat_69::
    .string "Wow, you're too good.$"

Gauntlet_Text_NotEnoughMons::
    .string "Hmm, looks like you are a dumbass,\p"
    .string "who did not know that,\n"
    .string "this is double battle area.\p"
    .string "Come back later with two pokemons.\n"
    .string "Einstein.$"

Gauntlet_Text_NeighNotEnoughMons::
    .string "I beg your pardon, but we can't battle\n"
    .string "without two pokemons.\p"
    .string "Come back later with two pokemons.$"

