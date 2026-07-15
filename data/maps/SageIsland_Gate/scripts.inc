SageIsland_Gate_MapScripts::
	.byte 0

SageIsland_Gate_EventScrpt_Expert::
	lock
	msgbox SageIsland_Gate_Text_Whisper, MSGBOX_NPC
	release
	end

SageIsland_Gate_Text_Whisper:
	.string "Man1: “What do you think of\n"
	.string "Hoenn's new champion?”\p"
	.string "Man2: “That kid is good but,\n"
	.string "nowhere near Steven.”$"
