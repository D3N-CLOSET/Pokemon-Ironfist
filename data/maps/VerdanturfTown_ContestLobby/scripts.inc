VerdanturfTown_ContestLobby_MapScripts:: @ 8153D6A
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_ContestLobby_MapScript1_TryShowContestReporter
	.byte 0

VerdanturfTown_ContestLobby_MapScript1_TryShowContestReporter:: @ 8153D70
	call VerdanturfTown_ContestLobby_EventScript_TryShowContestReporter
	end

VerdanturfTown_ContestLobby_EventScript_ContestReceptionist::
	special ClearLinkContestFlags
	call VerdanturfTown_ContestLobby_EventScript_SpeakToContestReceptionist
	call VerdanturfTown_ContestLobby_EventScript_LeadToContestHall
	special SetContestTrainerGfxIds
	call LilycoveCity_ContestLobby_EventScript_SetPlayerGfx
	call VerdanturfTown_ContestLobby_EventScript_SetContestType
	call VerdanturfTown_ContestLobby_EventScript_WarpToContestHall
	waitstate
	end



VerdanturfTown_ContestLobby_EventScript_LeadToContestHall:: @ 8153DA1
	lockall
	applymovement 1, VerdanturfTown_ContestLobby_Movement_Three
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 4, 2, METATILE_Contest_WallShadow, 1
	setmetatile 4, 3, METATILE_Contest_FloorShadow, 1
	special DrawWholeMapView
	applymovement 1, VerdanturfTown_ContestLobby_Movement_Four
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 4, 2, METATILE_Contest_CounterFlap_Top, 1
	setmetatile 4, 3, METATILE_Contest_CounterFlap_Bottom, 1
	special DrawWholeMapView
	delay 20
	applymovement 1, VerdanturfTown_ContestLobby_Movement_Six
	waitmovement 0
	applymovement LOCALID_PLAYER, VerdanturfTown_ContestLobby_Movement_Two
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_ComeThroughHere, MSGBOX_DEFAULT
	closemessage
	applymovement 1, VerdanturfTown_ContestLobby_Movement_Five
	applymovement LOCALID_PLAYER, VerdanturfTown_ContestLobby_Movement_One
	waitmovement 0
	releaseall
	return

VerdanturfTown_ContestLobby_Movement_One:: @ 8153E19
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

VerdanturfTown_ContestLobby_Movement_Two:: @ 8153E23
	walk_in_place_fast_left
	step_end

VerdanturfTown_ContestLobby_Movement_Three:: @ 8153E25
	walk_left
	walk_in_place_fast_down
	step_end

VerdanturfTown_ContestLobby_Movement_Four:: @ 8153E28
	walk_down
	walk_down
	walk_in_place_fast_up
	step_end

VerdanturfTown_ContestLobby_Movement_Five:: @ 8153E2C
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

VerdanturfTown_ContestLobby_Movement_Six:: @ 8153E35
	walk_in_place_fast_right
	step_end


VerdanturfTown_ContestLobby_EventScript_WarpToContestHall::
	setflag FLAG_ENTERED_CONTEST
	setvar VAR_CONTEST_LOCATION, 1
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, VerdanturfTown_ContestLobby_EventScript_WarpToCoolContestHall
	case CONTEST_CATEGORY_BEAUTY, VerdanturfTown_ContestLobby_EventScript_WarpToBeautyContestHall
	case CONTEST_CATEGORY_CUTE, VerdanturfTown_ContestLobby_EventScript_WarpToCuteContestHall
	case CONTEST_CATEGORY_SMART, VerdanturfTown_ContestLobby_EventScript_WarpToSmartContestHall
	case CONTEST_CATEGORY_TOUGH, VerdanturfTown_ContestLobby_EventScript_WarpToToughContestHall
	return


VerdanturfTown_ContestLobby_EventScript_WarpToCoolContestHall::
	setwarp MAP_CONTEST_HALL_COOL, 7, 5
	special DoContestHallWarp
	return

VerdanturfTown_ContestLobby_EventScript_WarpToBeautyContestHall::
	setwarp MAP_CONTEST_HALL_BEAUTY, 7, 5
	special DoContestHallWarp
	return

VerdanturfTown_ContestLobby_EventScript_WarpToCuteContestHall::
	setwarp MAP_CONTEST_HALL_CUTE, 7, 5
	special DoContestHallWarp
	return

VerdanturfTown_ContestLobby_EventScript_WarpToSmartContestHall::
	setwarp MAP_CONTEST_HALL_SMART, 7, 5
	special DoContestHallWarp
	return

VerdanturfTown_ContestLobby_EventScript_WarpToToughContestHall::
	setwarp MAP_CONTEST_HALL_TOUGH, 7, 5
	special DoContestHallWarp
	return


VerdanturfTown_ContestLobby_EventScript_SetContestType::
	switch VAR_CONTEST_RANK
	case CONTEST_RANK_SUPER, VerdanturfTown_ContestLobby_EventScript_SetSuperContestType
	return

VerdanturfTown_ContestLobby_EventScript_SetSuperContestType::
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
	return


VerdanturfTown_ContestLobby_EventScript_ContestHallWinner::
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_5
	releaseall
	end


VerdanturfTown_ContestLobby_EventScript_GonnaBeTenseBoy:: @ 8153E3E
	msgbox VerdanturfTown_ContestLobby_Text_GonnaBeTense, MSGBOX_NPC
	end

VerdanturfTown_ContestLobby_EventScript_AttractWoman:: @ 8153E47
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ATTRACT, VerdanturfTown_ContestLobby_EventScript_AttractWomanAfterTMGiven
	msgbox VerdanturfTown_ContestLobby_Text_GiveAttract, MSGBOX_DEFAULT
	giveitem ITEM_TM45
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ATTRACT
	release
	end

VerdanturfTown_ContestLobby_EventScript_AttractWomanAfterTMGiven:: @ 8153E76
	msgbox VerdanturfTown_ContestLobby_Text_AttractWomanAfterTMGiven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_ContestLobby_EventScript_WhichContest:: @ 8153E80
	msgbox VerdanturfTown_ContestLobby_Text_WhichContest, MSGBOX_NPC
	end

VerdanturfTown_ContestLobby_EventScript_BerryBlenderSpeedRecords::
	lockall
	special ShowBerryBlenderRecordWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

VerdanturfTown_ContestLobby_Text_GonnaBeTense:: @ 8177D6C
	.string "I went in through the entrance and\n"
	.string "took a look around the CONTEST hall.\p"
	.string "Getting up on that big stage...\n"
	.string "It's going to be tense!$"

VerdanturfTown_ContestLobby_Text_GiveAttract:: @ 8177DEC
	.string "Oh, my love for POKéMON...\n"
	.string "The attraction they evoke in me...\p"
	.string "Whoops!\n"
	.string "You weren't meant to see that!\l"
	.string "Well, anyway.\p"
	.string "If you're entering a CONTEST, try this\n"
	.string "move on for size.$"

VerdanturfTown_ContestLobby_Text_AttractWomanAfterTMGiven:: @ 8177E98
	.string "My feelings for POKéMON...\n"
	.string "Oh, they attract me so...$"

VerdanturfTown_ContestLobby_Text_WhichContest:: @ 8177ECD
	.string "Which CONTEST are you planning on\n"
	.string "entering?\p"
	.string "If you're entering a COOL CONTEST,\n"
	.string "a cool POKéMON has to be the one!\p"
	.string "Pick a POKéMON worthy of the CONTEST\n"
	.string "theme, and make sure it has the\l"
	.string "right set of moves to match.\p"
	.string "That's fundamental!$"
