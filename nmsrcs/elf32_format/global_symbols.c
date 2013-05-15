/*
** global_symbols.c for nm in /home/catuss_a//Desktop/nmobjdump
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Mar 10 22:58:43 2011 axel catusse
** Last update Sun Mar 13 22:37:03 2011 axel catusse
*/

#include <elf.h>
#include "nm.h"

static t_flags		globflags[] = {
  { STT_NOTYPE, SHT_PROGBITS, 3, 'D' },
  { STT_OBJECT, SHT_PROGBITS, 3, 'D' },
  { STT_OBJECT, SHT_PROGBITS, 2, 'R' },
  { STT_OBJECT, SHT_NOBITS, 3, 'B' },
  { STT_FUNC, SHT_NULL, 0, 'U' },
  { STT_FUNC, SHT_PROGBITS, 6, 'T' },
  { STT_LOOS, SHT_PROGBITS, 6, 'i' }
};

char			global_symbol(Elf32_Sym *symtab,
				      Elf32_Shdr *shdr)
{
  unsigned int		i;
  static unsigned int	gsize = sizeof(globflags) / sizeof(*globflags);

  if (ELF32_ST_BIND(symtab->st_info) == STB_GLOBAL)
    {
      i = -1;
      while (++i < gsize)
	{
	  if (ELF32_ST_TYPE(symtab->st_info) == globflags[i].stt)
	    if (shdr[symtab->st_shndx].sh_type == globflags[i].sh_type)
	      if (shdr[symtab->st_shndx].sh_flags == globflags[i].sh_flags)
		return (globflags[i].type);
	}
      return ('U');
    }
  return (NO_TYPE);
}
