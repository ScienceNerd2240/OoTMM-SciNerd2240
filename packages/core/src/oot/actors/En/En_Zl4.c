#include <combo.h>
#include <combo/item.h>

void EnZl4_Update6(Actor* actor, GameState_Play* play)
{
    SetEventChk(EV_OOT_CHK_ZELDA_LETTER);
    SetEventChk(EV_OOT_CHK_SONG_ZELDA);
    Actor_Kill(actor);

    play->transitionTrigger = TRANS_TRIGGER_NORMAL;
    play->transitionType = TRANS_GFX_SHORTCUT;
    play->nextEntranceIndex = ENTR_OOT_CASTLE_CAUGHT;
}

void EnZl4_Update5(Actor* actor, GameState_Play* play)
{
    if (Message_GetState(&play->msgCtx) == 2)
    {
        EnZl4_Update6(actor, play);
        actor->update = EnZl4_Update6;
    }
}

void EnZl4_Update4(Actor* actor, GameState_Play* play)
{
    if (Actor_HasParentZ(actor))
    {
        actor->parent = NULL;
        EnZl4_Update5(actor, play);
        actor->update = EnZl4_Update5;
        return;
    }
    comboGiveItemNpc(actor, play, GI_OOT_SONG_ZELDA, NPC_OOT_ZELDA_SONG, 10000.f, 400.f);
}

void EnZl4_Update3(Actor* actor, GameState_Play* play)
{
    if (Actor_HasParentZ(actor))
    {
        actor->parent = NULL;
        EnZl4_Update4(actor, play);
        actor->update = EnZl4_Update4;
        return;
    }
    comboGiveItemNpc(actor, play, GI_OOT_ZELDA_LETTER, NPC_OOT_ZELDA_LETTER, 10000.f, 400.f);
}

void EnZl4_Update2(Actor* actor, GameState_Play* play)
{
    Message_Close(play);
    EnZl4_Update3(actor, play);
    actor->update = EnZl4_Update3;
}

void EnZl4_Update(Actor* actor, GameState_Play* play)
{
    actor->messageId = 0x2005;
    if (ActorTalkedTo(actor))
    {
        actor->update = EnZl4_Update2;
    }
    else
    {
        ActorEnableTalk(actor, play, 100.f);
    }
}

PATCH_FUNC(0x80b83374, EnZl4_Update);
