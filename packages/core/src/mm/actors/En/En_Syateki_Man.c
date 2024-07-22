#include <combo.h>
#include <combo/item.h>
#include <combo/player.h>

int EnSyatekiMan_HasGivenItemSwamp(Actor* this, GameState_Play* play)
{
    Actor_Player* link;

    if (gSave.shootingGalleryHighScoreSwamp >= 2180 && !MM_GET_EVENT_WEEK(EV_MM_WEEK_ARCHERY_SWAMP_QUIVER))
    {
        /* Give two items */
        link = GET_PLAYER(play);
        if (link->state & PLAYER_ACTOR_STATE_GET_ITEM)
        {
            this->parent = NULL;
            MM_SET_EVENT_WEEK(EV_MM_WEEK_ARCHERY_SWAMP_QUIVER);
        }
    }

    return Actor_HasParentZ(this);
}

PATCH_CALL(0x809c7aa4, EnSyatekiMan_HasGivenItemSwamp);

int EnSyatekiMan_HasGivenItemTown(Actor* this, GameState_Play* play)
{
    Actor_Player* link;

    if (gSave.shootingGalleryHighScoreTown >= 50 && !MM_GET_EVENT_WEEK(EV_MM_WEEK_ARCHERY_TOWN_QUIVER))
    {
        /* Give two items */
        link = GET_PLAYER(play);
        if (link->state & PLAYER_ACTOR_STATE_GET_ITEM)
        {
            this->parent = NULL;
            MM_SET_EVENT_WEEK(EV_MM_WEEK_ARCHERY_TOWN_QUIVER);
            *(u16*)((char*)this + 0x284) = 0x406;
        }
    }

    return Actor_HasParentZ(this);
}

PATCH_CALL(0x809c7d28, EnSyatekiMan_HasGivenItemTown);

void EnSyatekiMan_GiveItem(Actor* actor, GameState_Play* play, s16 gi, float a, float b)
{
    Actor_Player* link;
    int npcQuiver;
    int npcHeartPiece;
    int npc;

    link = GET_PLAYER(play);
    if (link->state & PLAYER_ACTOR_STATE_GET_ITEM)
        return;

    if (play->sceneId == SCE_MM_SHOOTING_GALLERY)
    {
        npcQuiver = NPC_MM_SHOOTING_GAME_TOWN_1;
        npcHeartPiece = NPC_MM_SHOOTING_GAME_TOWN_2;
    }
    else
    {
        npcQuiver = NPC_MM_SHOOTING_GAME_SWAMP_1;
        npcHeartPiece = NPC_MM_SHOOTING_GAME_SWAMP_2;
    }

    switch (gi)
    {
    case GI_MM_BOW:
    case GI_MM_QUIVER2:
    case GI_MM_QUIVER3:
        npc = npcQuiver;
        break;
    case GI_MM_HEART_PIECE:
        npc = npcHeartPiece;
        break;
    default:
        npc = -1;
        break;
    }
    comboGiveItemNpc(actor, play, gi, npc, a, b);
}

PATCH_CALL(0x809c7b64, EnSyatekiMan_GiveItem);
PATCH_CALL(0x809c7b90, EnSyatekiMan_GiveItem);
PATCH_CALL(0x809c7bc4, EnSyatekiMan_GiveItem);
PATCH_CALL(0x809c7bdc, EnSyatekiMan_GiveItem);
PATCH_CALL(0x809c7e14, EnSyatekiMan_GiveItem);
PATCH_CALL(0x809c7e30, EnSyatekiMan_GiveItem);
PATCH_CALL(0x809c7e64, EnSyatekiMan_GiveItem);
PATCH_CALL(0x809c7e7c, EnSyatekiMan_GiveItem);
