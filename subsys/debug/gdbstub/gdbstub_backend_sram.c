/*
 * Copyright (c) 2020 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0

This implements a backend for Zephyr's GDB stub. Since a serial connection is
not available, we need to implement a GDB communication system that uses an
alternative medium. This uses two circular buffers in shared SRAM within the
DEBUG region, similar to the closed-source FW implementation. The SOF kernel
driver will expose a DebugFS file which allows the GDB client to communicate
with Zephyr's stub through these buffers. To allow the setup sequence to proceed
without interference from the GDB stub, it is not activated until a special IPC
command is received. The SOF driver automatically sends this command when the
DebugFS file is accessed. In the future, this may be configurable to allow for
early-boot debugging. To enable GDB, the CONFIG_GDBSTUB kconfig option must be
enabled.
*/

#include "adsp_memory.h"
#include "ringbuffer.h"
#include <stddef.h>
#include <string.h>

#define BUFFER_OFFSET 0x120

volatile struct ring * const rx = (void *)HP_SRAM_WIN3_BASE;
volatile struct ring * const tx = (void *)(HP_SRAM_WIN3_BASE + sizeof(struct ring));

void z_gdb_backend_init(void)
{
	rx->head = rx->tail = 0x00;
	tx->head = tx->tail = 0x00;

}

void z_gdb_putchar(unsigned char c)
{
	while (!ring_have_space(tx)) {
		xthal_dcache_region_invalidate((char *)&tx->tail, 1);
		xthal_dcache_region_writeback((char *)&tx->head, 1);
	}
	tx->data[tx->head] = c;
	tx->head = ring_next_head(tx);
	xthal_dcache_region_writeback((char *)&tx->head, 1);
	xthal_dcache_region_writeback((char *)&tx->data, RING_SIZE);
}

unsigned char z_gdb_getchar(void)
{
	unsigned char v;
	while (!ring_have_data(rx)) {
		xthal_dcache_region_invalidate((char *)&rx->head, 1);
		xthal_dcache_region_writeback((char *)&rx->tail, 1);
	}
	xthal_dcache_region_invalidate((char *)&rx->data, RING_SIZE);
	v = rx->data[rx->tail];
	rx->tail = ring_next_tail(rx);
	return v;
}