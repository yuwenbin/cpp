#include <stdio.h>

void hexshow(unsigned char *buf,int size,int order)
{
	int i;

	if(order==0){

	for(i=0;i<size;i++)
		printf("%.2x ",buf[i]);
	}
	else
	{

	for(i=size-1;i>=0;i--)
		printf("%.2x ",buf[i]);
	}
	printf("\n");
	return;
}
