#include <combo.h>

static s32 progressiveRutoLetter(void)
{
    if (gOotExtraItems.rutoLetter)
        return GI_OOT_BOTTLE_EMPTY;
    return GI_OOT_RUTO_LETTER;
}

static s32 progressiveBombBag(void)
{
    if (gOotSave.inventory.items[ITS_OOT_BOMBS] == ITEM_NONE)
        return GI_OOT_BOMB_BAG;
    switch (gOotSave.inventory.upgrades.bombBag)
    {
    case 0:
        return GI_OOT_BOMB_BAG; /* Redundent */
    case 1:
        return GI_OOT_BOMB_BAG2;
    default:
        return GI_OOT_BOMB_BAG3;
    }
}

static s32 progressiveBow(void)
{
    if (gOotSave.inventory.items[ITS_OOT_BOW] == ITEM_NONE)
        return GI_OOT_BOW;
    switch (gOotSave.inventory.upgrades.quiver)
    {
    case 0:
    case 1:
        return GI_OOT_QUIVER2;
    default:
        return GI_OOT_QUIVER3;
    }
}

static s32 progressiveSlingshot(void)
{
    if (gOotSave.inventory.items[ITS_OOT_SLINGSHOT] == ITEM_NONE)
        return GI_OOT_SLINGSHOT;
    switch (gOotSave.inventory.upgrades.bulletBag)
    {
    case 0:
        return GI_OOT_BULLET_BAG; /* Not used */
    case 1:
        return GI_OOT_BULLET_BAG2;
    default:
        return GI_OOT_BULLET_BAG3;
    }
}

static s32 progressiveOcarina(void)
{
    if (gOotExtraItems.ocarina == 0)
        return GI_OOT_OCARINA_FAIRY;
    return GI_OOT_OCARINA_TIME;
}

static s32 progressiveHookshot(void)
{
    if (gOotExtraItems.hookshot == 0)
        return GI_OOT_HOOKSHOT;
    return GI_OOT_LONGSHOT;
}

static s32 progressiveSwordGoron(void)
{
    if (!(gOotSave.inventory.equipment.swords & (EQ_OOT_SWORD_KNIFE | EQ_OOT_SWORD_KNIFE_BROKEN)))
        return GI_OOT_SWORD_KNIFE;
    return GI_OOT_SWORD_BIGGORON;
}

static s32 progressiveSword(void)
{
    if (!(gOotSave.inventory.equipment.swords & EQ_OOT_SWORD_KOKIRI))
        return GI_OOT_SWORD_KOKIRI;
    if (!(gOotSave.inventory.equipment.swords & EQ_OOT_SWORD_MASTER))
        return GI_OOT_SWORD_MASTER;
    return progressiveSwordGoron();
}

/* We use an extra field to know which shields we got from shops */
static s32 progressiveShield(void)
{
    if (!(gOotExtraItems.shield & EQ_OOT_SHIELD_DEKU))
        return GI_OOT_PROGRESSIVE_SHIELD_DEKU;
    if (!(gOotExtraItems.shield & EQ_OOT_SHIELD_HYLIAN))
    {
#if defined(GAME_MM)
        if (comboConfig(CFG_SHARED_SHIELDS))
            return GI_MM_PROGRESSIVE_SHIELD_HERO;
#endif
        return GI_OOT_PROGRESSIVE_SHIELD_HYLIAN;
    }

#if defined(GAME_MM)
    if (comboConfig(CFG_SHARED_SHIELDS))
        return GI_MM_SHIELD_MIRROR;
#endif

    return GI_OOT_SHIELD_MIRROR;
}

static s32 progressiveStrength(void)
{
    switch (gOotSave.inventory.upgrades.strength)
    {
    case 0:
        return GI_OOT_GORON_BRACELET;
    case 1:
        return GI_OOT_SILVER_GAUNTLETS;
    default:
        return GI_OOT_GOLDEN_GAUNTLETS;
    }
}

static s32 progressiveDive(void)
{
    if (gOotSave.inventory.upgrades.dive)
        return GI_OOT_SCALE_GOLDEN;
    return GI_OOT_SCALE_SILVER;
}

static s32 progressiveWallet(void)
{
    if (!gOotExtraFlags.childWallet)
        return GI_OOT_WALLET;
    switch (gOotSave.inventory.upgrades.wallet)
    {
    case 0: return GI_OOT_WALLET2;
    case 1: return GI_OOT_WALLET3;
    case 2: return comboConfig(CFG_COLOSSAL_WALLET) ? GI_OOT_WALLET4 : GI_OOT_WALLET3;
    case 3: return comboConfig(CFG_BOTTOMLESS_WALLET) ? GI_OOT_WALLET5 : GI_OOT_WALLET4;
    }
}

static s32 progressiveMagic(void)
{
    if (gOotSave.playerData.magicUpgrade)
        return GI_OOT_MAGIC_UPGRADE2;
    return GI_OOT_MAGIC_UPGRADE;
}

static s32 progressiveUpgradeNut(void)
{
    if (gOotSave.inventory.upgrades.dekuNut < 2)
        return GI_OOT_NUT_UPGRADE;
    return GI_OOT_NUT_UPGRADE2;
}

static s32 progressiveUpgradeStick(void)
{
    if (gOotSave.inventory.upgrades.dekuStick < 2)
        return GI_OOT_STICK_UPGRADE;
    return GI_OOT_STICK_UPGRADE2;
}

s32 comboProgressiveOot(s32 gi)
{
    switch (gi)
    {
    /* Items */
    case GI_OOT_BOMB_BAG:
    case GI_OOT_BOMB_BAG2:
    case GI_OOT_BOMB_BAG3:
        gi = progressiveBombBag();
        break;
    case GI_OOT_BOW:
    case GI_OOT_QUIVER2:
    case GI_OOT_QUIVER3:
        gi = progressiveBow();
        break;
    case GI_OOT_SLINGSHOT:
    case GI_OOT_BULLET_BAG:
    case GI_OOT_BULLET_BAG2:
    case GI_OOT_BULLET_BAG3:
        gi = progressiveSlingshot();
        break;
    case GI_OOT_OCARINA_FAIRY:
    case GI_OOT_OCARINA_TIME:
        gi = progressiveOcarina();
        break;
    case GI_OOT_HOOKSHOT:
    case GI_OOT_LONGSHOT:
        gi = progressiveHookshot();
        break;
    /* Equipment */
    case GI_OOT_SWORD_KOKIRI:
    case GI_OOT_SWORD_MASTER:
        if (comboConfig(CFG_OOT_PROGRESSIVE_SWORDS))
            gi = progressiveSword();
        break;
    case GI_OOT_SWORD_BIGGORON:
    case GI_OOT_SWORD_KNIFE:
        if (comboConfig(CFG_OOT_PROGRESSIVE_SWORDS) || comboConfig(CFG_OOT_PROGRESSIVE_SWORDS_GORON))
            gi = progressiveSwordGoron();
        break;
    case GI_OOT_PROGRESSIVE_SHIELD_DEKU:
    case GI_OOT_PROGRESSIVE_SHIELD_HYLIAN:
    case GI_OOT_SHIELD_MIRROR:
        if (comboConfig(CFG_OOT_PROGRESSIVE_SHIELDS))
            gi = progressiveShield();
        break;
    /* Upgrades */
    case GI_OOT_GORON_BRACELET:
    case GI_OOT_SILVER_GAUNTLETS:
    case GI_OOT_GOLDEN_GAUNTLETS:
        gi = progressiveStrength();
        break;
    case GI_OOT_SCALE_SILVER:
    case GI_OOT_SCALE_GOLDEN:
        gi = progressiveDive();
        break;
    case GI_OOT_WALLET:
    case GI_OOT_WALLET2:
    case GI_OOT_WALLET3:
    case GI_OOT_WALLET4:
    case GI_OOT_WALLET5:
        gi = progressiveWallet();
        break;
    case GI_OOT_MAGIC_UPGRADE:
    case GI_OOT_MAGIC_UPGRADE2:
        gi = progressiveMagic();
        break;
    case GI_OOT_NUT_UPGRADE:
    case GI_OOT_NUT_UPGRADE2:
        gi = progressiveUpgradeNut();
        break;
    case GI_OOT_STICK_UPGRADE:
    case GI_OOT_STICK_UPGRADE2:
        gi = progressiveUpgradeStick();
        break;
    /* Misc */
    case GI_OOT_RUTO_LETTER:
        gi = progressiveRutoLetter();
        break;
    default:
        break;
    }

    return gi;
}
