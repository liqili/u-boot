/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2020 Philippe Reynes <philippe.reynes@softathome.com>
 */

#include <linux/sizes.h>

/*
 * common
 */

/* UART */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200, \
					  230400, 500000, 1500000 }
/* Memory usage */
#define CONFIG_SYS_MAXARGS		24
#define CONFIG_SYS_MALLOC_LEN		(1024 * 1024 * 32)
#define CONFIG_SYS_BOOTM_LEN		(32 * 1024 * 1024)

/*
 * 6750
 */

/* RAM */
#define PHYS_SDRAM_1			0x00000000UL
#define PHYS_SDRAM_1_SIZE		(1UL * SZ_512M) /* Maximum possible bnk 0 size */
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1

/* U-Boot */
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_TEXT_BASE + SZ_16M)
#define CONFIG_SYS_LOAD_ADDR		CONFIG_TEXT_BASE

#define CONFIG_SKIP_LOWLEVEL_INIT 1

// #ifdef CONFIG_MTD_RAW_NAND
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_SELF_INIT 1
#define CONFIG_SYS_NAND_ONFI_DETECTION
// #endif /* CONFIG_MTD_RAW_NAND */

/* U-Boot */

#define CFG_SYS_INIT_RAM_ADDR	0x84200000
#define CFG_SYS_INIT_RAM_SIZE	0x000a0000

#define CFG_SYS_INIT_SP_OFFSET \
	(CFG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CFG_SYS_INIT_SP_ADDR \
	(CFG_SYS_INIT_RAM_ADDR + CFG_SYS_INIT_SP_OFFSET)


/*
 * 96750ref1
 */
#define CONFIG_ARCH_CPU_INIT
#define COUNTER_FREQUENCY       50000000
#define CONFIG_ENV_SIZE		(8 * 1024)

#define CONFIG_SYS_BOOTMAPSZ	(128 << 20)
#define CONFIG_SYS_FDT_PAD	0x80000