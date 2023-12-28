#ifndef MM_SAVE_H
#define MM_SAVE_H

#include <combo/types.h>
#include <combo/xflags.h>

typedef struct
{
    char    newf[6];
    u16     deaths;
    u8      playerName[8];
    s16     healthMax;
    s16     health;
    s8      magicLevel;
    s8      magicAmount;
    s16     rupees;
    u16     swordHealth;
    u16     tatlTimer;
    u8      magicAcquired;
    u8      doubleMagic;
    u8      doubleDefense;
    u8      unk_1F;
    u16     unk_20;
    u16     owlActivationFlags;
    u16     unk_24;
    s16     savedSceneNum;
}
MmSavePlayerData;

typedef struct
{
    u8      buttonItems[4][4];
    u8      cButtonSlots[4][4];
    u16     unused:10;
    u16     shield:2;
    u16     sword:4;
}
MmItemEquips;

typedef struct
{
    u32     unused:9;
    u32     dekuNut:3;
    u32     dekuStick:3;
    u32     unused2:3;
    u32     wallet:2;
    u32     unused3:6;
    u32     bombBag:3;
    u32     quiver:3;
}
MmUpgrades;

typedef struct
{
    u8 maxKeys:5;
    u8 map:1;
    u8 compass:1;
    u8 bossKey:1;
}
MmDungeonItems;

typedef union
{
    struct
    {
        u32 heartPieces:4;
        u32 unused:3;
        u32 songLullabyIntro:1;
        u32 unused2:5;
        u32 notebook:1;
        u32 songSun:1;
        u32 songStorms:1;
        u32 songSoaring:1;
        u32 songEpona:1;
        u32 songHealing:1;
        u32 songTime:1;
        u32 songSaria:1;
        u32 songOrder:1;
        u32 songEmpty:1;
        u32 songNewWave:1;
        u32 songLullaby:1;
        u32 songAwakening:1;
        u32 unused3:2;
        u32 remainsTwinmold:1;
        u32 remainsGyorg:1;
        u32 remainsGoht:1;
        u32 remainsOdolwa:1;
    };
    u32 value;
}
MmQuestItems;

#define QUEST_MM_REMAINS_ODOLWA         0
#define QUEST_MM_REMAINS_GOHT           1
#define QUEST_MM_REMAINS_GYORG          2
#define QUEST_MM_REMAINS_TWINMOLD       3
#define QUEST_MM_SONG_AWAKENING         6
#define QUEST_MM_SONG_GORON             7
#define QUEST_MM_SONG_ZORA              8
#define QUEST_MM_SONG_EMPTINESS         9
#define QUEST_MM_SONG_ORDER             10
#define QUEST_MM_SONG_SARIA             11
#define QUEST_MM_SONG_TIME              12
#define QUEST_MM_SONG_HEALING           13
#define QUEST_MM_SONG_EPONA             14
#define QUEST_MM_SONG_SOARING           15
#define QUEST_MM_SONG_STORMS            16
#define QUEST_MM_SONG_SUN               17
#define QUEST_MM_NOTEBOOK               18
#define QUEST_MM_SONG_GORON_HALF        24

typedef struct
{
    u8              items[48];
    s8              ammo[24];
    MmUpgrades      upgrades;
    MmQuestItems    quest;
    MmDungeonItems  dungeonItems[10];
    s8              dungeonKeys[9];
    s8              defenseHearts;
    s8              strayFairies[10];
    char            dekuPlaygroundPlayerName[3][8];
}
MmInventory;

typedef union
{
    struct
    {
        u32 chest;
        u32 switch0;
        u32 switch1;
        u32 clearedRoom;
        u32 collectible;
        u32 clearedFloors;
        u32 rooms;
    };
    char raw[0x1c];
}
MmPermanentSceneFlags;

typedef struct
{
    s16         scene;
    Vec3s       pos;
    s16         yaw;
}
MmHorseData;

typedef struct
{
    s32                     entranceIndex;
    u8                      equippedMask;
    u8                      isFirstCycle;
    char                    unk_006;
    u8                      linkAge;
    s32                     cutscene;
    u16                     time;
    u16                     owlLocation;
    s32                     isNight;
    s32                     daySpeed;
    s32                     day;
    u32                     daysElapsed;
    u8                      playerForm;
    u8                      snowheadCleared;
    u8                      hasTatl;
    u8                      isOwlSave;
    MmSavePlayerData        playerData;
    MmItemEquips            itemEquips;
    MmInventory             inventory;
    MmPermanentSceneFlags   permanentSceneFlags[120];
    u8                      unk_E18[0x54];
    u32                     dekuPlaygroundHighScores[3];
    u32                     pictoFlags0;
    u32                     pictoFlags1;
    u32                     unk_E80;
    u32                     unk_E84;
    u32                     unk_E88[7];
    u32                     scenesVisible[7];
    u16                     skullCountSwamp;
    u16                     skullCountOcean;
    u32                     unk_EC4;
    u32                     unk_EC8;
    u32                     unk_ECC[2];
    u32                     stolenItems;
    u32                     unk_DD8;
    u32                     bankRupees;
    u32                     unk_ee0;
    u32                     unk_ee4;
    u32                     unk_ee8;
    u32                     horseBackBalloonHighScore;
    u32                     lotteryCodeGuess;
    u16                     shootingGalleryHighScoreSwamp;
    u16                     shootingGalleryHighScoreTown;
    u8                      weekEventReg[100];
    u32                     mapsVisited;
    u32                     worldMapCloudVisibility;
    u8                      unk_F64;
    u8                      unk_F65;
    u8                      scarecrowSpawnSong[128];
    s8                      bombersCaughtNum;
    s8                      bombersCaughtOrder[5];
    s8                      lotteryCodes[3][3];
    s8                      spiderHouseMaskOrder[6];
    s8                      bomberCode[5];
    MmHorseData             horseData;
    u16                     checksum;
    u8                      eventInf[8];
    u8                      unk_1014;
    u8                      unk_1015;
    u16                     jinxTimer;
    s16                     rupeesDelta;
    char                    unk[0x2c86];
}
MmSave;

typedef struct
{
    u16 optionId;
    u8  unk_02;
    u8  audio;
    u8  unk_04;
    u8  zTarget;
}
SaveOptions;

typedef struct
{
    MmSave          save;
    u32             fileIndex;
    char            unk_3ca4[0x4];
    s32             gameMode;
    s32             sceneSetupId;
    char            unk_3cb0[0x077];
    u8              grottoChestFlag;
    char            unk_3d28[0xa8];
    u8              timerStates[0x7];
    char            unk_3dd7[0x151];
    u16             magicState;
    u16             isMagicRequested;
    u16             magicFlag;
    u16             magicCapacity;
    u16             magicFillTarget;
    u16             magicToConsume;
    u16             magicToAdd;
    u16             dungeonId2;
    char            unk_3f38[0x2];
    u16             minigameCounter[2];
    char            unk_3f3e[0x2];
    SaveOptions     options;
    char            unk_3f46[0x4];
    u16             nextCutscene;
    char            unk_3f4c[0xe];
    u16             healthDelta;
    char            unk_3f5c[0x96c];
    u16             dungeonId;
}
MmSaveContext;

_Static_assert(sizeof(MmSave) == 0x3ca0, "MmSave size is wrong");
_Static_assert(sizeof(MmSaveContext) == 0x48cc, "MmSaveContext size is wrong");

ASSERT_OFFSET(MmSaveContext, fileIndex,         0x3ca0);
ASSERT_OFFSET(MmSaveContext, unk_3ca4,          0x3ca4);
ASSERT_OFFSET(MmSaveContext, gameMode,          0x3ca8);
ASSERT_OFFSET(MmSaveContext, sceneSetupId,      0x3cac);
ASSERT_OFFSET(MmSaveContext, unk_3cb0,          0x3cb0);
ASSERT_OFFSET(MmSaveContext, grottoChestFlag,   0x3d27);
ASSERT_OFFSET(MmSaveContext, unk_3d28,          0x3d28);
ASSERT_OFFSET(MmSaveContext, timerStates,       0x3dd0);
ASSERT_OFFSET(MmSaveContext, unk_3dd7,          0x3dd7);
ASSERT_OFFSET(MmSaveContext, dungeonId2,        0x3f36);
ASSERT_OFFSET(MmSaveContext, minigameCounter,   0x3f3a);
ASSERT_OFFSET(MmSaveContext, options,           0x3f40);
ASSERT_OFFSET(MmSaveContext, unk_3f4c,          0x3f4c);
ASSERT_OFFSET(MmSaveContext, healthDelta,       0x3f5a);
ASSERT_OFFSET(MmSaveContext, unk_3f5c,          0x3f5c);
ASSERT_OFFSET(MmSaveContext, dungeonId,         0x48c8);

#if defined(GAME_MM)
ALIGNED(16) extern MmSaveContext gSaveContext;
# define gMmSave        (gSaveContext.save)
# define gSave          gMmSave
# define gForeignSave   gOotSave
#else
ALIGNED(16) extern MmSave gMmSave;
#endif

/* Custom */
typedef struct
{
    u8 boss;
    u8 bossCycle;
    u8 items;
    u8 unused;
}
MmExtraBoss;

typedef struct
{
    u8 hookshot;
    u8 ocarina;
    u8 goldDust:1;
    u8 unused:7;
    u8 unused2;
}
MmExtraItems;

typedef struct
{
    u32 trade1:5;
    u32 trade2:2;
    u32 trade3:2;
    u32 tradeObtained1:5;
    u32 tradeObtained2:2;
    u32 tradeObtained3:2;
}
MmExtraTrade;

typedef struct
{
    u32 pictobox:1;
    u32 songSoaring:1;
    u32 maskBunny:1;
    u32 songEpona:1;
    u32 maskRomani:1;
    u32 maskGaro:1;
    u32 maskZora:1;
    u32 maskDonGero:1;
    u32 swordRazor:1;
    u32 swordGilded:1;
    u32 maskGoron:1;
    u32 scrubTown:1;
    u32 scrubSwamp:1;
    u32 scrubMountain:1;
    u32 scrubOcean:1;
    u32 scrubValley:1;
    u32 scrubBombBag:1;
    u32 zoraHallLights:1;
    u32 songGoronIntro:1;
    u32 songGoron:1;
    u32 powderKeg:1;
    u32 maskStone:1;
    u32 songStorms:1;
    u32 songEmptiness:1;
    u32 maskGibdo:1;
    u32 greatFairies:6;
    u32 bankReward2:1;
}
MmExtraFlags;

typedef struct
{
    u32 childWallet:1;
    u32 scrubBeans:1;
    u32 scrubPotionGreen:1;
    u32 maskKafei:1;
    u32 honeyDarling:1;
    u32 roomKey:1;
    u32 letterKafei:1;
    u32 pendant:1;
    u32 letterMama:1;
    u32 notebook:1;
    u32 maskBlast:1;
    u32 dekuPlayground:1;
    u32 maskCouple:1;
    u32 grandma:1;
    u32 maskPostman:1;
    u32 maskTroupeLeader:1;
    u32 maskFierceDeity:1;
    u32 ocarina:1;
    u32 songOath:1;
    u32 progressiveShield:1;
    u32 majora:1;
    u32 maskBremen:1;
    u32 maskScents:1;
    u32 maskKamaro:1;
    u32 maskTruth:1;
    u32 moonTear:1;
    u32 songHealing:1;
    u32 townStrayFairy:1;
    u32 scrubPotionBlue:1;
    u32 gormanMilk:1;
    u32 milkBarMilk:1;
    u32 milkBarChateau:1;
}
MmExtraFlags2;

typedef struct
{
    u32 bottomlessWallet:1;
    u32 unused:31;
}
MmExtraFlags3;

#define MM_PLAYER_FORM_FIERCE_DEITY 0
#define MM_PLAYER_FORM_GORON        1
#define MM_PLAYER_FORM_ZORA         2
#define MM_PLAYER_FORM_DEKU         3
#define MM_PLAYER_FORM_HUMAN        4

typedef struct ALIGNED(16)
{
    u8 xflags[XFLAGS_COUNT_MM];
}
MmCustomSave;

#endif /* MM_SAVE_H */
