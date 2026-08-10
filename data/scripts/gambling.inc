Common_EventScript_DoYouWantToRNG::
    msgbox RNG_Text_HelloThere, MSGBOX_NPC
    msgbox RNG_Text_EnterGacha, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, RNG_EventScript_LetsGamble
    msgbox RNG_Text_HaveANiceDay, MSGBOX_NPC
    end

RNG_EventScript_LetsGamble::
    checkitem ITEM_METAL_ALLOY
    goto_if_eq VAR_RESULT, FALSE, RNG_EventScript_YouDontHaveMetalAlloy
    msgbox RNG_Text_DoStartGambling, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, RNG_EventScript_HereWeGo
    msgbox RNG_Text_HaveANiceDay, MSGBOX_NPC
    end

RNG_EventScript_HereWeGo::
    removeitem ITEM_METAL_ALLOY, 1

    callnative ScrCmd_RollPokemonRNG
    copyvar VAR_TEMP_1, VAR_RESULT

    call RNG_EventScript_MidRNG
    delay 60
    closemessage
    call RNG_EventScript_PostRNG
    closemessage
    givemon VAR_RESULT, 5, ITEM_NONE
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, UnCommon_EventScript_NameReceivedBoxMon
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, UnCommon_EventScript_TransferredToPC
    goto RNG_EventScript_NoRoom
    release
    end

RNG_EventScript_YouDontHaveMetalAlloy::
    msgbox RNG_Text_YouDontHaveMetalAlloy, MSGBOX_NPC
    release
    end

RNG_EventScript_NoRoom::
    goto_if_set FLAG_SYS_PC_LANETTE, gText_PkmnTransferredLanettesPCBoxFull
    msgbox gText_PkmnTransferredSomeonesPCBoxFull, MSGBOX_NPC
    release
    end

UnCommon_EventScript_NameReceivedBoxMon::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
    msgbox Uncommon_Text_Cua, MSGBOX_NPC
    release
    end

UnCommon_EventScript_TransferredToPC::
	call Common_EventScript_NameReceivedBoxMon
	call Common_EventScript_TransferredToPC
    msgbox Uncommon_Text_Cua, MSGBOX_NPC
    release
    end

RNG_EventScript_MidRNG::
    msgbox RNG_Text_MidRNGDots, MSGBOX_DEFAULT
    return

RNG_EventScript_PostRNG::
    bufferspeciesname STR_VAR_1, VAR_RESULT
    msgbox RNG_Text_CongratsYouWonA, MSGBOX_DEFAULT
    return

RNG_EventScript_RarityBoard::
    msgbox RNG_Text_DoYouWantToReadRarityBoard, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, RNG_EventScript_RarityBoardText
    release
    end

RNG_EventScript_RarityBoardText::
    msgbox RNG_Text_RarityBoard, MSGBOX_SIGN
    end

Common_EventScript_NotEligibleForSkyBattles::
    msgbox Common_Text_NotEligibleForSkyBattles, MSGBOX_NPC
    end

Common_Text_NotEligibleForSkyBattles:
    .string "Hello, pardon me but I wanted\n"
    .string "to have a sky battle, but it looks\l"
    .string "like, you are ineligble for one.\p"
    .string "I am sorry to have taken your time.$"

Common_EventScript_NotEligibleForSkyBattlesRematch::
    msgbox Common_Text_NotEligibleForSkyBattlesRematch, MSGBOX_NPC
    end

Common_Text_NotEligibleForSkyBattlesRematch:
    .string "Hello, I wanted\n"
    .string "to have a sky battle, but it looks\l"
    .string "like, you are ineligble for one.\p"
    .string "Let's have a sky battle sometime\n"
    .string "later, okay?$"

