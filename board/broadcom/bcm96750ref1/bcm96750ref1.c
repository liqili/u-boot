// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2020 Philippe Reynes <philippe.reynes@softathome.com>
 */

#include <common.h>
#include <fdtdec.h>
#include <linux/io.h>
#include <cpu_func.h>

int board_init(void)
{
	return 0;
}

int dram_init(void)
{
	if (fdtdec_setup_mem_size_base() != 0)
		printf("fdtdec_setup_mem_size_base() has failed\n");

	return 0;
}

int dram_init_banksize(void)
{
	fdtdec_setup_memory_banksize();

	return 0;
}

int print_cpuinfo(void)
{
	return 0;
}

void enable_caches(void)
{
#if !CONFIG_IS_ENABLED(SYS_ICACHE_OFF)
	icache_enable();
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
	dcache_enable();
#endif
}
