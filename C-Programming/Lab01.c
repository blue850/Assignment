#include <stdio.h>

main()
{
	printf("  F      C\n\n");
	float fahr, celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	for (fahr = upper; fahr >= lower; fahr -= step)
	{
		celsius = (5.0/9.0) * (fahr- 32);
		printf("%3.0f %6.1f\n", fahr, celsius);
	}
}
