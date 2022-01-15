#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

/* 使用位域的方式，进行二进制转换 */
struct char_bit {
	unsigned char b0:1;
	unsigned char b1:1;
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
};
/* 打印ASCII表中可打印字符 */
#define LINEBUFSIZE   1024
int main(int argc,char *argv[])
{

	struct char_bit cb[LINEBUFSIZE] ;
	int i=0,readbytes=0;
	unsigned char buf[LINEBUFSIZE];
	unsigned long offset=0;

	printf("%ld\n",sizeof(cb[0]));
	if(argc<2){
		perror("Usage: bitread [filename]");
		exit(0);
	}

	int fd = open(argv[1],O_RDWR,S_IRUSR);
	if(fd<0){
		perror("open file failure.");
		exit(0);
	}
	while((readbytes=read(fd,buf,LINEBUFSIZE))>0){
		memcpy(cb,buf,readbytes);
		
		for(i=0;i<readbytes;i++){
			printf("%12ld,0x%.2x = %d%d%d%d%d%d%d%d\n",
					offset+i,buf[i],cb[i].b7,cb[i].b6,cb[i].b5,cb[i].b4,cb[i].b3,cb[i].b2,cb[i].b1,cb[i].b0);
		}
		offset += readbytes;
	}
	close(fd);
	return(0);
}

