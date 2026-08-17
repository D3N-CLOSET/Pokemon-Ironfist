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
	msgbox SageMountains_T_YouSeemToHaveQuiteTheSpirit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SageMountains_ES_ZygardeQuestContinue
	release
	end

SageMountains_ES_ZygardeQuestContinue::
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
	.string