SageVillage_Mart_MapScripts::
	.byte 0

SageVill_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SageVill_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_SACRED_ASH
	.2byte ITEM_SWEET_HEART
	.2byte ITEM_PEWTER_CRUNCHIES
	.2byte ITEM_RAGE_CANDY_BAR
	.2byte ITEM_OLD_GATEAU
	.2byte ITEM_CASTELIACONE
	.2byte ITEM_LUMIOSE_GALETTE
	.2byte ITEM_SHALOUR_SABLE
	.2byte ITEM_BIG_MALASADA
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_HELIX_FOSSIL
	.2byte ITEM_DOME_FOSSIL
	.2byte ITEM_OLD_AMBER
	.2byte ITEM_ARMOR_FOSSIL
    .2byte ITEM_SKULL_FOSSIL
    .2byte ITEM_COVER_FOSSIL
    .2byte ITEM_PLUME_FOSSIL
    .2byte ITEM_JAW_FOSSIL
    .2byte ITEM_SAIL_FOSSIL
    .2byte ITEM_FOSSILIZED_BIRD
    .2byte ITEM_FOSSILIZED_FISH
    .2byte ITEM_FOSSILIZED_DRAKE
    .2byte ITEM_FOSSILIZED_DINO
	pokemartlistend

SageVill_Mart_EventScript_Boy::
	goto_if_set FLAG_TALKED_TO_SAGE_BOY, SageVill_Mart_Text_Boy
	faceplayer
	msgbox SageVill_Mart_Text_FirstBoy, MSGBOX_NPC
	giveitem ITEM_GRACIDEA
	giveitem ITEM_REVEAL_GLASS
	giveitem ITEM_DNA_SPLICERS
	giveitem ITEM_PRISON_BOTTLE
	giveitem ITEM_N_SOLARIZER
	giveitem ITEM_N_SOLARIZER
	giveitem ITEM_N_LUNARIZER
	setflag FLAG_TALKED_TO_SAGE_BOY
	end

SageVill_Mart_Text_FirstBoy:
	.string "Sage Island trades regularly with other\n"
	.string "regions.\p"
	.string "That's why we have so many unique\n"
	.string "items here.\p"
	.string "Here take these.$"

SageVill_Mart_Text_Boy:
	.string "Sage Island trades regularly with other\p"
	.string "regions.\p"
	.string "That's why we have so many unique\p"
	.string "items here.$"

SageVill_Mart_EventScript_Cook::
	faceplayer
	msgbox SageVill_Mart_Text_Boy, MSGBOX_NPC
	end

SageVill_Mart_Text_Cook:
	.string "That Gauntlet building came out of nowhere\p"
	.string "over the spot of my lovely shop!\p"
	.string "And the village folks don't even remember my shop\p"
	.string "anymore!"
	.string "What is this blasphemy!"
