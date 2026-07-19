SilverFalls_MapScripts::
	.byte 0

SilverFalls_EventScript_Sign::
    msgbox SilverFalls_Text_Sign, MSGBOX_SIGN
    end

SilverFalls_Text_Sign:
    .string "Silver Falls$"

SilverFalls_EventScript_Drake::
    lock
    msgbox SilverFalls_Text_Drake, MSGBOX_DEFAULT
    release
    end

SilverFalls_EventScript_Sidney::
    faceplayer
    msgbox SilverFalls_Text_Sidney, MSGBOX_NPC
    end

SilverFalls_EventScript_Phoebe::
    faceplayer
    msgbox SilverFalls_Text_Phoebe, MSGBOX_NPC
    end

SilverFalls_EventScript_Glacia::
    faceplayer
    msgbox SilverFalls_Text_Glacia, MSGBOX_NPC
    end

SilverFalls_Text_Drake:
    .string "The Silver Falls....\p"
    .string "The beauty of it is staggering.$"

SilverFalls_Text_Sidney:
    .string "Hello {PLAYER}.\p"
    .string "Did you know?\p"
    .string "Silver Falls is the largest waterfall\n"
    .string "In all of Hoenn?\p"
    .string "People come for vacation here every year.$"

SilverFalls_Text_Phoebe:
    .string "The Silver Falls is a beautiful\n"
    .string "waterfall.\p"
    .string "Beautiful flowers grow near it as well.\p"
    .string "It's very peaceful here.\p"
    .string "Don't you think the same, {PLAYER}?$"

SilverFalls_Text_Glacia:
    .string "It is always refreshing to visit\n"
    .string "this place every year.\p"
    .string "It's almost like heaven.$"
