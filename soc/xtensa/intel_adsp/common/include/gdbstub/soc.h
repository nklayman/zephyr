/*
 * Copyright (c) 2021 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

// TODO: Validate this
// Just copied from ESP32, not sure if it's correct

#include <inttypes.h>

#ifndef SOC_XTENSA_ADSP_GDBSTUB_H_
#define SOC_XTENSA_ADSP_GDBSTUB_H_

#ifndef ZEPHYR_INCLUDE_ARCH_XTENSA_GDBSTUB_SYS_H_
#error "Must be included after arch/xtensa/gdbstub.h"
#endif /* ZEPHYR_INCLUDE_ARCH_XTENSA_GDBSTUB_SYS_H_ */

#define SOC_GDB_GPKT_BIN_SIZE		420
#define SOC_GDB_GPKT_HEX_SIZE		(SOC_GDB_GPKT_BIN_SIZE * 2)

#define SOC_GDB_REGNO_A1		0x0001

#endif /* SOC_XTENSA_ADSP_GDBSTUB_H_ */
