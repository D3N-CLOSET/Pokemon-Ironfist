SageVillage_Gauntlet_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SageVillage_Gauntlet_OnTransition
	.byte 0

SageVillage_Gauntlet_OnTransition:
    cleartrainerflag TRAINER_D3N_AR
    cleartrainerflag TRAINER_NEIGHBOR
    end

Route121_Gauntlet_EventScript_D3N::
	faceplayer
	trainerbattle_single TRAINER_D3N_AR, Gauntlet_Text_IntroD3N, Gauntlet_Text_Defeat_67
	msgbox Gauntlet_Text_PostBattleDih, MSGBOX_AUTOCLOSE
	end


Route121_Gauntlet_EventScript_Neighbor::
	faceplayer
	trainerbattle_double TRAINER_NEIGHBOR, Gauntlet_Text_IntroNeigh, Gauntlet_Text_Defeat_69, Gauntlet_Text_NeighNotEnoughMons
	msgbox Gauntlet_Text_PostBattleDih, MSGBOX_AUTOCLOSE
	end
