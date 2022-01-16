#include <stdio.h>
void hexshow(unsigned char *,int,int);
int main(int argc,char *argv[])
{

	unsigned short x = 0x0102;
	unsigned char *p ;


	p = &x;
	hexshow(p,2,0);
	if(p[0]==0x01&&p[1]==0x02)
		printf("This machine is big endian.\n");
	else
		printf("This machine is litte endian.\n");

	p = &main;
	printf("main program startup address:  0x%016x\n",p);
	p = &hexshow;
	printf("hexshow program startup address:  0x%016x\n",p);
	p = &printf;
	printf("printf program startup address:  0x%016x\n",p);
	return 0;
}

