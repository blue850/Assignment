#include <stdio.h>
#include <string.h> 

void printbinary(unsigned x) {
	int i;
	for (i = 0; i < 32; i++) {
		putchar(x & 0x80000000 ? '1' : '0');
		if (i % 4 == 3) {
			putchar(' ');
		}
		x <<= 1;
	}
	putchar('\n');
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {

	int bitsA, bitsC, bitsE;

	bitsA = p + 1;
	bitsC = p - n + 1;
	bitsE = n;

	/*printf("A구간 : ");
	printbinary(x & (~0 << bitsA));
	printf("C구간 : ");
	printbinary(x & ~(~0 << bitsC));
	printf("E구간 : ");
	printbinary((y & ~(~0 << bitsE)) << bitsC);
	printf("결과: ");
	printbinary(x & (~0 << bitsA)) | (x & ~(~0 << bitsC)) | ((y & ~(~0 << bitsE)) << bitsC);*/

	return (x & (~0 << bitsA)) | (x & ~(~0 << bitsC)) | ((y & ~(~0 << bitsE)) << bitsC);
}

main() {
	printf("setbits(0X12345678, 7, 8, 0X89ABCDEF) = %X\n", setbits(0X12345678, 7, 8, 0X89ABCDEF));
	printf("setbits(0X12345678, 15, 16, 0X89ABCDEF) = %X\n", setbits(0X12345678, 15, 16, 0X89ABCDEF));
	printf("setbits(0X12345678, 15, 8, 0X89ABCDEF) = %X\n", setbits(0X12345678, 15, 8, 0X89ABCDEF));
	printf("setbits(0X12345678, 9, 10, 0X89ABCDEF) = %X\n", setbits(0X12345678, 9, 10, 0X89ABCDEF));
}