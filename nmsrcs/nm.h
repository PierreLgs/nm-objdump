/*
** nm.h for nm in /home/catuss_a//Desktop/nmobjdump
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Mon Mar  7 18:01:38 2011 axel catusse
** Last update Sun Mar 13 22:38:24 2011 axel catusse
*/

#ifndef _NM_H_
# define _NM_H_

#include <elf.h>

#define NO_TYPE '?'

extern char *test;

int			xaccess(char *filename);
int			xopen(char *filename);
void			*xmmap(int fd, char * filename, unsigned int size);

/*
** --------------------------------------
** -  STRUCTURE ELF32_FORMAT		-
** --------------------------------------
*/
typedef struct	s_flags
{
  int		stt;
  Elf32_Word	sh_type;
  Elf32_Word	sh_flags;
  char		type;
}		t_flags;

/*
** --------------------------------------
** -  PROTOTYPE ELF32_FORMAT FUNCTIONS  -
** --------------------------------------
*/
char			global_symbol(Elf32_Sym *symtab,
				      Elf32_Shdr *shdr);
char			local_symbol(Elf32_Sym *symtab,
				     Elf32_Shdr *shdr);
char			weak_symbol(Elf32_Sym *symtab);
char			get_flag(Elf32_Sym *symtab,
				 Elf32_Shdr *shdr);
void			elf32_format(void *data, char *filename, int ac);
void			print_sym(Elf32_Shdr *symsection,
				  Elf32_Sym *symtab,
				  char *strsymtab,
				  Elf32_Shdr *shdr);
void			sort_by_ascii(Elf32_Sym **symtab_cpy,
				      int begin,
				      int end,
				      char *strsymtab);
void			print_sym(Elf32_Shdr *symsection,
				  Elf32_Sym *symtab,
				  char *strsymtab,
				  Elf32_Shdr *shdr);

/*
** --------------------------------------
** -  PROTOTYPE ELF64_FORMAT FUNCTIONS  -
** --------------------------------------
*/

void			elf64_format(void *data, char *filename, int ac);
char			global_symbol64(Elf64_Sym *symtab,
 					Elf64_Shdr *shdr);
char			local_symbol64(Elf64_Sym *symtab,
				     Elf64_Shdr *shdr);
char			weak_symbol64(Elf64_Sym *symtab);
char			get_flag64(Elf64_Sym *symtab,
				 Elf64_Shdr *shdr);
void			elf64_format64(void *data, char *filename, int ac);
void			print_sym64(Elf64_Shdr *symsection,
				  Elf64_Sym *symtab,
				  char *strsymtab,
				  Elf64_Shdr *shdr);
void			sort_by_ascii64(Elf64_Sym **symtab_cpy,
				      int begin,
				      int end,
				      char *strsymtab);
void			print_sym64(Elf64_Shdr *symsection,
				    Elf64_Sym *symtab,
				    char *strsymtab,
				    Elf64_Shdr *shdr);

#endif /* !_NM_H_ */
