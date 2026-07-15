SilverIsland_Plateau_2_MapScripts::
	.byte 0

SilverPlatH_EventScript_Sign::
    msgbox SilverPlatH_Text_Sign, MSGBOX_SIGN
    end

SilverPlatH_Text_Sign:
    .string "Silver Plateau$"

SilverPlateau_Mart_EventScript_BlackMarket::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SilverPlateau_Mart_May
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SilverPlateau_Mart_May:
	.2byte ITEM_LEVEL_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_MOON_BALL
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_LOVE_BALL
	.2byte ITEM_FAST_BALL
    .2byte ITEM_HEAVY_BALL
    .2byte ITEM_DREAM_BALL
    .2byte ITEM_SPORT_BALL
    .2byte ITEM_PARK_BALL
    .2byte ITEM_BEAST_BALL
    .2byte ITEM_CHERISH_BALL
    .2byte ITEM_ELIXER
    .2byte ITEM_MAX_ELIXIR
    .2byte ITEM_ETHER
    .2byte ITEM_MAX_ETHER
    .2byte ITEM_RARE_CANDY
    .2byte ITEM_EXP_CANDY_XS
    .2byte ITEM_EXP_CANDY_S
    .2byte ITEM_EXP_CANDY_M
    .2byte ITEM_EXP_CANDY_L
    .2byte ITEM_EXP_CANDY_XL
    .2byte ITEM_RETRO_MAIL
    .2byte ITEM_FAB_MAIL
    .2byte ITEM_DREAM_MAIL
	pokemartlistend
