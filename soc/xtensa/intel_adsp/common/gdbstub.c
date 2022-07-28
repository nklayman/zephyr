/*
 * Copyright (c) 2021 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
// TODO: figure out how to include using the proper include path
// For some reason, the #include errors because it can't find the file
#include "../../../../arch/xtensa/include/xtensa-asm2-context.h"
#include <stdint.h>
#include <zephyr/debug/gdbstub.h>

// By providing an empty array, the GDB stub will assume all memory can be
// accessed, which should be fine for now. Ideally this would be filled in.
const struct gdb_mem_region gdb_mem_region_array[] = {};

const size_t gdb_mem_num_regions = ARRAY_SIZE(gdb_mem_region_array);

static struct xtensa_register gdb_reg_list[] = {
	{
		/* PC */
		.idx = 32,
		.regno = 0x0020,
		.byte_size = 4,
		.gpkt_offset = 0,
		.stack_offset = BSA_PC_OFF,
	},
	{
		/* AR0 */
		.idx = (uint32_t) 0x100,
		.regno = 0x100,
		.byte_size = 4,
		.gpkt_offset = 4,
	},
	{
		/* AR1 */
		.idx = (uint32_t) 0x101,
		.regno = 0x101,
		.byte_size = 4,
		.gpkt_offset = 8,
	},
	{
		/* AR2 */
		.idx = (uint32_t) 0x102,
		.regno = 0x102,
		.byte_size = 4,
		.gpkt_offset = 12,
	},
	{
		/* AR3 */
		.idx = (uint32_t) 0x103,
		.regno = 0x103,
		.byte_size = 4,
		.gpkt_offset = 16,
	},
	{
		/* AR4 */
		.idx = (uint32_t) 0x104,
		.regno = 0x104,
		.byte_size = 4,
		.gpkt_offset = 20,
	},
	{
		/* AR5 */
		.idx = (uint32_t) 0x105,
		.regno = 0x105,
		.byte_size = 4,
		.gpkt_offset = 24,
	},
	{
		/* AR6 */
		.idx = (uint32_t) 0x106,
		.regno = 0x106,
		.byte_size = 4,
		.gpkt_offset = 28,
	},
	{
		/* AR7 */
		.idx = (uint32_t) 0x107,
		.regno = 0x107,
		.byte_size = 4,
		.gpkt_offset = 32,
	},
	{
		/* AR8 */
		.idx = (uint32_t) 0x108,
		.regno = 0x108,
		.byte_size = 4,
		.gpkt_offset = 36,
	},
	{
		/* AR9 */
		.idx = (uint32_t) 0x109,
		.regno = 0x109,
		.byte_size = 4,
		.gpkt_offset = 40,
	},
	{
		/* AR10 */
		.idx = (uint32_t) 0x10a,
		.regno = 0x10a,
		.byte_size = 4,
		.gpkt_offset = 44,
	},
	{
		/* AR11 */
		.idx = (uint32_t) 0x10b,
		.regno = 0x10b,
		.byte_size = 4,
		.gpkt_offset = 48,
	},
	{
		/* AR12 */
		.idx = (uint32_t) 0x10c,
		.regno = 0x10c,
		.byte_size = 4,
		.gpkt_offset = 52,
	},
	{
		/* AR13 */
		.idx = (uint32_t) 0x10d,
		.regno = 0x10d,
		.byte_size = 4,
		.gpkt_offset = 56,
	},
	{
		/* AR14 */
		.idx = (uint32_t) 0x10e,
		.regno = 0x10e,
		.byte_size = 4,
		.gpkt_offset = 60,
	},
	{
		/* AR15 */
		.idx = (uint32_t) 0x10f,
		.regno = 0x10f,
		.byte_size = 4,
		.gpkt_offset = 64,
	},
	{
		/* AR16 */
		.idx = (uint32_t) 0x110,
		.regno = 0x110,
		.byte_size = 4,
		.gpkt_offset = 68,
	},
	{
		/* AR17 */
		.idx = (uint32_t) 0x111,
		.regno = 0x111,
		.byte_size = 4,
		.gpkt_offset = 72,
	},
	{
		/* AR18 */
		.idx = (uint32_t) 0x112,
		.regno = 0x112,
		.byte_size = 4,
		.gpkt_offset = 76,
	},
	{
		/* AR19 */
		.idx = (uint32_t) 0x113,
		.regno = 0x113,
		.byte_size = 4,
		.gpkt_offset = 80,
	},
	{
		/* AR20 */
		.idx = (uint32_t) 0x114,
		.regno = 0x114,
		.byte_size = 4,
		.gpkt_offset = 84,
	},
	{
		/* AR21 */
		.idx = (uint32_t) 0x115,
		.regno = 0x115,
		.byte_size = 4,
		.gpkt_offset = 88,
	},
	{
		/* AR22 */
		.idx = (uint32_t) 0x116,
		.regno = 0x116,
		.byte_size = 4,
		.gpkt_offset = 92,
	},
	{
		/* AR23 */
		.idx = (uint32_t) 0x117,
		.regno = 0x117,
		.byte_size = 4,
		.gpkt_offset = 96,
	},
	{
		/* AR24 */
		.idx = (uint32_t) 0x118,
		.regno = 0x118,
		.byte_size = 4,
		.gpkt_offset = 100,
	},
	{
		/* AR25 */
		.idx = (uint32_t) 0x119,
		.regno = 0x119,
		.byte_size = 4,
		.gpkt_offset = 104,
	},
	{
		/* AR26 */
		.idx = (uint32_t) 0x11a,
		.regno = 0x11a,
		.byte_size = 4,
		.gpkt_offset = 108,
	},
	{
		/* AR27 */
		.idx = (uint32_t) 0x11b,
		.regno = 0x11b,
		.byte_size = 4,
		.gpkt_offset = 112,
	},
	{
		/* AR28 */
		.idx = (uint32_t) 0x11c,
		.regno = 0x11c,
		.byte_size = 4,
		.gpkt_offset = 116,
	},
	{
		/* AR29 */
		.idx = (uint32_t) 0x11d,
		.regno = 0x11d,
		.byte_size = 4,
		.gpkt_offset = 120,
	},
	{
		/* AR30 */
		.idx = (uint32_t) 0x11e,
		.regno = 0x11e,
		.byte_size = 4,
		.gpkt_offset = 124,
	},
	{
		/* AR31 */
		.idx = (uint32_t) 0x11f,
		.regno = 0x11f,
		.byte_size = 4,
		.gpkt_offset = 128,
	},
	{
		/* AR32 */
		.idx = (uint32_t) 0x120,
		.regno = 0x120,
		.byte_size = 4,
		.gpkt_offset = 132,
	},
	{
		/* AR33 */
		.idx = (uint32_t) 0x121,
		.regno = 0x121,
		.byte_size = 4,
		.gpkt_offset = 136,
	},
	{
		/* AR34 */
		.idx = (uint32_t) 0x122,
		.regno = 0x122,
		.byte_size = 4,
		.gpkt_offset = 140,
	},
	{
		/* AR35 */
		.idx = (uint32_t) 0x123,
		.regno = 0x123,
		.byte_size = 4,
		.gpkt_offset = 144,
	},
	{
		/* AR36 */
		.idx = (uint32_t) 0x124,
		.regno = 0x124,
		.byte_size = 4,
		.gpkt_offset = 148,
	},
	{
		/* AR37 */
		.idx = (uint32_t) 0x125,
		.regno = 0x125,
		.byte_size = 4,
		.gpkt_offset = 152,
	},
	{
		/* AR38 */
		.idx = (uint32_t) 0x126,
		.regno = 0x126,
		.byte_size = 4,
		.gpkt_offset = 156,
	},
	{
		/* AR39 */
		.idx = (uint32_t) 0x127,
		.regno = 0x127,
		.byte_size = 4,
		.gpkt_offset = 160,
	},
	{
		/* AR40 */
		.idx = (uint32_t) 0x128,
		.regno = 0x128,
		.byte_size = 4,
		.gpkt_offset = 164,
	},
	{
		/* AR41 */
		.idx = (uint32_t) 0x129,
		.regno = 0x129,
		.byte_size = 4,
		.gpkt_offset = 168,
	},
	{
		/* AR42 */
		.idx = (uint32_t) 0x12a,
		.regno = 0x12a,
		.byte_size = 4,
		.gpkt_offset = 172,
	},
	{
		/* AR43 */
		.idx = (uint32_t) 0x12b,
		.regno = 0x12b,
		.byte_size = 4,
		.gpkt_offset = 176,
	},
	{
		/* AR44 */
		.idx = (uint32_t) 0x12c,
		.regno = 0x12c,
		.byte_size = 4,
		.gpkt_offset = 180,
	},
	{
		/* AR45 */
		.idx = (uint32_t) 0x12d,
		.regno = 0x12d,
		.byte_size = 4,
		.gpkt_offset = 184,
	},
	{
		/* AR46 */
		.idx = (uint32_t) 0x12e,
		.regno = 0x12e,
		.byte_size = 4,
		.gpkt_offset = 188,
	},
	{
		/* AR47 */
		.idx = (uint32_t) 0x12f,
		.regno = 0x12f,
		.byte_size = 4,
		.gpkt_offset = 192,
	},
	{
		/* AR48 */
		.idx = (uint32_t) 0x130,
		.regno = 0x130,
		.byte_size = 4,
		.gpkt_offset = 196,
	},
	{
		/* AR49 */
		.idx = (uint32_t) 0x131,
		.regno = 0x131,
		.byte_size = 4,
		.gpkt_offset = 200,
	},
	{
		/* AR50 */
		.idx = (uint32_t) 0x132,
		.regno = 0x132,
		.byte_size = 4,
		.gpkt_offset = 204,
	},
	{
		/* AR51 */
		.idx = (uint32_t) 0x133,
		.regno = 0x133,
		.byte_size = 4,
		.gpkt_offset = 208,
	},
	{
		/* AR52 */
		.idx = (uint32_t) 0x134,
		.regno = 0x134,
		.byte_size = 4,
		.gpkt_offset = 212,
	},
	{
		/* AR53 */
		.idx = (uint32_t) 0x135,
		.regno = 0x135,
		.byte_size = 4,
		.gpkt_offset = 216,
	},
	{
		/* AR54 */
		.idx = (uint32_t) 0x136,
		.regno = 0x136,
		.byte_size = 4,
		.gpkt_offset = 220,
	},
	{
		/* AR55 */
		.idx = (uint32_t) 0x137,
		.regno = 0x137,
		.byte_size = 4,
		.gpkt_offset = 224,
	},
	{
		/* AR56 */
		.idx = (uint32_t) 0x138,
		.regno = 0x138,
		.byte_size = 4,
		.gpkt_offset = 228,
	},
	{
		/* AR57 */
		.idx = (uint32_t) 0x139,
		.regno = 0x139,
		.byte_size = 4,
		.gpkt_offset = 232,
	},
	{
		/* AR58 */
		.idx = (uint32_t) 0x13a,
		.regno = 0x13a,
		.byte_size = 4,
		.gpkt_offset = 236,
	},
	{
		/* AR59 */
		.idx = (uint32_t) 0x13b,
		.regno = 0x13b,
		.byte_size = 4,
		.gpkt_offset = 240,
	},
	{
		/* AR60 */
		.idx = (uint32_t) 0x13c,
		.regno = 0x13c,
		.byte_size = 4,
		.gpkt_offset = 244,
	},
	{
		/* AR61 */
		.idx = (uint32_t) 0x13d,
		.regno = 0x13d,
		.byte_size = 4,
		.gpkt_offset = 248,
	},
	{
		/* AR62 */
		.idx = (uint32_t) 0x13e,
		.regno = 0x13e,
		.byte_size = 4,
		.gpkt_offset = 252,
	},
	{
		/* AR63 */
		.idx = (uint32_t) 0x13f,
		.regno = 0x13f,
		.byte_size = 4,
		.gpkt_offset = 256,
	},
	{
		/* LBEG */
		.idx = (uint32_t) 512,
		.regno = 0x0200,
		.byte_size = 4,
		.gpkt_offset = 260,
		.stack_offset = BSA_LBEG_OFF,
	},
	{
		/* LEND */
		.idx = (uint32_t) 513,
		.regno = 0x0201,
		.byte_size = 4,
		.gpkt_offset = 264,
		.stack_offset = BSA_LEND_OFF,
	},
	{
		/* LCOUNT */
		.idx = (uint32_t) 514,
		.regno = 0x0202,
		.byte_size = 4,
		.gpkt_offset = 268,
		.stack_offset = BSA_LCOUNT_OFF,
	},
	{
		/* SAR */
		.idx = (uint32_t) 515,
		.regno = 0x0203,
		.byte_size = 4,
		.gpkt_offset = 272,
		.stack_offset = BSA_SAR_OFF,
	},
	{
		/* BR */
		.idx = (uint32_t) 516,
		.regno = 0x204,
		.byte_size = 4,
		// .gpkt_offset = 276,
		.is_read_only = 1,
	},
	{
		/* PREFCTL */
		.idx = (uint32_t) 552,
		.regno = 0x0228,
		.byte_size = 4,
		// .gpkt_offset = 276,
		.is_read_only = 1,
	},
	{
		/* WINDOWBASE */
		.idx = (uint32_t) 584,
		.regno = 0x0248,
		.byte_size = 4,
		.gpkt_offset = 280,
		.is_read_only = 1,
	},
	{
		/* WINDOWSTART */
		.idx = (uint32_t) 585,
		.regno = 0x0249,
		.byte_size = 4,
		.gpkt_offset = 284,
		.is_read_only = 1,
	},
	{
		/* PS */
		.idx = (uint32_t) 742,
		.regno = 0x02E6,
		.byte_size = 4,
		.gpkt_offset = 296,
		.stack_offset = BSA_PS_OFF,
	},
	{
		/* THREADPTR */
		.idx = (uint32_t) 999, //?
		.regno = 0x03E7,
		.byte_size = 4,
		.gpkt_offset = 300,
#ifdef CONFIG_THREAD_LOCAL_STORAGE
		/* Only saved in stack if TLS is enabled */
		.stack_offset = BSA_THREADPTR_OFF,
#endif
	},
	{
		/* SCOMPARE1 */
		.idx = (uint32_t) 524,
		.regno = 0x020C,
		.byte_size = 4,
		.gpkt_offset = 308,
		.stack_offset = BSA_SCOMPARE1_OFF,
	},
	{
		/* EXCCAUSE */
		.idx = (uint32_t) 744,
		.regno = 0x02E8,
		.byte_size = 4,
		.gpkt_offset = 592,
		.stack_offset = BSA_EXCCAUSE_OFF,
	},
	{
		/* DEBUGCAUSE */
		.idx = (uint32_t) 569, //?
		.regno = 0x02E9,
		.byte_size = 4,
		.gpkt_offset = 596,
	},
	{
		/* EXCVADDR */
		.idx = (uint32_t) 750,
		.regno = 0x02EE,
		.byte_size = 4,
		.gpkt_offset = 616,
	},
	{
		/* A0 */
		.idx = (uint32_t) 0x0000,
		.regno = 0x0000,
		.byte_size = 4,
		.gpkt_offset = 632,
		.stack_offset = BSA_A0_OFF,
	},
	{
		/* A1 */
		.idx = (uint32_t) 0x0001,
		.regno = 0x0001,
		.byte_size = 4,
		.gpkt_offset = 636,
	},
	{
		/* A2 */
		.idx = (uint32_t) 0x0002,
		.regno = 0x0002,
		.byte_size = 4,
		.gpkt_offset = 640,
		.stack_offset = BSA_A2_OFF,
	},
	{
		/* A3 */
		.idx = (uint32_t) 0x0003,
		.regno = 0x0003,
		.byte_size = 4,
		.gpkt_offset = 644,
		.stack_offset = BSA_A3_OFF,
	},
	{
		/* A4 */
		.idx = (uint32_t) 0x0004,
		.regno = 0x0004,
		.byte_size = 4,
		.gpkt_offset = 648,
		.stack_offset = -16,
	},
	{
		/* A5 */
		.idx = (uint32_t) 0x0005,
		.regno = 0x0005,
		.byte_size = 4,
		.gpkt_offset = 652,
		.stack_offset = -12,
	},
	{
		/* A6 */
		.idx = (uint32_t) 0x0006,
		.regno = 0x0006,
		.byte_size = 4,
		.gpkt_offset = 656,
		.stack_offset = -8,
	},
	{
		/* A7 */
		.idx = (uint32_t) 0x0007,
		.regno = 0x0007,
		.byte_size = 4,
		.gpkt_offset = 660,
		.stack_offset = -4,
	},
	{
		/* A8 */
		.idx = (uint32_t) 0x0008,
		.regno = 0x0008,
		.byte_size = 4,
		.gpkt_offset = 664,
		.stack_offset = -32,
	},
	{
		/* A9 */
		.idx = (uint32_t) 0x0009,
		.regno = 0x0009,
		.byte_size = 4,
		.gpkt_offset = 668,
		.stack_offset = -28,
	},
	{
		/* A10 */
		.idx = (uint32_t) 0x000A,
		.regno = 0x000A,
		.byte_size = 4,
		.gpkt_offset = 672,
		.stack_offset = -24,
	},
	{
		/* A11 */
		.idx = (uint32_t) 0x000B,
		.regno = 0x000B,
		.byte_size = 4,
		.gpkt_offset = 676,
		.stack_offset = -20,
	},
	{
		/* A12 */
		.idx = (uint32_t) 0x000C,
		.regno = 0x000C,
		.byte_size = 4,
		.gpkt_offset = 680,
		.stack_offset = -48,
	},
	{
		/* A13 */
		.idx = (uint32_t) 0x000D,
		.regno = 0x000D,
		.byte_size = 4,
		.gpkt_offset = 684,
		.stack_offset = -44,
	},
	{
		/* A14 */
		.idx = (uint32_t) 0x000E,
		.regno = 0x000E,
		.byte_size = 4,
		.gpkt_offset = 688,
		.stack_offset = -40,
	},
	{
		/* A15 */
		.idx = (uint32_t) 0x000F,
		.regno = 0x000F,
		.byte_size = 4,
		.gpkt_offset = 692,
		.stack_offset = -36,
	},
	// {
	// 	/* A0 */
	// 	.idx = (uint32_t) 256 + 0,
	// 	.regno = 0x0000,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 632,
	// 	.stack_offset = BSA_A0_OFF,
	// },
	// {
	// 	/* A1 */
	// 	.idx = (uint32_t) 256 + 1,
	// 	.regno = 0x0001,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 636,
	// },
	// {
	// 	/* A2 */
	// 	.idx = (uint32_t) 256 + 2,
	// 	.regno = 0x0002,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 640,
	// 	.stack_offset = BSA_A2_OFF,
	// },
	// {
	// 	/* A3 */
	// 	.idx = (uint32_t) 256 + 3,
	// 	.regno = 0x0003,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 644,
	// 	.stack_offset = BSA_A3_OFF,
	// },
	// {
	// 	/* A4 */
	// 	.idx = (uint32_t) 256 + 4,
	// 	.regno = 0x0004,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 648,
	// 	.stack_offset = -16,
	// },
	// {
	// 	/* A5 */
	// 	.idx = (uint32_t) 256 + 5,
	// 	.regno = 0x0005,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 652,
	// 	.stack_offset = -12,
	// },
	// {
	// 	/* A6 */
	// 	.idx = (uint32_t) 256 + 6,
	// 	.regno = 0x0006,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 656,
	// 	.stack_offset = -8,
	// },
	// {
	// 	/* A7 */
	// 	.idx = (uint32_t) 256 + 7,
	// 	.regno = 0x0007,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 660,
	// 	.stack_offset = -4,
	// },
	// {
	// 	/* A8 */
	// 	.idx = (uint32_t) 256 + 8,
	// 	.regno = 0x0008,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 664,
	// 	.stack_offset = -32,
	// },
	// {
	// 	/* A9 */
	// 	.idx = (uint32_t) 256 + 9,
	// 	.regno = 0x0009,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 668,
	// 	.stack_offset = -28,
	// },
	// {
	// 	/* A10 */
	// 	.idx = (uint32_t) 256 + 10,
	// 	.regno = 0x000A,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 672,
	// 	.stack_offset = -24,
	// },
	// {
	// 	/* A11 */
	// 	.idx = (uint32_t) 256 + 11,
	// 	.regno = 0x000B,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 676,
	// 	.stack_offset = -20,
	// },
	// {
	// 	/* A12 */
	// 	.idx = (uint32_t) 256 + 12,
	// 	.regno = 0x000C,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 680,
	// 	.stack_offset = -48,
	// },
	// {
	// 	/* A13 */
	// 	.idx = (uint32_t) 256 + 13,
	// 	.regno = 0x000D,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 684,
	// 	.stack_offset = -44,
	// },
	// {
	// 	/* A14 */
	// 	.idx = (uint32_t) 256 + 14,
	// 	.regno = 0x000E,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 688,
	// 	.stack_offset = -40,
	// },
	// {
	// 	/* A15 */
	// 	.idx = (uint32_t) 256 + 15,
	// 	.regno = 0x000F,
	// 	.byte_size = 4,
	// 	.gpkt_offset = 692,
	// 	.stack_offset = -36,
	// },
};
// static struct xtensa_register gdb_reg_list[] = {
// 	{
// 		/* PC */
// 		.idx = (uint32_t) 0,
// 		.regno = 0x0020,
// 		.byte_size = 4,
// 		.gpkt_offset = 0,
// 		.stack_offset = BSA_PC_OFF,
// 	},
// 	{
// 		/* AR0 */
// 		.idx = (uint32_t) 1,
// 		.regno = 0x100,
// 		.byte_size = 4,
// 		.gpkt_offset = 4,
// 	},
// 	{
// 		/* AR1 */
// 		.idx = (uint32_t) 2,
// 		.regno = 0x101,
// 		.byte_size = 4,
// 		.gpkt_offset = 8,
// 	},
// 	{
// 		/* AR2 */
// 		.idx = (uint32_t) 3,
// 		.regno = 0x102,
// 		.byte_size = 4,
// 		.gpkt_offset = 12,
// 	},
// 	{
// 		/* AR3 */
// 		.idx = (uint32_t) 4,
// 		.regno = 0x103,
// 		.byte_size = 4,
// 		.gpkt_offset = 16,
// 	},
// 	{
// 		/* AR4 */
// 		.idx = (uint32_t) 5,
// 		.regno = 0x104,
// 		.byte_size = 4,
// 		.gpkt_offset = 20,
// 	},
// 	{
// 		/* AR5 */
// 		.idx = (uint32_t) 6,
// 		.regno = 0x105,
// 		.byte_size = 4,
// 		.gpkt_offset = 24,
// 	},
// 	{
// 		/* AR6 */
// 		.idx = (uint32_t) 7,
// 		.regno = 0x106,
// 		.byte_size = 4,
// 		.gpkt_offset = 28,
// 	},
// 	{
// 		/* AR7 */
// 		.idx = (uint32_t) 8,
// 		.regno = 0x107,
// 		.byte_size = 4,
// 		.gpkt_offset = 32,
// 	},
// 	{
// 		/* AR8 */
// 		.idx = (uint32_t) 9,
// 		.regno = 0x108,
// 		.byte_size = 4,
// 		.gpkt_offset = 36,
// 	},
// 	{
// 		/* AR9 */
// 		.idx = (uint32_t) 10,
// 		.regno = 0x109,
// 		.byte_size = 4,
// 		.gpkt_offset = 40,
// 	},
// 	{
// 		/* AR10 */
// 		.idx = (uint32_t) 11,
// 		.regno = 0x10a,
// 		.byte_size = 4,
// 		.gpkt_offset = 44,
// 	},
// 	{
// 		/* AR11 */
// 		.idx = (uint32_t) 12,
// 		.regno = 0x10b,
// 		.byte_size = 4,
// 		.gpkt_offset = 48,
// 	},
// 	{
// 		/* AR12 */
// 		.idx = (uint32_t) 13,
// 		.regno = 0x10c,
// 		.byte_size = 4,
// 		.gpkt_offset = 52,
// 	},
// 	{
// 		/* AR13 */
// 		.idx = (uint32_t) 14,
// 		.regno = 0x10d,
// 		.byte_size = 4,
// 		.gpkt_offset = 56,
// 	},
// 	{
// 		/* AR14 */
// 		.idx = (uint32_t) 15,
// 		.regno = 0x10e,
// 		.byte_size = 4,
// 		.gpkt_offset = 60,
// 	},
// 	{
// 		/* AR15 */
// 		.idx = (uint32_t) 16,
// 		.regno = 0x10f,
// 		.byte_size = 4,
// 		.gpkt_offset = 64,
// 	},
// 	{
// 		/* AR16 */
// 		.idx = (uint32_t) 17,
// 		.regno = 0x110,
// 		.byte_size = 4,
// 		.gpkt_offset = 68,
// 	},
// 	{
// 		/* AR17 */
// 		.idx = (uint32_t) 18,
// 		.regno = 0x111,
// 		.byte_size = 4,
// 		.gpkt_offset = 72,
// 	},
// 	{
// 		/* AR18 */
// 		.idx = (uint32_t) 19,
// 		.regno = 0x112,
// 		.byte_size = 4,
// 		.gpkt_offset = 76,
// 	},
// 	{
// 		/* AR19 */
// 		.idx = (uint32_t) 20,
// 		.regno = 0x113,
// 		.byte_size = 4,
// 		.gpkt_offset = 80,
// 	},
// 	{
// 		/* AR20 */
// 		.idx = (uint32_t) 21,
// 		.regno = 0x114,
// 		.byte_size = 4,
// 		.gpkt_offset = 84,
// 	},
// 	{
// 		/* AR21 */
// 		.idx = (uint32_t) 22,
// 		.regno = 0x115,
// 		.byte_size = 4,
// 		.gpkt_offset = 88,
// 	},
// 	{
// 		/* AR22 */
// 		.idx = (uint32_t) 23,
// 		.regno = 0x116,
// 		.byte_size = 4,
// 		.gpkt_offset = 92,
// 	},
// 	{
// 		/* AR23 */
// 		.idx = (uint32_t) 24,
// 		.regno = 0x117,
// 		.byte_size = 4,
// 		.gpkt_offset = 96,
// 	},
// 	{
// 		/* AR24 */
// 		.idx = (uint32_t) 25,
// 		.regno = 0x118,
// 		.byte_size = 4,
// 		.gpkt_offset = 100,
// 	},
// 	{
// 		/* AR25 */
// 		.idx = (uint32_t) 26,
// 		.regno = 0x119,
// 		.byte_size = 4,
// 		.gpkt_offset = 104,
// 	},
// 	{
// 		/* AR26 */
// 		.idx = (uint32_t) 27,
// 		.regno = 0x11a,
// 		.byte_size = 4,
// 		.gpkt_offset = 108,
// 	},
// 	{
// 		/* AR27 */
// 		.idx = (uint32_t) 28,
// 		.regno = 0x11b,
// 		.byte_size = 4,
// 		.gpkt_offset = 112,
// 	},
// 	{
// 		/* AR28 */
// 		.idx = (uint32_t) 29,
// 		.regno = 0x11c,
// 		.byte_size = 4,
// 		.gpkt_offset = 116,
// 	},
// 	{
// 		/* AR29 */
// 		.idx = (uint32_t) 30,
// 		.regno = 0x11d,
// 		.byte_size = 4,
// 		.gpkt_offset = 120,
// 	},
// 	{
// 		/* AR30 */
// 		.idx = (uint32_t) 31,
// 		.regno = 0x11e,
// 		.byte_size = 4,
// 		.gpkt_offset = 124,
// 	},
// 	{
// 		/* AR31 */
// 		.idx = (uint32_t) 32,
// 		.regno = 0x11f,
// 		.byte_size = 4,
// 		.gpkt_offset = 128,
// 	},
// 	{
// 		/* AR32 */
// 		.idx = (uint32_t) 33,
// 		.regno = 0x120,
// 		.byte_size = 4,
// 		.gpkt_offset = 132,
// 	},
// 	{
// 		/* AR33 */
// 		.idx = (uint32_t) 34,
// 		.regno = 0x121,
// 		.byte_size = 4,
// 		.gpkt_offset = 136,
// 	},
// 	{
// 		/* AR34 */
// 		.idx = (uint32_t) 35,
// 		.regno = 0x122,
// 		.byte_size = 4,
// 		.gpkt_offset = 140,
// 	},
// 	{
// 		/* AR35 */
// 		.idx = (uint32_t) 36,
// 		.regno = 0x123,
// 		.byte_size = 4,
// 		.gpkt_offset = 144,
// 	},
// 	{
// 		/* AR36 */
// 		.idx = (uint32_t) 37,
// 		.regno = 0x124,
// 		.byte_size = 4,
// 		.gpkt_offset = 148,
// 	},
// 	{
// 		/* AR37 */
// 		.idx = (uint32_t) 38,
// 		.regno = 0x125,
// 		.byte_size = 4,
// 		.gpkt_offset = 152,
// 	},
// 	{
// 		/* AR38 */
// 		.idx = (uint32_t) 39,
// 		.regno = 0x126,
// 		.byte_size = 4,
// 		.gpkt_offset = 156,
// 	},
// 	{
// 		/* AR39 */
// 		.idx = (uint32_t) 40,
// 		.regno = 0x127,
// 		.byte_size = 4,
// 		.gpkt_offset = 160,
// 	},
// 	{
// 		/* AR40 */
// 		.idx = (uint32_t) 41,
// 		.regno = 0x128,
// 		.byte_size = 4,
// 		.gpkt_offset = 164,
// 	},
// 	{
// 		/* AR41 */
// 		.idx = (uint32_t) 42,
// 		.regno = 0x129,
// 		.byte_size = 4,
// 		.gpkt_offset = 168,
// 	},
// 	{
// 		/* AR42 */
// 		.idx = (uint32_t) 43,
// 		.regno = 0x12a,
// 		.byte_size = 4,
// 		.gpkt_offset = 172,
// 	},
// 	{
// 		/* AR43 */
// 		.idx = (uint32_t) 44,
// 		.regno = 0x12b,
// 		.byte_size = 4,
// 		.gpkt_offset = 176,
// 	},
// 	{
// 		/* AR44 */
// 		.idx = (uint32_t) 45,
// 		.regno = 0x12c,
// 		.byte_size = 4,
// 		.gpkt_offset = 180,
// 	},
// 	{
// 		/* AR45 */
// 		.idx = (uint32_t) 46,
// 		.regno = 0x12d,
// 		.byte_size = 4,
// 		.gpkt_offset = 184,
// 	},
// 	{
// 		/* AR46 */
// 		.idx = (uint32_t) 47,
// 		.regno = 0x12e,
// 		.byte_size = 4,
// 		.gpkt_offset = 188,
// 	},
// 	{
// 		/* AR47 */
// 		.idx = (uint32_t) 48,
// 		.regno = 0x12f,
// 		.byte_size = 4,
// 		.gpkt_offset = 192,
// 	},
// 	{
// 		/* AR48 */
// 		.idx = (uint32_t) 49,
// 		.regno = 0x130,
// 		.byte_size = 4,
// 		.gpkt_offset = 196,
// 	},
// 	{
// 		/* AR49 */
// 		.idx = (uint32_t) 50,
// 		.regno = 0x131,
// 		.byte_size = 4,
// 		.gpkt_offset = 200,
// 	},
// 	{
// 		/* AR50 */
// 		.idx = (uint32_t) 51,
// 		.regno = 0x132,
// 		.byte_size = 4,
// 		.gpkt_offset = 204,
// 	},
// 	{
// 		/* AR51 */
// 		.idx = (uint32_t) 52,
// 		.regno = 0x133,
// 		.byte_size = 4,
// 		.gpkt_offset = 208,
// 	},
// 	{
// 		/* AR52 */
// 		.idx = (uint32_t) 53,
// 		.regno = 0x134,
// 		.byte_size = 4,
// 		.gpkt_offset = 212,
// 	},
// 	{
// 		/* AR53 */
// 		.idx = (uint32_t) 54,
// 		.regno = 0x135,
// 		.byte_size = 4,
// 		.gpkt_offset = 216,
// 	},
// 	{
// 		/* AR54 */
// 		.idx = (uint32_t) 55,
// 		.regno = 0x136,
// 		.byte_size = 4,
// 		.gpkt_offset = 220,
// 	},
// 	{
// 		/* AR55 */
// 		.idx = (uint32_t) 56,
// 		.regno = 0x137,
// 		.byte_size = 4,
// 		.gpkt_offset = 224,
// 	},
// 	{
// 		/* AR56 */
// 		.idx = (uint32_t) 57,
// 		.regno = 0x138,
// 		.byte_size = 4,
// 		.gpkt_offset = 228,
// 	},
// 	{
// 		/* AR57 */
// 		.idx = (uint32_t) 58,
// 		.regno = 0x139,
// 		.byte_size = 4,
// 		.gpkt_offset = 232,
// 	},
// 	{
// 		/* AR58 */
// 		.idx = (uint32_t) 59,
// 		.regno = 0x13a,
// 		.byte_size = 4,
// 		.gpkt_offset = 236,
// 	},
// 	{
// 		/* AR59 */
// 		.idx = (uint32_t) 60,
// 		.regno = 0x13b,
// 		.byte_size = 4,
// 		.gpkt_offset = 240,
// 	},
// 	{
// 		/* AR60 */
// 		.idx = (uint32_t) 61,
// 		.regno = 0x13c,
// 		.byte_size = 4,
// 		.gpkt_offset = 244,
// 	},
// 	{
// 		/* AR61 */
// 		.idx = (uint32_t) 62,
// 		.regno = 0x13d,
// 		.byte_size = 4,
// 		.gpkt_offset = 248,
// 	},
// 	{
// 		/* AR62 */
// 		.idx = (uint32_t) 63,
// 		.regno = 0x13e,
// 		.byte_size = 4,
// 		.gpkt_offset = 252,
// 	},
// 	{
// 		/* AR63 */
// 		.idx = (uint32_t) 64,
// 		.regno = 0x13f,
// 		.byte_size = 4,
// 		.gpkt_offset = 256,
// 	},
// 	{
// 		/* LBEG */
// 		.idx = (uint32_t) 65,
// 		.regno = 0x0200,
// 		.byte_size = 4,
// 		.gpkt_offset = 260,
// 		.stack_offset = BSA_LBEG_OFF,
// 	},
// 	{
// 		/* LEND */
// 		.idx = (uint32_t) 66,
// 		.regno = 0x0201,
// 		.byte_size = 4,
// 		.gpkt_offset = 264,
// 		.stack_offset = BSA_LEND_OFF,
// 	},
// 	{
// 		/* LCOUNT */
// 		.idx = (uint32_t) 67,
// 		.regno = 0x0202,
// 		.byte_size = 4,
// 		.gpkt_offset = 268,
// 		.stack_offset = BSA_LCOUNT_OFF,
// 	},
// 	{
// 		/* SAR */
// 		.idx = (uint32_t) 68,
// 		.regno = 0x0203,
// 		.byte_size = 4,
// 		.gpkt_offset = 272,
// 		.stack_offset = BSA_SAR_OFF,
// 	},
// 	{
// 		/* WINDOWBASE */
// 		.idx = (uint32_t) 70,
// 		.regno = 0x0248,
// 		.byte_size = 4,
// 		.gpkt_offset = 280,
// 		.is_read_only = 1,
// 	},
// 	{
// 		/* WINDOWSTART */
// 		.idx = (uint32_t) 71,
// 		.regno = 0x0249,
// 		.byte_size = 4,
// 		.gpkt_offset = 284,
// 		.is_read_only = 1,
// 	},
// 	{
// 		/* PS */
// 		.idx = (uint32_t) 74,
// 		.regno = 0x02E6,
// 		.byte_size = 4,
// 		.gpkt_offset = 296,
// 		.stack_offset = BSA_PS_OFF,
// 	},
// 	{
// 		/* THREADPTR */
// 		.idx = (uint32_t) 75,
// 		.regno = 0x03E7,
// 		.byte_size = 4,
// 		.gpkt_offset = 300,
// #ifdef CONFIG_THREAD_LOCAL_STORAGE
// 		/* Only saved in stack if TLS is enabled */
// 		.stack_offset = BSA_THREADPTR_OFF,
// #endif
// 	},
// 	{
// 		/* SCOMPARE1 */
// 		.idx = (uint32_t) 77,
// 		.regno = 0x020C,
// 		.byte_size = 4,
// 		.gpkt_offset = 308,
// 		.stack_offset = BSA_SCOMPARE1_OFF,
// 	},
// 	{
// 		/* EXCCAUSE */
// 		.idx = (uint32_t) 148,
// 		.regno = 0x02E8,
// 		.byte_size = 4,
// 		.gpkt_offset = 592,
// 		.stack_offset = BSA_EXCCAUSE_OFF,
// 	},
// 	{
// 		/* DEBUGCAUSE */
// 		.idx = (uint32_t) 149,
// 		.regno = 0x02E9,
// 		.byte_size = 4,
// 		.gpkt_offset = 596,
// 	},
// 	{
// 		/* EXCVADDR */
// 		.idx = (uint32_t) 154,
// 		.regno = 0x02EE,
// 		.byte_size = 4,
// 		.gpkt_offset = 616,
// 	},
// 	{
// 		/* A0 */
// 		.idx = (uint32_t) 158,
// 		.regno = 0x0000,
// 		.byte_size = 4,
// 		.gpkt_offset = 632,
// 		.stack_offset = BSA_A0_OFF,
// 	},
// 	{
// 		/* A1 */
// 		.idx = (uint32_t) 159,
// 		.regno = 0x0001,
// 		.byte_size = 4,
// 		.gpkt_offset = 636,
// 	},
// 	{
// 		/* A2 */
// 		.idx = (uint32_t) 160,
// 		.regno = 0x0002,
// 		.byte_size = 4,
// 		.gpkt_offset = 640,
// 		.stack_offset = BSA_A2_OFF,
// 	},
// 	{
// 		/* A3 */
// 		.idx = (uint32_t) 161,
// 		.regno = 0x0003,
// 		.byte_size = 4,
// 		.gpkt_offset = 644,
// 		.stack_offset = BSA_A3_OFF,
// 	},
// 	{
// 		/* A4 */
// 		.idx = (uint32_t) 162,
// 		.regno = 0x0004,
// 		.byte_size = 4,
// 		.gpkt_offset = 648,
// 		.stack_offset = -16,
// 	},
// 	{
// 		/* A5 */
// 		.idx = (uint32_t) 163,
// 		.regno = 0x0005,
// 		.byte_size = 4,
// 		.gpkt_offset = 652,
// 		.stack_offset = -12,
// 	},
// 	{
// 		/* A6 */
// 		.idx = (uint32_t) 164,
// 		.regno = 0x0006,
// 		.byte_size = 4,
// 		.gpkt_offset = 656,
// 		.stack_offset = -8,
// 	},
// 	{
// 		/* A7 */
// 		.idx = (uint32_t) 165,
// 		.regno = 0x0007,
// 		.byte_size = 4,
// 		.gpkt_offset = 660,
// 		.stack_offset = -4,
// 	},
// 	{
// 		/* A8 */
// 		.idx = (uint32_t) 166,
// 		.regno = 0x0008,
// 		.byte_size = 4,
// 		.gpkt_offset = 664,
// 		.stack_offset = -32,
// 	},
// 	{
// 		/* A9 */
// 		.idx = (uint32_t) 167,
// 		.regno = 0x0009,
// 		.byte_size = 4,
// 		.gpkt_offset = 668,
// 		.stack_offset = -28,
// 	},
// 	{
// 		/* A10 */
// 		.idx = (uint32_t) 168,
// 		.regno = 0x000A,
// 		.byte_size = 4,
// 		.gpkt_offset = 672,
// 		.stack_offset = -24,
// 	},
// 	{
// 		/* A11 */
// 		.idx = (uint32_t) 169,
// 		.regno = 0x000B,
// 		.byte_size = 4,
// 		.gpkt_offset = 676,
// 		.stack_offset = -20,
// 	},
// 	{
// 		/* A12 */
// 		.idx = (uint32_t) 170,
// 		.regno = 0x000C,
// 		.byte_size = 4,
// 		.gpkt_offset = 680,
// 		.stack_offset = -48,
// 	},
// 	{
// 		/* A13 */
// 		.idx = (uint32_t) 171,
// 		.regno = 0x000D,
// 		.byte_size = 4,
// 		.gpkt_offset = 684,
// 		.stack_offset = -44,
// 	},
// 	{
// 		/* A14 */
// 		.idx = (uint32_t) 172,
// 		.regno = 0x000E,
// 		.byte_size = 4,
// 		.gpkt_offset = 688,
// 		.stack_offset = -40,
// 	},
// 	{
// 		/* A15 */
// 		.idx = (uint32_t) 173,
// 		.regno = 0x000F,
// 		.byte_size = 4,
// 		.gpkt_offset = 692,
// 		.stack_offset = -36,
// 	},
// };

struct gdb_ctx xtensa_gdb_ctx = {
	.regs = gdb_reg_list,
	.num_regs = ARRAY_SIZE(gdb_reg_list),
};
