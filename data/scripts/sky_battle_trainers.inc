@ Note: There are two other sky battle trainers that are not called from here, check Jagged Pass map's script and Route 115 map's script to find them


SkyBattle_ES_Virat::
    lock
	faceplayer
	goto_if_defeated TRAINER_VIRAT, SkyBattle_ES_ViratDefeated
	special TrySkyBattle
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NotEligibleForSkyBattles
	setflag FLAG_SYS_SKY_BATTLE
	trainerbattle_single TRAINER_VIRAT, SkyBattle_T_ViratIntro, SkyBattle_T_ViratDefeat, SkyBattle_ES_ViratDefeated
	msgbox SkyBattle_T_ViratPostBattle, MSGBOX_DEFAULT
	clearflag FLAG_SYS_SKY_BATTLE
	release
	end

SkyBattle_ES_ViratDefeated::
	clearflag FLAG_SYS_SKY_BATTLE
	msgbox SkyBattle_T_ViratPostBattle, MSGBOX_NPC
	release
	end

SkyBattle_T_ViratIntro:
    .string "The wind is perfect today, Let's\n"
    .string "see if your POKéMON can handle\l"
    .string "the intense turbulence up here!$"

SkyBattle_T_ViratDefeat:
    .string "Down to earth with a crash...\n"
    .string "You read the winds better than I\l"
    .string "did....$"

SkyBattle_T_ViratPostBattle:
    .string "My Swellow gets even stronger when\n"
    .string "the pressure is on.\p"
    .string "You've trained your team well to\n"
    .string "withstand our power!$"

SkyBattle_ES_Ishowspeed::
    lock
	faceplayer
	goto_if_defeated TRAINER_ISHOWSPEED, SkyBattle_ES_IshowspeedDefeated
	special TrySkyBattle
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NotEligibleForSkyBattles
	setflag FLAG_SYS_SKY_BATTLE
	trainerbattle_single TRAINER_ISHOWSPEED, SkyBattle_T_IshowspeedIntro, SkyBattle_T_IshowspeedDefeat, SkyBattle_ES_IshowspeedDefeated
	msgbox SkyBattle_T_IshowspeedPostBattle, MSGBOX_DEFAULT
	clearflag FLAG_SYS_SKY_BATTLE
	release
	end

SkyBattle_ES_IshowspeedDefeated::
	clearflag FLAG_SYS_SKY_BATTLE
	msgbox SkyBattle_T_IshowspeedPostBattle, MSGBOX_NPC
	release
	end

SkyBattle_T_IshowspeedIntro:
    .string "(BARK BARK!)$"

SkyBattle_T_IshowspeedDefeat:
    .string "Are we serious rn bro?$"

SkyBattle_T_IshowspeedPostBattle:
    .string "C'mon bru, I almost won that!$"


