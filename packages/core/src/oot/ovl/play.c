#include <combo.h>
#include <combo/souls.h>
#include <combo/net.h>

extern void* gMmMag;
GameState_Play* gPlay;

static void debugCheat(GameState_Play* play)
{
#if defined(DEBUG)
    if (!gSaveContext.gameMode && play->gs.input[0].current.buttons & L_TRIG)
    {
        //MM_SET_EVENT_WEEK(EV_MM_WEEK_DRANK_CHATEAU_ROMANI);
        SetEventChk(EV_OOT_CHK_MASTER_SWORD_PULLED);
        SetEventChk(EV_OOT_CHK_MASTER_SWORD_CHAMBER);
        gSave.playerData.swordHealth = 8;
        gSave.isBiggoronSword = 1;

        gSave.inventory.quest.gerudoCard = 1;
        gSave.inventory.dungeonKeys[SCE_OOT_TEMPLE_FIRE] = 8;
        gSave.inventory.dungeonKeys[SCE_OOT_TREASURE_SHOP] = 6;
        gSave.inventory.items[ITS_OOT_STICKS] = ITEM_OOT_STICK;
        gSave.inventory.items[ITS_OOT_NUTS] = ITEM_OOT_NUT;
        gSave.inventory.items[ITS_OOT_BOMBS] = ITEM_OOT_BOMB;
        gSave.inventory.items[ITS_OOT_BOW] = ITEM_OOT_BOW;
        gSave.inventory.items[ITS_OOT_ARROW_FIRE] = ITEM_OOT_ARROW_FIRE;
        gSave.inventory.items[ITS_OOT_ARROW_ICE] = ITEM_OOT_ARROW_ICE;
        gSave.inventory.items[ITS_OOT_ARROW_LIGHT] = ITEM_OOT_ARROW_LIGHT;
        gSave.inventory.items[ITS_OOT_SLINGSHOT] = ITEM_OOT_SLINGSHOT;
        gSave.inventory.items[ITS_OOT_OCARINA] = ITEM_OOT_OCARINA_TIME;
        gSave.inventory.items[ITS_OOT_BOOMERANG] = ITEM_OOT_BOOMERANG;
        gSave.inventory.items[ITS_OOT_BOTTLE] = ITEM_OOT_RUTO_LETTER;
        gSave.inventory.items[ITS_OOT_BOTTLE2] = ITEM_OOT_FISH;
        gSave.inventory.items[ITS_OOT_BOTTLE3] = ITEM_OOT_BIG_POE;
        gSave.inventory.items[ITS_OOT_BOTTLE4] = ITEM_OOT_BIG_POE;
        gSave.inventory.items[ITS_OOT_BOMBCHU] = ITEM_OOT_BOMBCHU_10;
        gSave.inventory.items[ITS_OOT_TRADE_CHILD] = ITEM_OOT_ZELDA_LETTER;
        gSave.inventory.items[ITS_OOT_HAMMER] = ITEM_OOT_HAMMER;
        gSave.inventory.items[ITS_OOT_HOOKSHOT] = ITEM_OOT_LONGSHOT;
        gSave.inventory.items[ITS_OOT_LENS] = ITEM_OOT_LENS;
        gSave.inventory.items[ITS_OOT_SPELL_WIND] = ITEM_OOT_SPELL_WIND;

        gSave.inventory.equipment.swords = 0x7;
        gSave.inventory.equipment.shields = 0x7;
        gSave.inventory.equipment.tunics = 0x7;
        gSave.inventory.equipment.boots = 0x7;

        gSave.inventory.upgrades.dekuStick = 3;
        gSave.inventory.upgrades.dekuNut = 3;
        //gSave.inventory.upgrades.bulletBag = 3;
        gSave.inventory.upgrades.bombBag = 3;
        gSave.inventory.upgrades.quiver = 3;
        gSave.inventory.upgrades.dive = 2;
        gSave.inventory.upgrades.wallet = 3;
        gSave.inventory.upgrades.strength = 3;

        gSave.inventory.ammo[ITS_OOT_STICKS] = 10;
        gSave.inventory.ammo[ITS_OOT_SLINGSHOT] = 50;
        gSave.inventory.ammo[ITS_OOT_NUTS] = 40;
        gSave.inventory.ammo[ITS_OOT_BOMBS] = 40;
        gSave.inventory.ammo[ITS_OOT_BOW] = 50;
        gSave.inventory.ammo[ITS_OOT_BOMBCHU] = 50;
        gSave.inventory.quest.songZelda = 1;
        gSave.inventory.quest.songSaria = 1;
        gSave.inventory.quest.songTime = 1;
        gSave.inventory.quest.songSun = 1;
        gSave.inventory.quest.songEpona = 1;
        gSave.inventory.quest.songStorms = 1;
        gSave.inventory.quest.songTpLight = 1;
        gSave.inventory.quest.songTpShadow = 1;
        gSave.inventory.quest.songTpWater = 1;
        gSave.inventory.quest.songTpFire = 1;
        gSave.inventory.quest.songTpForest = 1;
        gSave.inventory.quest.songTpSpirit = 1;

        gSave.inventory.quest.stoneEmerald = 1;
        gSave.inventory.quest.stoneRuby = 0;
        gSave.inventory.quest.stoneSapphire = 0;

        gSave.playerData.magicUpgrade = 1;
        gSave.playerData.magicUpgrade2 = 1;
        gOotSave.playerData.magicSize = 0;
        gSaveContext.magicFillTarget = 0x60;

        gSave.inventory.dungeonKeys[SCE_OOT_TEMPLE_FOREST] = 9;
        gSave.inventory.dungeonKeys[SCE_OOT_INSIDE_GANON_CASTLE] = 9;

        /*
        gSave.inventory.quest.medallionShadow = 1;
        gSave.inventory.quest.medallionSpirit = 1;
        gSave.inventory.quest.medallionForest = 1;
        gSave.inventory.quest.medallionFire = 1;
        gSave.inventory.quest.medallionWater = 1;
        gSave.inventory.quest.medallionLight = 1;
        */

        gSave.inventory.quest.stoneRuby = 1;

        gSave.playerData.health = gSave.playerData.healthMax = 20 * 0x10;

        gSave.playerData.rupees = 500;

        gOotExtraTrade.child = 0xffff;
        gOotExtraTrade.adult = 0xffff;
        gOotExtraTrade.adult |= (1 << XITEM_OOT_ADULT_EYEBALL_FROG);
        gOotExtraTrade.adult |= (1 << XITEM_OOT_ADULT_EYE_DROPS);
        gOotExtraTrade.adult |= (1 << XITEM_OOT_ADULT_CLAIM_CHECK);
        gSave.inventory.items[ITS_OOT_TRADE_ADULT] = ITEM_OOT_POCKET_EGG;

        SetEventChk(EV_OOT_CHK_EPONA);

#if defined(DEBUG_AGE)
        gSave.age = DEBUG_AGE;
#endif

        //BITMAP16_SET(gSave.eventsMisc, EV_OOT_INF_KING_ZORA_THAWED);
    }
#endif
}

static int isRainbowBridgeOpen(void)
{
    if (comboConfig(CFG_OOT_BRIDGE_CUSTOM) && !comboSpecialCond(SPECIAL_BRIDGE))
        return 0;

    if (comboConfig(CFG_OOT_BRIDGE_VANILLA) && !(
        gOotSave.inventory.quest.medallionShadow
        && gOotSave.inventory.quest.medallionSpirit
        && gOotSave.inventory.items[ITS_OOT_ARROW_LIGHT] == ITEM_OOT_ARROW_LIGHT
    ))
        return 0;

    if (comboConfig(CFG_OOT_BRIDGE_MEDALLIONS) && !(
        gOotSave.inventory.quest.medallionLight
        && gOotSave.inventory.quest.medallionForest
        && gOotSave.inventory.quest.medallionFire
        && gOotSave.inventory.quest.medallionWater
        && gOotSave.inventory.quest.medallionShadow
        && gOotSave.inventory.quest.medallionSpirit
    ))
        return 0;

    return 1;
}

static void eventFixes(GameState_Play* play)
{
    /* Skip forest temple cutscene */
    if (gSave.entrance == 0x169)
    {
        u32 tmp;
        tmp = gSave.perm[SCE_OOT_TEMPLE_FOREST].switches;
        if ((tmp & 0xf0000000) != 0xf0000000)
            tmp |= 0x08000000;
        gSave.perm[SCE_OOT_TEMPLE_FOREST].switches = tmp;
    }

    /* Ruto fixes */
    if (gSave.entrance == 0x028)
    {
        /* Skip the intro cutscene */
        u16 tmp;
        tmp = gSave.eventsMisc[20];
        if (!(tmp & 0xff))
            tmp |= 0x1e;
        gSave.eventsMisc[20] = tmp;

        /* Ruto kidnap fixes */
        if (BITMAP16_GET(gSave.eventsMisc, EV_OOT_INF_RUTO_KIDNAPPED) || BITMAP16_GET(gSave.eventsMisc, EV_OOT_INF_RUTO_GOT_SAPPHIRE))
        {
            /* Un-kidnap ruto */
            BITMAP16_CLEAR(gSave.eventsMisc, EV_OOT_INF_RUTO_KIDNAPPED);
            BITMAP16_CLEAR(gSave.eventsMisc, EV_OOT_INF_RUTO_GOT_SAPPHIRE);
        }
    }

    /* Skip Zelda's cutscene when having all the spiritual stones */
    if (gSave.inventory.quest.stoneEmerald && gSave.inventory.quest.stoneRuby && gSave.inventory.quest.stoneSapphire)
    {
        SetEventChk(EV_OOT_CHK_ZELDA_FLED);
        SetEventChk(EV_OOT_CHK_ZELDA_FLED_BRIDGE);
    }

    /* Set the rainbow bridge flag */
    if (isRainbowBridgeOpen())
    {
        SetEventChk(EV_OOT_CHK_RAINBOW_BRIDGE);
    }
}

static void sendSelfTriforce(void)
{
    NetContext* net;
    int npc;
    s16 gi;

    if (!comboConfig(CFG_MULTIPLAYER))
        return;

    gi = GI_OOT_TRIFORCE_FULL;
    npc = NPC_OOT_GANON;

    net = netMutexLock();
    netWaitCmdClear();
    bzero(&net->cmdOut, sizeof(net->cmdOut));
    net->cmdOut.op = NET_OP_ITEM_SEND;
    net->cmdOut.itemSend.playerFrom = gComboData.playerId;
    net->cmdOut.itemSend.playerTo = gComboData.playerId;
    net->cmdOut.itemSend.game = 0;
    net->cmdOut.itemSend.gi = gi;
    net->cmdOut.itemSend.key = ((u32)OV_NPC << 24) | npc;
    net->cmdOut.itemSend.flags = 0;
    netMutexUnlock();

    /* Mark the NPC as obtained */
    BITMAP8_SET(gSharedCustomSave.oot.npc, npc);
}

static void endGame(void)
{
    u8  tmpAge;
    u16 tmpNextCutscene;
    s32 tmpCutscene;
    u16 tmpEntrance;
    u16 tmpSceneId;

    /* Ignore credit warp */
    if (g.isCreditWarp)
        return;

    /* Flag ganon as beaten */
    gOotExtraFlags.ganon = 1;

    /* Send self triforce */
    sendSelfTriforce();

    /* Save tmp gameplay values (in case majora was beaten too) */
    tmpAge = gSave.age;
    tmpNextCutscene = *(u16*)((char*)&gSaveContext + 0x1412);
    tmpCutscene = gSave.cutscene;
    tmpEntrance = gSave.entrance;
    tmpSceneId = gSave.sceneId;

    /* Edit gameplay values for end of game save */
    gSave.age = AGE_ADULT;
    *(u16*)((char*)&gSaveContext + 0x1412) = 0;
    gSave.cutscene = 0;
    if (comboConfig(CFG_ER_ANY))
    {
        gSave.entrance = ENTR_OOT_GANON_TOWER;
        gSave.sceneId = SCE_OOT_GANON_TOWER;
    }
    else
    {
        gSave.entrance = ENTR_OOT_GANON_CASTLE_EXTERIOR_FROM_CASTLE;
        gSave.sceneId = SCE_OOT_GANON_CASTLE_EXTERIOR;
    }

    /* Save */
    comboSave(NULL, SF_PASSIVE);

    /* Restore gameplay values to play the cutscene if majora was beaten too */
    if (comboGoalCond())
    {
        gSave.age = tmpAge;
        *(u16*)((char*)&gSaveContext + 0x1412) = tmpNextCutscene;
        gSave.cutscene = tmpCutscene;
        gSave.entrance = tmpEntrance;
        gSave.sceneId = tmpSceneId;
    }
}

static u32 entranceForOverride(u32 entrance)
{
    switch (entrance)
    {
    case 0x1d9:
        /* Water entrance to zora river */
        return 0x0ea;
    case 0x311:
        /* Water entrance to hyrule */
        return 0x181;
    case ENTR_OOT_HYRULE_CASTLE_FROM_FAIRY:
        return gLastScene == SCE_OOT_GREAT_FAIRY_FOUNTAIN_UPGRADES ? ENTR_OOT_OUTSIDE_GANON_FROM_FAIRY : ENTR_OOT_HYRULE_CASTLE_FROM_FAIRY;
    default:
        return entrance;
    }
}

void hookPlay_Init(GameState_Play* play)
{
    s32 override;

    /* Init */
    gActorCustomTriggers = NULL;
    gMultiMarkChests = 0;
    gMultiMarkCollectibles = 0;
    gMultiMarkSwitch0 = 0;
    gMultiMarkSwitch1 = 0;
    comboMultiResetWisps();

    /* Register play */
    gPlay = play;

    /* Handle transition override */
    if (g.inGrotto)
        gIsEntranceOverride = 0;
    if (gIsEntranceOverride)
    {
        gIsEntranceOverride = 0;
        override = comboEntranceOverride(entranceForOverride(gSave.entrance));
        if (override != -1)
        {
            if (override >= 0)
                gSave.entrance = override;
            else
            {
                gSave.entrance = gLastEntrance;
                Play_Init(play);
                gComboCtx.shuffledEntrance = 1;
                comboClearEpona(play);
                comboGameSwitch(play, override);
                return;
            }
        }
    }

    /* Handle custom entrance IDs */
    switch (gSave.entrance)
    {
    case ENTR_OOT_OUTSIDE_GANON_FROM_FAIRY:
        gSave.entrance = ENTR_OOT_HYRULE_CASTLE_FROM_FAIRY;
        break;
    }

    /* Handle swordless & time travel sword oddities */
    if (gSave.entrance == 0x2ca)
    {
        if (gSave.age == AGE_CHILD)
        {
            gSave.equips.buttonItems[0] = gSave.childEquips.buttonItems[0];
            if (gSave.equips.buttonItems[0] == ITEM_NONE)
            {
                gSave.equips.equipment.swords = 0;
                gSave.eventsMisc[29] = 1;
            }
        }
    }

    if (gSave.equips.equipment.swords == 0 || (gSave.inventory.equipment.swords & (1 << (gSave.equips.equipment.swords - 1))) == 0)
    {
        /* Set swordless */
        gSave.equips.equipment.swords = 0;
        switch (gSave.equips.buttonItems[0])
        {
        case ITEM_OOT_SWORD_KOKIRI:
        case ITEM_OOT_SWORD_MASTER:
        case ITEM_OOT_SWORD_KNIFE_BIGGORON:
        case ITEM_OOT_SWORD_KNIFE_BROKEN:
            gSave.equips.buttonItems[0] = ITEM_NONE;
            break;
        }
        gSave.eventsMisc[29] = 1;
    }
    else
    {
        /* Set sworded */
        gSave.eventsMisc[29] = 0;
    }

    if (gSave.entrance == 0x007a)
    {
        /* Entering courtyard */
        if (GetEventChk(EV_OOT_CHK_ZELDA_LETTER))
            gSave.entrance = 0x0594;
        else
            gSave.entrance = 0x0400;
    }
    else if (gSave.entrance == 0x006b)
    {
        endGame();
    }
    else if (gSave.entrance == 0x517 && !comboHasSoulOot(GI_OOT_SOUL_NPC_ZELDA))
    {
        gSave.entrance = ENTR_OOT_GANON_TOWER;
    }

    comboCacheClear();
    comboObjectsReset();
    comboExObjectsReset();
    debugCheat(play);
    eventFixes(play);

    Play_Init(play);

    /* Epona fix */
    if (!IsSceneValidEpona(play->sceneId))
        comboClearEpona(play);

    gLastEntrance = gSave.entrance;
    g.inGrotto = (play->sceneId == SCE_OOT_GROTTOS || play->sceneId == SCE_OOT_FAIRY_FOUNTAIN);
    if (!g.inGrotto)
    {
        gLastScene = play->sceneId;
    }

    if (gSave.entrance == 0x0530)
    {
        gComboCtx.shuffledEntrance = 0;
        comboGameSwitch(play, ENTR_MM_CLOCK_TOWN);
        return;
    }

    /* Spawn Custom Triggers */
    CustomTriggers_Spawn(play);

    /* Title screen transition skip */
    if (gComboCtx.valid)
    {
        play->transition.gfx = 11;
    }

    if (!gCustomKeep)
    {
        comboLoadCustomKeep();
    }

#if defined(DEBUG)
    if (!gSaveContext.gameMode && (play->gs.input[0].current.buttons & R_TRIG))
    {
        gComboCtx.shuffledEntrance = 0;
        comboGameSwitch(play, ENTR_MM_CLOCK_TOWN);
        return;
    }
#endif
}

void Play_DrawWrapper(GameState_Play* play)
{
    comboCacheGarbageCollect();
    comboObjectsGC();
    Play_Draw(play);

    if (gComboCtx.valid)
    {
        OPEN_DISPS(play->gs.gfx);
        gDPSetCycleType(OVERLAY_DISP++, G_CYC_FILL);
        gDPSetRenderMode(OVERLAY_DISP++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(OVERLAY_DISP++, 0);
        gDPFillRectangle(OVERLAY_DISP++, 0, 0, 319, 239);
        CLOSE_DISPS();
    }
    else
    {
        /* Need to draw dpad */
        comboDpadDraw(play);
    }
}

static void Play_LoadKaleidoScopeHook(void* unk)
{
    Play_LoadKaleidoOverlay(unk);
    comboMqKaleidoHook(gPlay);
}

PATCH_CALL(0x8009a06c, Play_LoadKaleidoScopeHook);

void comboClearEpona(GameState_Play* play)
{
    if (AREG(6) != 0)
    {
        /* Link is on Epona, needs to dismount */
        AREG(6) = 0;

        /* Reset the TempB */
        gSave.equips.buttonItems[0] = gSaveContext.buttonStatus[0];
        gSaveContext.buttonStatus[0] = ITEM_NONE;

        /* Reload the B button icon */
        Interface_LoadItemIconImpl(play, 0);
    }
}
