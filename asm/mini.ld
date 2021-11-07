SECTIONS
{
  /DISCARD/ : {
    *(.comment);
    *(.note.gnu.property);
    *(.eh_frame);
  }

  . = 0x100b0;
  .text :  { *(.text) }
}
