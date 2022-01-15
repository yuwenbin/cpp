#include <stdio.h>
#include <string.h>
#include<ctype.h>

/* 使用位域的方式，进行二进制转换 */
struct char_bit {
	unsigned int b0:1;
	unsigned int b1:1;
	unsigned int b2:1;
	unsigned int b3:1;
	unsigned int b4:1;
	unsigned int b5:1;
	unsigned int b6:1;
	unsigned int b7:1;
};
/* 打印ASCII表中可打印字符 */

int main(int argc,char *argv[])
{

	struct char_bit cb ;
	char c[1];
	int i=0;

	for(i=0;i<256;i++){
		c[0]=(unsigned char )i;
		memcpy(&cb,c,1);
		if(isprint(c[0]))
			printf("%d %.2x '%c' = %d%d%d%d%d%d%d%d\n",i,i,c[0],cb.b7,cb.b6,cb.b5,cb.b4,cb.b3,cb.b2,cb.b1,cb.b0);
	}
	return(0);
}

