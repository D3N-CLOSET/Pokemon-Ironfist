NorthernCape_MapScripts::
	.byte 0

NorthernCape_EventScript_PassSign::
	msgbox NorthernCape_Text_PassSign, MSGBOX_SIGN
	end

NorthernCave_EventScript_WaterfallBorderSign::
	msgbox NorthernCape_Text_WaterfallBorderSign, MSGBOX_SIGN
	end

NorthernCave_EventScript_WaterfallBorderDownSign::
	msgbox NorthernCape_Text_WaterfallBorderDownSign, MSGBOX_SIGN
	end

NorthernCave_EventScript_FirstSteps::
	msgbox NorthernCape_Text_FirstSteps, MSGBOX_NPC
	call Common_EventScript_PlayGymBadgeFanfare
	end

NorthernCape_EventScript_D3N::
	msgbox NorthernCape_Text_D3N, MSGBOX_NPC
	end

NorthernCape_Text_PassSign:
	.string "Mountain Pass {UP_ARROW}\n"
	.string "Northern Cape {DOWN_ARROW}$"

NorthernCape_Text_WaterfallBorderSign:
	.string "Northern Cape, Sage Island, Hoenn\p"
	.string "{DOWN_ARROW} Northern Cape, Sage Island, Johto$"

NorthernCape_Text_WaterfallBorderDownSign:
	.string "Northern Cape, Sage Island, Johto\p"
	.string "{UP_ARROW} Northern Cape, Sage Island, Hoenn$"

NorthernCape_Text_FirstSteps:
	.string "Did you realize that,\p"
	.string "you took your first steps in Johto!$"

NorthernCape_Text_D3N:
	.string "What?\p"
	.string "Nah bro, Johto is NOT coming to this game.\p"
	.string "I don't got enough time for it.\p"
	.string "I mean, meow meow bitch.$"
