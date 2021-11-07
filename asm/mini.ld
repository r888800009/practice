SECTIONS
{
  /DISCARD/ : {
    *(.comment);
    *(.note.gnu.property);
    *(.eh_frame);
  }

/*
原因是因為會 alignment 0x1000，那如果有辦法塞到前面的話就可以減少大小
$ objdump mini -x

mini:     file format elf64-x86-64
mini
architecture: i386:x86-64, flags 0x00000102:
EXEC_P, D_PAGED
start address 0x00000000000100b0

Program Header:
    LOAD off    0x0000000000000000 vaddr 0x0000000000010000 paddr 0x000000000000f000 align 2**12
         filesz 0x00000000000000b0 memsz 0x00000000000000b0 flags r--
    LOAD off    0x00000000000000b0 vaddr 0x00000000000100b0 paddr 0x00000000000100b0 align 2**12
         filesz 0x0000000000000042 memsz 0x0000000000000042 flags r-x

另外一點直得注意，就是 ELF 在載入的時候，是一個個 page 下去載入的，
因此這個檔案在掛 debugger 可以看到 0x10000 的地方其實和 xxd dump 出來的東西是一樣的
*/

  . = 0x100b0;
  .text :  { *(.text) }
}
