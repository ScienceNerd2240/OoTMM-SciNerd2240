#ifndef COMBO_SAVE_H
#define COMBO_SAVE_H

#if !defined(__ASSEMBLER__)
# include <combo/oot/save.h>
# include <combo/mm/save.h>

typedef struct ALIGNED(16)
{
    OotCustomSave   oot;
    MmCustomSave    mm;
    u16             coins[4];
    u16             ocarinaButtonMaskOot;
    u16             ocarinaButtonMaskMm;
    u8              soulsEnemyOot[8];
    u8              soulsEnemyMm[8];
    u8              soulsBossOot[2];
    u8              soulsBossMm[1];
    u8              soulsNpcOot[8];
    u8              caughtChildFishWeight[20]; // first item is length. should this be in OotCustomSave?
    u8              caughtAdultFishWeight[20]; // first item is length. should this be in OotCustomSave?
}
SharedCustomSave;

extern SharedCustomSave gSharedCustomSave;

# if defined(GAME_OOT)
#  define gCustomSave gSharedCustomSave.oot
# else
#  define gCustomSave gSharedCustomSave.mm
# endif
#endif

#define SAVE_OFFSET_MM_1            0x08000
#define SAVE_OFFSET_MM_1_BACKUP     0x0c000
#define SAVE_OFFSET_MM_2            0x10000
#define SAVE_OFFSET_MM_2_BACKUP     0x14000
#define SAVE_OFFSET_MM_3            0x18000
#define SAVE_OFFSET_MM_3_BACKUP     0x1c000

#if defined(__ASSEMBLER__)
# if defined(GAME_OOT)
#  define gOotSave gSaveContext
# else
#  define gMmSave gSaveContext
# endif
# define SAVE_EXTRA_RECORD(type, index) (gOotSave + 0xd4 + 0x1c * (index) + 0x10)
#else
# define SAVE_EXTRA_RECORD(type, index) (*((type*)(gOotSave.perm[index].raw + 0x10)))
typedef struct
{
    u32 erSpring:1;
    u32 erSwampClear:1;
    u32 erCoastClear:1;
    u32 unused:29;
}
MiscFlags;
#endif

#define gOotExtraTrade              SAVE_EXTRA_RECORD(OotExtraTrade,     0)
#define gOotExtraItems              SAVE_EXTRA_RECORD(OotExtraItems,     1)
#define gOotExtraFlags              SAVE_EXTRA_RECORD(OotExtraFlags,     2)
#define gMmExtraBoss                SAVE_EXTRA_RECORD(MmExtraBoss,       3)
#define gMmExtraItems               SAVE_EXTRA_RECORD(MmExtraItems,      4)
#define gMmExtraTrade               SAVE_EXTRA_RECORD(MmExtraTrade,      5)
#define gMmExtraFlags               SAVE_EXTRA_RECORD(MmExtraFlags,      6)
#define gMmExtraFlags2              SAVE_EXTRA_RECORD(MmExtraFlags2,     7)
#define gMiscFlags                  SAVE_EXTRA_RECORD(MiscFlags,         8)
#define gCowFlags                   SAVE_EXTRA_RECORD(u32,               9)
#define gOotExtraShopsLo            SAVE_EXTRA_RECORD(u32,              10)
#define gOotExtraShopsHi            SAVE_EXTRA_RECORD(u32,              11)
#define gMmExtraShops               SAVE_EXTRA_RECORD(u32,              12)
#define gOotExtraScrubsLo           SAVE_EXTRA_RECORD(u32,              13)
#define gOotExtraScrubsHi           SAVE_EXTRA_RECORD(u32,              14)
#define gOotExtraTradeSave          SAVE_EXTRA_RECORD(OotExtraTrade,    15)
#define gMmOwlFlags                 SAVE_EXTRA_RECORD(u32,              16)
#define gSaveLedgerBase             SAVE_EXTRA_RECORD(u32,              17)
#define gMmExtraFlags3              SAVE_EXTRA_RECORD(MmExtraFlags3,    18)
#define gOotSilverRupeeFlags1       SAVE_EXTRA_RECORD(u32,              19)
#define gOotSilverRupeeFlags2       SAVE_EXTRA_RECORD(u32,              20)
#define gOotSilverRupeeFlags3       SAVE_EXTRA_RECORD(u32,              21)
#define gOotSilverRupeeFlags4       SAVE_EXTRA_RECORD(u32,              22)
#define gOotSilverRupeeCounts1      SAVE_EXTRA_RECORD(u32,              23)
#define gOotSilverRupeeCounts2      SAVE_EXTRA_RECORD(u32,              24)
#define gOotSilverRupeeCounts3      SAVE_EXTRA_RECORD(u32,              25)
#define gOotSilverRupeeCounts4      SAVE_EXTRA_RECORD(u32,              26)
#define gOotSilverRupeeCounts5      SAVE_EXTRA_RECORD(u32,              27)
#define gTriforceCount              SAVE_EXTRA_RECORD(u32,              28)

#endif
