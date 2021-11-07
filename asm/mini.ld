SECTIONS
{
  /DISCARD/ : {
    *(.comment);
    *(.note.gnu.property);
    *(.eh_frame);
  }

  /*
   原因是因為會 alignment 0x1000，那如果有辦法塞到前面的話就可以減少大小
  */

  . = 0x100b0;
  .text :  { *(.text) }
}
