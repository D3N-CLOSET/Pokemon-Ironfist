PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_EventScript_Hecker::
	lock
	faceplayer
	msgbox PacifidlogTown_Text_Hecker, MSGBOX_NPC
	release
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "The sea between PACIFIDLOG and\n"
	.string "SLATEPORT has a fast-running tide.\p"
	.string "If you decide to SURF, you could end\n"
	.string "up swept away somewhere else.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "See, isn't it neat?\n"
	.string "These houses are on water!\p"
	.string "I was born here!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "The SKY PILLAR?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in PACIFIDLOG,\n"
	.string "that suits me fine.$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIDLOG TOWN\p"
	.string "“Where the morning sun smiles upon\n"
	.string "the waters.”$"

PacifidlogTown_Text_Hecker:
	.string "Hey {PLAYER}, I am D3N_AR,\p"
	.string "aka the dev of this hack.\p"
	.string "I am here to give ya a tip.\p"
	.string "It is going to make ya life\n"
	.string "easier.\p"
	.string "Click START while holding R.\p"
	.string "Thanks for playing though!$"

PacifidlogTown_EventScript_MYhome::
	msgbox PacifidlogTown_Text_MYhome, MSGBOX_SIGN
	end

PacifidlogTown_Text_MYhome:
	.string "MY HOME\p"
	.string "“The home of the dev of this hack.\p"
	.string "Now allowing indoor cycling!”$"

PacifidlogTown_EventScript_KyogreStatue::
	msgbox PacifidlogTown_Text_KyogreStatue, MSGBOX_SIGN
	end

PacifidlogTown_Text_KyogreStatue:
	.string "It's a statue of KYOGRE!$"
