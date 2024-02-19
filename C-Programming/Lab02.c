#include <stdio.h>
void strmul(char s[], char t[], int n);
void strsum(char to[], char from1[], char from2[]);

main() {
	char s[100], t[100], u[100];
	strmul(t, "abc", 2);
	strmul(u, "DE", 3);
	strsum(s, t, u);
	printf("%s\n", s);
}

void strmul(char s[], char t[], int n) { //t를 n번 반복하여 s로 보냄
	/*
	int i, j, k;
	i = 0;
	j = 0;
	k = 0;

	while (k < n) {
		while ((s[i] = t[j]) != '\0') {
			++i;
			++j;
		}
		j = 0;
		++k;
	} */

	int j = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		while ((s[j] = t[k]) != '\0') {
			j++;
			k++;
		}
		k = 0;
	}
}

void strsum(char to[], char from1[], char from2[]) {

	int i, j;
	i = 0;

	while ((to[i] = from1[i]) != '\0') {
		i++;
	}

	j = 0;

	while ((to[i] = from2[j]) != '\0') {
	i++;
	j++;
	}
}