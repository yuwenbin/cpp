#include <stdio.h>
#include <string.h>

void show_binary(char c)
{
        int i;
        int array[8];
        for(i=0;i<8;i++){
                array[7-i] = (c>>i)&0x01;
        }
        for(i=0;i<8;i++){
                printf("%d",array[i]);
        }
}

void show_fhex(float *f)
{
	unsigned char array_c[4];
	int i=0;

	memcpy(array_c,f,sizeof(f)); 
	printf("hex = [");
	for(i=3;i>=0;i--)
		printf(" %.2x",array_c[i]);
	printf(" ]");
}

void show_fbin(float *f)
{
	int j;
	unsigned char array_c[4];

	memcpy(array_c,f,sizeof(f)); 
	printf("binary = [ ");
	for(j=3;j>=0;j--){
		show_binary(array_c[j]);
		printf(" ");
	}

	printf("]");
}

int main(int argc,char *argv[])
{
	char c;
	int m;
	float f;
	unsigned int n;

	while(1){
	printf("Please input float:");
	scanf("%f",&f);
	printf("%f,\t",f);
	show_fhex(&f);
	printf(",\t");
	show_fbin(&f);
	printf("\n");
	}

	return 0;
}
