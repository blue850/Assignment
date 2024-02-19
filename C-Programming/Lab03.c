#include <stdio.h>

main() {
	int prime[1000];

	for (int i = 0; i < 1000; i++) {
		prime[i] = 1;
	}

	prime[0] = prime[1] = 0;

	for (int p = 2; p * p < 1000; p++) {
		if (prime[p] == 1) {
			for (int i = 2; p * i < 1000; i++) {
				prime[p * i] = 0;
			}
		}
	}

	int j = 1;
	for (int i = 0; i < 1000; i++) {
		if (prime[i] == 1) {
			printf("%3d ", i);
			j++;
			if (j % 15 == 0)
				printf("\n");
		}
	}
}