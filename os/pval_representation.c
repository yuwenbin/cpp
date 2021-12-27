#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len){
	size_t i;
	for(i = 0;i<len;i++)
		printf(" %.2x",start[i]);
	//printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer) &x,sizeof(int));
}

void show_float(float x){
	show_bytes((byte_pointer) &x,sizeof(float));
}

void show_pointer(void *x){
	show_bytes((byte_pointer) &x,sizeof(void *));
}

void test_show_bytes(int val){
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	printf("int: %d\t\t be Expressed in hexadecimal:[ ",ival);
	show_int(ival);
	printf(" ]\n");
	printf("float: %f\t\t be Expressed in hexadecimal:[ ",fval);
	show_float(fval);
	printf(" ]\n");
	printf("pointer: %p\t\t be Expressed in hexadecimal:[ ",pval);
	show_pointer(pval);
	printf(" ]\n");
}

