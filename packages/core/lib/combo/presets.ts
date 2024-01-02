import { Settings, DEFAULT_SETTINGS, makeSettings } from './settings';

export type Presets = { [k: string]: Settings };

const PRESET_DEFAULT = DEFAULT_SETTINGS;

const PRESET_BLITZ = makeSettings({
  tingleShuffle: 'starting',
  mapCompassShuffle: 'starting',
  smallKeyShuffleMm: 'removed',
  smallKeyShuffleHideout: 'vanilla',
  bossKeyShuffleOot: 'ownDungeon',
  bossKeyShuffleMm: 'ownDungeon',
  strayFairyChestShuffle: 'starting',
  strayFairyOtherShuffle: 'vanilla',
  shuffleMasterSword: false,
  shuffleGerudoCard: false,
  shuffleMerchantsMm: false,
  doorOfTime: 'open',
  dekuTree: 'closed',
  kakarikoGate: 'open',
  gerudoFortress: 'single',
  skipZelda: true,
  bossWarpPads: 'remains',
  crossWarpOot: true,
  crossWarpMm: 'full',
  fastBunnyHood: true,
  blueFireArrows: true,
  startingAge: 'random',
  defaultHoldTarget: true,
  progressiveGoronLullaby: 'single',
  freeScarecrowOot: true,
  sharedBows: true,
  sharedBombBags: true,
  sharedMagic: true,
  sharedMagicArrowFire: true,
  sharedMagicArrowIce: true,
  sharedMagicArrowLight: true,
  sharedSongStorms: true,
  sharedHookshot: true,
  sharedLens: true,
  sharedMaskGoron: true,
  sharedMaskZora: true,
  sharedMaskBunny: true,
  sharedMaskKeaton: true,
  sharedMaskTruth: true,
  sharedWallets: true,
  sharedHealth: true,
  noPlandoHints: true,
  hintImportance: true,
  tricks: [
    'MM_LENS',
    'MM_NO_SEAHORSE',
    'MM_ONE_MASK_STONE_TOWER',
    'MM_PALACE_BEAN_SKIP',
    'OOT_DC_JUMP',
    'OOT_DEAD_HAND_STICKS',
    'OOT_FOREST_HOOK',
    'OOT_HAMMER_WALLS',
    'OOT_HIDDEN_GROTTOS',
    'OOT_LENS',
    'OOT_MAN_ON_ROOF',
    'OOT_NIGHT_GS',
    'OOT_TUNICS',
    'OOT_VOLCANO_HOVERS',
    'OOT_WINDMILL_HP_NOTHING'
  ],
  specialConds: {
    BRIDGE: {
      count: 5,
      stones: true,
      medallions: true
    },
    MOON: {
      count: 4,
      stones: true,
      remains: true
    }
  },
  startingItems: {
    OOT_NUTS_10: 2,
    OOT_SHIELD_DEKU: 1,
    OOT_STICK: 10,
    MM_SONG_EPONA: 1,
    MM_SHIELD_HERO: 1,
    MM_OCARINA: 1,
    OOT_OCARINA: 1,
    MM_SWORD: 1,
    MM_SONG_SOARING: 1
  },
  junkLocations: [
    'MM Deku Playground Reward 2',
    'MM Beneath The Graveyard Dampe Chest',
    'MM Goron Race Reward',
    'MM Great Bay Great Fairy',
    'MM Honey & Darling Reward 2',
    'MM Ikana Great Fairy',
    'MM Laboratory Zora Song',
    'MM Moon Fierce Deity Mask',
    'MM Mountain Village Frog Choir HP',
    'MM Ocean Spider House Wallet',
    'MM Pinnacle Rock HP',
    'MM Snowhead Great Fairy',
    'MM Stock Pot Inn Couple\'s Mask',
    'MM Swamp Spider House Mask of Truth',
    'MM Town Archery Reward 2',
    'MM Waterfall Rapids Beaver Race 2',
    'MM Woodfall Great Fairy',
    'OOT Hyrule Field Ocarina of Time',
    'OOT Kakariko Song Shadow',
    'OOT Skulltula House 40 Tokens',
    'OOT Skulltula House 50 Tokens'
  ],
  plando: {
    locations: {
      'OOT Zora River Bean Seller': 'OOT_MAGIC_BEAN',
      'OOT Zelda\'s Letter': 'OOT_OCARINA',
      'OOT Zelda\'s Song': 'OOT_SONG_TP_LIGHT',
      'MM Initial Song of Healing': 'MM_SONG_TIME'
    }
  },
  hints: [
    { type: 'foolish', amount: 8, extra: 1 },
    { type: 'always', amount: 'max', extra: 1 },
    { type: 'sometimes', amount: 4, extra: 1 },
    { type: 'playthrough', amount: 4, extra: 1 },
    { type: 'woth', amount: 9, extra: 1 },
    { type: 'sometimes', amount: 'max', extra: 1 },
  ]
});

const PRESET_BLITZ_PRECOMPLETED = makeSettings({
  hintImportance: true,
  tingleShuffle: "starting",
  mapCompassShuffle: "starting",
  smallKeyShuffleMm: "removed",
  smallKeyShuffleHideout: "vanilla",
  strayFairyChestShuffle: "starting",
  shuffleMasterSword: false,
  shuffleGerudoCard: false,
  startingAge: "random",
  doorOfTime: "open",
  ageChange: "always",
  dekuTree: "closed",
  kakarikoGate: "open",
  gerudoFortress: "single",
  skipZelda: true,
  bossWarpPads: "remains",
  freeScarecrowOot: true,
  preCompletedDungeons: true,
  preCompletedDungeonsMajor: 6,
  preCompletedDungeonsStones: 2,
  preCompletedDungeonsMedallions: 2,
  preCompletedDungeonsRemains: 2,
  crossWarpOot: true,
  crossWarpMm: "full",
  progressiveGoronLullaby: "single",
  bottleContentShuffle: true,
  blueFireArrows: true,
  sunlightArrows: true,
  shortHookshotMm: true,
  lenientSpikes: false,
  sharedBows: true,
  sharedBombBags: true,
  sharedMagic: true,
  sharedMagicArrowFire: true,
  sharedMagicArrowIce: true,
  sharedMagicArrowLight: true,
  sharedSongStorms: true,
  sharedHookshot: true,
  sharedLens: true,
  sharedMaskGoron: true,
  sharedMaskZora: true,
  sharedMaskBunny: true,
  sharedMaskKeaton: true,
  sharedMaskTruth: true,
  sharedWallets: true,
  sharedHealth: true,
  sharedShields: true,
  startingItems: {
    OOT_NUTS_10: 2,
    OOT_SHIELD_DEKU: 1,
    OOT_STICK: 10,
    MM_SONG_EPONA: 1,
    SHARED_SHIELD_HYLIAN: 1,
    MM_OCARINA: 1,
    OOT_OCARINA: 1,
    MM_SWORD: 1,
    MM_SONG_SOARING: 1
  },
  junkLocations: [
    "MM Beneath The Graveyard Dampe Chest",
    "MM Deku Playground Reward 2",
    "MM Goron Race Reward",
    "MM Great Bay Great Fairy",
    "MM Honey & Darling Reward 2",
    "MM Ikana Great Fairy",
    "MM Laboratory Zora Song",
    "MM Moon Fierce Deity Mask",
    "MM Mountain Village Frog Choir HP",
    "MM Ocean Spider House Wallet",
    "MM Pinnacle Rock HP",
    "MM Snowhead Great Fairy",
    "MM Stock Pot Inn Couple's Mask",
    "MM Swamp Spider House Mask of Truth",
    "MM Town Archery Reward 2",
    "MM Waterfall Rapids Beaver Race 2",
    "MM Woodfall Great Fairy",
    "OOT Skulltula House 40 Tokens",
    "OOT Skulltula House 50 Tokens"
  ],
  tricks: [
    "MM_LENS",
    "MM_NO_SEAHORSE",
    "MM_ONE_MASK_STONE_TOWER",
    "MM_PALACE_BEAN_SKIP",
    "MM_SOUTHERN_SWAMP_SCRUB_HP_GORON",
    "MM_ZORA_HALL_SCRUB_HP_NO_DEKU",
    "OOT_DC_JUMP",
    "OOT_DEAD_HAND_STICKS",
    "OOT_FOREST_HOOK",
    "OOT_HAMMER_WALLS",
    "OOT_HIDDEN_GROTTOS",
    "OOT_LENS",
    "OOT_MAN_ON_ROOF",
    "OOT_NIGHT_GS",
    "OOT_TUNICS",
    "OOT_VOLCANO_HOVERS",
    "OOT_WINDMILL_HP_NOTHING"
  ],
  specialConds: {
    BRIDGE: {
      "count": 9,
      "stones": true,
      "medallions": true,
      "remains": false
    },
    MOON: {
      "count": 7,
      "stones": true,
      "medallions": false,
      "remains": true
    },
    "GANON_BK": {
      "count": 5,
      "stones": true
    },
    MAJORA: {
      "count": 4,
      "stones": true,
      "medallions": false,
      "remains": true
    }
  },
  plando: {
    locations: {
      "OOT Zora River Bean Seller": "OOT_MAGIC_BEAN",
      "OOT Zelda's Letter": "OOT_OCARINA",
      "OOT Zelda's Song": "OOT_SONG_TP_LIGHT",
      "MM Initial Song of Healing": "MM_SONG_TIME"
    }
  },
  hints: [
    { type: "foolish", amount: 8, extra: 1 },
    { type: "always", amount: "max", extra: 1 },
    { type: "sometimes", amount: 4, extra: 1 },
    { type: "item", amount: 1, extra: 1, item: "SHARED_SHIELD_MIRROR" },
    { type: "item", amount: 1, extra: 1, item: "MM_MASK_CAPTAIN" },
    { type: "item", amount: 1, extra: 1, item: "MM_POWDER_KEG" },
    { type: "playthrough", amount: 1, extra: 1 },
    { type: "woth", amount: 9, extra: 1 },
    { type: "sometimes", amount: "max", extra: 1 }
  ]
});

const PRESET_TRIFORCE_BLITZ = makeSettings({
  goal: "triforce3",
  hintImportance: true,
  tingleShuffle: "starting",
  mapCompassShuffle: "starting",
  smallKeyShuffleMm: "removed",
  smallKeyShuffleHideout: "vanilla",
  strayFairyChestShuffle: "starting",
  shuffleMasterSword: false,
  shuffleGerudoCard: false,
  startingAge: "random",
  doorOfTime: "open",
  ageChange: "always",
  dekuTree: "closed",
  kakarikoGate: "open",
  gerudoFortress: "single",
  skipZelda: true,
  bossWarpPads: "remains",
  freeScarecrowOot: true,
  preCompletedDungeons: true,
  preCompletedDungeonsMajor: 6,
  preCompletedDungeonsStones: 2,
  preCompletedDungeonsMedallions: 2,
  preCompletedDungeonsRemains: 2,
  crossWarpOot: true,
  crossWarpMm: "full",
  progressiveGoronLullaby: "single",
  bottleContentShuffle: true,
  blueFireArrows: true,
  sunlightArrows: true,
  shortHookshotMm: true,
  lenientSpikes: false,
  sharedBows: true,
  sharedBombBags: true,
  sharedMagic: true,
  sharedMagicArrowFire: true,
  sharedMagicArrowIce: true,
  sharedMagicArrowLight: true,
  sharedSongStorms: true,
  sharedHookshot: true,
  sharedLens: true,
  sharedMaskGoron: true,
  sharedMaskZora: true,
  sharedMaskBunny: true,
  sharedMaskKeaton: true,
  sharedMaskTruth: true,
  sharedWallets: true,
  sharedHealth: true,
  sharedShields: true,
  startingItems: {
    OOT_NUTS_10: 2,
    OOT_SHIELD_DEKU: 1,
    OOT_STICK: 10,
    MM_SONG_EPONA: 1,
    SHARED_SHIELD_HYLIAN: 1,
    MM_OCARINA: 1,
    OOT_OCARINA: 1,
    MM_SWORD: 1,
    MM_SONG_SOARING: 1
  },
  junkLocations: [
    "MM Beneath The Graveyard Dampe Chest",
    "MM Deku Playground Reward 2",
    "MM Goron Race Reward",
    "MM Great Bay Great Fairy",
    "MM Honey & Darling Reward 2",
    "MM Ikana Great Fairy",
    "MM Laboratory Zora Song",
    "MM Moon Fierce Deity Mask",
    "MM Mountain Village Frog Choir HP",
    "MM Ocean Spider House Wallet",
    "MM Pinnacle Rock HP",
    "MM Snowhead Great Fairy",
    "MM Stock Pot Inn Couple's Mask",
    "MM Swamp Spider House Mask of Truth",
    "MM Town Archery Reward 2",
    "MM Waterfall Rapids Beaver Race 2",
    "MM Woodfall Great Fairy",
    "OOT Skulltula House 40 Tokens",
    "OOT Skulltula House 50 Tokens"
  ],
  tricks: [
    "MM_LENS",
    "MM_NO_SEAHORSE",
    "MM_ONE_MASK_STONE_TOWER",
    "MM_PALACE_BEAN_SKIP",
    "MM_SOUTHERN_SWAMP_SCRUB_HP_GORON",
    "MM_ZORA_HALL_SCRUB_HP_NO_DEKU",
    "OOT_DC_JUMP",
    "OOT_DEAD_HAND_STICKS",
    "OOT_FOREST_HOOK",
    "OOT_HAMMER_WALLS",
    "OOT_HIDDEN_GROTTOS",
    "OOT_LENS",
    "OOT_MAN_ON_ROOF",
    "OOT_NIGHT_GS",
    "OOT_TUNICS",
    "OOT_VOLCANO_HOVERS",
    "OOT_WINDMILL_HP_NOTHING"
  ],
  specialConds: {
    BRIDGE: {
      count: 10,
      stones: true,
      medallions: true,
      remains: true
    },
    MOON: {
      count: 0
    }
  },
  plando: {
    locations: {
      "OOT Zora River Bean Seller": "OOT_MAGIC_BEAN",
      "OOT Zelda's Letter": "OOT_OCARINA",
      "OOT Zelda's Song": "OOT_SONG_TP_LIGHT",
      "MM Initial Song of Healing": "MM_SONG_TIME"
    }
  },
  hints: [
    { type: "foolish", amount: 8, extra: 1 },
    { type: "always", amount: "max", extra: 1 },
    { type: "sometimes", amount: 3, extra: 1 },
    { type: "item", amount: 1, extra: 1, item: "MM_MASK_CAPTAIN" },
    { type: "item", amount: 1, extra: 1, item: "MM_POWDER_KEG" },
    { type: "item", amount: 1, extra: 1, item: "SHARED_SHIELD_MIRROR" },
    { type: "item", amount: 1, extra: 1, item: "SHARED_ARROW_LIGHT" },
    { type: "woth", amount: 9, extra: 1 },
    { type: "sometimes", amount: "max", extra: 1 }
  ]
})

const PRESET_ALLSANITY = makeSettings({
  goal: 'both',
  logic: 'beatable',
  songs: 'anywhere',
  goldSkulltulaTokens: 'all',
  housesSkulltulaTokens: 'all',
  tingleShuffle: 'anywhere',
  mapCompassShuffle: 'anywhere',
  smallKeyShuffleOot: 'anywhere',
  smallKeyShuffleHideout: 'anywhere',
  bossKeyShuffleOot: 'anywhere',
  smallKeyShuffleMm: 'anywhere',
  bossKeyShuffleMm: 'anywhere',
  townFairyShuffle: 'anywhere',
  strayFairyChestShuffle: 'anywhere',
  strayFairyOtherShuffle: 'anywhere',
  ganonBossKey: 'anywhere',
  dungeonRewardShuffle: 'anywhere',
  scrubShuffleOot: true,
  cowShuffleOot: true,
  cowShuffleMm: true,
  shopShuffleOot: 'full',
  shopShuffleMm: 'full',
  shuffleMasterSword: true,
  shuffleGerudoCard: true,
  eggShuffle: true,
  doorOfTime: 'closed',
  kakarikoGate: 'closed',
  zoraKing: 'vanilla',
  skipZelda: false,
  crossWarpOot: true,
  crossWarpMm: 'full',
  sunSongMm: true,
  csmc: 'always',
  fillWallets: true,
  progressiveShieldsOot: 'separate',
  progressiveSwordsOot: 'separate',
  progressiveShieldsMm: 'separate',
  progressiveGoronLullaby: 'single',
  childWallets: true,
  colossalWallets: true,
  fastBunnyHood: true,
  dekuTree: 'closed',
  dekuTreeAdult: true,
  wellAdult: true,
  fireChild: true,
  erBoss: 'full',
  erDungeons: 'full',
  erMajorDungeons: true,
  erMinorDungeons: true,
  erSpiderHouses: true,
  erPirateFortress: true,
  erBeneathWell: true,
  erIkanaCastle: true,
  erSecretShrine: true,
  erRegions: 'full',
  erRegionsExtra: true,
  erRegionsShortcuts: true,
  erIndoors: 'full',
  erIndoorsMajor: true,
  erIndoorsExtra: true,
  erOneWays: 'full',
  erOneWaysMajor: true,
  erOneWaysIkana: true,
  erOneWaysSongs: true,
  erOneWaysStatues: true,
  erOneWaysOwls: true,
});

const PRESET_HELL = makeSettings({
  itemPool: 'minimal',
  goal: 'both',
  logic: 'beatable',
  songs: 'anywhere',
  goldSkulltulaTokens: 'all',
  housesSkulltulaTokens: 'all',
  tingleShuffle: 'anywhere',
  mapCompassShuffle: 'anywhere',
  smallKeyShuffleOot: 'anywhere',
  smallKeyShuffleMm: 'anywhere',
  smallKeyShuffleHideout: 'anywhere',
  bossKeyShuffleOot: 'anywhere',
  bossKeyShuffleMm: 'anywhere',
  townFairyShuffle: 'anywhere',
  strayFairyChestShuffle: 'anywhere',
  strayFairyOtherShuffle: 'anywhere',
  ganonBossKey: 'custom',
  majoraChild: 'custom',
  dungeonRewardShuffle: 'anywhere',
  scrubShuffleOot: true,
  cowShuffleOot: true,
  cowShuffleMm: true,
  shopShuffleOot: 'full',
  shopShuffleMm: 'full',
  shuffleMasterSword: true,
  shuffleGerudoCard: true,
  eggShuffle: true,
  doorOfTime: 'closed',
  kakarikoGate: 'closed',
  zoraKing: 'vanilla',
  skipZelda: false,
  crossWarpOot: true,
  crossWarpMm: 'full',
  sunSongMm: true,
  csmc: 'always',
  fillWallets: false,
  priceOotShops: 'random',
  priceOotScrubs: 'random',
  priceMmShops: 'random',
  priceMmTingle: 'random',
  progressiveShieldsOot: 'separate',
  progressiveSwordsOot: 'separate',
  progressiveShieldsMm: 'separate',
  progressiveGoronLullaby: 'progressive',
  childWallets: true,
  colossalWallets: true,
  fastBunnyHood: true,
  dekuTree: 'closed',
  dekuTreeAdult: true,
  wellAdult: true,
  fireChild: true,
  erBoss: 'full',
  erDungeons: 'full',
  erMajorDungeons: true,
  erMinorDungeons: true,
  erSpiderHouses: true,
  erPirateFortress: true,
  erBeneathWell: true,
  erIkanaCastle: true,
  erSecretShrine: true,
  erRegions: 'full',
  erRegionsExtra: true,
  erRegionsShortcuts: true,
  erIndoors: 'full',
  erIndoorsMajor: true,
  erIndoorsExtra: true,
  erOneWays: 'full',
  erOneWaysMajor: true,
  erOneWaysIkana: true,
  erOneWaysSongs: true,
  erOneWaysStatues: true,
  erOneWaysOwls: true,
  erGanonCastle: true,
  erGanonTower: true,
  erMoon: true,
  specialConds: {
    GANON_BK: {
      count: 266,
      stones: true,
      medallions: true,
      remains: true,
      skullsGold: true,
      skullsSwamp: true,
      skullsOcean: true,
      fairiesWF: true,
      fairiesSH: true,
      fairiesGB: true,
      fairiesST: true,
      fairyTown: true,
      masksRegular: true,
      masksTransform: true,
      masksOot: true
    },
    MAJORA: {
      count: 266,
      stones: true,
      medallions: true,
      remains: true,
      skullsGold: true,
      skullsSwamp: true,
      skullsOcean: true,
      fairiesWF: true,
      fairiesSH: true,
      fairiesGB: true,
      fairiesST: true,
      fairyTown: true,
      masksRegular: true,
      masksTransform: true,
      masksOot: true
    }
  },
  dungeon: {
    DT: 'mq',
    DC: 'mq',
    JJ: 'mq',
    BotW: 'mq',
    Forest: 'mq',
    Fire: 'mq',
    Water: 'mq',
    Shadow: 'mq',
    Spirit: 'mq',
    IC: 'mq',
    GTG: 'mq',
    Ganon: 'mq'
  },
  hints: [
    { type: 'foolish', amount: 'max', extra: 2 },
  ],
  tricks: [
    'OOT_LENS',
    'OOT_TUNICS',
    'OOT_HIDDEN_GROTTOS',
    'OOT_MIDO_SKIP',
    'OOT_MAN_ON_ROOF',
    'OOT_BLIND_WASTELAND',
    'OOT_DEKU_SKIP',
    'OOT_DC_JUMP',
    'OOT_FOREST_HOOK',
    'OOT_HAMMER_WALLS',
    'OOT_VOLCANO_HOVERS',
    'OOT_NIGHT_GS',
    'OOT_DOMAIN_CUCCO',
    'OOT_DOMAIN_HOVER',
    'OOT_WATER_LONGSHOT',
    'OOT_SAND_RIVER_NOTHING',
    'OOT_SHADOW_FIRE_ARROW',
    'OOT_KZ_SKIP',
    'OOT_LOST_WOODS_ADULT_GS',
    'OOT_WINDMILL_HP_NOTHING',
    'OOT_LAB_DIVE_NO_GOLD_SCALE',
    'OOT_LAB_WALL_GS',
    'OOT_PASS_COLLISION',
    'OOT_DMT_RED_ROCK_GS',
    'OOT_DEAD_HAND_STICKS',
    'OOT_BFA_MUDWALLS',
    'OOT_JABU_BOSS_HOVER',
    'OOT_SPIRIT_CHILD_HOVER',
    'OOT_VALLEY_GATE_HOVER',
    'OOT_MQ_ICE_SCARE_NOTHING',
    'OOT_MQ_ICE_SCARE_HOVER',
    'OOT_MQ_GTG_FLAMES',
    'OOT_FORTRESS_JUMPS',
    'OOT_COLOSSUS_GS_NO_BEAN',
    'OOT_ENTER_JABU',
    'OOT_JABU_BOSS_HIGH_SWITCH',
    'OOT_WATER_REVERSE_RIVER',
    'OOT_WATER_PIT_GS_CHU',
    'OOT_SHADOW_BOAT_EARLY',
    'OOT_SPIRIT_BOSS_CLIMB_NO_HOOK',
    'OOT_DC_BOULDER',
    'OOT_LAKE_SHORTCUT',
    'OOT_TENT_CHILD',
    'OOT_WELL_ADULT_TT',
    'OOT_ADULT_GALLERY_TT',
    'OOT_GTG_CHILD_TT',
    'OOT_REVERSE_DAMPE',
    'OOT_GANON_FAIRY_TT',
    'MM_LENS',
    'MM_PALACE_BEAN_SKIP',
    'MM_DARMANI_WALL',
    'MM_NO_SEAHORSE',
    'MM_ZORA_HALL_HUMAN',
    'MM_ICELESS_IKANA',
    'MM_ONE_MASK_STONE_TOWER',
    'MM_ISTT_EYEGORE',
    'MM_SCT_NOTHING',
    'MM_GORON_BOMB_JUMP',
    'MM_BOMBER_SKIP',
    'MM_CAPTAIN_SKIP',
    'MM_ISTT_ENTRY_JUMP',
    'MM_HARD_HOOKSHOT',
    'MM_PFI_BOAT_HOOK',
    'MM_PALACE_GUARD_SKIP',
    'MM_SHT_FIRELESS',
    'MM_SHT_STICKS_RUN',
    'MM_SHT_PILLARLESS',
    'MM_KEG_EXPLOSIVES',
    'MM_DOG_RACE_CHEST_NOTHING',
    'MM_MAJORA_LOGIC',
    'MM_SOUTHERN_SWAMP_SCRUB_HP_GORON',
    'MM_ZORA_HALL_SCRUB_HP_NO_DEKU',
    'MM_IKANA_ROOF_PARKOUR',
    'MM_POST_OFFICE_GAME',
    'MM_WELL_HSW',
    'MM_GBT_WATERWHEEL_GORON',
    'MM_GBT_ENTRANCE_BOW',
    'MM_OOB_MOVEMENT',
    'MM_ST_UPDRAFTS',
    'MM_ESCAPE_CAGE',
    'MM_GBT_FAIRY2_HOOK',
    'MM_GBT_CENTRAL_GEYSER',
    'MM_BANK_NO_WALLET',
    'MM_CLOCK_TOWER_WAIT',
  ]
});

export const PRESETS: Presets = {
  'Default': PRESET_DEFAULT,
  'Blitz': PRESET_BLITZ,
  'Blitz (with pre-completed dungeons)': PRESET_BLITZ_PRECOMPLETED,
  'Triforce Blitz': PRESET_TRIFORCE_BLITZ,
  'Allsanity': PRESET_ALLSANITY,
  'Hell': PRESET_HELL,
};
