SageMountains_MapScripts::
	.byte 0

SageMountains_ES_ZygardeQuest::
	lock
	faceplayer
	goto_if_unset FLAG_TOOK_ZYGARDE_QUEST, SageMountains_ES_TakeZygardeQuest
	goto_if_unset FLAG_QUEST_INFO_TAKEN, SageMountains_ES_YouNeedToCatchZygardeFirst
	goto_if_unset FLAG_FINISHED_QUEST_ZYGARDE, SageMountains_ES_ShowZygarde
	msgbox SageMountains_T_QuestDoneAlready, MSGBOX_DEFAULT
	release
	end

SageMountains_ES_TakeZygardeQuest::
	setflag FLAG_TOOK_ZYGARDE_QUEST @ Intro should not repeat
	msgbox SageMountains_T_YouSeemToHaveQuiteTheSpirit, MSGBOX_DEFAULT
	goto SageMountains_ES_ZygardeQuest

SageMountains_ES_YouNeedToCatchZygardeFirst::
	msgbox SageMountains_T_YouNeedToCatchZygardeFirst, MSGBOX_DEFAULT
	setflag FLAG_QUEST_INFO_TAKEN
	release
	end

SageMountains_ES_ShowZygarde::
	msgbox SageMountains_T_HaveYouCaughtIt, MSGBOX_DEFAULT
	checkspecies SPECIES_ZYGARDE_10 @ Player will only have 10% without cheats
	goto_if_eq VAR_RESULT, FALSE, SageMountains_ES_ShowZygarde2
	goto_if_eq VAR_RESULT, TRUE, SageMountains_ES_ShowZygardeTrue
	msgbox SageMountains_T_NotZygarde, MSGBOX_DEFAULT
	release
	end

SageMountains_ES_ShowZygarde2::
	checkspecies SPECIES_ZYGARDE_10_POWER_CONSTRUCT @ Player will only have 10% without cheats
	goto_if_eq VAR_RESULT, TRUE, SageMountains_ES_ShowZygardeTrue
	msgbox SageMountains_T_NotZygarde, MSGBOX_DEFAULT
	release
	end

SageMountains_ES_ShowZygardeTrue::
	setflag FLAG_FINISHED_QUEST_ZYGARDE
	msgbox SageMountains_T_YouDidIt, MSGBOX_DEFAULT
	giveitem ITEM_ZYGARDE_CUBE
	release
	end

SageMountains_T_YouSeemToHaveQuiteTheSpirit:
	.string "Huh? Who are you? I have never seen anyone\n"
	.string "enter the Sage Mountains in a decade.\p"
	.string "Oh, so you are {PLAYER}, I see.\n"
	.string "I think I heard about you a while ago.\p"
	.string "Anyways; Hi, I am Vera, nice to meet you.\n"
	.string "I live at the village with my sister.\p"
	.string "What am I doing here you may ask?\n"
	.string "Well, I came here because I wanted to test\l"
	.string "a myth from hundreds of years ago.\p"
	.string "Sorry I cannot explain it right now as it\n"
	.string "is too complex for a young soul like you.\p"
	.string "But I will say one thing, which is I have\n"
	.string "found this weird shaped object which in\n"
	.string "ancient mythology, helps transform the\l"
	.string "legendary POKéMON Zygarde.\p"
	.string "It is said to be given to the person\n"
	.string "that has managed to control the sheer\l"
	.string "power of Zygarde.\p"
	.string "..............................\n"
	.string "..............................\p"
	.string "You.... are the new champion of\n"
	.string "HOENN, am I right?.....\p"
	.string "Well that's awesome, since you are the\n"
	.string "champion now, I think you have the\l"
	.string "capability to capture Zygarde.\p"
	.string "Am I right?$"

SageMountains_T_YouNeedToCatchZygardeFirst:
	.string "Great. So, first you need to\n"
	.string "catch Zygarde.\p"
	.string "I think that it might be in an area\n"
	.string "that is quite strange let's say.$"

SageMountains_T_HaveYouCaughtIt:
	.string "Have you managed to capture it?\n"
	.string "Let's see..........$"

SageMountains_T_NotZygarde:
	.string "Looks like you have not caught it yet.\n"
	.string "I think that it might be in an area\n"
	.string "that is quite strange let's say.$"

SageMountains_T_YouDidIt:
	.string "{PLAY_BGM MUS_OBTAIN_BADGE}Wow, you have actually did it! Amazing!{WAIT_SE}\n"
	.string "Now, I want you to take this mythical\l"
	.string "item said by the local myth.$"

SageMountains_T_QuestDoneAlready:
	.string "How long am I staying here?\n"
	.string "Well, I am trying to catch a vanilite\l"
	.string "right now.\p"
	.string "I'll return to the village once I\n"
	.string "manage to catch it.$"
