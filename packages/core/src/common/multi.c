#include <combo.h>
#include <combo/multi.h>
#include <combo/net.h>
#include <combo/player.h>
#include <combo/config.h>
#include <combo/item.h>
#include <combo/actor.h>
#include <combo/global.h>

#if defined(GAME_OOT)
# define RECOVERY_HEART GI_OOT_RECOVERY_HEART
#else
# define RECOVERY_HEART GI_MM_RECOVERY_HEART
#endif

u32 gMultiMarkChests;
u32 gMultiMarkCollectibles;
u32 gMultiMarkSwitch0;
u32 gMultiMarkSwitch1;

static int mmSceneId(int sceneId)
{
    switch (sceneId)
    {
    case SCE_MM_TEMPLE_STONE_TOWER_INVERTED:
        return SCE_MM_TEMPLE_STONE_TOWER;
    case SCE_MM_SOUTHERN_SWAMP_CLEAR:
        return SCE_MM_SOUTHERN_SWAMP;
    case SCE_MM_MOUNTAIN_VILLAGE_SPRING:
        return SCE_MM_MOUNTAIN_VILLAGE_WINTER;
    case SCE_MM_GORON_VILLAGE_SPRING:
        return SCE_MM_GORON_VILLAGE_WINTER;
    case SCE_MM_TWIN_ISLANDS_SPRING:
        return SCE_MM_TWIN_ISLANDS_WINTER;
    case SCE_MM_STONE_TOWER_INVERTED:
        return SCE_MM_STONE_TOWER;
    default:
        return sceneId;
    }
}

static int getChestMarkOot(GameState_Play* play, int sceneId, int flagId)
{
#if defined(GAME_OOT)
    if (play && play->sceneId == sceneId)
        return !!(gMultiMarkChests & (1 << flagId));
#endif

    return !!(gOotSave.perm[sceneId].chests & (1 << flagId));
}

static int getChestMarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
        return !!(gMultiMarkChests & (1 << flagId));
    if (gSaveContext.cycleSceneFlags[sceneId].chest & (1 << flagId))
        return 1;
#endif

    return !!(gMmSave.permanentSceneFlags[sceneId].chest & (1 << flagId));
}

static void setChestMarkOot(GameState_Play* play, int sceneId, int flagId)
{
#if defined(GAME_OOT)
    if (play && play->sceneId == sceneId)
    {
        SetChestFlag(play, flagId);
        gMultiMarkChests |= (1 << flagId);
        return;
    }
#endif

    gOotSave.perm[sceneId].chests |= (1 << flagId);
}

static void setChestMarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
    {
        SetChestFlag(play, flagId);
        gMultiMarkChests |= (1 << flagId);
        return;
    }
    gSaveContext.cycleSceneFlags[sceneId].chest |= (1 << flagId);
#endif

    gMmSave.permanentSceneFlags[sceneId].chest |= (1 << flagId);
}

static int getCollectibleMarkOot(GameState_Play* play, int sceneId, int flagId)
{
#if defined(GAME_OOT)
    if (play && play->sceneId == sceneId)
        return !!(gMultiMarkCollectibles & (1 << flagId));
#endif

    return !!(gOotSave.perm[sceneId].collectibles & (1 << flagId));
}

static int getCollectibleMarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
        return !!(gMultiMarkCollectibles & (1 << flagId));
    if (gSaveContext.cycleSceneFlags[sceneId].collectible & (1 << flagId))
        return 1;
#endif

    return !!(gMmSave.permanentSceneFlags[sceneId].collectible & (1 << flagId));
}

static void setCollectibleMarkOot(GameState_Play* play, int sceneId, int flagId)
{
#if defined(GAME_OOT)
    if (play && play->sceneId == sceneId)
    {
        SetCollectibleFlag(play, flagId);
        gMultiMarkCollectibles |= (1 << flagId);
        return;
    }
#endif

    gOotSave.perm[sceneId].collectibles |= (1 << flagId);
}

static void setCollectibleMarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
    {
        SetCollectibleFlag(play, flagId);
        gMultiMarkCollectibles |= (1 << flagId);
        return;
    }
    gSaveContext.cycleSceneFlags[sceneId].collectible |= (1 << flagId);
#endif

    gMmSave.permanentSceneFlags[sceneId].collectible |= (1 << flagId);
}

static int getSwitch0MarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
        return !!(gMultiMarkSwitch0 & (1 << flagId));
    if (gSaveContext.cycleSceneFlags[sceneId].switch0 & (1 << flagId))
        return 1;
#endif

    return !!(gMmSave.permanentSceneFlags[sceneId].switch0 & (1 << flagId));
}

static int getSwitch1MarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
        return !!(gMultiMarkSwitch1 & (1 << flagId));
    if (gSaveContext.cycleSceneFlags[sceneId].switch1 & (1 << flagId))
        return 1;
#endif

    return !!(gMmSave.permanentSceneFlags[sceneId].switch1 & (1 << flagId));
}

static void setSwitch0MarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
    {
        SetSwitchFlag(play, flagId);
        gMultiMarkSwitch0 |= (1 << flagId);
        return;
    }
    gSaveContext.cycleSceneFlags[sceneId].switch0 |= (1 << flagId);
#endif

    gMmSave.permanentSceneFlags[sceneId].switch0 |= (1 << flagId);
}

static void setSwitch1MarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
    {
        SetSwitchFlag(play, flagId | 0x20);
        gMultiMarkSwitch1 |= (1 << flagId);
        return;
    }
    gSaveContext.cycleSceneFlags[sceneId].switch1 |= (1 << flagId);
#endif

    gMmSave.permanentSceneFlags[sceneId].switch1 |= (1 << flagId);
}

static int getStrayFairyMarkMm(GameState_Play* play, int sceneId, int id)
{
    if (id >= 0x30)
        return getCollectibleMarkMm(play, sceneId, id & 0x1f);
    else if (id >= 0x20)
        return getSwitch1MarkMm(play, sceneId, id & 0x1f);
    else
        return getSwitch0MarkMm(play, sceneId, id & 0x1f);
}

static void setStrayFairyMarkMm(GameState_Play* play, int sceneId, int id)
{
    if (id >= 0x30)
        setCollectibleMarkMm(play, sceneId, id & 0x1f);
    else if (id >= 0x20)
        setSwitch1MarkMm(play, sceneId, id & 0x1f);
    else
        setSwitch0MarkMm(play, sceneId, id & 0x1f);
}

static void markXflag(Xflag* xf, int sliceId, int sceneId, int roomId, int id)
{
    bzero(xf, sizeof(*xf));
    xf->sliceId = sliceId;
    xf->setupId = (roomId & 0xc0) >> 6;
    xf->sceneId = sceneId;
    xf->roomId = roomId & 0x3f;
    xf->id = id;
}

static int getXflagsMarkOot(GameState_Play* play, int sliceId, int sceneId, int roomId, int id)
{
    Xflag xf;

    markXflag(&xf, sliceId, sceneId, roomId, id);
    return comboXflagsGetOot(&xf);
}

static int getXflagsMarkMm(GameState_Play* play, int sliceId, int sceneId, int roomId, int id)
{
    Xflag xf;

    markXflag(&xf, sliceId, sceneId, roomId, id);
    return comboXflagsGetMm(&xf);
}

static void setXflagsMarkOot(GameState_Play* play, int sliceId, int sceneId, int roomId, int id)
{
    Xflag xf;

    markXflag(&xf, sliceId, sceneId, roomId, id);
    comboXflagsSetOot(&xf);
}

static void setXflagsMarkMm(GameState_Play* play, int sliceId, int sceneId, int roomId, int id)
{
    Xflag xf;

    markXflag(&xf, sliceId, sceneId, roomId, id);
    comboXflagsSetMm(&xf);
}

void Multi_SetMarkedOot(GameState_Play* play, u8 ovType, u8 sceneId, u8 roomId, u8 id)
{
    if (!Config_Flag(CFG_MULTIPLAYER))
        return;

    switch (ovType)
    {
    case OV_NONE:
        break;
    case OV_CHEST:
        setChestMarkOot(play, sceneId, id);
        break;
    case OV_COLLECTIBLE:
        setCollectibleMarkOot(play, sceneId, id);
        break;
    case OV_NPC:
        BITMAP8_SET(gSharedCustomSave.oot.npc, id);
        break;
    case OV_GS:
        BITMAP32_SET(gOotSave.gsFlags, id - 8);
        break;
    case OV_SF:
        break;
    case OV_COW:
        gCowFlags |= (1 << id);
        break;
    case OV_SHOP:
        BITMAP8_SET(gSharedCustomSave.oot.shops, id);
        break;
    case OV_SCRUB:
        BITMAP8_SET(gSharedCustomSave.oot.scrubs, id);
        break;
    case OV_SR:
        BITMAP8_SET(gSharedCustomSave.oot.sr, id);
        break;
    case OV_FISH:
        BITMAP8_SET(gSharedCustomSave.caughtFishFlags, id);
        break;
    default:
        setXflagsMarkOot(play, ovType - OV_XFLAG0, sceneId, roomId, id);
        break;
    }
}

void Multi_SetMarkedMm(GameState_Play* play, u8 ovType, u8 sceneId, u8 roomId, u8 id)
{
    if (!Config_Flag(CFG_MULTIPLAYER))
        return;

    switch (ovType)
    {
    case OV_NONE:
        break;
    case OV_CHEST:
        setChestMarkMm(play, sceneId, id);
        break;
    case OV_COLLECTIBLE:
        setCollectibleMarkMm(play, sceneId, id);
        break;
    case OV_NPC:
        BITMAP8_SET(gSharedCustomSave.mm.npc, id);
        break;
    case OV_GS:
        break;
    case OV_SF:
        setStrayFairyMarkMm(play, sceneId, id);
        break;
    case OV_COW:
        gCowFlags |= (1 << id);
        break;
    case OV_SHOP:
        BITMAP8_SET(gSharedCustomSave.mm.shops, id);
        break;
    case OV_SCRUB:
        break;
    case OV_SR:
        break;
    case OV_FISH:
        break;
    default:
        setXflagsMarkMm(play, ovType - OV_XFLAG0, sceneId, roomId, id);
        break;
    }
}

int Multi_IsMarkedOot(GameState_Play* play, u8 ovType, u8 sceneId, u8 roomId, u8 id)
{
    if (!Config_Flag(CFG_MULTIPLAYER))
        return 0;

    switch (ovType)
    {
    case OV_NONE:
        break;
    case OV_CHEST:
        return getChestMarkOot(play, sceneId, id);
    case OV_COLLECTIBLE:
        return getCollectibleMarkOot(play, sceneId, id);
    case OV_NPC:
        return BITMAP8_GET(gSharedCustomSave.oot.npc, id);
    case OV_GS:
        return BITMAP32_GET(gOotSave.gsFlags, id - 8);
    case OV_SF:
        break;
    case OV_COW:
        return !!(gCowFlags & (1 << id));
    case OV_SHOP:
        return BITMAP8_GET(gSharedCustomSave.oot.shops, id);
    case OV_SCRUB:
        return BITMAP8_GET(gSharedCustomSave.oot.scrubs, id);
    case OV_SR:
        return BITMAP8_GET(gSharedCustomSave.oot.sr, id);
    case OV_FISH:
        return BITMAP8_GET(gSharedCustomSave.caughtFishFlags, id);
    default:
        return getXflagsMarkOot(play, ovType - OV_XFLAG0, sceneId, roomId, id);
    }

    return 0;
}

int Multi_IsMarkedMm(GameState_Play* play, u8 ovType, u8 sceneId, u8 roomId, u8 id)
{
    if (!Config_Flag(CFG_MULTIPLAYER))
        return 0;

    switch (ovType)
    {
    case OV_NONE:
        break;
    case OV_CHEST:
        return getChestMarkMm(play, sceneId, id);
    case OV_COLLECTIBLE:
        return getCollectibleMarkMm(play, sceneId, id);
    case OV_NPC:
        return BITMAP8_GET(gSharedCustomSave.mm.npc, id);
    case OV_GS:
        break;
    case OV_SF:
        return getStrayFairyMarkMm(play, sceneId, id);
    case OV_COW:
        return !!(gCowFlags & (1 << id));
    case OV_SHOP:
        return BITMAP8_GET(gSharedCustomSave.mm.shops, id);
    case OV_SCRUB:
        break;
    case OV_SR:
        break;
    case OV_FISH:
        break;
    default:
        return getXflagsMarkMm(play, ovType - OV_XFLAG0, sceneId, roomId, id);
    }

    return 0;
}

static void processMessagesSendPlayerPos(GameState_Play* play, NetContext* net)
{
    Actor_Player* link;
    int index;
    NetMsg* msg;

    /* Find a suitable index */
    index = -1;
    for (int i = 0; i < NET_MSG_MAX; ++i)
    {
        if (net->msgInSize[i] == 0 && net->msgOutSize[i] == 0)
        {
            index = i;
            break;
        }
    }
    if (index < 0)
        return;

    /* We have a suitable index, send the message */
    link = GET_PLAYER(play);
    if (!link || (link->actor.id != AC_PLAYER))
        return;

    msg = &net->msgBuffer[index];
    msg->op = NETMSG_PLAYER_POS;
    msg->playerPos.frameCount = play->gs.frameCount;
    msg->playerPos.sceneKey = play->sceneId;
#if defined(GAME_MM)
    msg->playerPos.sceneKey |= 0x8000;
#endif
    msg->playerPos.x = (s16)link->actor.world.pos.x;
    msg->playerPos.y = (s16)link->actor.world.pos.y;
    msg->playerPos.z = (s16)link->actor.world.pos.z;
    net->msgOutSize[index] = 0x10;
}

typedef struct
{
    u16     clientId;
    u8      ttl;
    u32     frameCount;
    Vec3f   pos;
    Vec3f   target;
}
PlayerWisp;

static PlayerWisp sPlayerWisps[16];

static void updateWisp(PlayerWisp* wisp, NetMsgPlayerPos* playerPos)
{
    if (playerPos->frameCount < wisp->frameCount)
        return;

    wisp->ttl = 20;
    wisp->frameCount = playerPos->frameCount;
    wisp->target.x = playerPos->x;
    wisp->target.y = playerPos->y;
    wisp->target.z = playerPos->z;
}

static void processMessageInPlayerPos(GameState_Play* play, NetContext* net, NetMsgPlayerPos* playerPos, u16 clientId)
{
    u16 sceneKey;
    int freeIndex;

    sceneKey = play->sceneId;
#if defined(GAME_MM)
    sceneKey |= 0x8000;
#endif
    if (playerPos->sceneKey != sceneKey)
        return;

    freeIndex = -1;
    for (int i = 0; i < ARRAY_SIZE(sPlayerWisps); ++i)
    {
        if (sPlayerWisps[i].ttl && sPlayerWisps[i].clientId == clientId)
        {
            updateWisp(&sPlayerWisps[i], playerPos);
            return;
        }
        else if (!sPlayerWisps[i].ttl && freeIndex < 0)
        {
            freeIndex = i;
        }
    }

    if (freeIndex >= 0)
    {
        sPlayerWisps[freeIndex].ttl = 20;
        sPlayerWisps[freeIndex].clientId = clientId;
        sPlayerWisps[freeIndex].frameCount = playerPos->frameCount;
        sPlayerWisps[freeIndex].pos.x = playerPos->x;
        sPlayerWisps[freeIndex].pos.y = playerPos->y;
        sPlayerWisps[freeIndex].pos.z = playerPos->z;
        sPlayerWisps[freeIndex].target.x = playerPos->x;
        sPlayerWisps[freeIndex].target.y = playerPos->y;
        sPlayerWisps[freeIndex].target.z = playerPos->z;
    }
}

static void processMessageIn(GameState_Play* play, NetContext* net, NetMsg* msg, u16 clientId)
{
    if (msg->op == NETMSG_PLAYER_POS)
        processMessageInPlayerPos(play, net, &msg->playerPos, clientId);
}

static void Multi_ProcessMessages(GameState_Play* play, NetContext* net)
{
    /* Send pos */
    if ((play->gs.frameCount & 3) == 0)
        processMessagesSendPlayerPos(play, net);

    /* Decrement wisps ttl */
    for (int i = 0; i < ARRAY_SIZE(sPlayerWisps); ++i)
    {
        if (sPlayerWisps[i].ttl)
            --sPlayerWisps[i].ttl;
        if (sPlayerWisps[i].ttl)
        {
            sPlayerWisps[i].pos.x += (sPlayerWisps[i].target.x - sPlayerWisps[i].pos.x) * 0.25f;
            sPlayerWisps[i].pos.y += (sPlayerWisps[i].target.y - sPlayerWisps[i].pos.y) * 0.25f;
            sPlayerWisps[i].pos.z += (sPlayerWisps[i].target.z - sPlayerWisps[i].pos.z) * 0.25f;
        }
    }

    for (int i = 0; i < NET_MSG_MAX; ++i)
    {
        if (net->msgInSize[i])
        {
            processMessageIn(play, net, &net->msgBuffer[i], net->msgClientId[i]);
            net->msgInSize[i] = 0;
        }
    }
}

static const u32 kWispColors[] = {
    0xff0000cc, 0x00ff00cc, 0x0000ffcc, 0xffff00cc,
    0xff00ffcc, 0x00ffffcc, 0x000000cc, 0xffffffcc,
    0x7f0000cc, 0x007f00cc, 0x00007fcc, 0x7f7f00cc,
    0x7f007fcc, 0x007f7fcc, 0x7f7f7fcc, 0x3f3f3fcc,
};

static void drawSingleWisp(GameState_Play* play, const PlayerWisp* wisp)
{
    OPEN_DISPS(play->gs.gfx);
    ModelViewTranslate(wisp->pos.x, wisp->pos.y, wisp->pos.z, MAT_SET);
    Gfx_DrawFlameColor(play, kWispColors[wisp->clientId & 0xf], 0.35f, -50.0f);
    CLOSE_DISPS();
}

void Multi_DrawWisps(GameState_Play* play)
{
    if (!Config_Flag(CFG_MULTIPLAYER))
        return;

    InitListPolyXlu(play->gs.gfx);
    for (int i = 0; i < ARRAY_SIZE(sPlayerWisps); ++i)
    {
        if (sPlayerWisps[i].ttl)
            drawSingleWisp(play, &sPlayerWisps[i]);
    }
}

void Multi_ResetWisps(void)
{
    if (!Config_Flag(CFG_MULTIPLAYER))
        return;
    bzero(sPlayerWisps, sizeof(sPlayerWisps));
}

static int Multi_CanReceiveItem(GameState_Play* play)
{
    Actor_Player* link;

    if (gSaveContext.gameMode || (gSaveContext.minigameState == 1))
        return 0;
    if (Message_GetState(&play->msgCtx) != 0)
        return 0;
    link = GET_PLAYER(play);
    if (link->state & (PLAYER_ACTOR_STATE_GET_ITEM | PLAYER_ACTOR_STATE_FROZEN | PLAYER_ACTOR_STATE_CUTSCENE_FROZEN | PLAYER_ACTOR_STATE_EPONA))
        return 0;

    return 1;
}

static void Multi_GiveItem(GameState_Play* play, s16 gi, u8 from, int flags)
{
    ComboItemQuery q = ITEM_QUERY_INIT;

    q.gi = gi;
    q.from = from;

    if ((flags & OVF_PRECOND) && (!isItemLicensed(gi)))
    {
        bzero(&q, sizeof(q));
        q.ovType = OV_NONE;
        q.gi = RECOVERY_HEART;
    }

    Item_AddWithDecoy(play, &q);
}

static void Multi_ReceiveItem(GameState_Play* play, NetContext* net)
{
    s16 gi;
    u8 ovType;
    u8 sceneId;
    u8 roomId;
    u8 id;
    u8 isMarked;
    u8 needsMarking;
    u8 isSamePlayer;

    gi = net->cmdIn.itemRecv.gi;
    isMarked = 0;
    needsMarking = 0;
    isSamePlayer = (net->cmdIn.itemRecv.playerFrom == gComboConfig.playerId);
    if (isSamePlayer)
    {
        if (!(net->cmdIn.itemRecv.flags & OVF_RENEW))
        {
            needsMarking = 1;
            ovType = (net->cmdIn.itemRecv.key >> 24) & 0xff;
            sceneId = (net->cmdIn.itemRecv.key >> 16) & 0xff;
            roomId = (net->cmdIn.itemRecv.key >> 8) & 0xff;
            id = net->cmdIn.itemRecv.key & 0xff;
            if (net->cmdIn.itemRecv.game)
                isMarked = Multi_IsMarkedMm(play, ovType, sceneId, roomId, id);
            else
                isMarked = Multi_IsMarkedOot(play, ovType, sceneId, roomId, id);
        }
        else
        {
            for (int i = 0; i < ARRAY_SIZE(gSharedCustomSave.netGiSkip); ++i)
            {
                if (gSharedCustomSave.netGiSkip[i] == gi)
                {
                    isMarked = 1;
                    gSharedCustomSave.netGiSkip[i] = GI_NONE;
                    break;
                }
            }
        }
    }

    if (!isMarked && gi != GI_NOTHING)
    {
        /* Need to actually give the item */
        if (!Multi_CanReceiveItem(play) || g.decoysCount)
            return;
        Multi_GiveItem(play, gi, net->cmdIn.itemRecv.playerFrom, net->cmdIn.itemRecv.flags);
    }

    /* Triggers the side-effect */
    if (needsMarking)
    {
        if (net->cmdIn.itemRecv.game)
            Multi_SetMarkedMm(play, ovType, sceneId, roomId, id);
        else
            Multi_SetMarkedOot(play, ovType, sceneId, roomId, id);
    }

    /* Mark as obtained on the network */
    bzero(&net->cmdIn, sizeof(net->cmdIn));
    gSaveLedgerBase++;
    net->ledgerBase = gSaveLedgerBase;
}

static void Multi_ProcessItems(GameState_Play* play, NetContext* net)
{
    if (net->cmdIn.op == NET_OP_ITEM_RECV)
    {
        if (net->cmdIn.itemRecv.playerTo != gComboConfig.playerId)
        {
            bzero(&net->cmdIn, sizeof(net->cmdIn));
            gSaveLedgerBase++;
            net->ledgerBase = gSaveLedgerBase;
        }
        else
        {
            Multi_ReceiveItem(play, net);
        }
    }
}

void Multi_Update(GameState_Play* play)
{
    NetContext* ctx;

    if (!Config_Flag(CFG_MULTIPLAYER))
        return;

    ctx = netMutexLock();
    Multi_ProcessMessages(play, ctx);
    Multi_ProcessItems(play, ctx);
    netMutexUnlock();
}
