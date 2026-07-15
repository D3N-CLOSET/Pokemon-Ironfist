LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
	.2byte ITEM_MOON_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_UPGRADE
	.2byte ITEM_PROTECTOR
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_REAPER_CLOTH
	.2byte ITEM_PRISM_SCALE
	.2byte ITEM_OVAL_STONE
	pokemartlistend

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_TM_THUNDER
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
	pokemartlistend

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.string "Hmm…\p"
	.string "An attacking move…\n"
	.string "Or a defensive move…\p"
	.string "It's no easy matter to decide which TM\n"
	.string "moves should be taught to POKéMON…$"

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.string "There are so many different kinds of\n"
	.string "TM moves.\p"
	.string "A catalog I read said there are fifty\n"
	.string "different kinds.$"

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "DUDE THE NEW DUSK STONE IS INSANE!\p"
	.string "IT EVOLVED MY MURKROW DUDE.$"

