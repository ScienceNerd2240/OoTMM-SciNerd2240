#include <combo.h>
#include <combo/item.h>
#include <combo/player.h>
#include <combo/global.h>
#include <combo/draw.h>
#include <combo/actor.h>

#if defined(GAME_OOT)
# define DUMMY_MSG 0xb4
#else
# define DUMMY_MSG 0x52
#endif

void EnItem00_AliasFreestandingRupee(Xflag* xflag);
void EnItem00_AliasFreestandingHeart(Xflag* xflag);

void EnItem00_InitWrapper(Actor_EnItem00* this, GameState_Play* play)
{
    /* Forward */
    EnItem00_Init(this, play);

    /* Set extended fields */
    bzero(&this->xflag, sizeof(this->xflag));
    this->xflagGi = 0;
    this->isExtended = 0;
    this->isExtendedCollected = 0;
    this->isExtendedMajor = 0;
}

static void EnItem00_DrawXflag(Actor_EnItem00* this, GameState_Play* play)
{
    ComboItemOverride o;
    s16 gi;

    if (this->isExtendedCollected)
        gi = this->xflagGi;
    else
    {
        comboXflagItemOverride(&o, &this->xflag, 0);
        gi = o.gi;
        this->xflagGi = gi;
    }

    ModelViewTranslate(this->base.world.pos.x, this->base.world.pos.y + 20.f, this->base.world.pos.z, MAT_SET);
    ModelViewScale(0.35f, 0.35f, 0.35f, MAT_MUL);
    ModelViewRotateY(this->base.shape.rot.y * ((M_PI * 2.f) / 32767.f), MAT_MUL);
    Draw_Gi(play, &this->base, gi, 0);
}

static int EnItem00_XflagCanCollect(Actor_EnItem00* this, GameState_Play* play)
{
    Actor_Player* link;

    link = GET_PLAYER(play);
    if (link->state & (PLAYER_ACTOR_STATE_FROZEN | PLAYER_ACTOR_STATE_EPONA))
        return 0;

    /* Check for textbox */
    if (Message_GetState(&play->msgCtx) != 0)
        return 0;

    return 1;
}

static void EnItem00_UpdateXflagDrop(Actor_EnItem00* this, GameState_Play* play)
{
    /* Artifically disable collisions if the items shouldn't be collected */
    if (!EnItem00_XflagCanCollect(this, play))
        this->base.xzDistToPlayer = 100.f;

    /* Item permanence */
    if (!this->isExtendedCollected)
        this->timer++;

    /* Update */
    EnItem00_Update(this, play);
}

void EnItem00_AddXflag(Actor_EnItem00* this)
{
    ComboItemQuery q;
    ComboItemOverride o;

    if (!this->isExtended)
    {
        AddItem(gPlay, ITEM_RUPEE_GREEN);
        return;
    }

    comboXflagItemQuery(&q, &this->xflag, 0);
    comboItemOverride(&o, &q);
    if (!isItemFastBuy(o.gi))
    {
        PlayerDisplayTextBox(gPlay, DUMMY_MSG, NULL);
        Player_Freeze(gPlay);
        this->isExtendedMajor = 1;
    }
    comboAddItemEx(gPlay, &q, this->isExtendedMajor);
    comboXflagsSet(&this->xflag);

    comboPlayItemFanfare(o.gi, 1);
    this->isExtendedCollected = 1;
}

void EnItem00_PlaySoundXflag(Actor_EnItem00* this)
{
    if (this->isExtended)
        return;
    PlaySound(0x4803);
}

void EnItem00_XflagInit(Actor_EnItem00* this, const Xflag* xflag)
{
    ComboItemOverride o;

    /* Query */
    comboXflagItemOverride(&o, xflag, 0);

    /* Check if there is an override */
    if (o.gi == 0)
        return;
    if (comboXflagsGet(xflag))
        return;

    /* It's an actual item - mark it as such */
    memcpy(&this->xflag, xflag, sizeof(*xflag));
    this->xflagGi = o.gi;
    this->isExtended = 1;

    /* Use our draw func */
    this->base.draw = EnItem00_DrawXflag;
    this->base.variable = 0;
}

void EnItem00_XflagInitFreestanding(Actor_EnItem00* this, GameState_Play* play, u8 actorIndex, u8 slice)
{
    Xflag xflag;

    /* Setup the xflag */
    bzero(&xflag, sizeof(xflag));
    xflag.sceneId = play->sceneId;
    xflag.setupId = g.sceneSetupId;
    xflag.roomId = this->base.room;
    xflag.sliceId = slice;
    xflag.id = actorIndex;

    /* Alias as required */
    switch (this->base.variable & 0xff)
    {
    case ITEM00_RUPEE_GREEN:
    case ITEM00_RUPEE_BLUE:
    case ITEM00_RUPEE_RED:
        EnItem00_AliasFreestandingRupee(&xflag);
        break;
    case ITEM00_RECOVERY_HEART:
        EnItem00_AliasFreestandingHeart(&xflag);
        break;
    }

    /* Init */
    EnItem00_XflagInit(this, &xflag);
}

static void EnItem00_XflagCollectedHandler(Actor_EnItem00* this, GameState_Play* play)
{
    this->timer = 1;
    EnItem00_CollectedHandler(this, play);
    if (Message_IsClosed(&this->base, play))
    {
        Player_Unfreeze(play);
        this->handler = EnItem00_CollectedHandler;
    }
    else
        Player_Freeze(play);
}

void EnItem00_SetXflagCollectedHandler(Actor_EnItem00* this)
{
    if (!this->isExtendedMajor)
    {
        this->handler = EnItem00_CollectedHandler;
        return;
    }

#if defined(GAME_MM)
    this->base.flags |= 0x100000;
#endif

    this->handler = EnItem00_XflagCollectedHandler;
}

Actor_EnItem00* EnItem00_DropCustom(GameState_Play* play, const Vec3f* pos, const Xflag* xflag)
{
    Actor* actor;
    Actor_EnItem00* item;
    ComboItemOverride o;

    /* Check if the xflag item is already spawned */
    for (actor = play->actorCtx.actors[0x08].first; actor != NULL; actor = actor->next)
    {
        if (actor->id != AC_EN_ITEM00)
            continue;
        item = (Actor_EnItem00*)actor;
        if (memcmp(&item->xflag, xflag, sizeof(Xflag)) == 0)
            return NULL;
    }

    /* Check if the item to be spawned is literaly Nothing */
    comboXflagItemOverride(&o, xflag, 0);
    if (o.gi == GI_NOTHING)
    {
        comboXflagsSet(xflag);
        return NULL;
    }

    /* Spawn the item */
    item = Item_DropCollectible(play, pos, 0x0000);

    if (!item)
        return NULL;

    /* Init the custom fields */
    EnItem00_XflagInit(item, xflag);
    item->base.update = EnItem00_UpdateXflagDrop;

    return item;
}
