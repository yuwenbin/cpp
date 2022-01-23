#include <unistd.h>
#include <sys/syscall.h>

int main()
{
	syscall(1,1,"Hello world!",11);
	return 0;
}
