CeladonCity_DepartmentStore_2F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_2F_EventScript_UnusedNPC::
	msgbox CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_Lass::
	msgbox CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_2F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkItems::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_TMs
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_TMs::
	.2byte ITEM_TM05
	.2byte ITEM_TM15
	.2byte ITEM_TM28
	.2byte ITEM_TM31
	.2byte ITEM_TM43
	.2byte ITEM_TM45
	.2byte ITEM_TM_ROOST
    .2byte ITEM_TM_ENERGY_BALL
    .2byte ITEM_TM_PSYSHOCK
    .2byte ITEM_TM_ENDURE
    .2byte ITEM_TM_DRAGON_PULSE
    .2byte ITEM_TM_DREAM_EATER
    .2byte ITEM_TM_GRASS_KNOT
    .2byte ITEM_TM_SWAGGER
    .2byte ITEM_TM_SLEEP_TALK
    .2byte ITEM_TM_SUBSTITUTE
    .2byte ITEM_TM_TRICK_ROOM
    .2byte ITEM_TM_WILD_CHARGE
    .2byte ITEM_TM_ROCK_POLISH
    .2byte ITEM_TM_POISON_JAB
    .2byte ITEM_TM_DARK_PULSE
    .2byte ITEM_TM_X_SCISSOR
    .2byte ITEM_TM_FLAME_CHARGE
    .2byte ITEM_TM_BULLDOZE
    .2byte ITEM_TM_NATURAL_GIFT
    .2byte ITEM_TM_PAYBACK
    .2byte ITEM_TM_GIGA_IMPACT
    .2byte ITEM_TM_ROCK_SLIDE
    .2byte ITEM_TM_INCINERATE
    .2byte ITEM_TM_SWORDS_DANCE
    .2byte ITEM_TM_DAZZLING_GLEAM
    .2byte ITEM_TM_CLOSE_COMBAT
    .2byte ITEM_TM_FOCUS_BLAST
    .2byte ITEM_TM_STONE_EDGE
    .2byte ITEM_TM_SHADOW_CLAW
    .2byte ITEM_TM_DRAIN_PUNCH
    .2byte ITEM_TM_BRINE
    .2byte ITEM_TM_CHARGE_BEAM
    .2byte ITEM_TM_FLING
    .2byte ITEM_TM_EMBARGO
    .2byte ITEM_TM_GYRO_BALL
    .2byte ITEM_TM_CAPTIVATE
    .2byte ITEM_TM_FALSE_SWIPE
    .2byte ITEM_TM_BRUTAL_SWING
    .2byte ITEM_TM_SMACK_DOWN
    .2byte ITEM_TM_ROUND
    .2byte ITEM_TM_ECHOED_VOICE
    .2byte ITEM_TM_CHILLING_WATER
    .2byte ITEM_TM_TRAILBLAZE
    .2byte ITEM_TM_PLAY_ROUGH
	.2byte ITEM_TM_FLARE_BLITZ
	.2byte ITEM_TM_SLUDGE_WAVE
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_2F_Text_SuperRepelMorePowerfulRepel::
	.string "SUPER REPEL keeps weak POKéMON at\n"
	.string "bay…\p"
	.string "Hmm, it's a more powerful REPEL.$"

CeladonCity_DepartmentStore_2F_Text_BuyReviveForLongOutings::
	.string "For long outings, you should buy\n"
	.string "REVIVE.$"

CeladonCity_DepartmentStore_2F_Text_FloorSign::
	.string "Top-Grade Items for TRAINERS!\p"
	.string "2F: TRAINER'S MARKET$"

CeladonCity_DepartmentStore_2F_Text_LanceComesToBuyCapes::
	.string "We have a customer, LANCE, who\n"
	.string "occasionally comes.\p"
	.string "He always buys capes.\p"
	.string "I wonder… Does he have many\n"
	.string "identical capes at home?$"
