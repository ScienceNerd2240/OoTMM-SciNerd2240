#include <combo.h>
#include <combo/item.h>
#include <combo/config.h>

static void BgTokiSwd_GiveItem(Actor* this, GameState_Play* play, s16 gi, int npc, int event)
{
    if (Actor_HasParentZ(this))
    {
        this->parent = NULL;
        SetEventChk(event);
        return;
    }

    comboGiveItemNpc(this, play, gi, npc, 200.f, 50.f);
}

void BgTokiSwd_Handler(Actor* this, GameState_Play* play)
{
    if (gSave.age == AGE_CHILD && !GetEventChk(EV_OOT_CHK_MASTER_SWORD_CHAMBER))
    {
        BgTokiSwd_GiveItem(this, play, GI_OOT_SWORD_MASTER, NPC_OOT_MASTER_SWORD, EV_OOT_CHK_MASTER_SWORD_CHAMBER);
        return;
    }

    if (gSave.age == AGE_ADULT && !GetEventChk(EV_OOT_CHK_MASTER_SWORD_PULLED))
    {
        BgTokiSwd_GiveItem(this, play, GI_OOT_MEDALLION_LIGHT, NPC_OOT_LIGHT_MEDALLION, EV_OOT_CHK_MASTER_SWORD_PULLED);
        return;
    }

    if (Actor_HasParentZ(this))
    {
        /* Swap farore */
        swapFarore();

        /* Time Travel */
        play->transitionTrigger = TRANS_TRIGGER_NORMAL;
        play->transitionType = TRANS_GFX_SHORTCUT;
        play->nextEntranceIndex = 0x02ca;
        play->linkAgeOnLoad = !(gSave.age);

        Actor_Kill(this);
    }
    else
    {
        /* Needs the Master Sword to become adult */
        if (!Config_Flag(CFG_OOT_TIME_TRAVEL_REQUIRES_MS) || (gSave.inventory.equipment.swords & EQ_OOT_SWORD_MASTER))
            Actor_OfferCarry(this, play);
    }
}

PATCH_FUNC(0x8091902c, BgTokiSwd_Handler);
