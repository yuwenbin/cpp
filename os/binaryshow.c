#include <stdio.h>

void show_binary(char c)
{
	int i;
	int array[8];
	for(i=0;i<8;i++){
		array[7-i] = (c>>i)&0x01;
	}
	printf("[");
	for(i=0;i<8;i++){
		printf("%d",array[i]);
		if((i+1)%4==0)
			printf(" ");
	}
	printf("]");
}

void show_ibin(int i)
{
	int j;
	int array[32];
	for(j=0;j<32;j++)
	{
		array[31-j] = (i>>j)&0x01;
	}

	printf("[");
	for(j=0;j<32;j++){
		printf("%d",array[j]);
		if((j+1)%4==0)
			printf(" ");
	}
	printf("]");
}

int main(int argc,char *argv[])
{
	char c;
	int m;
	unsigned int n;

	printf("Please input char:");
	scanf("%c",&c);
	for(int i=0;i<8;i++){
	printf("\nhex=[%.2x],binary=",c>>i);
	show_binary(c>>i);
	printf("\n");
	}
	printf("Please input integer:");
	scanf("%d",&m);
	n = (unsigned int)m;
	for(int i=0;i<32;i++){
	printf("\nhex=[%.2x],binary=",n>>i);
	show_ibin(n>>i);
	printf("\n");
	}


	return 0;
}
