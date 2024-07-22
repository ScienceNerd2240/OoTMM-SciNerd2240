#include <combo.h>
#include <combo/item.h>
#include <combo/player.h>
#include <combo/inventory.h>

void EnKo_GiveItem(Actor* actor, GameState_Play* play, s16 gi, float a, float b)
{
    if (!(GET_PLAYER(play)->state & PLAYER_ACTOR_STATE_GET_ITEM))
        Message_Close(play);
    comboRemoveTradeItemAdult(XITEM_OOT_ADULT_ODD_POTION);
    comboGiveItemNpc(actor, play, gi, NPC_OOT_TRADE_POACHER_SAW, a, b);
}

PATCH_CALL(0x80ad43ec, EnKo_GiveItem);

void EnKo_SpawnHook(Actor* this)
{
    /* Check for Lost Woods */
    switch (gSave.entrance)
    {
    case 0x11e:
    case 0x1a9:
    case 0x1b1:
    case 0x4d6:
    case 0x4da:
    case 0x4de:
    case 0x5e0:
        break;
    default:
        Actor_Kill(this);
        return;
    }

    /* Check for Odd Potion or selected cojiro */
    if ((!(gOotExtraTrade.adult & (1 << XITEM_OOT_ADULT_ODD_POTION))) || gSave.inventory.items[ITS_OOT_TRADE_ADULT] == ITEM_OOT_COJIRO)
        Actor_Kill(this);
}

PATCH_CALL(0x80ad3ea0, EnKo_SpawnHook);
