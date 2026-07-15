SageVillage_PkmnCenter1F_MapScripts::
	.byte 0

SageVill_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SageVill_PokemonCenter_1F_EventScript_Leaf::
	faceplayer
	msgbox SageVill_PokemonCenter_1F_Text_Leaf, MSGBOX_NPC
	end

SageVill_PokemonCenter_1F_Text_Leaf:
	.string "Man, it's so cold in here.\p"
	.string "I should've brought a sweater myself.\p"
	.string "Come, on, when will Red come here?$"
