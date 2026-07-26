SlateportCity_ContestLobby_MapScripts:: @ 81539C1
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_ContestLobby_OnTransition
	.byte 0

SlateportCity_ContestLobby_OnTransition:: @ 81539C7
	call SlateportCity_ContestLobby_EventScript_TryShowContestReporter
	end

SlateportCity_ContestLobby_EventScript_ContestReceptionist::
	special ClearLinkContestFlags
	call SlateportCity_ContestLobby_EventScript_SpeakToContestReceptionist
	call SlateportCity_ContestLobby_EventScript_LeadToContestHall
	special SetContestTrainerGfxIds
	call LilycoveCity_ContestLobby_EventScript_SetPlayerGfx
	call SlateportCity_ContestLobby_EventScript_SetContestType
	call SlateportCity_ContestLobby_EventScript_WarpToContestHall
	waitstate
	end

SlateportCity_ContestLobby_EventScript_WarpToContestHall::
	setflag FLAG_ENTERED_CONTEST
	setvar VAR_CONTEST_LOCATION, 3
	switch VAR_CONTEST_CATEGORY
	case CONTEST_CATEGORY_COOL, SlateportCity_ContestLobby_EventScript_WarpToCoolContestHall
	case CONTEST_CATEGORY_BEAUTY, SlateportCity_ContestLobby_EventScript_WarpToBeautyContestHall
	case CONTEST_CATEGORY_CUTE, SlateportCity_ContestLobby_EventScript_WarpToCuteContestHall
	case CONTEST_CATEGORY_SMART, SlateportCity_ContestLobby_EventScript_WarpToSmartContestHall
	case CONTEST_CATEGORY_TOUGH, SlateportCity_ContestLobby_EventScript_WarpToToughContestHall
	return

SlateportCity_ContestLobby_EventScript_WarpToCoolContestHall::
	setwarp MAP_CONTEST_HALL_COOL, 7, 5
	special DoContestHallWarp
	return

SlateportCity_ContestLobby_EventScript_WarpToBeautyContestHall::
	setwarp MAP_CONTEST_HALL_BEAUTY, 7, 5
	special DoContestHallWarp
	return

SlateportCity_ContestLobby_EventScript_WarpToCuteContestHall::
	setwarp MAP_CONTEST_HALL_CUTE, 7, 5
	special DoContestHallWarp
	return

SlateportCity_ContestLobby_EventScript_WarpToSmartContestHall::
	setwarp MAP_CONTEST_HALL_SMART, 7, 5
	special DoContestHallWarp
	return

SlateportCity_ContestLobby_EventScript_WarpToToughContestHall::
	setwarp MAP_CONTEST_HALL_TOUGH, 7, 5
	special DoContestHallWarp
	return

SlateportCity_ContestLobby_EventScript_SetContestType::
	switch VAR_CONTEST_RANK
	case CONTEST_RANK_NORMAL, SlateportCity_ContestLobby_EventScript_SetNormalContestType
	return

SlateportCity_ContestLobby_EventScript_SetNormalContestType::
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
	return

SlateportCity_ContestLobby_EventScript_SetSuperContestType::
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
	return



SlateportCity_ContestLobby_EventScript_LeadToContestHall:: @ 8155448
	lockall
	applymovement 1, SlateportCity_ContestLobby_Movement_three
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 4, 2, METATILE_Contest_WallShadow, 1
	setmetatile 4, 3, METATILE_Contest_FloorShadow, 1
	special DrawWholeMapView
	applymovement 1, SlateportCity_ContestLobby_Movement_four
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 4, 2, METATILE_Contest_CounterFlap_Top, 1
	setmetatile 4, 3, METATILE_Contest_CounterFlap_Bottom, 1
	special DrawWholeMapView
	delay 20
	applymovement 1, SlateportCity_ContestLobby_Movement_six
	waitmovement 0
	applymovement LOCALID_PLAYER, SlateportCity_ContestLobby_Movement_two
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_ComeThroughHere, MSGBOX_DEFAULT
	closemessage
	applymovement 1, SlateportCity_ContestLobby_Movement_five
	applymovement LOCALID_PLAYER, SlateportCity_ContestLobby_Movement_one
	waitmovement 0
	releaseall
	return

SlateportCity_ContestLobby_Movement_one:: @ 81554C0
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

SlateportCity_ContestLobby_Movement_two:: @ 81554CA
	walk_in_place_fast_left
	step_end

SlateportCity_ContestLobby_Movement_three:: @ 81554CC
	walk_left
	walk_in_place_fast_down
	step_end

SlateportCity_ContestLobby_Movement_four:: @ 81554CF
	walk_down
	walk_down
	walk_in_place_fast_up
	step_end

SlateportCity_ContestLobby_Movement_five:: @ 81554D3
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

SlateportCity_ContestLobby_Movement_six:: @ 81554DC
	walk_in_place_fast_right
	step_end

SlateportCity_ContestLobby_EventScript_BerryBlender1:: @ 81B761E
	goto BerryBlender_EventScript_BerryBlender2
	end


SlateportCity_ContestLobby_EventScript_Man:: @ 81554DE
	msgbox SlateportCity_ContestLobby_Text_WantToRaiseUltimateMon, MSGBOX_NPC
	end

SlateportCity_ContestLobby_EventScript_Girl:: @ 81554E7
	msgbox SlateportCity_ContestLobby_Text_DoYourFriendsHaveBerries, MSGBOX_NPC
	end

SlateportCity_ContestLobby_EventScript_Woman:: @ 81554F0
	msgbox SlateportCity_ContestLobby_Text_ContestWinnerPostersOnWall, MSGBOX_NPC
	end

SlateportCity_ContestLobby_EventScript_LittleGirl:: @ 81554F9
	lockall
	goto_if_set FLAG_RECEIVED_POKEBLOCK_CASE, SlateportCity_ContestLobby_EventScript_HavePokeblockCase
	applymovement 7, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_ContestLobby_Text_YouCanHavePokeblockCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	releaseall
	end

SlateportCity_ContestLobby_EventScript_HavePokeblockCase:: @ 8155526
	msgbox SlateportCity_ContestLobby_Text_PutPokeblocksInThere, MSGBOX_NPC
	end

SlateportCity_ContestLobby_EventScript_ContestHallWinner:: @ 815552F
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_3
	releaseall
	end
SlateportCity_ContestLobby_EventScript_Boy:: @ 8155536
	msgbox SlateportCity_ContestLobby_Text_Boy, MSGBOX_NPC
	end

SlateportCity_ContestLobby_EventScript_BerryBlenderSpeedRecords::
	lockall
	special ShowBerryBlenderRecordWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end






SlateportCity_ContestLobby_Text_WantToRaiseUltimateMon:: @ 817C937
	.string "I want to raise a POKéMON that's\n"
	.string "the ultimate in “great” for both\l"
	.string "battles and CONTESTS.\p"
	.string "It's vexing, trying to figure out\n"
	.string "which moves I should make it learn.$"

SlateportCity_ContestLobby_Text_DoYourFriendsHaveBerries:: @ 817C9D5
	.string "Do any of your friends have any\n"
	.string "BERRIES?\p"
	.string "You can use that BERRY BLENDER and\n"
	.string "make {POKEBLOCK}S with your friends!\p"
	.string "You should try it - it's a lot of fun!$"

SlateportCity_ContestLobby_Text_YouCanHavePokeblockCase:: @ 817CA67
	.string "I have two, so you can have one!$"

SlateportCity_ContestLobby_Text_PutPokeblocksInThere:: @ 817CA88
	.string "Make {POKEBLOCK}S and put them in there.\p"
	.string "When you make a {POKEBLOCK}, everyone\n"
	.string "has to put in a different BERRY.$"

SlateportCity_ContestLobby_Text_ContestWinnerPostersOnWall:: @ 817CAEC
	.string "If you win a CONTEST, they put up a\n"
	.string "poster of your POKéMON on the wall.\p"
	.string "It will have a portrait of your\n"
	.string "POKéMON and both your names.$"

SlateportCity_ContestLobby_Text_Boy::
	.string "I fucking hate this game.\p"
	.string "Why did he have to make it more\n"
	.string "difficult?$"
