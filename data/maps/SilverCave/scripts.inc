SilverCave_MapScripts::
	.byte 0

SilverCave_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_SILVER_NPC_TRADE_COMPLETED, SilverCave_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MEWTWO, SilverCave_Text_IllTradeIfYouWant, SilverCave_EventScript_DeclineTrade, SilverCave_EventScript_NotRequestedMon, SilverCave_Text_PleaseBeGoodToMyPokemon
	setflag FLAG_SILVER_NPC_TRADE_COMPLETED
	release
	end

SilverCave_EventScript_DeclineTrade::
	msgbox SilverCave_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

SilverCave_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox SilverCave_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

SilverCave_EventScript_TradeCompleted::
	msgbox SilverCave_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

SilverCave_Text_IllTradeIfYouWant:
	.string "Huh? My POKéMON is TUFF?\n"
	.string "Sure, I knew that.\p"
	.string "But if you really want, I'm willing\n"
	.string "to trade it to you.\p"
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

SilverCave_Text_PleaseBeGoodToMyPokemon:
	.string "Hahahah\n"
	.string "It's yours my friend.$"

SilverCave_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

SilverCave_Text_YouDontWantToThatsOkay:
	.string "Your missing out on TUFFNESS,\n"
	.string "my friend.$"

SilverCave_Text_AnyPokemonCanBeCute:
	.string "Any POKéMON can be TUFF if you raise\n"
	.string "it with beers and tuffness.$"

