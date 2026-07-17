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
	pokemartlistend

SageVill_Mart_EventScript_Boy::
	goto_if_set FLAG_TALKED_TO_SAGE_BOY, SageVill_Mart_Text_Boy
	faceplayer
	lock
	msgbox SageVill_Mart_Text_FirstBoy, MSGBOX_NPC
	giveitem ITEM_GRACIDEA
	giveitem ITEM_REVEAL_GLASS
	giveitem ITEM_DNA_SPLICERS
	giveitem ITEM_PRISON_BOTTLE
	giveitem ITEM_N_SOLARIZER
	giveitem ITEM_N_LUNARIZER
	setflag FLAG_TALKED_TO_SAGE_BOY
	release
	end

SageVill_Mart_Text_FirstBoy:
	.string "Sage Island trades regularly with other\n"
	.string "regions.\p"
	.string "That's why we have so many unique\n"
	.string "items here.\p"
	.string "Here take these.$"

SageVill_Mart_Text_Boy:
	.string "Sage Island trades regularly with other\n"
	.string "regions.\p"
	.string "That's why we have so many\n"
	.string "unique items here.$"

SageVill_Mart_EventScript_Cook::
	faceplayer
	lock
	goto_if_set  FLAG_SHOAL_ICY_UNUSED, SageVill_Mart_EventScript_CanCook
	msgbox SageVill_Mart_Text_Cook, MSGBOX_NPC
	giveitem ITEM_HELIX_FOSSIL
	giveitem ITEM_DOME_FOSSIL
	giveitem ITEM_OLD_AMBER
	giveitem ITEM_ARMOR_FOSSIL
    giveitem ITEM_SKULL_FOSSIL
    giveitem ITEM_COVER_FOSSIL
    giveitem ITEM_PLUME_FOSSIL
    giveitem ITEM_JAW_FOSSIL
    giveitem ITEM_SAIL_FOSSIL
    giveitem ITEM_FOSSILIZED_BIRD
    giveitem ITEM_FOSSILIZED_FISH
    giveitem ITEM_FOSSILIZED_DRAKE
    giveitem ITEM_FOSSILIZED_DINO
	setflag FLAG_SHOAL_ICY_UNUSED
	release
	end

SageVill_Mart_EventScript_CanCook::
	faceplayer
	msgbox SageVill_Mart_Text_CookNext, MSGBOX_NPC
	release
	end

SageVill_Mart_Text_CookNext:
	.string "That Gauntlet building came out\n"
	.string "of nowhereover the spot of my\l"
	.string " lovely shop!\p"
	.string "And the village folks don't even remember\n"
	.string "my shop anymore\p!"
	.string "What is this blasphemy!$"

SageVill_Mart_Text_Cook:
	.string "That Gauntlet building came out\n"
	.string "of nowhereover the spot of my\l"
	.string " lovely shop!\p"
	.string "And the village folks don't even remember\n"
	.string "my shop anymore\p!"
	.string "What is this blasphemy!\p"
	.string "I am so mad that I want to give you\n"
	.string "these fossils!$"

