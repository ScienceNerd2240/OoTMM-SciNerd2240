#ifndef INCLUDED_COMBO_OOT_MESSAGE_H
#define INCLUDED_COMBO_OOT_MESSAGE_H

#include <combo/util.h>

#define FONT_CHAR_TEX_WIDTH  16
#define FONT_CHAR_TEX_HEIGHT 16
#define FONT_CHAR_TEX_SIZE ((FONT_CHAR_TEX_WIDTH * FONT_CHAR_TEX_HEIGHT) / 2)

typedef struct Font
{
    u32 msgOffset;
    u32 msgLength;
    ALIGNED(8) u8 charTexBuf[FONT_CHAR_TEX_SIZE * 120];
    ALIGNED(8) u8 iconBuf[FONT_CHAR_TEX_SIZE];
    ALIGNED(8) u8 fontBuf[FONT_CHAR_TEX_SIZE * 320];
    ALIGNED(8) union
    {
        char msgBuf[1280];
        u16 msgBufWide[640];
    };
}
Font;

ASSERT_SIZE(Font, 0xe188);

typedef struct PACKED
{
    char view[0x128];
    char unk_0128[0xdc88];
    char textBuffer[0x500];
    /* 0xE2B0 */ u8* textboxSegment; /* original name: "fukidashiSegment" */
    /* 0xE2B4 */ char unk_E2B4[0x4];
    /* 0xE2B8 */ struct OcarinaStaff* ocarinaStaff; /* original name : "info" */
    /* 0xE2BC */ char unk_E2BC[0x3C];
    /* 0xE2F8 */ u16 textId;
    /* 0xE2FA */ u16 choiceTextId;
    /* 0xE2FC */ u8 textBoxProperties; /* original name : "msg_disp_type" */
    /* 0xE2FD */ u8 textBoxType; /* "Text Box Type" */
    /* 0xE2FE */ u8 textBoxPos; /* text box position */
    /* 0xE2FF */ u8 pad_e2ff;
    /* 0xE300 */ s32 msgLength;
    /* 0xE304 */ u8 msgMode;
    /* 0xE305 */ u8 unk_e305;
    char unk_e306[0xdf];
    u8   choice;
    char unk_e3e6[0x06];
    u16  lastSongPlayed;
    u16  ocarinaMode;
    u16  ocarinaAction;
    char unk_e3f2[0x26];
}
MessageContext;

ASSERT_SIZE(MessageContext, 0xe418);

#define OCARINA_SONG_MINUET             0x0
#define OCARINA_SONG_BOLERO             0x1
#define OCARINA_SONG_SERENADE           0x2
#define OCARINA_SONG_REQUIEM            0x3
#define OCARINA_SONG_NOCTURNE           0x4
#define OCARINA_SONG_PRELUDE            0x5
#define OCARINA_SONG_SARIAS             0x6
#define OCARINA_SONG_EPONAS             0x7
#define OCARINA_SONG_LULLABY            0x8
#define OCARINA_SONG_SUNS               0x9
#define OCARINA_SONG_TIME               0xa
#define OCARINA_SONG_STORMS             0xb
#define OCARINA_SONG_SCARECROW_SPAWN    0xc
#define OCARINA_SONG_MEMORY_GAME        0xd

#endif
