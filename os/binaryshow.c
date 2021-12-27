#include <stdio.h>

void show_binary(char c)
{
	int i;
	printf("[");
	for(i=0;i<8;i++){
		printf(" %d",((c<<i)&0x80)>>7);
		if(i==3)
			printf("  ");
	}
	printf(" ]");
}

int main(int argc,char *argv[])
{
	char c;

	printf("Please input char:");
	scanf("%c",&c);
	printf("\nhex=[%.2x],binary=",c);
	show_binary(c);

	printf("\n");
	return 0;
}
