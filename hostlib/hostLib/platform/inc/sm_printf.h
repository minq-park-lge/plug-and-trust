/*
 *
 * Copyright 2016-2020,2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SM_PRINTF_H_
#define _SM_PRINTF_H_
#include <stdint.h>
#include <stdio.h>
#include "sm_types.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "se05x_platform.h"

#if AX_EMBEDDED \
    && (!defined (__MBED__))
#   include "fsl_debug_console.h"
#else
#   define PRINTF se05x_platform_printf
#   define SCANF
#   define PUTCHAR
#   define GETCHAR
#endif

#define CONSOLE         (0x01)
#define MEMORY          (0x02)
#define LOGFILE         (0x04)
#define DBGOUT_ALL      (CONSOLE|MEMORY|LOGFILE)

#define DBGOUT          CONSOLE

void sm_printf(unsigned char dev, const char * format, ...);
void AssertZeroAllocation(void);

#ifdef __cplusplus
}
#endif
#endif // _SM_PRINTF_H_
