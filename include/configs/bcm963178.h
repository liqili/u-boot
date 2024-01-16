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

#define CONFIG_ENV_CALLBACK_LIST_STATIC "boardid:boardid,voiceboardid:voiceboardid,"

/*
 * 63178
 */

#define CONFIG_SYS_INIT_STD_32K_ADDR    0xfff80000 
#define CONFIG_SYS_SEC_CRED_ADDR        (CONFIG_SYS_INIT_STD_32K_ADDR + 0x7000)
/* RAM */
#define PHYS_SDRAM_1			0x00000000UL
#define PHYS_SDRAM_1_SIZE		(2UL * SZ_1G) /* Maximum possible bnk 0 size */
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1

/* U-Boot */
#if defined(CONFIG_TPL_BUILD)
/* CONFIG_TPL_TEXT_BASE=0x00020000 */
/* #define CONFIG_SPL_MAX_SIZE		0x00100000 */
#define CONFIG_SPL_MAX_SIZE		0x00040000
#define CONFIG_SPL_BSS_START_ADDR	0x00120000
#define CONFIG_SPL_BSS_MAX_SIZE		0x8000
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_TPL_TEXT_BASE + SZ_1M)
#define CONFIG_SYS_PAGETBL_BASE		CONFIG_SYS_INIT_SP_ADDR
#define CONFIG_SYS_PAGETBL_SIZE		0x00004000

#define CONFIG_SYS_MALLOC_SIMPLE
#elif defined(CONFIG_SPL_BUILD)
#define CONFIG_SYS_INIT_RAM_ADDR	0x84200000
#define CONFIG_SYS_INIT_RAM_SIZE	0x000a0000

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)


/* CONFIG_SPL_TEXT_BASE=0x80820000 */
#define CONFIG_SPL_MAX_SIZE		0x00040000
//#define CONFIG_SPL_BSS_START_ADDR	0x84240000
//#define CONFIG_SPL_BSS_MAX_SIZE		0x8000
#define CONFIG_SYS_PAGETBL_BASE		0x84290000
#define CONFIG_SYS_PAGETBL_SIZE		0x4000

#define CONFIG_SYS_MALLOC_SIMPLE

#else
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_TEXT_BASE + SZ_16M)
#endif

#define CONFIG_SYS_LOAD_ADDR		(CONFIG_TEXT_BASE)

#define CONFIG_SKIP_LOWLEVEL_INIT 1

#define CONFIG_SPL_LOAD_FIT_ADDRESS	(CONFIG_TPL_TEXT_BASE + 0x2000000)

#ifdef CONFIG_NAND
#define CONFIG_SYS_NAND_BASE            0xff801800
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_SELF_INIT 1
#define CONFIG_SYS_NAND_ONFI_DETECTION

/* dummy definition to make spl nand image loader happy */
#define CONFIG_SYS_NAND_U_BOOT_OFFS	0x100000
#define CONFIG_SYS_NAND_U_BOOT_SIZE	0x100000
#define CONFIG_SYS_NAND_U_BOOT_DST	0x00100000
#define CONFIG_SYS_NAND_U_BOOT_START	CONFIG_SYS_NAND_U_BOOT_DST
#define CONFIG_SYS_NAND_BLOCK_SIZE	(256*1024) // max possible size

#define CONFIG_TPL_UBI
#define CONFIG_SPL_UBI_MAX_VOL_LEBS	256
#define CONFIG_SPL_UBI_MAX_PEB_SIZE	CONFIG_SYS_NAND_BLOCK_SIZE
#define CONFIG_SPL_UBI_IMG_OFFSET	0x100000
#define CONFIG_SPL_UBI_MAX_PEBS 	4096
#define CONFIG_SPL_UBI_VOL_IDS		8
#define CONFIG_SPL_UBI_LOAD_MONITOR_ID	0
#define CONFIG_SPL_UBI_PEB_OFFSET	4
#define CONFIG_SPL_UBI_VID_OFFSET	512
#define CONFIG_SPL_UBI_LEB_START	2048
#define CONFIG_SPL_UBI_INFO_ADDR	(CONFIG_SPL_LOAD_FIT_ADDRESS - 0x1000000)
#endif /* CONFIG_NAND */

// #define CONFIG_SYS_MTDPARTS_RUNTIME
#define CONFIG_JFFS2_NAND 1

/*
 * bcm963178
 */
#define CONFIG_ARCH_CPU_INIT
#define COUNTER_FREQUENCY       50000000
#define CONFIG_ENV_SIZE		(8 * 1024)

#define CONFIG_SYS_BOOTMAPSZ	(128 << 20)
#define CONFIG_SYS_FDT_PAD	0x80000
