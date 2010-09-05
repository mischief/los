#ifndef MULTIBOOT_H
#define MULTIBOOT_H

#define MULTIBOOT_SEARCH		8192
#define MULTIBOOT_HEADER_MAGIC		0x1BADB002
#define MULTIBOOT_BOOTLOADER_MAGIC	0x2BADBOO2
#define MULTIBOOT_UNSUPPORTED		0x0000fffc
#define MULTIBOOT_MOD_ALIGN		0x00001000
#define MULTIBOOT_INFO_ALIGN		0x00000004
#define MULTIBOOT_PAGE_ALIGN		0x00000001
#define MULTIBOOT_MEMORY_INFO		0x00000002
#define MULTIBOOT_VIDEO_MODE		0x00000004
#define MULTIBOOT_AOUT_KLUDGE		0x00010000
#define MULTIBOOT_INFO_MEMORY		0x00000001
#define MULTIBOOT_INFO_BOOTDEV		0x00000002
#define MULTIBOOT_INFO_CMDLINE		0x00000004
#define MULTIBOOT_INFO_MODS		0x00000008
#define MULTIBOOT_INFO_AOUT_SYMS	0x00000010
#define MULTIBOOT_INFO_ELF_SHDR		0x00000020
#define MULTIBOOT_INFO_MEM_MAP		0x00000040
#define MULTIBOOT_INFO_DRIVE_INFO	0x00000080
#define MULTIBOOT_INFO_CONFIG_TABLE	0x00000100
#define MULTIBOOT_INFO_BOOT_LOADER_NAME 0x00000200
#define MULTIBOOT_INFO_APM_TABLE	0x00000400
#define MULTIBOOT_INFO_VIDEO_INFO	0x00000800

#ifndef ASM_FILE

typedef unsigned short  multiboot_uint16_t;
typedef unsigned int    multiboot_uint32_t;
typedef unsigned long   multiboot_uint64_t;

struct multiboot_header {
  multiboot_uint32_t magic;
  multiboot_uint32_t flags;
  multiboot_uint32_t checksum;
  
  multiboot_uint32_t header_addr;
  multiboot_uint32_t load_addr;
  multiboot_uint32_t load_end_addr;
  multiboot_uint32_t bss_end_addr;
  multiboot_uint32_t entry_addr;
  
  multiboot_uint32_t mode_type;
  multiboot_uint32_t width;
  multiboot_uint32_t height;
  multiboot_uint32_t depth;
};

struct multiboot_aout_symbol_table {
  multiboot_uint32_t tabsize;
  multiboot_uint32_t strsize;
  multiboot_uint32_t addr;
  multiboot_uint32_t reserved;
};

typedef struct multiboot_aout_symbol_table multiboot_aout_symbol_table_t;

struct multiboot_elf_section_header_table {
  multiboot_uint32_t num;
  multiboot_uint32_t size;
  multiboot_uint32_t addr;
  multiboot_uint32_t shndx;
};

typedef struct multiboot_elf_section_header_table multiboot_elf_section_header_table_t;

struct multiboot_info {
  multiboot_uint32_t flags;
  multiboot_uint32_t mem_lower;
  multiboot_uint32_t mem_upper;
  multiboot_uint32_t boot_device;
  multiboot_uint32_t cmdline;
  multiboot_uint32_t mods_count;
  multiboot_uint32_t mods_addr;
  
  union {
    multiboot_aout_symbol_table_t aout_sym;
    multiboot_elf_section_header_table_t elf_sec;
  } u;
  
  multiboot_uint32_t mmap_length;
  multiboot_uint32_t mmap_addr;
  multiboot_uint32_t drives_length;
  multiboot_uint32_t drives_addr;
  multiboot_uint32_t config_table;
  multiboot_uint32_t boot_loader_name;
  multiboot_uint32_t apm_table;
  
  multiboot_uint32_t vbe_control_info;
  multiboot_uint32_t vbe_mode_info;
  multiboot_uint16_t vbe_mode;
  multiboot_uint16_t vbe_interface_seg;
  multiboot_uint16_t vbe_interface_off;
  multiboot_uint16_t vbe_interface_len;
};

typedef struct multiboot_info multiboot_info_t;

struct multiboot_mmap_entry {
  multiboot_uint32_t size;
  multiboot_uint64_t addr;
  multiboot_uint64_t len;

  /* why is this in the middle of the struct? */
  #define MULTIBOOT_MEMORY_AVAILABLE	1
  #define MULTIBOOT_MEMORY_RESERVED	2
  
  multiboot_uint32_t type;
  
};

typedef struct multiboot_mmap_entry multiboot_memory_map_t;

struct multiboot_mod_list {
  multiboot_uint32_t mod_start;
  multiboot_uint32_t mod_end;
  multiboot_uint32_t cmdline;
  multiboot_uint32_t pad;
};

typedef struct multiboot_mod_list multiboot_module_t;

#endif /* !ASM_FILE */

#endif /* !MULTIBOOT_H */
