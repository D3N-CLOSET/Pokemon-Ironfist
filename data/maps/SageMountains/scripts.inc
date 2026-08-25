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
	.string "A stranger? A ghost?\n"
	.string "Or a stray wind?\p"
	.string "No footstep has broken\n"
	.string "the silence of these\l"
	.string "mountains in a decade.\p"
	.string "Ah... you are {PLAYER}.\n"
	.string "I remember now.\p"
	.string "The whispers of the valley\n"
	.string "carried your name to me\l"
	.string "some time ago.\p"
	.string "I am Vera. My sister and\n"
	.string "I share a quiet hearth\l"
	.string "in the village below.\p"
	.string "You wonder what brings\n"
	.string "me to these heights?\p"
	.string "I came chasing shadows-\n"
	.string "to test a myth born\l"
	.string "hundreds of winters ago.\p"
	.string "Forgive me, but its\n"
	.string "truths are quite heavy...\p"
	.string "And perhaps too tangled\n"
	.string "for a soul as young and\l"
	.string "unburdened as yours.\p"
	.string "Yet, look closer...\n"
	.string "I have unearthed this relic.\p"
	.string "Ancient texts call it a\n"
	.string "vessel meant to awaken\l"
	.string "the power of Zygarde.\p"
	.string "Legend says it chooses\n"
	.string "its own true master:\p"
	.string "One who can look into the\n"
	.string "abyss and tame the\l"
	.string "beast's fracturing power.\p"
	.string "..............................\n"
	.string "..............................\p"
	.string "The air around you changes...\n"
	.string "You wear the crown of\l"
	.string "HOENN, do you not?\p"
	.string "The new Champion...\n"
	.string "Magnificent.\p"
	.string "If anyone holds the strength\n"
	.string "to seek the order-bringer\l"
	.string "and bind it, it is you.\p"
	.string "Am I wrong?$"

SageMountains_T_YouNeedToCatchZygardeFirst:
	.string "Splendid. But first,\n"
	.string "the beast must be found.\l"
	.string "You must claim Zygarde.\p"
	.string "Seek the places where\n"
	.string "reality frays- an anomaly\l"
	.string "in this world.$"

SageMountains_T_HaveYouCaughtIt:
	.string "Has the great serpent\n"
	.string "answered your call?\l"
	.string "Let me look into\n"
	.string "your eyes..........$"

SageMountains_T_NotZygarde:
	.string "The aura of the land\n"
	.string "remains unbroken.\l"
	.string "You have not claimed it.\p"
	.string "Seek the places where\n"
	.string "reality frays- an anomaly\l"
	.string "in this world.$"

SageMountains_T_YouDidIt:
	.string "{PLAY_BGM MUS_OBTAIN_BADGE}Incredible! The stars\n"
	.string "themselves bow to your\l"
	.string "triumph! You did it!{WAIT_SE}\p"
	.string "Take this mythical relic.\n"
	.string "Let it serve the destiny\l"
	.string "promised by the old world.$"

SageMountains_T_QuestDoneAlready:
	.string "How long will I linger\n"
	.string "here in the deep snow?\p"
	.string "I find myself charmed\n"
	.string "by a lone Vanillite\l"
	.string "drifting through frost.\p"
	.string "Once its cold spirit joins\n"
	.string "mine, I shall finally\l"
	.string "return to the village.$"
