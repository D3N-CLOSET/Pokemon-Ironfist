#include "global.h"
#include "script.h"
#include "random.h"
#include "constants/species.h"
#include "event_data.h"

static u16 GetRandomPseudoSpecies(void);
static u16 GetRandomRareSpecies(void);
static u16 GetRandomUncommonSpecies(void);
static u16 GetRandomCommonSpecies(void);

u16 RollPokemonRNG(void)
{
    u16 roll = (Random() % 100) + 1;

    if (gSaveBlock2Ptr ->wishingWellPityCount >= 10)
    {
        gSaveBlock2Ptr ->wishingWellPityCount = 0;

        if (roll <= 2)  return GetRandomPseudoSpecies();
        if (roll <= 24)  return GetRandomRareSpecies();
        if (roll <= 80)  return GetRandomUncommonSpecies();
        return GetRandomCommonSpecies();
    }
    else
    {
        if (roll <= 1)
        {
            gSaveBlock2Ptr ->wishingWellPityCount = 0;
            return GetRandomPseudoSpecies();
        }
        if (roll <= 12)
        {
            gSaveBlock2Ptr ->wishingWellPityCount = 0;
            return GetRandomRareSpecies();
        }

        gSaveBlock2Ptr ->wishingWellPityCount++;

        if (roll <= 40)
        {
            return GetRandomUncommonSpecies();
        }
        return GetRandomCommonSpecies();
    }
}

bool8 ScrCmd_RollPokemonRNG(struct ScriptContext *ctx)
{
    gSpecialVar_Result = RollPokemonRNG();
    return FALSE;
}

static const u16 sPseudoTable[] = 
{
    SPECIES_DRATINI,
    SPECIES_LARVITAR,
    SPECIES_BELDUM,
    SPECIES_VOLCANION, // gacha exclusive, could not find the perfect place for my boy
    SPECIES_DEINO,
    SPECIES_GOOMY,
    SPECIES_JANGMO_O,
    SPECIES_BAGON,
    SPECIES_XURKITREE, // gacha exclusive, not a pseudo legendary but whatever
    SPECIES_SLAKOTH,
    SPECIES_GIBLE
};

static const u16 sRareTable[] = 
{
    SPECIES_DUCKLETT, // gacha exclusive
    SPECIES_SIGILYPH, // gacha exclusive
    SPECIES_ROCKRUFF,
    SPECIES_EEVEE,
    SPECIES_GASTLY,
    SPECIES_MAREEP,
    SPECIES_ELEKID,
    SPECIES_BUNEARY,
    SPECIES_RIOLU,
    SPECIES_SKARMORY,
    SPECIES_SABLEYE,
    SPECIES_HERACROSS,
    SPECIES_ZORUA
};

static const u16 sUncommonTable[] = 
{
    SPECIES_MANTINE, // gacha exclusive
    SPECIES_CHATOT, // gacha exclusive
    SPECIES_CRABRAWLER, // gacha exclusive
    SPECIES_SPRITZEE, // gacha exclusive
    SPECIES_TRAPINCH,
    SPECIES_TYROGUE,
    SPECIES_MUNCHLAX,
    SPECIES_SKITTY,
    SPECIES_WOOBAT,
    SPECIES_PANPOUR,
    SPECIES_PANSEAR,
    SPECIES_PANSAGE,
    SPECIES_DODUO,
    SPECIES_SHUPPET,
    SPECIES_TANGELA,
    SPECIES_MAGBY
};

static const u16 sCommonTable[] = 
{
    SPECIES_STUNFISK, // gacha exclusive
    SPECIES_POLIWAG,
    SPECIES_COMFEY,
    SPECIES_EXEGGCUTE,
    SPECIES_PATRAT,
    SPECIES_BIDOOF,
    SPECIES_WURMPLE,
    SPECIES_SCATTERBUG,
    SPECIES_STARLY,
    SPECIES_TAILLOW,
    SPECIES_RATTATA,
    SPECIES_PIDGEY,
    SPECIES_EKANS,
    SPECIES_NINCADA,
    SPECIES_SENTRET,
    SPECIES_MACHOP,
    SPECIES_LILEEP,
    SPECIES_SEWADDLE,
    SPECIES_ZIGZAGOON,
    SPECIES_WINGULL,
    SPECIES_SHROOMISH
};

static u16 GetRandomPseudoSpecies(void) {return sPseudoTable[Random() % ARRAY_COUNT(sPseudoTable)]; }
static u16 GetRandomRareSpecies(void) {return sRareTable[Random() % ARRAY_COUNT(sRareTable)]; }
static u16 GetRandomUncommonSpecies(void) {return sUncommonTable[Random() % ARRAY_COUNT(sUncommonTable)]; }
static u16 GetRandomCommonSpecies(void) {return sCommonTable[Random() % ARRAY_COUNT(sCommonTable)]; }
