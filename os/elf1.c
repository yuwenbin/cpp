#include <elf.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc,char **argv)
{

	unsigned char *p;
	Elf64_Ehdr *elf_header;
	int elffd;
	int readbytes;
	unsigned char HBuf[64];

	if(argc<2)
	{
		perror("Usage: elfr [filename]");
		exit(-1);
	}

	elffd = open(argv[1],O_RDWR,S_IRUSR);

	readbytes = read(elffd,HBuf,64);
	if(readbytes != 64)
	{
		perror("File format error!");
		exit(-1);
	}
	printf("ELF Header:\n");
	hexshow(HBuf,64,0);
	elf_header = malloc(64);
	memcpy(elf_header,HBuf,64);
	printf("\nMagic number: ");
	hexshow(elf_header->e_ident,16,0);

	printf("\nObject file type:");
	hexshow(&elf_header->e_type,2,1);
	printf("\nArchitecture:");
	hexshow(&elf_header->e_machine,2,1);
	printf("\nObject file version:");
	hexshow(&elf_header->e_version,4,1);
	printf("\nEntry point virtual address:");
	hexshow(&elf_header->e_entry,8,1);
	printf("\nProgram header table file offset:");
	hexshow(&elf_header->e_phoff,8,1);
	printf("\nSection header table file offset:");
	hexshow(&elf_header->e_shoff,8,1);
	printf("\nProcessor-specific flags:");
	hexshow(&elf_header->e_flags,4,1);
	printf("\nELF header size in bytes:");
	hexshow(&elf_header->e_ehsize,2,1);
	printf("\nProgram header table entry count:");
	hexshow(&elf_header->e_phentsize,2,1);
	printf("\nProgram header table entry size:");
	hexshow(&elf_header->e_phnum,2,1);
	printf("\nSection header table entry size:");
	hexshow(&elf_header->e_shentsize,2,1);
	printf("\nSection header table entry count:");
	hexshow(&elf_header->e_shnum,2,1);
	printf("\nSection header string table index:");
	hexshow(&elf_header->e_shstrndx,2,1);
	free(elf_header);
	return(0);
}


