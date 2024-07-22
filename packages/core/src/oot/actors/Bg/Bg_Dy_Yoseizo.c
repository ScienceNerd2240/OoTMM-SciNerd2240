#include <combo.h>
#include <combo/item.h>

static const s16 kGreatFairyRewards[] = {
    GI_OOT_MAGIC_UPGRADE,
    GI_OOT_MAGIC_UPGRADE2,
    GI_OOT_DEFENSE_UPGRADE,
    GI_OOT_SPELL_WIND,
    GI_OOT_SPELL_FIRE,
    GI_OOT_SPELL_LOVE,
};

static const u8 kGreatFairyNPCs[] = {
    NPC_OOT_FAIRY_MAGIC_UPGRADE,
    NPC_OOT_FAIRY_MAGIC_UPGRADE2,
    NPC_OOT_FAIRY_DEFENSE_UPGRADE,
    NPC_OOT_FAIRY_SPELL_WIND,
    NPC_OOT_FAIRY_SPELL_FIRE,
    NPC_OOT_FAIRY_SPELL_LOVE,
};

void BgDyYoseizo_Update(Actor* this, GameState_Play* play)
{
    u8 index;
    u8 mask;

    if (GetSwitchFlag(play, 0x38))
    {
        index = play->spawn;
        if (play->sceneId == SCE_OOT_GREAT_FAIRY_FOUNTAIN_SPELLS)
            index += 3;
        mask = 1 << index;

        if (Actor_HasParentZ(this) || gOotExtraFlags.greatFairies & mask)
        {
            /* Refill */
            if (gSave.playerData.magicUpgrade)
            {
                gSave.playerData.magicSize = 0;
                gSaveContext.magicFillTarget = gSave.playerData.magicUpgrade2 ? 0x60 : 0x30;
            }
            gSaveContext.healthDelta += 20 * 0x10;
            gOotExtraFlags.greatFairies |= mask;
            Actor_Kill(this);
            return;
        }

        comboGiveItemNpc(this, play, kGreatFairyRewards[index], kGreatFairyNPCs[index], 400.f, 400.f);
    }
}

PATCH_FUNC(0x808eda34, BgDyYoseizo_Update);
