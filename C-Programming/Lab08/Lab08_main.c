#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	int op_st[100],			/* operator stack */
		op_opr_size[100],	/* operand stack size at the time of pushing the operator */
		op_sp = -1;			/* operator stack position */

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case '+': 
			op_sp++;
			op_st[op_sp] = type;
			op_opr_size[op_sp] = size();
		case '-': 
			op_sp++;
			op_st[op_sp] = type;
			op_opr_size[op_sp] = size();
		case '*': 
			op_sp++;
			op_st[op_sp] = type;
			op_opr_size[op_sp] = size();
		case '/':
			op_sp++;
			op_st[op_sp] = type;
			op_opr_size[op_sp] = size();
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case NUMBER:
			push(atof(s));
			while (	op_opr_size[op_sp] == size() - 2 && size() >= 2/* 연산자 존재 && 피연산자 2개 준비되어있는지 확인 */) {
				int op = op_st[op_sp];
					switch (op) {
					case '+':
						push(pop() + pop());
						break;
					case '*':
						push(pop() * pop());
						break;
					case '-':
						op2 = pop();
						push(pop() - op2);
						break;
					case '/':
						op2 = pop();
						if (op2 != 0.0)
							push(pop() / op2);
						else
							printf("error: zero divisor\n");
						break;
					}
			}
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}