#include <stdio.h>

int htoi(char s[]) {
	int val, i;
	val = 0; 
	i = 0;
	while (s[i] != '\0') {
		if( s[i] >=  '0' && s[i] <=  '9') {
			val = val * 16 + s[i]-'0';
		}
		else if (s[i] >= 'A' && s[i] <= 'F') {
			val = val * 16 + s[i] - 'A' + 10;
		}
		i++;
	}
	return val;
}

main() {
	printf("ABCDEF == > %d\n", htoi("ABCDEF"));
	printf("123456 == > %d\n", htoi("123456"));
	printf("0100 == > %d\n", htoi("0100"));
}