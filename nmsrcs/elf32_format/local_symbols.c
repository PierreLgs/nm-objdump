/*
** local_symbols.c for nm in /home/catuss_a//Desktop/nmobjdump
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Thu Mar 10 23:08:38 2011 axel catusse
** Last update Sun Mar 13 22:36:44 2011 axel catusse
*/

#include "nm.h"

static t_flags		localflags[] = {
  { STT_NOTYPE, SHT_PROGBITS, 0, 'n' },
  { STT_NOTYPE, SHT_PROGBITS, 2, 'r' },
  { STT_NOTYPE, SHT_PROGBITS, 50, 'r' },
  { STT_NOTYPE, SHT_PROGBITS, 3, 'd' },
  { STT_NOTYPE, SHT_PROGBITS, 6, 't' },
  { STT_NOTYPE, SHT_NOBITS, 3, 'b' },
  { STT_OBJECT, SHT_DYNAMIC, 3, 'd' },
  { STT_OBJECT, SHT_NOTE, 2, 'r' },
  { STT_OBJECT, SHT_FINI_ARRAY, 3, 't' },
  { STT_OBJECT, SHT_INIT_ARRAY, 3, 't' },
  { STT_OBJECT, SHT_PROGBITS, 0, 'n' },
  { STT_OBJECT, SHT_PROGBITS, 2, 'r' },
  { STT_OBJECT, SHT_PROGBITS, 50, 'r' },
  { STT_OBJECT, SHT_PROGBITS, 3, 'd' },
  { STT_OBJECT, SHT_NOBITS, 3, 'b' },
  { STT_FUNC, SHT_PROGBITS, 6, 't' },
  { STT_TLS, SHT_PROGBITS, 1027, 'd' },
  { STT_TLS, SHT_NOBITS, 1027, 'b' },
  { STT_LOOS, SHT_PROGBITS, 6, 'i' }
};

char			local_symbol(Elf32_Sym *symtab,
				     Elf32_Shdr *shdr)
{
  unsigned int		i;
  static unsigned int	lsize = sizeof(localflags) / sizeof(*localflags);

  if (ELF32_ST_BIND(symtab->st_info) == STB_LOCAL)
    {
      i = -1;
      while (++i < lsize)
	{
	  if (ELF32_ST_TYPE(symtab->st_info) == localflags[i].stt)
	    if (shdr[symtab->st_shndx].sh_type == localflags[i].sh_type)
	      if (shdr[symtab->st_shndx].sh_flags == localflags[i].sh_flags)
		return (localflags[i].type);
	}
    }
  return (NO_TYPE);
}
