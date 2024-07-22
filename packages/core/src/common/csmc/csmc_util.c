#include <combo.h>
#include <combo/csmc.h>
#include <combo/item.h>
#include <combo/config.h>

int csmcFromItem(s16 gi)
{
    if (gi == 0)
        return CSMC_NORMAL;
    if (gi < 0)
        gi = -gi;

    /* Special case: OoT bombchu */
    if (Config_Flag(CFG_OOT_BOMBCHU_BAG))
    {
        switch (gi)
        {
        case GI_OOT_BOMBCHU_5:
        case GI_OOT_BOMBCHU_10:
        case GI_OOT_BOMBCHU_20:
            return CSMC_MAJOR;
        }
    }

    /* Special case: MM bombchu */
    if (Config_Flag(CFG_MM_BOMBCHU_BAG))
    {
        switch (gi)
        {
        case GI_MM_BOMBCHU:
        case GI_MM_BOMBCHU_5:
        case GI_MM_BOMBCHU_10:
        case GI_MM_BOMBCHU_20:
            return CSMC_MAJOR;
        }
    }

    switch (comboItemType(gi))
    {
    case ITT_MAJOR:
    case ITT_MASK:
        return CSMC_MAJOR;
    case ITT_BOSS_KEY:
        return CSMC_BOSS_KEY;
    case ITT_KEY:
        return CSMC_KEY;
    case ITT_SKULL:
        return CSMC_SPIDER;
    case ITT_FAIRY:
        return CSMC_FAIRY;
    case ITT_HEART:
        return Config_Flag(CFG_CSMC_HEARTS) ? CSMC_HEART : CSMC_NORMAL;
    case ITT_MAP_COMPASS:
        return Config_Flag(CFG_CSMC_MAP_COMPASS) ? CSMC_MAP_COMPASS : CSMC_NORMAL;
    case ITT_SOUL:
        return CSMC_SOUL;
    case ITT_NONE:
    case ITT_RUPEE:
    case ITT_MINOR:
    case ITT_NORMAL:
    default:
        return CSMC_NORMAL;
    }
}

int csmcEnabled(void)
{
    return (Config_Flag(CFG_CSMC) || (Config_Flag(CFG_CSMC_AGONY) && gOotSave.inventory.quest.agonyStone));
}

int csmcEnabledSkulltula(void)
{
    return csmcEnabled() && Config_Flag(CFG_CSMC_SKULLTULA);
}

int csmcEnabledCow(void)
{
    return csmcEnabled() && Config_Flag(CFG_CSMC_COW);
}
