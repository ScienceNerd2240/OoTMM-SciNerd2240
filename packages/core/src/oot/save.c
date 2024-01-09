#include <combo.h>
#include <combo/item.h>
#include <combo/net.h>
#include <combo/dungeon.h>
#include <combo/dma.h>

#define ENTRANCE_MARKET       0x1d1

static const s32 kDungeonEntrances[] = {
    0x000,
    0x004,
    0x028,
    0x169,
    0x165,
    0x010,
    0x037,
    0x082,
};

static void dungeonRespawn(s16 sceneId)
{
    int bossId;

    switch (sceneId)
    {
    case SCE_OOT_LAIR_GOHMA:
        bossId = BOSSID_GOHMA;
        break;
    case SCE_OOT_LAIR_KING_DODONGO:
        bossId = BOSSID_KING_DODONGO;
        break;
    case SCE_OOT_LAIR_BARINADE:
        bossId = BOSSID_BARINADE;
        break;
    case SCE_OOT_LAIR_PHANTOM_GANON:
        bossId = BOSSID_PHANTOM_GANON;
        break;
    case SCE_OOT_LAIR_VOLVAGIA:
        bossId = BOSSID_VOLVAGIA;
        break;
    case SCE_OOT_LAIR_MORPHA:
        bossId = BOSSID_MORPHA;
        break;
    case SCE_OOT_LAIR_BONGO_BONGO:
        bossId = BOSSID_BONGO_BONGO;
        break;
    case SCE_OOT_LAIR_TWINROVA:
        bossId = BOSSID_TWINROVA;
        break;
    default:
        return;
    }

    bossId = gComboData.boss[bossId];
    if (bossId >= BOSSID_ODOLWA)
    {
        /* Coming from MM */
        gSave.entrance = ENTRANCE_MARKET;
        return;
    }

    gSave.entrance = kDungeonEntrances[bossId];
}

void Sram_AfterOpenSave(void)
{
#if defined(DEBUG) && defined(DEBUG_OOT_ENTRANCE)
    gSave.entrance = DEBUG_OOT_ENTRANCE;
#endif

    /* Read the other save */
    comboReadForeignSave();

    /* Met deku tree - deku tree open - met mido */
    gSave.eventsChk[0] |= 0x102c;
    gSave.eventsMisc[0] |= 0x000b;

    if (comboConfig(CFG_OOT_OPEN_DEKU))
        SetEventChk(EV_OOT_CHK_DEKU_MIDO_SWORD_SHIELD);

    comboOnSaveLoad();

    /* Dungeon shuffle override */
    dungeonRespawn(gSave.sceneId);

    /* Game switch override */
    if (gComboCtx.valid)
    {
        gSave.entrance = ENTRANCE_MARKET;
        gComboCtx.valid = 0;

        if (gComboCtx.entrance != -1)
        {
            gSave.entrance = gComboCtx.entrance;
            gComboCtx.entrance = -1;
        }
    }
}

void Sram_CopySaveWrapper(void* fileSelect, void* sramCtx)
{
    Sram_CopySave(fileSelect, sramCtx);
    comboCopyMmSave(*(short*)((char*)fileSelect + 0x1ca50), *(short*)((char*)fileSelect + 0x1ca38));
}

PATCH_CALL(0x808048d8, Sram_CopySaveWrapper);

ALIGNED(16) static u16 gStartingItemsBuffer[64];

static void applyStartingItems(void)
{
    int slice;
    u16 gi;
    u16 count;

    slice = 0;
    for (;;)
    {
        comboDmaLoadFilePartial(gStartingItemsBuffer, COMBO_VROM_STARTING_ITEMS, slice * sizeof(gStartingItemsBuffer), sizeof(gStartingItemsBuffer));
        slice++;
        for (int i = 0; i < ARRAY_SIZE(gStartingItemsBuffer); i += 2)
        {
            gi = gStartingItemsBuffer[i];
            count = gStartingItemsBuffer[i + 1];
            if (gi == 0xffff)
                return;
            for (u16 j = 0; j < count; ++j)
            {
                gi = comboProgressive(gi, 0);
                comboAddItem(NULL, gi);
            }
        }
    }
}

static void applyStartingEvents(void)
{
    int skippedTrials;

    if (comboConfig(CFG_DOOR_OF_TIME_OPEN))
    {
        SetEventChk(EV_OOT_CHK_DOOR_TIME);
    }

    if (comboConfig(CFG_OOT_SKIP_ZELDA))
    {
        SetEventChk(EV_OOT_CHK_ZELDA_LETTER);
        SetEventChk(EV_OOT_CHK_SONG_ZELDA);
        SetEventChk(EV_OOT_CHK_CHILD_TALON_WOKEN);
        SetEventChk(EV_OOT_CHK_CHILD_TALON_FLED);
    }

    if (comboConfig(CFG_OOT_OPEN_KAKARIKO_GATE))
    {
        BITMAP16_SET(gSave.eventsMisc, EV_OOT_INF_KAKARIKO_GATE_OPEN);
    }

    if (comboConfig(CFG_OOT_KZ_OPEN))
    {
        SetEventChk(EV_OOT_CHK_KING_ZORA_MOVED);
    }

    if (gComboData.mq & (1 << MQ_TEMPLE_SHADOW))
    {
        gSave.perm[SCE_OOT_TEMPLE_SHADOW].switches |= (1 << 7);
    }

    /* Carpenters */
    if (comboConfig(CFG_OOT_CARPENTERS_NONE) || comboConfig(CFG_OOT_CARPENTERS_ONE))
    {
        SetEventChk(EV_OOT_CHK_CARPENTER_2);
        SetEventChk(EV_OOT_CHK_CARPENTER_3);
        SetEventChk(EV_OOT_CHK_CARPENTER_4);

        gSave.perm[SCE_OOT_THIEVES_HIDEOUT].switches |= (1 << 2);
        gSave.perm[SCE_OOT_THIEVES_HIDEOUT].switches |= (1 << 3);
        gSave.perm[SCE_OOT_THIEVES_HIDEOUT].switches |= (1 << 4);

        if (comboConfig(CFG_OOT_CARPENTERS_NONE))
        {
            SetEventChk(EV_OOT_CHK_CARPENTER_1);
            gSave.perm[SCE_OOT_THIEVES_HIDEOUT].switches |= (1 << 1);
        }
    }

    /* Ganon trials */
    skippedTrials = 0;
    if (!comboConfig(CFG_OOT_TRIAL_LIGHT))
    {
        SetEventChk(EV_OOT_CHK_TRIAL_LIGHT);
        skippedTrials++;
    }

    if (!comboConfig(CFG_OOT_TRIAL_FOREST))
    {
        SetEventChk(EV_OOT_CHK_TRIAL_FOREST);
        skippedTrials++;
    }

    if (!comboConfig(CFG_OOT_TRIAL_FIRE))
    {
        SetEventChk(EV_OOT_CHK_TRIAL_FIRE);
        skippedTrials++;
    }

    if (!comboConfig(CFG_OOT_TRIAL_WATER))
    {
        SetEventChk(EV_OOT_CHK_TRIAL_WATER);
        skippedTrials++;
    }

    if (!comboConfig(CFG_OOT_TRIAL_SHADOW))
    {
        SetEventChk(EV_OOT_CHK_TRIAL_SHADOW);
        skippedTrials++;
    }

    if (!comboConfig(CFG_OOT_TRIAL_SPIRIT))
    {
        SetEventChk(EV_OOT_CHK_TRIAL_SPIRIT);
        skippedTrials++;
    }

    if (skippedTrials == 6)
        SetEventChk(EN_OOT_CHK_GANON_BARRIER);

    if (comboConfig(CFG_OOT_FREE_SCARECROW))
    {
        SetEventChk(EV_OOT_CHK_SONG_SCARECROW_ADULT);
    }

    if (comboConfig(CFG_MM_REMOVED_FAIRIES))
    {
        gMmSave.permanentSceneFlags[SCE_MM_TEMPLE_WOODFALL].switch1 |= 0x0007fc00;
        gMmSave.permanentSceneFlags[SCE_MM_TEMPLE_WOODFALL].collectible |= 0x70000000;

        gMmSave.permanentSceneFlags[SCE_MM_TEMPLE_SNOWHEAD].switch1 |= 0x0007b800;
        gMmSave.permanentSceneFlags[SCE_MM_TEMPLE_SNOWHEAD].collectible |= 0x40000000;

        gMmSave.permanentSceneFlags[SCE_MM_TEMPLE_GREAT_BAY].switch1 |= 0x00078000;
        gMmSave.permanentSceneFlags[SCE_MM_TEMPLE_GREAT_BAY].collectible |= 0x7c000000;
    }
}

void comboCreateSave(void* unk, void* buffer)
{
    u32 base;

    /* Create MM save */
    comboCreateSaveMM();

    /* Apply some early settings */
    if (!comboConfig(CFG_CHILD_WALLET))
    {
        gOotExtraFlags.childWallet = 1;
        gMmExtraFlags2.childWallet = 1;

        gOotMaxRupees[0] = 99;
        gMmMaxRupees[0] = 99;
    }

    /* Apply enemy souls */
    if (!comboConfig(CFG_OOT_SOULS_ENEMY))
        memset(gSharedCustomSave.soulsEnemyOot, 0xff, sizeof(gSharedCustomSave.soulsEnemyOot));
    if (!comboConfig(CFG_MM_SOULS_ENEMY))
        memset(gSharedCustomSave.soulsEnemyMm, 0xff, sizeof(gSharedCustomSave.soulsEnemyMm));
    if (!comboConfig(CFG_OOT_SOULS_BOSS))
        memset(gSharedCustomSave.soulsBossOot, 0xff, sizeof(gSharedCustomSave.soulsBossOot));
    if (!comboConfig(CFG_MM_SOULS_BOSS))
        memset(gSharedCustomSave.soulsBossMm, 0xff, sizeof(gSharedCustomSave.soulsBossMm));
    if (!comboConfig(CFG_OOT_SOULS_NPC))
        memset(gSharedCustomSave.soulsNpcOot, 0xff, sizeof(gSharedCustomSave.soulsNpcOot));

    /* Apply ocarina buttons */
    if (!comboConfig(CFG_OOT_OCARINA_BUTTONS))
        gSharedCustomSave.ocarinaButtonMaskOot = 0xffff;
    if (!comboConfig(CFG_MM_OCARINA_BUTTONS))
        gSharedCustomSave.ocarinaButtonMaskMm = 0xffff;

    gOotSave.childEquips.buttonItems[0] = ITEM_NONE;
    gOotSave.adultEquips.buttonItems[0] = ITEM_NONE;

    /* Apply starting age */
    if (comboConfig(CFG_OOT_START_ADULT))
    {
        /* Spawn as adult in ToT */
        gOotSave.age = AGE_ADULT;
        gOotSave.entrance = ENTR_OOT_TEMPLE_OF_TIME;
        gOotSave.sceneId = SCE_OOT_TEMPLE_OF_TIME;

        /* Force Master Sword */
        gOotSave.equips.buttonItems[0] = ITEM_OOT_SWORD_MASTER;
        gOotSave.inventory.equipment.swords |= EQ_OOT_SWORD_MASTER;
        gOotSave.equips.equipment.swords = 2;

        /* Unset the swordless flag */
        gSave.eventsMisc[29] = 0;
    }

    /* Apply starting items */
    applyStartingItems();

    /* Apply starting events */
    applyStartingEvents();

    /* Apply pre-completed dungeons */
    for (int i = 0; i < 32; ++i)
    {
        if (gComboData.preCompleted & (1 << i))
            comboDungeonSetFlags(i, 0);
    }

    /* Write save */
    comboWriteSave();

    /* Copy inside the buffer */
    base = 0x20 + 0x1450 * gSaveContext.fileIndex;
    memcpy((char*)buffer + base, &gOotSave, 0x1354);
    memcpy((char*)buffer + base + 0x3cf0, &gOotSave, 0x1354);
}

static void DeathWarpWrapper(GameState_Play* play)
{
    dungeonRespawn(play->sceneId);
    DeathWarp(play);
}

PATCH_CALL(0x8009dacc, DeathWarpWrapper);

void PrepareAndSave(void)
{
    comboSave(gPlay, 0);
}

void comboSave(GameState_Play* play, int saveFlags)
{
    /* Wait for net */
    netWaitSave();

    gComboCtx.saveIndex = gSaveContext.fileIndex;
    if (!(saveFlags & SF_PASSIVE))
    {
        if (!(saveFlags & SF_NOCOMMIT))
            PlayStoreFlags(play);
        gSave.sceneId = play->sceneId;
    }

    if (!(saveFlags & SF_NOCOMMIT))
    {
        comboWriteSave();
    }
}
