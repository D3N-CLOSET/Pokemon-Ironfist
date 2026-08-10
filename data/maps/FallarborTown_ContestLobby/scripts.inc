FallarborTown_ContestLobby_MapScripts:: @ 81539C1
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_ContestLobby_OnTransition
	.byte 0

FallarborTown_ContestLobby_OnTransition:: @ 81539C7
	call FallarborTown_ContestLobby_EventScript_TryShowContestReporter
	end

FallarborTown_ContestLobby_EventScript_ContestReceptionist::
	special ClearLinkContestFlags
	call FallarborTown_ContestLobby_EventScript_SpeakToContestReceptionist
	call FallarborTown_ContestLobby_EventScript_LeadToContestHall
	special SetContestTrainerGfxIds
	call LilycoveCity_ContestLobby_EventScript_SetPlayerGfx
	call FallarborTown_ContestLobby_EventScript_SetContestType
	call FallarborTown_ContestLobby_EventScript_WarpToContestHall
	waitstate
	end

FallarborTown_ContestLobby_EventScript_WarpToContestHall::
	setflag FLAG_ENTERED_CONTEST
	setvar VAR_CONTEST_LOCATION, 2
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, FallarborTown_ContestLobby_EventScript_WarpToCoolContestHall
	case CONTEST_CATEGORY_BEAUTY, FallarborTown_ContestLobby_EventScript_WarpToBeautyContestHall
	case CONTEST_CATEGORY_CUTE, FallarborTown_ContestLobby_EventScript_WarpToCuteContestHall
	case CONTEST_CATEGORY_SMART, FallarborTown_ContestLobby_EventScript_WarpToSmartContestHall
	case CONTEST_CATEGORY_TOUGH, FallarborTown_ContestLobby_EventScript_WarpToToughContestHall
	return

FallarborTown_ContestLobby_EventScript_WarpToCoolContestHall::
	setwarp MAP_CONTEST_HALL_COOL, 7, 5
	special DoContestHallWarp
	return

FallarborTown_ContestLobby_EventScript_WarpToBeautyContestHall::
	setwarp MAP_CONTEST_HALL_BEAUTY, 7, 5
	special DoContestHallWarp
	return

FallarborTown_ContestLobby_EventScript_WarpToCuteContestHall::
	setwarp MAP_CONTEST_HALL_CUTE, 7, 5
	special DoContestHallWarp
	return

FallarborTown_ContestLobby_EventScript_WarpToSmartContestHall::
	setwarp MAP_CONTEST_HALL_SMART, 7, 5
	special DoContestHallWarp
	return

FallarborTown_ContestLobby_EventScript_WarpToToughContestHall::
	setwarp MAP_CONTEST_HALL_TOUGH, 7, 5
	special DoContestHallWarp
	return






FallarborTown_ContestLobby_EventScript_BerryBlenderMan:: @ 81B778A
	msgbox BerryBlender_Text_LetsGetBlendingAlready, MSGBOX_NPC
	end




@ TEXT SCRIPTS
FallarborTown_ContestLobby_EventScript_Boy::
	msgbox FallarborTown_ContestLobby_Text_UsedToHaveSketch, MSGBOX_NPC
	end

FallarborTown_ContestLobby_EventScript_SketchArtist::
	goto_if_set FLAG_CONTEST_SKETCH_CREATED, FallarborTown_ContestLobby_EventScript_YourSketchIsUp
	msgbox FallarborTown_ContestLobby_Text_ICreateSketches, MSGBOX_NPC
	end

FallarborTown_ContestLobby_EventScript_YourSketchIsUp::
	msgbox FallarborTown_ContestLobby_Text_YourSketchIsUp, MSGBOX_NPC
	end

FallarborTown_ContestLobby_EventScript_Lass::
	msgbox FallarborTown_ContestLobby_Text_AreYouMakingPokeblock, MSGBOX_NPC
	end

FallarborTown_ContestLobby_EventScript_ContestWinner1::
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_3
	releaseall
	end

FallarborTown_ContestLobby_EventScript_ContestWinner2::
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_2
	releaseall
	end


FallarborTown_ContestLobby_EventScript_SetContestType::
	switch VAR_CONTEST_RANK
	case CONTEST_RANK_HYPER, FallarborTown_ContestLobby_EventScript_SetHyperContestType
	return

FallarborTown_ContestLobby_EventScript_SetNormalContestType::
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
	return

FallarborTown_ContestLobby_EventScript_SetSuperContestType::
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
	return

FallarborTown_ContestLobby_EventScript_SetHyperContestType::
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER
	return



FallarborTown_ContestLobby_EventScript_1A4EDD:: @ 81A4EDD
	clearflag FLAG_TEMP_1
	return

FallarborTown_ContestLobby_EventScript_BerryBlenderSpeedRecords::
	lockall
	special ShowBerryBlenderRecordWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end


FallarborTown_ContestLobby_EventScript_ParticipateAnotherTime:: @ 81A503E
	msgbox FallarborTown_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
	release
	end

FallarborTown_ContestLobby_EventScript_AlreadyHasContestPass:: @ 81A4F44
	msgbox FallarborTown_ContestLobby_Text_AlreadyHasContestPass, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_ContestLobby_EventScript_1A4F4E:: @ 81A4F4E
	msgbox FallarborTown_ContestLobby_Text_1A685A, MSGBOX_DEFAULT
	switch VAR_CONTEST_PRIZE_PICKUP
	case 4, FallarborTown_ContestLobby_EventScript_GiveLuxuryBall
	end

FallarborTown_ContestLobby_EventScript_GiveLuxuryBall:: @ 81A4F67
	giveitem ITEM_LUXURY_BALL
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A4F86
	setvar VAR_CONTEST_PRIZE_PICKUP, 0
	closemessage
	release
	end

FallarborTown_ContestLobby_EventScript_1A4F86:: @ 81A4F86
	msgbox FallarborTown_ContestLobby_Text_1A68C6, MSGBOX_NPC
	end


FallarborTown_ContestLobby_EventScript_ExplainContestsNow:: @ 81A5014
	msgbox FallarborTown_ContestLobby_Text_ExplainContests, MSGBOX_DEFAULT
	goto FallarborTown_ContestLobby_EventScript_ExplainContests
	end

FallarborTown_ContestLobby_EventScript_ExplainContestTypes:: @ 81A5022
	msgbox FallarborTown_ContestLobby_Text_ExplainContestTypes, MSGBOX_DEFAULT
	goto FallarborTown_ContestLobby_EventScript_ExplainContests
	end

FallarborTown_ContestLobby_EventScript_ExplainContestRanks:: @ 81A5030
	msgbox FallarborTown_ContestLobby_Text_ExplainContestRanks, MSGBOX_DEFAULT
	goto FallarborTown_ContestLobby_EventScript_ExplainContests
	end


FallarborTown_ContestLobby_Movement_one:: @ 8153A70
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

FallarborTown_ContestLobby_Movement_two:: @ 8153A7A
	walk_in_place_fast_left
	step_end

FallarborTown_ContestLobby_Movement_three:: @ 8153A7C
	walk_left
	walk_in_place_fast_down
	step_end

FallarborTown_ContestLobby_Movement_four:: @ 8153A7F
	walk_down
	walk_down
	walk_in_place_fast_up
	step_end

FallarborTown_ContestLobby_Movement_five:: @ 8153A83
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

FallarborTown_ContestLobby_Movement_six:: @ 8153A8C
	walk_in_place_fast_right
	step_end



FallarborTown_ContestLobby_EventScript_LeadToContestHall:: @ 81539F8
	lockall
	applymovement 1, FallarborTown_ContestLobby_Movement_three
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 4, 2, METATILE_Contest_WallShadow, 1
	setmetatile 4, 3, METATILE_Contest_FloorShadow, 1
	special DrawWholeMapView
	applymovement 1, FallarborTown_ContestLobby_Movement_four
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 4, 2, METATILE_Contest_CounterFlap_Top, 1
	setmetatile 4, 3, METATILE_Contest_CounterFlap_Bottom, 1
	special DrawWholeMapView
	delay 20
	applymovement 1, FallarborTown_ContestLobby_Movement_six
	waitmovement 0
	applymovement LOCALID_PLAYER, FallarborTown_ContestLobby_Movement_two
	waitmovement 0
	msgbox FallarborTown_ContestLobby_Text_ComeThroughHere, MSGBOX_DEFAULT
	closemessage
	applymovement 1, FallarborTown_ContestLobby_Movement_five
	applymovement LOCALID_PLAYER, FallarborTown_ContestLobby_Movement_one
	waitmovement 0
	releaseall
	return

FallarborTown_ContestLobby_EventScript_ExplainContests::
	message FallarborTown_ContestLobby_Text_ExplainContests
	waitmessage
	multichoice 0, 0, 3, 0
	switch VAR_RESULT
	case 0, FallarborTown_ContestLobby_EventScript_ExplainContestsNow
	case 1, FallarborTown_ContestLobby_EventScript_ExplainContestTypes
	case 2, FallarborTown_ContestLobby_EventScript_ExplainContestRanks
	end



FallarborTown_ContestLobby_Text_UsedToHaveSketch:: @ 8177141
	.string "They had a sketch of my POKéMON up\n"
	.string "on the wall over there, but they\l"
	.string "changed it with a new one already.\p"
	.string "I'm going to enter my HANA in CONTESTS\n"
	.string "so we can get her sketch up again!$"

FallarborTown_ContestLobby_Text_AreYouMakingPokeblock:: @ 81771F2
	.string "Hi, are you making any {POKEBLOCK}S?\p"
	.string "You should come by with a bunch of\n"
	.string "BERRIES sometime.$"

FallarborTown_ContestLobby_Text_ICreateSketches:: @ 8177246
	.string "You see how they display a sketch of\n"
	.string "a CONTEST winner here?\p"
	.string "I sketch them!\p"
	.string "If any of your POKéMON wins a CONTEST,\n"
	.string "I'd gladly make a sketch of it!$"

FallarborTown_ContestLobby_Text_YourSketchIsUp:: @ 81772D8
	.string "Hello! Congratulations!\p"
	.string "I've put up a sketch of your POKéMON\n"
	.string "right here for everyone to see!$"

FallarborTown_ContestLobby_Text_1A5DFC:: @ 81A5DFC
	.string "Hello, there!\p"
	.string "We're accepting registrations for\n"
	.string "{STR_VAR_1} Rank POKéMON CONTESTS.$"

FallarborTown_ContestLobby_Text_WouldYouLikeToEnter:: @ 81A5E46
	.string "Would you like to enter your POKéMON\n"
	.string "in our CONTESTS?$"

FallarborTown_ContestLobby_Text_EnterContest::
	.string "Would you like to enter a CONTEST?$"

FallarborTown_ContestLobby_Text_EnterWhichPokemon::
	.string "Which POKéMON would you like to enter?$"

FallarborTown_ContestLobby_Text_YouMayObtain::
	.string "Anyone with a CONTEST PASS may enter.\p"
	.string "You may obtain a CONTEST PASS at the\n"
	.string "NORMAL RANK CONTEST HALL in\l"
	.string "VERDANTURF TOWN free of charge.\p"
	.string "Please obtain a CONTEST PASS and\n"
	.string "come again.$"

FallarborTown_ContestLobby_Text_AnyoneWithContestPass::
	.string "Anyone with a CONTEST PASS may enter.\p"
	.string "If you don't have one, I can issue one\n"
	.string "for you right now.\p"
	.string "Would you like me to issue you a\n"
	.string "CONTEST PASS?$"

FallarborTown_ContestLobby_Text_1A6583::
	.string "Here you go!$"

FallarborTown_ContestLobby_Text_AlreadyHasContestPass::
	.string "Oh?\p"
	.string "We've already issued you a CONTEST\n"
	.string "PASS, {PLAYER}.\p"
	.string "Please come back with your CONTEST\n"
	.string "PASS.$"

FallarborTown_ContestLobby_Text_PleaseVisit::
	.string "Please visit whenever you would like\n"
	.string "to enter a CONTEST.$"

FallarborTown_ContestLobby_Text_WhichContest::
	.string "Which CONTEST would you like to enter?$"

FallarborTown_ContestLobby_Text_1A685A::
	.string "Congratulations! Your POKéMON is the\n"
	.string "CONTEST winner!\p"
	.string "We have your prize right here.\n"
	.string "Please, right this way!$"

FallarborTown_ContestLobby_Text_1A68C6::
	.string "Please come back for your prize\n"
	.string "later on.$"

FallarborTown_ContestLobby_Text_ParticipateAnotherTime::
	.string "We hope you will participate another\n"
	.string "time.$"

FallarborTown_ContestLobby_Text_ExplainContests:: @ 81A5E98
	.string "A POKéMON CONTEST involves four\n"
	.string "TRAINERS entering one POKéMON each\l"
	.string "in competitive judging.\p"
	.string "A CONTEST has two stages of judging,\n"
	.string "primary and secondary.\p"
	.string "Primary judging is a popularity poll\n"
	.string "involving the audience.\p"
	.string "Secondary judging features appeals\n"
	.string "by the POKéMON using their moves.\p"
	.string "Plan appeals carefully to earn the\n"
	.string "most attention of the JUDGE and\l"
	.string "excite the audience.\l"
	.string "Do your best to stand out.\p"
	.string "The primary and secondary scores are\n"
	.string "added at the end.\p"
	.string "The POKéMON garnering the highest\n"
	.string "score is declared the winner.$"

FallarborTown_ContestLobby_Text_ExplainContestTypes:: @ 81A609B
	.string "There are five kinds of CONTESTS.\p"
	.string "COOL, BEAUTY, CUTE, SMART, and\n"
	.string "TOUGH are the five categories.\p"
	.string "Choose the CONTEST that is right for\n"
	.string "the POKéMON you plan to enter.$"

FallarborTown_ContestLobby_Text_ExplainContestRanks:: @ 81A613F
	.string "There are four ranks of POKéMON\n"
	.string "CONTESTS.\p"
	.string "NORMAL, SUPER, HYPER and MASTER\n"
	.string "are the four ranks.\p"
	.string "In the NORMAL Rank, any POKéMON may\n"
	.string "enter.\p"
	.string "Any POKéMON that won a NORMAL Rank\n"
	.string "CONTEST may move up the SUPER Rank in\l"
	.string "the same category.\p"
	.string "In the same way, a SUPER Rank winner\n"
	.string "can move up to the HYPER Rank, and a\l"
	.string "HYPER Rank winner can advance to the\l"
	.string "MASTER Rank in the same category.\p"
	.string "A POKéMON that won in the MASTER Rank\n"
	.string "may compete in the MASTER Rank as\l"
	.string "often as its TRAINER wants.$"

FallarborTown_ContestLobby_Text_ComeThroughHere:: @ 81A6832
	.string "Please come in through here.\n"
	.string "Good luck!$"
