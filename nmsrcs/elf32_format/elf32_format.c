/*
** elf32_format.c for nm in /home/catuss_a//Desktop/nmobjdump
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Mar 11 00:07:40 2011 axel catusse
** Last update Sat Mar 12 16:41:53 2011 axel catusse
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nm.h"

static Elf32_Shdr	*set_sym_tab(Elf32_Shdr **strsymsection,
				     char *strtab,
				     Elf32_Ehdr *elf,
				     Elf32_Shdr *shdr)
{
  int			i;
  Elf32_Shdr		*symsection;

  symsection = NULL;
  *strsymsection = NULL;
  i = -1;
  while (++i < elf->e_shnum)
    {
      if (shdr[i].sh_size)
	{
	  if (!strcmp(&strtab[shdr[i].sh_name], ".symtab"))
	    symsection = (Elf32_Shdr*)&shdr[i];
	  if (!strcmp(&strtab[shdr[i].sh_name], ".strtab"))
	    *strsymsection = (Elf32_Shdr*)&shdr[i];
	}
    }
  return (symsection);
}

static int		check_elf_format(Elf32_Ehdr *elf, char *path)
{
  if (elf->e_ident[EI_MAG0] != ELFMAG0
      || elf->e_ident[EI_MAG1] != ELFMAG1
      || elf->e_ident[EI_MAG2] != ELFMAG2
      || elf->e_ident[EI_MAG3] != ELFMAG3
      || (elf->e_type != ET_EXEC && elf->e_type
	  != ET_REL && elf->e_type != ET_DYN))
    {
      fprintf(stderr, "nm: %s: File format not recognized\n", path);
      return (-1);
    }
  return (1);
}

char *test;

void			elf32_format(void *data, char *filename, int ac)
{
  Elf32_Ehdr		*elf;
  Elf32_Shdr		*shdr;
  Elf32_Sym		*symtab;
  Elf32_Shdr		*strsymsection;
  Elf32_Shdr		*symsection;
  char			*strsymtab;
  char			*strtab;

  test = filename;
  elf = (Elf32_Ehdr*)data;
  if (check_elf_format(elf, filename) == -1)
    return ;
  shdr = (Elf32_Shdr*)(data + elf->e_shoff);
  strtab = (char*)(data + shdr[elf->e_shstrndx].sh_offset);
  symsection = set_sym_tab(&strsymsection, strtab, elf, shdr);
  if (ac > 2)
    printf("\n%s:\n", filename);
  if (strsymsection == NULL || symsection == NULL)
    {
      fprintf(stderr, "nm: %s: no symbols\n", filename);
      return ;
    }
  symtab = (Elf32_Sym*)((char*)data + symsection->sh_offset);
  strsymtab = (char*)((char*)data + strsymsection->sh_offset);
  print_sym(symsection, symtab, strsymtab, shdr);
}
