SECTIONS
{
  /DISCARD/ : {
    *(.comment);
    *(.note.gnu.property);
    *(.eh_frame);
  }

  . = 0x100f0;
  .text :  { *(.text) }
}
