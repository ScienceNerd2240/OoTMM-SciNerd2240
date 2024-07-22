#include <combo.h>
#include <combo/item.h>
#include <combo/player.h>

static int checkSetEvent(Actor* actor, int event)
{
    if (GetEventChk(event))
    {
        Actor_Kill(actor);
        return 1;
    }
    if (Actor_HasParentZ(actor))
    {
        SetEventChk(event);
        Actor_Kill(actor);
        return 1;
    }
    return 0;
}

static void EnXc_Update_ForestMeadow(Actor* actor, GameState_Play* play)
{
    if (checkSetEvent(actor, EV_OOT_CHK_SONG_TP_FOREST))
        return;
    if (GET_PLAYER(play)->actor.world.pos.z < -2225.f)
        comboGiveItemNpc(actor, play, GI_OOT_SONG_TP_FOREST, NPC_OOT_SHEIK_FOREST, 10000.f, 50.f);
}

static void EnXc_Update_DeathMountainCrater(Actor* actor, GameState_Play* play)
{
    float x;
    float y;
    float z;

    if (checkSetEvent(actor, EV_OOT_CHK_SONG_TP_FIRE))
        return;

    x = GET_PLAYER(play)->actor.world.pos.x;
    y = GET_PLAYER(play)->actor.world.pos.y;
    z = GET_PLAYER(play)->actor.world.pos.z;

    if (x <= -784.f || x >= -584.f)
        return;

    if (y <= 447.f || y >= 647.f)
        return;

    if (z <= -446.f || z >= -246.f)
        return;

    play->actorCtx.titleCtx.alpha = 0;
    comboGiveItemNpc(actor, play, GI_OOT_SONG_TP_FIRE, NPC_OOT_SHEIK_FIRE, 10000.f, 50.f);
}

static void EnXc_Update_IceCavern(Actor* actor, GameState_Play* play)
{
    Actor_Player* link;
    static int lagFrame = 0;

    if (checkSetEvent(actor, EV_OOT_CHK_SONG_TP_WATER))
        return;

    link = GET_PLAYER(play);
    if (Flags_GetTreasure(play, 0x02))
    {
        if (link->state & PLAYER_ACTOR_STATE_GET_ITEM)
        {
            lagFrame = 0;
        }
        else
        {
            if (lagFrame)
            {
                comboGiveItemNpc(actor, play, GI_OOT_SONG_TP_WATER, NPC_OOT_SHEIK_WATER, 10000.f, 5000.f);
                lagFrame = 0;
            }
            lagFrame++;
        }
    }
}

static void EnXc_Update_TempleOfTime(Actor* this, GameState_Play* play)
{
    if (!gSave.inventory.quest.medallionForest || GetEventChk(EV_OOT_CHK_SONG_TP_LIGHT))
        Actor_Kill(this);

    if (checkSetEvent(this, EV_OOT_CHK_SONG_TP_LIGHT))
        return;

    comboGiveItemNpc(this, play, GI_OOT_SONG_TP_LIGHT, NPC_OOT_SHEIK_LIGHT, 10000.f, 50.f);
}

static void EnXc_Init(Actor* this, GameState_Play* play)
{
    this->draw = NULL;
    if (gSave.age == AGE_CHILD && this->variable != 0 && this->variable != 0x8)
    {
        Actor_Kill(this);
    }
}

void EnXc_Update(Actor* this, GameState_Play* play)
{
    switch (this->variable)
    {
    case 0x6:
        EnXc_Update_ForestMeadow(this, play);
        break;
    case 0x7:
        EnXc_Update_DeathMountainCrater(this, play);
        break;
    case 0x8:
        EnXc_Update_IceCavern(this, play);
        break;
    case 0x9:
        EnXc_Update_TempleOfTime(this, play);
        break;
    default:
        Actor_Kill(this);
        break;
    }
}

PATCH_FUNC(0x808e30a8, EnXc_Init);
PATCH_FUNC(0x808e3060, EnXc_Update);
