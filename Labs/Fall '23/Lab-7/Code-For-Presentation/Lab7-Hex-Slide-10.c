#include <stdio.h>

int main(void) {
	/*printf("0 = 0\t4 = 4\t8 = 8\t12 = C\n");
	printf("1 = 1\t5 = 5\t9 = 9\t13 = D\n");
	printf("2 = 2\t6 = 6\t10 = A\t14 = E\n");
	printf("3 = 3\t7 = 7\t11 = B\t15 = F\n");
	return -1;*/
	printf("sizeof(int) = %lu\nsizeof(int*) = %lu\n", sizeof(int), sizeof(int*));
	int x = 0;
	printf("&x     = %p\n(&x)+1 = %p\n(&x)+2 = %p\n(&x)+3 = %p\n", &x, (&x)+1, (&x)+2, (&x)+3);
	printf("Note: We are doing +1, but the system does\n+4 since it knows the size of int is 4 bytes.\n");
	return 0;
}
