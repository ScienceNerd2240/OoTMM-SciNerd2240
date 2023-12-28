#include <combo.h>
#include <combo/custom.h>
#include <combo/item.h>
#include <combo/csmc.h>

void EnTuboTrap_InitWrapper(Actor_EnTuboTrap* this, GameState_Play* play)
{
    ActorFunc EnTuboTrap_Init;

    /* Set the extended properties */
    this->xflag.sceneId = play->sceneId;
    this->xflag.setupId = g.sceneSetupId;
    this->xflag.roomId = this->base.room;
    this->xflag.sliceId = 0;
    this->xflag.id = g.actorIndex;

    /* Forward init */
    EnTuboTrap_Init = actorAddr(AC_EN_TUBO_TRAP, 0x80a77b30);
    EnTuboTrap_Init(&this->base, play);
}

void EnTuboTrap_SpawnShuffledDrop(Actor_EnTuboTrap* this, GameState_Play* play)
{
    u16 var;

    if (comboXflagsGet(&this->xflag))
    {
        /* Already spawned */
        var = this->base.variable;
        if ((var & 0xff) < 0x1a)
        {
            Item_DropCollectible(play, &this->base.position, (var & 0xff) | (((var >> 9) & 0x3f) << 8));
        }
        return;
    }

    /* Spawn an extended item */
    DropCustomItem(play, &this->base.position, &this->xflag);
}

static void EnTuboTrap_Draw(Actor_EnTuboTrap* this, GameState_Play* play)
{
    ComboItemOverride o;

    if (comboConfig(CFG_OOT_SHUFFLE_POTS) && !comboXflagsGet(&this->xflag))
        comboXflagItemOverride(&o, &this->xflag, 0);
    else
        o.gi = 0;

    csmcPotPreDraw(&this->base, play, o.gi, CSMC_POT_NORMAL_DANGEON);

    /* Draw the pot */
    DrawSimpleOpa(play, 0x5017870);
}

PATCH_FUNC(0x80a78684, EnTuboTrap_Draw);
