/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: fontcvt.cxx,v $
 * $Revision: 1.24 $
 *
 * This file is part of OpenOffice.org.
 *
 * OpenOffice.org is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3
 * only, as published by the Free Software Foundation.
 *
 * OpenOffice.org is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3 along with OpenOffice.org.  If not, see
 * <http://www.openoffice.org/license.html>
 * for a copy of the LGPLv3 License.
 *
 ************************************************************************/
#ifdef AVS
// MARKER(update_precomp.py): autogen include statement, do not remove
#include "precompiled_vcl.hxx"
#include <vcl/fontcvt.hxx>
#include <vcl/outdev.h>

#ifndef _STLP_MAP
#include <map>
#endif
#ifndef _STLP_VECTOR
#include <vector>
#endif
#ifndef _STLP_ALGORITHM
#include <algorithm>
#endif
#ifndef _STLP_FUNCTIONAL
#include <functional>
#endif
#endif

#include "vcl/fontcvt.hxx"
#include "AvsOutputDevice.h"

using namespace SVMCore;
#ifdef AVS
//=======================================================================
// note: the character mappings that are only approximations
//       are marked (with an empty comment)

static const sal_Unicode aStarBatsTab[224] =
{
    // F020
        0x0020,    0x263a,    0x25cf,    0x274d,
        0x25a0,    0x25a1,    0xE000,    0x2751,
        0x2752,    0xE001,    0xE002,    0xE003,
        0x2756,    0xE004,    0xE005,    0x27a2,
    // F030
        0xE006,    0x2794,    0x2713,    0x2612,
        0x2611,    0x27b2,    0x261b,    0x270d,
        0x270e,    0xE007,    0x2714,    0xE008,
        0xE009,    0xE00A,    0x274f,    0x2750,
    // F040
        0xE00B,    0xE00C,    0xE00D,    0xE00E,
        0x2722,    0x2723,    0x2724,    0x2725,
        0x2733,    0x2734,    0x2735,    0x2736,
        0x2737,    0x2738,    0x2739,    0x2717,
    // F050
        0x2718,    0x2719,    0x271a,    0x271b,
        0x271c,    0x272b,    0x272c,    0x272d,
        0x272e,    0x272f,    0x2730,         0,
        0xE00F,    0x278a,    0x278b,    0x278c,
    // F060
        0x278d,    0x278e,    0x278f,    0x2790,
        0x2791,    0x2792,    0x2793,    0xE010,
        0x2780,    0x2781,    0x2782,    0x2783,
        0x2784,    0x2785,    0x2786,    0x2787,
    // F070
        0x2788,    0x2789,    0xE011,    0xE012,
        0x260e,    0xE013,    0xE014,    0xE015,
        0xE016,    0xE017,    0xE018,    0xE019,
        0xE01A,    0x261e,    0xE01B,         0,
    // F080
        0x20ac,         0,    0x201a,    0x0192,
        0x201e,    0x2026,    0x2020,    0x2021,
        0xE01c,    0x2030,    0x0160,    0x2039,
        0x0152,         0,    0x017d,         0,
    // F090
             0,    0x2018,    0x2019,    0x201c,
        0x201d,    0x2022,    0x2013,    0x2014,
        0xE01d,    0x2122,    0x0161,    0x203a,
        0x0153,         0,    0x017e,    0x0178,
    // F0A0
             0,    0x21e7,    0x21e8,    0x21e9,
        0x21e6,    0xE01e,    0xE01f,    0x00a7,
        0xE020,    0xE021,    0xE022,    0x00ab,
        0xE023,    0x2639,    0xE024,    0xE025,
    // F0B0
        0xE026,    0xE027,    0xE028,    0x21e5,
        0x21e4,    0x2192,    0x2193,    0x2190,
        0x2191,    0xE029,    0xE02a,    0x00bb,
        0xE02b,    0xE02c,    0xE02d,    0xE02e,
    // F0C0
        0xE02f,    0xE030,    0xE031,    0xE032,
        0x25be,    0x25b4,    0x25bf,    0x25b5,
        0xE033,    0xE034,    0xE035,    0x2702,
        0x2708,    0x2721,    0x273f,    0x2744,
    // F0D0
        0x25d7,    0x2759,    0xE036,    0xE037,
        0x2762,    0x2663,    0x2665,    0x2660,
        0x2194,    0x2195,    0x2798,    0x279a,
        0x27b8,         0,    0x00b6,         0,
    // F0E0
        0x00a2,    0x00a4,    0x00a5,    0xE038,
        0x20a1,    0x20a2,    0x20a3,    0x20a4,
        0x20a9,    0x20ab,    0x20a8,    0xE039,
             0,         0,         0,         0,
    // F0F0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,    0xE03a
};

// -----------------------------------------------------------------------

static const sal_Unicode aStarMathTab[224] =
{
    // F020
        0x0020,    0x0021,    0x0022,    0x0023,
        0xE080,    0x0025,    0x0026,    0x221e,
        0x0028,    0x0029,    0x002a,    0x002b,
        0x002c,    0x002d,    0x002e,    0x002f,
    // F030
        0x2224,    0x21d2,    0x21d0,    0x21d4,
        0xE081,    0xE082,    0x00b0,         0,
             0,         0,    0x003a,    0x003b,
        0x003c,    0x003d,    0x003e,    0x00bf,
    // F040
        0x2260,    0xE083,    0x2212,    0x2217,
        0x00d7,    0x22c5,    0x00f7,    0x00b1,
        0x2213,    0x2295,    0x2296,    0x2297,
        0x2298,    0x2299,    0x222a,    0x2229,
    // F050
        0xE084,    0xE085,    0x2264,    0x2265,
        0xE086,    0xE087,    0x226a,    0x226b,
        0x007e,    0x2243,    0x2248,    0x225d,
        0x2261,    0x221d,    0x2202,    0x2282,
    // F060
        0x2283,    0x2286,    0x2287,    0x2284,
        0x2285,    0x2288,    0x2289,    0x2208,
        0x2209,    0xE089,    0x2203,    0x220d,
        0x2135,    0x2111,    0x211c,    0x2118,
    // F070
        0xE08a,    0x2221,    0x2222,    0x2223,
        0x2225,    0x22a5,    0xE08b,    0x22ef,
        0x22ee,    0x22f0,    0x22f1,    0x22b6,
        0x22b7,    0xE08c,    0x2216,    0x00ac,
    // F080
        0x222b,    0x222c,    0x222d,    0x222e,
        0x222f,    0x2230,    0x221a,    0xE08d,
        0xE08e,    0xE08f,    0x2210,    0x220f,
        0x2211,    0x2207,    0x2200,    0xE090,
    // F090
        0xE091,    0xE092,    0xE093,    0xE094,
        0xE095,    0xE096,    0xE097,    0xE098,
        0x02d9,    0x00a8,    0xE09b,    0x02da,
        0x2227,    0x2228,    0x220b,    0x2205,
    // F0A0
        0x007b,    0x007d,    0xe09e,    0xe09f,
        0x2329,    0x232a,    0x005b,    0x005d,
        0xE0a0,    0x22be,    0xE0a1,    0x2259,
        0x2254,    0x2255,    0x21b3,    0x2197,
    // F0B0
        0x2198,    0x2245,    0x301a,    0x301b,
        0x2373,    0xE0a5,    0xE0a6,    0x22a4,
        0x2112,    0x2130,    0x2131,         0,
        0xE0a7,    0xE0a8,    0xE0a9,    0xE0aa,
    // F0C0
        0x2308,    0x230a,    0x2309,    0x230b,
             0,    0xe0ab,    0xe0ac,    0xe0ad,
        0xe0ae,    0xe0af,    0xe0b0,    0xe0b1,
        0xe0b2,    0xe0b3,    0xe0b4,    0xe0b5,
    // F0D0
        0xe0b6,    0xe0b7,    0xe0b8,    0xe0b9,
        0xe0ba,    0xe0bb,    0xe0bc,    0xe0bd,
        0xe0be,    0xe0bf,    0xe0c0,    0xe0c1,
        0xe0c2,    0xe0c3,    0xe0c4,    0xe0c5,
    // F0E0
        0xe0c6,    0xe0c7,    0xe0c8,    0xe0c9,
        0xe0ca,    0xe0cb,    0xe0cc,    0xe0cd,
        0xe0ce,    0xe0cf,    0xe0d0,    0xe0d1,
        0x03f1,    0xe0d3,    0xe0d4,    0xe0d5,
    // F0F0
        0x2113,     0xe0d6,   0x2107,    0x2127,
        0x210a,     0xe0d9,   0x210f,    0x019b,
        0xe0db,     0xe0dc,   0xe0dd,    0x2115,
        0x2124,     0x211a,   0x211d,    0x2102
};

// -----------------------------------------------------------------------

static const sal_Unicode aWingDingsTab[224] =
{
    // F020
        0x0020,    0xe400,    0xe401,    0xe402,
        0xe403,    0xe404,    0xe405,    0xe406,
        0xe407,    0xe408,    0xe409,    0xe40a,
        0xe40b,    0xe40c,    0xe40d,    0xe40e,
    // F030
        0xe40f,    0xe410,    0xe411,    0xe412,
        0xe413,    0xe414,    0xe415,    0xe416,
        0xe417,    0xe418,    0xe419,    0xe41a,
        0xe41b,    0xe41c,    0x2707,    0xe41d,
    // F040
        0xe41e,    0xe41f,    0xe420,    0xe421,
        0x261c,    0xe423,    0x261d,    0x261f,
        0x261f,    0xe424,    0xe425,    0xe426,
        0xe427,    0xe428,    0xe429,    0xe42a,
    // F050
        0xe42b,    0xe42c,    0x263c,    0xe42d,
        0xe42e,    0xe42f,    0xe430,    0xe431,
        0xe432,    0xe433,    0x262a,    0x262f,
        0x0950,    0xe434,    0x2648,    0x2649,
    // F060
        0x264a,    0x264b,    0x264c,    0x264d,
        0x264e,    0x264f,    0x2650,    0x2651,
        0x2652,    0x2653,    0xe435,    0xe436,
        0xe437,    0xe438,    0xe439,    0xe43a,
    // F070
        0xe43b,    0xe43c,    0xe43d,    0xe43e,
        0xe43f,    0xe440,    0xe441,    0xe442,
        0xe443,    0x2353,    0x2318,    0xe444,
        0xe445,    0xe446,    0xe447,         0,
    // F080
        0xe448,    0xe449,    0xe44a,    0xe44b,
        0xe44c,    0xe44d,    0xe44e,    0xe44f,
        0xe450,    0xe451,    0xe452,    0xe453,
        0xe454,    0xe455,    0xe456,    0xe457,
    // F090
        0xe458,    0xe459,    0xe45a,    0xe45b,
        0xe45c,    0xe45d,    0xe45e,    0xe45f,
        0xe460,    0xe461,    0xe462,    0xe463,
        0xe464,    0xe465,    0xe466,    0xe467,
    // F0a0
        0xe468,    0xe469,    0xe46a,    0xe46b,
        0xe46c,    0xe46d,    0xe46e,    0xe46f,
        0xe470,    0xe471,    0xe472,    0xe473,
        0xe474,    0xe475,    0xe476,    0xe477,
    // F0b0
        0xe478,    0xe479,    0xe47a,    0xe47b,
        0xe47c,    0xe47d,    0xe47e,    0xe47f,
        0xe480,    0xe481,    0xe482,    0xe483,
        0xe484,    0xe485,    0xe486,    0xe487,
    // F0c0
        0xe488,    0xe489,    0xe48a,    0xe48b,
        0xe48c,    0xe48d,    0xe48e,    0xe48f,
        0xe490,    0xe491,    0xe492,    0xe493,
        0xe494,    0xe495,    0xe496,    0xe497,
    // F0d0
        0xe498,    0xe499,    0xe49a,    0xe49b,
        0xe49c,    0x232b,    0x2326,    0xe49d,
        0xe49e,    0xe49f,    0xe4a0,    0xe4a1,
        0xe4a2,    0xe4a3,    0xe4a4,    0xe4a5,
    // F0e0
        0xe4a6,    0xe4a7,    0xe4a8,    0xe4a9,
        0xe4aa,    0xe4ab,    0xe4ac,    0xe4ad,
        0xe4ae,    0xe4af,    0xe4b0,    0xe4b1,
        0xe4b2,    0xe4b3,    0xe4b4,    0xe4b5,
    // F0f0
        0xe4b6,    0xe4b7,    0xe4b8,    0xe4b9,
        0xe4ba,    0xe4bb,    0xe4bc,    0xe4bd,
        0xe4be,    0xe4bf,    0xe4c0,    0xe4c1,
        0xe4c2,    0xe4c3,    0xe4c4,    0xe4c5
};

// -----------------------------------------------------------------------

static const sal_Unicode aWingDings2Tab[224] =
{
    // F020
        0x0020,    0xe500,    0xe501,    0xe502,
        0xe503,    0xe504,    0xe505,    0xe506,
        0xe507,    0xe508,    0xe509,    0xe50a,
        0xe50b,    0xe50c,    0xe50d,    0xe50e,
    // F030
        0xe50f,    0xe510,    0xe511,    0xe512,
        0xe513,    0xe514,    0xe515,    0xe516,
        0xe517,    0xe518,    0xe519,    0xe51a,
        0xe51b,    0xe51c,    0xe51d,    0xe51e,
    // F040
        0xe51f,    0xe520,    0xe521,    0xe522,
        0xe523,    0xe524,    0xe525,    0xe526,
        0xe527,    0xe528,    0xe529,    0xe52a,
        0xe52b,    0xe52c,    0xe52d,    0xe52e,
    // F050
        0xe52f,    0xe530,    0xe531,    0xe532,
        0xe533,    0xe534,    0xe535,    0xe536,
        0xe537,    0xe538,    0xe539,    0xe53a,
        0xe53b,    0xe53c,    0xe53d,    0xe53e,
    // F060
        0xe53f,    0xe540,    0xe541,    0xe542,
        0xe543,    0xe544,    0xe545,    0xe546,
        0xe547,    0xe548,    0xe549,    0xe54a,
        0xe54b,    0xe54c,    0xe54d,    0xe54e,
    // F070
        0xe54e,    0xe54f,    0xe550,    0xe551,
        0xe552,    0xe553,    0xe554,    0xe555,
        0xe556,    0xe557,    0xe558,    0xe559,
        0xe55a,    0xe55b,    0xe55c,         0,
    // F080
        0x2609,    0x25cb,    0x263d,    0x263e,
        0xe55d,    0xe55e,    0xe55f,    0xe560,
        0xe561,    0xe562,    0xe563,    0xe564,
        0xe565,    0xe566,    0xe567,    0xe568,
    // F090
        0xe569,    0xe56a,    0xe56b,    0xe56c,
        0xe56d,    0xe56e,    0xe56f,    0xe570,
        0xe571,    0xe572,    0xe573,    0xe574,
        0xe575,    0xe576,    0xe577,    0xe578,
    // F0a0
        0xe579,    0xe57a,    0xe57b,    0xe57c,
        0xe57d,    0xe57e,    0xe57f,    0xe580,
        0xe581,    0xe582,    0xe583,    0xe584,
        0xe585,    0xe586,    0xe587,    0xe588,
    // F0b0
        0xe589,    0xe58a,    0xe58b,    0xe58c,
        0xe58d,    0xe58e,    0xe58f,    0xe590,
        0xe591,    0xe592,    0xe593,    0xe594,
        0xe595,    0xe596,    0xe597,    0xe598,
    // F0c0
        0xe599,    0xe59a,    0xe59b,    0xe59c,
        0xe59d,    0xe59e,    0xe59f,    0xe5a0,
        0xe5a1,    0xe5a2,    0xe5a3,    0xe5a4,
        0xe5a5,    0xe5a6,    0xe5a7,    0xe5a8,
    // F0d0
        0xe5a9,    0xe5aa,    0xe5ab,    0xe5ac,
        0xe5ad,    0xe5ae,    0xe5af,    0xe5b0,
        0xe5b1,    0xe5b2,    0xe5b3,    0xe5b4,
        0xe5b5,    0xe5b6,    0xe5b7,    0xe5b8,
    // F0e0
        0xe5b9,    0xe5ba,    0xe5bb,    0xe5bc,
        0xe5bd,    0xe5be,    0xe5bf,    0xe5c0,
        0xe5c1,    0xe5c2,    0xe5c3,    0xe5c4,
        0xe5c5,    0xe5c6,    0xe5c7,    0xe5c8,
    // F0f0
        0xe5c9,    0xe5ca,    0xe5cb,    0xe5cc,
        0xe5cd,    0xe5ce,    0xe5cf,    0xe5d0,
        0x203b,    0x2042,         0,         0,
             0,         0,         0,         0
};

// -----------------------------------------------------------------------

static const sal_Unicode aWingDings3Tab[224] =
{
    // F020
        0x0020,    0xe600,    0xe601,    0xe602,
        0xe603,    0x2196,    0xe604,    0x2199,
        0xe605,    0xe606,    0xe607,    0xe608,
        0xe609,    0xe60a,    0xe60b,    0x21de,
    // F030
        0x21df,    0xe60c,    0xe60d,    0xe60e,
        0x21e2,    0x21e1,    0x21e3,    0x21af,
        0x21b5,    0xe60f,    0xe610,    0xe611,
        0xe612,    0xe613,    0xe614,    0xe615,
    // F040
        0xe616,    0xe617,    0xe618,    0xe619,
        0x21c4,    0x21c5,    0xe61a,    0xe61b,
        0x21c7,    0x21c9,    0x21c8,    0x21ca,
        0x21b6,    0x21b7,    0xe61c,    0xe61d,
    // F050
        0x21bb,    0x21ba,    0xe61e,    0x2324,
        0x2303,    0x2325,    0x2334,    0xe61f,
        0x21ea,    0xe620,    0xe621,    0xe622,
        0xe623,    0xe624,    0xe625,    0xe626,
    // F060
        0xe627,    0xe628,    0xe629,    0xe62a,
        0xe62b,    0xe62c,    0xe62d,    0xe62e,
        0xe62f,    0xe630,    0xe631,    0xe632,
        0xe633,    0xe634,    0xe635,    0xe636,
    // F070
        0xe637,    0xe638,    0x25b3,    0x25bd,
        0x25c0,    0x25b6,    0x25c1,    0x25b7,
        0x25e3,    0xe639,    0x25e4,    0x25e5,
        0x25c2,    0x25b8,    0xe63a,         0,
    // F080
        0xe63b,    0xe63c,    0xe63d,    0xe63e,
        0xe63f,    0xe640,    0xe641,    0xe642,
        0xe643,    0xe644,    0xe645,    0xe646,
        0xe647,    0xe648,    0xe649,    0xe64a,
    // F090
        0xe64b,    0xe64c,    0xe64d,    0xe64e,
        0xe64f,    0xe650,    0xe651,    0xe652,
        0xe653,    0xe654,    0xe655,    0xe656,
        0xe657,    0xe658,    0xe659,    0xe65a,
    // F0a0
        0xe65b,    0xe65c,    0xe65d,    0xe65e,
        0xe65f,    0xe660,    0xe661,    0xe662,
        0xe663,    0xe664,    0xe665,    0xe666,
        0xe667,    0xe668,    0xe669,    0xe66a,
    // F0b0
        0xe66b,    0xe66c,    0xe66d,    0xe66e,
        0xe66f,    0xe670,    0xe671,    0xe672,
        0xe673,    0xe674,    0xe675,    0xe676,
        0xe677,    0xe678,    0xe679,    0xe67a,
    // F0c0
        0xe67b,    0xe67c,    0xe67d,    0xe67e,
        0xe67f,    0xe680,    0xe681,    0xe682,
        0xe683,    0xe684,    0xe685,    0xe686,
        0xe687,    0xe688,    0xe689,    0xe68a,
    // F0d0
        0xe68b,    0xe68c,    0xe68d,    0xe68e,
        0xe68f,    0xe690,    0xe691,    0xe692,
        0xe693,    0xe694,    0xe695,    0xe696,
        0xe697,    0xe698,    0xe699,    0xe69a,
    // F0e0
        0xe69b,    0xe69c,    0xe69d,    0xe69e,
        0xe69f,    0xe6a0,    0xe6a1,    0xe6a2,
        0xe6a3,    0xe6a4,    0xe6a5,    0xe6a6,
        0xe6a7,    0xe6a8,    0xe6a9,    0xe6aa,
    // F0f0
        0xe6ab,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0
};

// -----------------------------------------------------------------------

static const sal_Unicode aWebDingsTab[224] =
{
    // F020
        0x0020,    0xe300,    0xe301,    0xe302,
        0xe303,    0xe304,    0xe305,    0xe306,
        0xe307,    0xe308,    0xe309,    0xe30a,
        0xe30b,    0xe30c,    0xe30d,    0xe30e,
    // F030
        0xe30f,    0xe310,    0xe311,    0xe312,
        0xe313,    0xe314,    0xe315,    0xe316,
        0xe317,    0xe318,    0xe319,    0xe31a,
        0xe31b,    0xe31c,    0xe31d,    0xe31e,
    // F040
        0xe31f,    0xe320,    0xe321,    0xe322,
        0xe323,    0xe324,    0xe325,    0xe326,
        0xe327,    0xe328,    0xe329,    0xe32a,
        0xe32b,    0xe32c,    0xe32d,    0xe32e,
    // F050
        0xe32f,    0xe330,    0xe331,    0xe332,
        0xe333,    0xe334,    0xe335,    0xe336,
        0xe337,    0xe338,    0xe339,    0xe33a,
        0xe33b,    0xe33c,    0xe33d,    0xe33e,
    // F060
        0xe33f,    0xe340,    0xe341,    0xe342,
        0xe343,    0xe344,    0xe345,    0xe346,
        0xe347,    0xe348,    0xe349,    0xe34a,
        0xe34b,    0xe34c,    0xe34d,    0xe34e,
    // F070
        0xe34f,    0xe350,    0xe351,    0xe352,
        0xe353,    0xe354,    0xe355,    0xe356,
        0xe357,    0xe358,    0xe359,    0xe35a,
        0xe35b,    0xe35c,    0xe35d,         0,
    // F080
        0xe35e,    0xe35f,    0xe360,    0xe361,
        0xe362,    0xe363,    0xe364,    0xe365,
        0xe366,    0xe367,    0xe368,    0xe369,
        0xe36a,    0xe36b,    0xe36c,    0xe36d,
    // F090
        0xe36e,    0xe36f,    0xe370,    0xe371,
        0xe372,    0xe373,    0xe374,    0xe375,
        0xe376,    0xe377,    0xe378,    0xe379,
        0xe37a,    0xe37b,    0xe37c,    0xe37d,
    // F0a0
        0xe37e,    0xe37f,    0xe380,    0xe381,
        0xe382,    0xe383,    0xe384,    0xe385,
        0xe386,    0xe387,    0xe388,    0xe389,
        0xe38a,    0xe38b,    0xe38c,    0xe38d,
    // F0b0
        0xe38e,    0xe38f,    0xe390,    0xe391,
        0xe392,    0xe393,    0xe394,    0xe395,
        0xe396,    0xe397,    0xe398,    0xe399,
        0xe39a,    0xe39b,    0xe39c,    0xe39d,
    // F0c0
        0xe39e,    0xe39f,    0xe3a0,    0xe3a1,
        0xe3a2,    0xe3a3,    0xe3a4,    0xe3a5,
        0xe3a6,    0xe3a7,    0xe3a8,    0xe3a9,
        0xe3aa,    0xe3ab,    0xe3ac,    0xe3ad,
    // F0d0
        0xe3ae,    0xe3af,    0xe3b0,    0xe3b1,
        0xe3b2,    0xe3b3,    0xe3b4,    0xe3b5,
        0xe3b6,    0xe3b7,    0xe3b8,    0xe3b9,
        0xe3ba,    0xe3bb,    0xe3bc,    0xe3bd,
    // F0e0
        0xe3be,    0xe3bf,    0xe3c0,    0xe3c1,
        0xe3c2,    0xe3c3,    0xe3c4,    0xe3c5,
        0xe3c6,    0xe3c7,    0xe3c8,    0xe3c9,
        0xe3ca,    0xe3cb,    0xe3cd,    0xe3ce,
    // F0f0
        0xe3cf,    0xe3d0,    0xe3d1,    0xe3d2,
        0xe3d3,    0xe3d4,    0xe3d5,    0xe3d6,
        0xe3d7,    0xe3d8,    0xe3d9,    0xe3da,
        0xe3db,    0xe3dc,    0xe3dd,    0xe3de
};

// -----------------------------------------------------------------------

static const sal_Unicode aAdobeSymbolTab[224] =
{
//TODO:
    // F020
        0x0020,    0xe100,    0xe101,    0xe102,
        0xe103,    0xe104,    0xe16a,    0xe105,
        0xe106,    0xe107,    0xe108,    0xe109,
        0xe10a,    0xe10b,    0xe10c,    0xe10d,
    // F030
        0x0030,    0x0031,    0x0032,    0x0033,
        0x0034,    0x0035,    0x0036,    0x0037,
        0x0038,    0x0039,    0xe10e,    0xe10f,
        0xe110,    0xe111,    0xe112,    0x003f,
    // F040
        0xe113,    0x0391,    0x0392,    0x03a7,
        0x0394,    0x0395,    0x03a6,    0x0393,
        0x0397,    0x0399,    0x03d1,    0x039a,
        0x039b,    0x039c,    0x039d,    0x039f,
    // F050
        0x03a0,    0x0398,    0x03a1,    0x03a3,
        0x03a4,    0x03a5,    0x03c2,    0x03a9,
        0x039e,    0x03a8,    0x0396,    0xe114,
        0x2234,    0xe115,    0xe116,    0x005f,
    // F060
        0x00af,    0x03b1,    0x03b2,    0x03c7,
        0x03b4,    0x03b5,    0x03d5,    0x03b3,
        0x03b7,    0x03b9,    0x03c6,    0x03ba,
        0x03bb,    0x03bc,    0x03bd,    0x03bf,
    // F070
        0x03c0,    0x03b8,    0x03c1,    0x03c3,
        0x03c4,    0x03c5,    0x03d6,    0x03c9,
        0x03be,    0x03c8,    0x03b6,    0xe117,
        0x007c,    0xe118,    0xe119,         0,
    // F080
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F090
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0a0
        0xe11a,    0x03d2,    0x0384,    0xe11b,
        0x2215,    0xe11c,    0xe11d,    0xe11e,
        0x2666,    0xe11f,    0xe120,    0xe121,
        0xe122,    0xe123,    0xe124,    0xe125,
    // F0b0
        0xe126,    0xe127,    0x2033,    0xe128,
        0xe129,    0xe12a,    0xe12b,    0xe12c,
        0xe12d,    0xe12e,    0xe12f,    0xe130,
        0xe131,    0x2502,    0x2500,    0x21b2,
    // F0c0
        0xe132,    0xe133,    0xe134,    0xe135,
        0xe136,    0xe137,    0xe138,    0xe139,
        0xe13a,    0xe13b,    0xe13c,    0xe13d,
        0xe13e,    0xe13f,    0xe140,    0xe141,
    // F0d0
        0x2220,    0xe142,    0x00ae,    0x00a9,
        0xe143,    0xe144,    0xe145,    0xe146,
        0xe147,    0xe148,    0xe149,    0xe14a,
        0xe14b,    0x21d1,    0xe14c,    0x21d3,
    // F0e0
        0x25ca,    0xe14d,    0xe14e,    0xe14f,
        0xe150,    0xe151,    0xe152,    0xe153,
        0xe154,    0xe155,    0xe156,    0xe157,
        0xe158,    0xe159,    0xe15a,    0xe15b,
    // F0f0
             0,    0xe15c,    0xe15d,    0xe15e,
        0xe15f,    0xe160,    0xe161,    0xe162,
        0xe163,    0xe164,    0xe165,    0xe166,
        0xe167,    0xe168,    0xe169,         0,
};

// -----------------------------------------------------------------------

static const sal_Unicode aMonotypeSortsTab[224] =
{
    // F020
        0x0020,    0x2701,    0xe200,    0x2703,
        0x2704,    0xe201,    0x2706,    0xe202,
        0xe203,    0xe203,    0xe204,    0xe205,
        0x270c,    0xe206,    0xe207,    0xe208,
    // F030
        0x2710,    0x2711,    0x2712,    0xe209,
        0xe20a,    0x2715,    0x2716,    0xe20b,
        0xe20c,    0xe20d,    0xe20e,    0xe20f,
        0xe210,    0x271d,    0x271e,    0x271f,
    // F040
        0x2720,    0xe211,    0xe212,    0xe213,
        0xe214,    0xe215,    0x2726,    0x2727,
        0x2605,    0x2729,    0x272a,    0xe216,
        0xe217,    0xe218,    0xe219,    0xe21a,
    // F050
        0xe21b,    0xe21c,    0x2732,    0xe21d,
        0xe21e,    0xe21f,    0xe220,    0xe221,
        0xe222,    0xe223,    0x273a,    0x273b,
        0x273c,    0x273d,    0x273e,    0xe224,
    // F060
        0x2740,    0x2741,    0x2742,    0x2743,
        0xe225,    0x2745,    0x2746,    0x2747,
        0x2748,    0x2749,    0x274a,    0x274b,
        0xe226,    0xe227,    0xe228,    0xe229,
    // F070
        0xe22a,    0xe22b,    0xe22c,    0x25b2,
        0x25bc,    0xe22d,    0xe22e,    0xe22f,
        0x2758,    0xe230,    0x275a,    0x275b,
        0x275c,    0x275d,    0x275e,         0,
    // F080
        0xe231,    0xe232,    0xe233,    0xe234,
        0xe235,    0xe236,    0xe237,    0xe238,
        0xe239,    0xe23a,    0xe23b,    0xe23c,
        0xe23d,    0xe23e,         0,         0,
    // F090
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0a0
             0,    0xe23f,    0xe240,    0x2763,
        0x2764,    0x2765,    0x2766,    0x2767,
        0xe241,    0xe242,    0xe243,    0xe244,
        0x2460,    0x2461,    0x2462,    0x2463,
    // F0b0
        0x2464,    0x2465,    0x2466,    0x2467,
        0x2468,    0x2469,    0x2776,    0x2777,
        0x2778,    0x2779,    0x277a,    0x277b,
        0x277c,    0x277d,    0x277e,    0x277f,
    // F0c0
        0xe245,    0xe246,    0xe247,    0xe248,
        0xe249,    0xe24a,    0xe24b,    0xe24c,
        0xe24d,    0xe24e,    0xe24f,    0xe250,
        0xe251,    0xe252,    0xe253,    0xe254,
    // F0d0
        0xe255,    0xe256,    0xe257,    0xe258,
        0xe259,    0xe25a,    0xe25b,    0xe25c,
        0xe25d,    0x2799,    0xe25e,    0x279b,
        0x279c,    0x279d,    0x279e,    0x279f,
    // F0e0
        0x27a0,    0x27a1,    0xe25f,    0x27a3,
        0x27a4,    0x27a5,    0x27a6,    0x27a7,
        0x27a8,    0x27a9,    0x27aa,    0x27ab,
        0x27ac,    0x27ad,    0x27ae,    0x27af,
    // F0f0
             0,    0x27b1,    0xe260,    0x27b3,
        0x27b4,    0x27b5,    0x27b6,    0x27b7,
        0xe261,    0x27b9,    0x27ba,    0x27bb,
        0x27bc,    0x27bd,    0x27be,         0,
};

// -----------------------------------------------------------------------

/*
static const sal_Unicode aMonotypeSorts2Tab[224] =
{
//TODO:
    // F020
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F030
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F040
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F050
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F060
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F070
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F080
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F090
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0a0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0b0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0c0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0d0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0e0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0f0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
};
*/

static const sal_Unicode aMTExtraTab[224] =
{
    // F020
        0x0020,         0,         0,    0xE095,
        0xE091,    0xE096,    0x02D9,         0,
        0xE093,         0,         0,         0,
             0,         0,         0,         0,
    // F030
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
        0x25C1,         0,    0x25B7,         0,
    // F040
             0,         0,    0x2210,    0x019b,
             0,         0,         0,         0,
             0,    0x2229,         0,    0xE08B,
        0x22EF,    0x22EE,    0x22F0,    0x22F1,
    // F050
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F060
        0xE095,         0,    0xE25C,    0xE4BA,
             0,         0,    0x210F,         0,
             0,         0,         0,         0,
        0x2113,    0x2213,         0,    0x00B0,
    // F070
             0,         0,    0xE098,         0,
             0,    0xE097,         0,         0,
             0,         0,         0,    0xE081,
             0,    0xE082,         0,         0,
    // F080
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F090
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0a0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0b0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0c0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0d0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0e0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
    // F0f0
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0,
             0,         0,         0,         0
};


//=======================================================================

static sal_Unicode ImplStarSymbolToStarBats( sal_Unicode c )
{
    switch ( c )
    {
        case 0x00A2: c = 0xF0E0; break;
        case 0x00A4: c = 0xF0E1; break;
        case 0x00A5: c = 0xF0E2; break;
        case 0x00A7: c = 0xF0A7; break;
        case 0x00AB: c = 0xF0AB; break;
        case 0x00B6: c = 0xF0DE; break;
        case 0x00BB: c = 0xF0BB; break;

        case 0x0152: c = 0xF08C; break;
        case 0x0153: c = 0xF09C; break;
        case 0x0160: c = 0xF08A; break;
        case 0x0161: c = 0xF09A; break;
        case 0x0178: c = 0xF09F; break;
        case 0x017D: c = 0xF08E; break;
        case 0x017E: c = 0xF09E; break;

        case 0x0192: c = 0xF083; break;
        case 0x02C6: c = 0xF088; break;
        case 0x02DC: c = 0xF098; break;
        case 0x2013: c = 0xF096; break;
        case 0x2014: c = 0xF097; break;
        case 0x2018: c = 0xF091; break;

        case 0x2019: c = 0xF092; break;
        case 0x201A: c = 0xF082; break;
        case 0x201C: c = 0xF093; break;
        case 0x201D: c = 0xF094; break;
        case 0x201E: c = 0xF084; break;
        case 0x2020: c = 0xF086; break;

        case 0x2021: c = 0xF087; break;
        case 0x2022: c = 0xF095; break;
        case 0x2026: c = 0xF085; break;
        case 0x2030: c = 0xF089; break;
        case 0x2039: c = 0xF08B; break;
        case 0x203A: c = 0xF09B; break;

        case 0x20A1: c = 0xF0E4; break;
        case 0x20A2: c = 0xF0E5; break;
        case 0x20A3: c = 0xF0E6; break;
        case 0x20A4: c = 0xF0E7; break;
        case 0x20A8: c = 0xF0EA; break;
        case 0x20A9: c = 0xF0E8; break;
        case 0x20AB: c = 0xF0E9; break;
        case 0x20AC: c = 0xF080; break;

        case 0x2122: c = 0xF099; break;
        case 0x2190: c = 0xF0B7; break;
        case 0x2191: c = 0xF0B8; break;
        case 0x2192: c = 0xF0B5; break;
        case 0x2193: c = 0xF0B6; break;
        case 0x2194: c = 0xF0D8; break;
        case 0x2195: c = 0xF0D9; break;

        case 0x21E4: c = 0xF0B4; break;
        case 0x21E5: c = 0xF0B3; break;
        case 0x21E6: c = 0xF0A4; break;
        case 0x21E7: c = 0xF0B2; break;
        case 0x21E8: c = 0xF0AF; break;
        case 0x21E9: c = 0xF0A3; break;

        case 0x25A0: c = 0xF024; break;
        case 0x25A1: c = 0xF025; break;
        case 0x25B4: c = 0xF0C5; break;
        case 0x25B5: c = 0xF0C7; break;
        case 0x25BE: c = 0xF0C4; break;
        case 0x25BF: c = 0xF0C6; break;
        case 0x25C6: c = 0xF043; break;
        case 0x25CF: c = 0xF022; break;
        case 0x25D7: c = 0xF0D0; break;

        case 0x260E: c = 0xF074; break;
        case 0x2611: c = 0xF034; break;
        case 0x2612: c = 0xF033; break;
        case 0x261B: c = 0xF036; break;
        case 0x261E: c = 0xF07D; break;
        case 0x2639: c = 0xF0AD; break;
        case 0x263A: c = 0xF021; break;

        case 0x2702: c = 0xF0CB; break;
        case 0x2708: c = 0xF0CC; break;
        case 0x270D: c = 0xF07E; break;
        case 0x270E: c = 0xF038; break;

        case 0x2713: c = 0xF039; break;
        case 0x2714: c = 0xF03A; break;
        case 0x2717: c = 0xF04F; break;
        case 0x2718: c = 0xF050; break;
        case 0x2719: c = 0xF051; break;
        case 0x271A: c = 0xF052; break;
        case 0x271B: c = 0xF053; break;
        case 0x271C: c = 0xF054; break;

        case 0x2721: c = 0xF0CD; break;
        case 0x2722: c = 0xF044; break;
        case 0x2723: c = 0xF045; break;
        case 0x2724: c = 0xF046; break;
        case 0x2725: c = 0xF047; break;
        case 0x272B: c = 0xF055; break;
        case 0x272C: c = 0xF056; break;
        case 0x272D: c = 0xF057; break;
        case 0x272E: c = 0xF058; break;
        case 0x272F: c = 0xF059; break;

        case 0x2730: c = 0xF05A; break;
        case 0x2733: c = 0xF048; break;
        case 0x2734: c = 0xF049; break;
        case 0x2735: c = 0xF04A; break;
        case 0x2736: c = 0xF04B; break;
        case 0x2737: c = 0xF04C; break;
        case 0x2738: c = 0xF04D; break;
        case 0x2739: c = 0xF04E; break;
        case 0x273F: c = 0xF0CE; break;

        case 0x2744: c = 0xF0CF; break;
        case 0x274D: c = 0xF023; break;
        case 0x274F: c = 0xF03E; break;
        case 0x2750: c = 0xF03F; break;
        case 0x2751: c = 0xF027; break;
        case 0x2752: c = 0xF028; break;
        case 0x2756: c = 0xF02C; break;
        case 0x2759: c = 0xF0D1; break;
        case 0x2762: c = 0xF0D4; break;

        case 0x2780: c = 0xF068; break;
        case 0x2781: c = 0xF069; break;
        case 0x2782: c = 0xF06A; break;
        case 0x2783: c = 0xF06B; break;
        case 0x2784: c = 0xF06C; break;
        case 0x2785: c = 0xF06D; break;
        case 0x2786: c = 0xF06E; break;
        case 0x2787: c = 0xF06F; break;
        case 0x2788: c = 0xF070; break;
        case 0x2789: c = 0xF071; break;
        case 0x278A: c = 0xF05D; break;
        case 0x278B: c = 0xF05E; break;
        case 0x278C: c = 0xF05F; break;
        case 0x278D: c = 0xF060; break;
        case 0x278E: c = 0xF061; break;
        case 0x278F: c = 0xF062; break;

        case 0x2790: c = 0xF063; break;
        case 0x2791: c = 0xF064; break;
        case 0x2792: c = 0xF065; break;
        case 0x2793: c = 0xF066; break;
        case 0x2794: c = 0xF031; break;
        case 0x2798: c = 0xF0DA; break;
        case 0x279A: c = 0xF0DB; break;

        case 0x27A2: c = 0xF02F; break;
        case 0x27B2: c = 0xF035; break;
        case 0x27B8: c = 0xF0DC; break;

        case 0xE000: c = 0xF000+38; break;
        case 0xE001: c = 0xF000+41; break;
        case 0xE002: c = 0xF000+42; break;
        case 0xE003: c = 0xF000+43; break;
        case 0xE004: c = 0xF000+45; break;
        case 0xE005: c = 0xF000+46; break;
        case 0xE006: c = 0xF000+48; break;
        case 0xE007: c = 0xF000+57; break;

        case 0xE008: c = 0xF000+59; break;
        case 0xE009: c = 0xF000+60; break;
        case 0xE00a: c = 0xF000+61; break;
        case 0xE00b: c = 0xF000+64; break;
        case 0xE00c: c = 0xF000+65; break;
        case 0xE00d: c = 0xF000+66; break;
        case 0xE00e: c = 0xF000+67; break;
        case 0xE00f: c = 0xF000+92; break;

        case 0xE010: c = 0xF000+103; break;
        case 0xE011: c = 0xF000+114; break;
        case 0xE012: c = 0xF000+115; break;
        case 0xE013: c = 0xF000+117; break;
        case 0xE014: c = 0xF000+118; break;
        case 0xE015: c = 0xF000+119; break;
        case 0xE016: c = 0xF000+120; break;
        case 0xE017: c = 0xF000+121; break;

        case 0xE018: c = 0xF000+122; break;
        case 0xE019: c = 0xF000+123; break;
        case 0xE01a: c = 0xF000+124; break;
        case 0xE01b: c = 0xF000+126; break;
        case 0xE01c: c = 0xF000+136; break;
        case 0xE01d: c = 0xF000+155; break;
        case 0xE01e: c = 0xF000+165; break;
        case 0xE01f: c = 0xF000+166; break;

        case 0xE020: c = 0xF000+168; break;
        case 0xE021: c = 0xF000+169; break;
        case 0xE022: c = 0xF000+170; break;
        case 0xE023: c = 0xF000+172; break;
        case 0xE024: c = 0xF000+174; break;
        case 0xE025: c = 0xF000+175; break;
        case 0xE026: c = 0xF000+176; break;
        case 0xE027: c = 0xF000+177; break;

        case 0xE028: c = 0xF000+178; break;
        case 0xE029: c = 0xF000+185; break;
        case 0xE02a: c = 0xF000+186; break;
        case 0xE02b: c = 0xF000+188; break;
        case 0xE02c: c = 0xF000+189; break;
        case 0xE02d: c = 0xF000+190; break;
        case 0xE02e: c = 0xF000+191; break;
        case 0xE02f: c = 0xF000+192; break;

        case 0xE030: c = 0xF000+193; break;
        case 0xE031: c = 0xF000+194; break;
        case 0xE032: c = 0xF000+195; break;
        case 0xE033: c = 0xF000+200; break;
        case 0xE034: c = 0xF000+201; break;
        case 0xE035: c = 0xF000+202; break;
        case 0xE036: c = 0xF000+210; break;
        case 0xE037: c = 0xF000+211; break;

        case 0xE038: c = 0xF000+227; break;
        case 0xE039: c = 0xF000+235; break;
        case 0xE03a: c = 0xF000+255; break;

        default: c = 0; break;
    }

    return c;
}

enum SymbolFont
{
    Symbol=1, Wingdings=2, MonotypeSorts=4, Webdings=8, Wingdings2=16,
    Wingdings3=32, MTExtra=64, TimesNewRoman=128
};

const char *aSymbolNames[] =
{
    "Symbol", "Wingdings", "Monotype Sorts", "Webdings", "Wingdings 2",
    "Wingdings 3", "MT Extra", "Times New Roman"
};

struct SymbolEntry
{
    sal_uInt8 cIndex;
    enum SymbolFont eFont;
};

class StarSymbolToMSMultiFontImpl : public StarSymbolToMSMultiFont
{
private:
    ::std::multimap<sal_Unicode, SymbolEntry> maMagicMap;
public:
    StarSymbolToMSMultiFontImpl(bool bPerfectOnly);
    String ConvertChar(sal_Unicode &rChar);
    String ConvertString(String &rString, xub_StrLen& rIndex);
};

struct ExtraTable { sal_Unicode cStar; sal_uInt8 cMS;};

ExtraTable aWingDingsExtraTab[] =
{
    {0x25cf, 0x6C}, {0x2714, 0xFC}, {0x2717, 0xFB}, {0x2794, 0xE8},
    {0x27a2, 0xD8}, {0xe000, 0x6F}, {0xe001, 0x73}, {0xe002, 0x74},
    {0xe003, 0x75}, {0xe004, 0x77}, {0xe005, 0xA6}, {0xe006, 0xE0},
    {0xe007, 0xFC}, {0xe008, 0x6C}, {0xe009, 0x6D}, {0xe00a, 0x6E},
    {0xe00b, 0x72}, {0xe00c, 0x75}, {0xe00d, 0x76}, {0xe00e, 0x74},
    {0xe00f, 0x8B}, {0xe010, 0x80}, {0xe011, 0x2B}, {0xe012, 0x3A},
    {0xe013, 0x5D}, {0xe014, 0x29}, {0xe015, 0x3A}, {0xe016, 0x3C},
    {0xe017, 0x38}, {0xe018, 0x3A}, {0xe019, 0x2A}, {0xe01a, 0x2B},
    {0xe01b, 0x3F}, {0xe01c, 0x9F}, {0xe01d, 0x80}, {0xe01e, 0x8B},
    {0xe023, 0x4A}, {0xe025, 0xF0}, {0xe026, 0xF2}, {0xe027, 0xEF},
    {0xe028, 0xF1}, {0xe029, 0x52}, {0xe02a, 0x29}, {0xe02b, 0xE0},
    {0xe02c, 0xE2}, {0xe02d, 0xDF}, {0xe02e, 0xE1}, {0xe02f, 0xAC},
    {0xe030, 0xAD}, {0xe031, 0xAE}, {0xe032, 0x7C}, {0xe033, 0x43},
    {0xe034, 0x4D}, {0xe0aa, 0x71}, {0xe422, 0x44}
};

ExtraTable aSymbolExtraTab2[] =
{
    {0x0020, 0x20}, {0x00A0, 0x20}, {0x0021, 0x21}, {0x2200, 0x22},
    {0x0023, 0x23}, {0x2203, 0x24}, {0x0025, 0x25}, {0x0026, 0x26},
    {0x220B, 0x27}, {0x0028, 0x28}, {0x0029, 0x29}, {0x2217, 0x2A},
    {0x002B, 0x2B}, {0x002C, 0x2C}, {0x2212, 0x2D}, {0x002E, 0x2E},
    {0x002F, 0x2F}, {0x003A, 0x3A}, {0x003B, 0x3B}, {0x003C, 0x3C},
    {0x003D, 0x3D}, {0x003E, 0x3E}, {0x2245, 0x40}, {0x2206, 0x44},
    {0x2126, 0x57}, {0x005B, 0x5B}, {0x005D, 0x5D}, {0x22A5, 0x5E},
    {0x03C6, 0x66}, {0x03D5, 0x6A}, {0x00B5, 0x6D}, {0x007B, 0x7B},
    {0x007C, 0x7C}, {0x007D, 0x7D}, {0x223C, 0x7E}, {0x20AC, 0xA0},
    {0x2032, 0xA2}, {0x2264, 0xA3}, {0x2044, 0xA4}, {0x221E, 0xA5},
    {0x0192, 0xA6}, {0x2663, 0xA7}, {0x2665, 0xA9}, {0x2660, 0xAA},
    {0x2194, 0xAB}, {0x2190, 0xAC}, {0x2191, 0xAD}, {0x2192, 0xAE},
    {0x2193, 0xAF}, {0x00B0, 0xB0}, {0x00B1, 0xB1}, {0x2265, 0xB3},
    {0x00D7, 0xB4}, {0x221D, 0xB5}, {0x2202, 0xB6}, {0x2022, 0xB7},
    {0x00F7, 0xB8}, {0x2260, 0xB9}, {0x2261, 0xBA}, {0x2248, 0xBB},
    {0x2026, 0xBC}, {0x21B5, 0xBF}, {0x2135, 0xC0}, {0x2111, 0xC1},
    {0x211C, 0xC2}, {0x2118, 0xC3}, {0x2297, 0xC4}, {0x2295, 0xC5},
    {0x2205, 0xC6}, {0x2229, 0xC7}, {0x222A, 0xC8}, {0x2283, 0xC9},
    {0x2287, 0xCA}, {0x2284, 0xCB}, {0x2282, 0xCC}, {0x2286, 0xCD},
    {0x2208, 0xCE}, {0x2209, 0xCF}, {0x2207, 0xD1}, {0x220F, 0xD5},
    {0x221A, 0xD6}, {0x22C5, 0xD7}, {0x00AC, 0xD8}, {0x2227, 0xD9},
    {0x2228, 0xDA}, {0x21D4, 0xDB}, {0x21D0, 0xDC}, {0x21D2, 0xDE},
    {0x2329, 0xE1}, {0x2211, 0xE5}, {0x232A, 0xF1}, {0x222B, 0xF2},
    {0x2320, 0xF3}, {0x2321, 0xF5}, {0x2013, 0x2D}
};

ExtraTable aSymbolExtraTab[] =
{
    {0xe021, 0xD3}, {0xe024, 0xD2}, {0xe035, 0x20}, {0xe036, 0x28},
    {0xe037, 0x29}, {0xe039, 0x20}, {0xe083, 0x2B}, {0xe084, 0x3C},
    {0xe085, 0x3E}, {0xe086, 0xA3}, {0xe087, 0xB3}, {0xe089, 0xCE},
    {0xe08a, 0xA6}, {0xe08c, 0xAE}, {0xe08d, 0xD6}, {0xe08e, 0xD6},
    {0xe08f, 0xD6}, {0xe094, 0xA2}, {0xe09e, 0x28}, {0xe09f, 0x29},
    {0xe0a0, 0xD0}, {0xe0a6, 0xA2}, {0xe0a7, 0x7C}, {0xe0a8, 0x2F},
    {0xe0ab, 0x7C}, {0xe0ac, 0x47}, {0xe0ad, 0x44}, {0xe0ae, 0x51},
    {0xe0af, 0x4C}, {0xe0b0, 0x58}, {0xe0b1, 0x50}, {0xe0b2, 0x53},
    {0xe0b3, 0x55}, {0xe0b4, 0x46}, {0xe0b5, 0x59}, {0xe0b6, 0x57},
    {0xe0b7, 0x61}, {0xe0b8, 0x62}, {0xe0b9, 0x67}, {0xe0ba, 0x64},
    {0xe0bb, 0x65}, {0xe0bc, 0x7A}, {0xe0bd, 0x68}, {0xe0be, 0x71},
    {0xe0bf, 0x69}, {0xe0c0, 0x6B}, {0xe0c1, 0x6C}, {0xe0c2, 0x6D},
    {0xe0c3, 0x6E}, {0xe0c4, 0x78}, {0xe0c5, 0x6F}, {0xe0c6, 0x70},
    {0xe0c7, 0x72}, {0xe0c8, 0x73}, {0xe0c9, 0x74}, {0xe0ca, 0x75},
    {0xe0cb, 0x66}, {0xe0cc, 0x63}, {0xe0cd, 0x79}, {0xe0ce, 0x77},
    {0xe0cf, 0x65}, {0xe0d0, 0x4A}, {0xe0d1, 0x76}, {0xe0d3, 0x56},
    {0xe0d4, 0x6A}, {0xe0d5, 0xB6}, {0xe0d6, 0x69}, {0xe0db, 0xAC},
    {0xe0dc, 0xAD}, {0xe0dd, 0xAF}
};

ExtraTable aTNRExtraTab[] =
{
    {0xe021, 0xA9},
    {0xe022, 0x40},
    {0xe024, 0xAE},
    {0xe035, 0x20},
    {0xe036, '('},
    {0xe037, ')'},
    {0xe039, 0x20},
    {0xe03a, 0x80},
    {0xe080, 0x89},
    {0xe083, '+'},
    {0xe084, '<'},
    {0xe085, '>'},
    {0xe0a9, '\\'}
};

StarSymbolToMSMultiFontImpl::StarSymbolToMSMultiFontImpl(bool bPerfectOnly)
{
    struct ConvertTable
    {
        enum SymbolFont meFont;
        const sal_Unicode* pTab;
    };

    //In order of preference
    const ConvertTable aConservativeTable[] =
    {
        {Symbol,         aAdobeSymbolTab},
        {Wingdings,      aWingDingsTab},
        {MonotypeSorts,  aMonotypeSortsTab},
        {Webdings,       aWebDingsTab},
        {Wingdings2,     aWingDings2Tab},
        {Wingdings3,     aWingDings3Tab},
        {MTExtra,        aMTExtraTab}
    };

    struct ExtendedConvertTable
    {
        enum SymbolFont meFont;
        const ExtraTable *mpTable;
        size_t mnSize;
        ExtendedConvertTable(SymbolFont eFont, const ExtraTable *pTable,
            size_t nSize)
            : meFont(eFont), mpTable(pTable), mnSize(nSize) {}
    };

    //Reverse map from a given starsymbol char to exact matches in ms symbol
    //fonts.
    int nEntries = sizeof(aConservativeTable) / sizeof(aConservativeTable[0]);
    int i;
    for (i = 0; i < nEntries; ++i)
    {
        const ConvertTable& r = aConservativeTable[i];
        SymbolEntry aEntry;
        aEntry.eFont = r.meFont;
        for (aEntry.cIndex = 0xFF; aEntry.cIndex >= 0x20; --aEntry.cIndex)
        {
            if (sal_Unicode cChar = r.pTab[aEntry.cIndex-0x20])
                maMagicMap.insert(
                    ::std::multimap<sal_Unicode, SymbolEntry>::value_type(
                    cChar, aEntry));
        }
    }

    //In order of preference
    const ExtendedConvertTable aAgressiveTable[] =
    {
        ExtendedConvertTable(Symbol, aSymbolExtraTab2,
            sizeof(aSymbolExtraTab2)),
        ExtendedConvertTable(Symbol, aSymbolExtraTab,
            sizeof(aSymbolExtraTab)),
        ExtendedConvertTable(Wingdings, aWingDingsExtraTab,
            sizeof(aWingDingsExtraTab)),
        ExtendedConvertTable(TimesNewRoman, aTNRExtraTab,
            sizeof(aTNRExtraTab))
    };

     //Allow extra conversions that are not perfect, but "good enough"
    if (!bPerfectOnly)
        nEntries = sizeof(aAgressiveTable) / sizeof(aAgressiveTable[0]);
    else
        nEntries = 1;

    for (i = 0; i < nEntries; ++i)
    {
        const ExtendedConvertTable& r = aAgressiveTable[i];
        SymbolEntry aEntry;
        aEntry.eFont = r.meFont;
        for (int j = r.mnSize / sizeof(r.mpTable[0]); j >=0; --j)
        {
            aEntry.cIndex = r.mpTable[j].cMS;
            maMagicMap.insert(
                ::std::multimap<sal_Unicode, SymbolEntry>::value_type(
                r.mpTable[j].cStar, aEntry));
        }
    }
}

const char *SymbolFontToString(int nResult)
{
    const char **ppName = aSymbolNames;
    int nI = Symbol;
    while (nI <= nResult)
    {
        if (!(nI & nResult))
            nI = nI << 1;
        else
            break;
        ppName++;
    }
    return *ppName;
}

String StarSymbolToMSMultiFontImpl::ConvertChar(sal_Unicode &rChar)
{
    String sRet;

    ::std::multimap<sal_Unicode, SymbolEntry>::const_iterator aResult =
        maMagicMap.find(rChar);

    if (aResult != maMagicMap.end())
    {
        const SymbolEntry &rEntry = (*aResult).second;
    	sRet.AssignAscii(SymbolFontToString(rEntry.eFont));
        rChar = rEntry.cIndex;
    }

    return sRet;
}

String StarSymbolToMSMultiFontImpl::ConvertString(String &rString,
    xub_StrLen& rIndex)
{
    typedef ::std::multimap<sal_Unicode, SymbolEntry>::iterator MI;
    typedef ::std::pair<MI, MI> Result;

    String sRet;

    xub_StrLen nLen = rString.Len();
    if (rIndex >= nLen)
        return sRet;

    int nTotal = 0, nResult = 0;
    ::std::vector<Result> aPossibilities;
    aPossibilities.reserve(nLen - rIndex);
    xub_StrLen nStart = rIndex;
    do
    {
        Result aResult = maMagicMap.equal_range(rString.GetChar(rIndex));
        int nBitfield = 0;
        for (MI aIndex = aResult.first; aIndex != aResult.second; ++aIndex)
            nBitfield |= aIndex->second.eFont;

        if (!nTotal)
            nTotal = nBitfield;
        else
        {
            if (nTotal != nBitfield)    //Allow a series of failures
            {
                nTotal &= nBitfield;
                if (!nTotal)
                    break;
            }
        }
        nResult = nTotal;
        if (nResult)    //Don't bother storing a series of failures
            aPossibilities.push_back(aResult);
        ++rIndex;
    }while(rIndex < nLen);

    if (nResult)
    {
        int nI = Symbol;
        while (nI <= nResult)
        {
            if (!(nI & nResult))
                nI = nI << 1;
            else
                break;
        }
        sRet.AssignAscii(SymbolFontToString(nI));

        xub_StrLen nSize = sal::static_int_cast<xub_StrLen>(aPossibilities.size());
        for(xub_StrLen nPos = 0; nPos < nSize; ++nPos)
        {
            const Result &rResult = aPossibilities[nPos];

            for (MI aIndex = rResult.first; aIndex != rResult.second; ++aIndex)
            {
                if (aIndex->second.eFont == nI)
                {
                    rString.SetChar(nPos+nStart, aIndex->second.cIndex);
                    break;
                }
            }
        }
    }

    return sRet;
}

StarSymbolToMSMultiFont *CreateStarSymbolToMSMultiFont(bool bPerfectOnly)
{
    return new StarSymbolToMSMultiFontImpl(bPerfectOnly);
}
#endif
namespace SVMCore{
//=======================================================================

sal_Unicode ImplRecodeChar( const ImplCvtChar* pConversion, sal_Unicode cChar )
{
    sal_Unicode cRetVal = 0;
    if( pConversion->mpCvtFunc )
    {
        // use a conversion function for recoding
        cRetVal = pConversion->mpCvtFunc( cChar );
    }
    else
    {
        // use a conversion table for recoding
        sal_Unicode cIndex = cChar;
        // allow symbol aliasing
        if( cIndex & 0xFF00 )
            cIndex -= 0xF000;
        // recode the symbol
        if( cIndex>=0x0020 && cIndex<=0x00FF )
            cRetVal = pConversion->mpCvtTab[ cIndex - 0x0020 ];
    }

    return cRetVal ? cRetVal : cChar;
}

// -----------------------------------------------------------------------

// recode the string assuming the character codes are symbol codes
// from an traditional symbol font (i.e. U+F020..U+F0FF)
void ImplRecodeString( const ImplCvtChar* pConversion, String& rStr,
           xub_StrLen nIndex, xub_StrLen nLen )
{
    ULONG nLastIndex = (ULONG)nIndex + nLen;
    if( nLastIndex > rStr.Len() )
        nLastIndex = rStr.Len();

    for(; nIndex < nLastIndex; ++nIndex )
    {
        sal_Unicode cOrig = rStr.GetChar( nIndex );
        // only recode symbols and their U+00xx aliases
        if( ((cOrig < 0x0020) || (cOrig > 0x00FF))
        &&  ((cOrig < 0xF020) || (cOrig > 0xF0FF)) )
            continue;

        // recode a symbol
        sal_Unicode cNew = ImplRecodeChar( pConversion, cOrig );
        if( cOrig != cNew )
            rStr.SetChar( nIndex, cNew );
    }
}
}//SVMCore
#ifdef AVS
//=======================================================================

struct RecodeTable { const char* pOrgName; ImplCvtChar aCvt;};

static RecodeTable aRecodeTable[] =
{
    // the first two entries must be StarMath and StarBats; do not reorder!
    // reason: fgrep for FONTTOSUBSFONT_ONLYOLDSOSYMBOLFONTS
    {"starbats",        {aStarBatsTab,  "StarSymbol", NULL}},
    {"starmath",        {aStarMathTab,  "StarSymbol", NULL}},

    {"symbol",          {aAdobeSymbolTab, "StarSymbol", NULL}},
    {"standardsymbols", {aAdobeSymbolTab, "StarSymbol", NULL}},
    {"standardsymbolsl",{aAdobeSymbolTab, "StarSymbol", NULL}},

    {"monotypesorts",   {aMonotypeSortsTab, "StarSymbol", NULL}},
//  {"monotypesorts2",  {aMonotypeSorts2Tab, "StarSymbol", NULL}}
    {"zapfdingbats",    {aMonotypeSortsTab, "StarSymbol", NULL}},  //ZapfDingbats=MonotypeSorts-X?
    {"itczapfdingbats", {aMonotypeSortsTab, "StarSymbol", NULL}},
    {"dingbats",        {aMonotypeSortsTab, "StarSymbol", NULL}},

    {"webdings",        {aWebDingsTab,   "StarSymbol", NULL}},
    {"wingdings",       {aWingDingsTab,  "StarSymbol", NULL}},
    {"wingdings2",      {aWingDings2Tab, "StarSymbol", NULL}},
    {"wingdings3",      {aWingDings3Tab, "StarSymbol", NULL}},
    {"mtextra",         {aMTExtraTab, "StarSymbol", NULL}}
};

static ImplCvtChar aImplStarSymbolCvt = { NULL, "StarBats", ImplStarSymbolToStarBats };
#if 0
// not used
static ImplCvtChar aImplDingBatsCvt   = { aMonotypeSortsTab, "StarSymbol", NULL };
#endif

// -----------------------------------------------------------------------

const ImplCvtChar* ImplGetRecodeData( const String& rOrgFontName,
                                      const String& rMapFontName )
{
    const ImplCvtChar* pCvt = NULL;
    String aOrgName( rOrgFontName );
    ImplGetEnglishSearchFontName( aOrgName );
    String aMapName( rMapFontName );
    ImplGetEnglishSearchFontName( aMapName );

    if( aMapName.EqualsAscii( "starsymbol" )
     || aMapName.EqualsAscii( "opensymbol" ) )
    {
        int nEntries = sizeof(aRecodeTable) / sizeof(aRecodeTable[0]);
        for( int i = 0; i < nEntries; ++i)
        {
            RecodeTable& r = aRecodeTable[i];
            if( aOrgName.EqualsAscii( r.pOrgName ) )
                { pCvt = &r.aCvt; break; }
        }
    }
    else if( aMapName.EqualsAscii( "starbats" ) )
    {
        if( aOrgName.EqualsAscii( "starsymbol" ) )
            pCvt = &aImplStarSymbolCvt;
        else if( aOrgName.EqualsAscii( "opensymbol" ) )
            pCvt = &aImplStarSymbolCvt;
    }

    return pCvt;
}

//=======================================================================

FontToSubsFontConverter CreateFontToSubsFontConverter(
    const String& rOrgName, ULONG nFlags )
{
    const ImplCvtChar* pCvt = NULL;

    String aName = rOrgName;
    ImplGetEnglishSearchFontName( aName );

    if ( nFlags & FONTTOSUBSFONT_IMPORT )
    {
        int nEntries = sizeof(aRecodeTable) / sizeof(aRecodeTable[0]);
        if ( nFlags & FONTTOSUBSFONT_ONLYOLDSOSYMBOLFONTS ) // only StarMath+StarBats
            nEntries = 2;
        for( int i = 0; i < nEntries; ++i )
        {
            RecodeTable& r = aRecodeTable[i];
            if( aName.EqualsAscii( r.pOrgName ) )
                { pCvt = &r.aCvt; break; }
        }
    }
    else
    {
        // TODO: FONTTOSUBSFONT_ONLYOLDSOSYMBOLFONTS
        if( aName.EqualsAscii( "starsymbol" ) )       pCvt = &aImplStarSymbolCvt;
        else if( aName.EqualsAscii( "opensymbol" ) )  pCvt = &aImplStarSymbolCvt;
    }

    return (FontToSubsFontConverter)pCvt;
}

// -----------------------------------------------------------------------

void DestroyFontToSubsFontConverter( FontToSubsFontConverter )
{
    // nothing to do for now, because we use static ImplCvtChars
}

// -----------------------------------------------------------------------

sal_Unicode ConvertFontToSubsFontChar(
    FontToSubsFontConverter hConverter, sal_Unicode cChar )
{
    if ( hConverter )
        return ImplRecodeChar( (ImplCvtChar*)hConverter, cChar );
    else
        return cChar;
}

// -----------------------------------------------------------------------

String GetFontToSubsFontName( FontToSubsFontConverter hConverter )
{
    if ( !hConverter )
        return String();

    const char* pName = ((ImplCvtChar*)hConverter)->mpSubsFontName;
    return String::CreateFromAscii( pName );
}
#endif