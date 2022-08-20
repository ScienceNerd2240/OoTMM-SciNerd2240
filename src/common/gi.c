#include <combo.h>

const GetItem kExtendedGetItems[] = {
#define X(a, b, c, d, e)    {a, b, Y(c), 8, Z(e)}
#define Y(x)                x
#define Z(x)                x

#if defined(GAME_OOT)
# include "data/oot/gi.inc"
#else
# include "data/mm/gi.inc"
#endif
# undef Y
# undef Z
# define Y(x)               ((x) | 0x80)
# define Z(x)               ((x) | 0x1000)
#if defined(GAME_OOT)
# include "data/mm/gi.inc"
#else
# include "data/oot/gi.inc"
#endif

#undef X
#undef Y
#undef Z
};
