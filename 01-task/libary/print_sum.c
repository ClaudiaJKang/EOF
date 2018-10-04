#include "mysum.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char oper[5];
	char left[11];
	char right[11];
	int result;

	memset(left, 0x00, 11);
	memset(right, 0x00, 11);

	fscanf(stdin, "%[0-9]%[^0-9]%[0-9]", left, oper, right);

	if (oper[0] == '-')
	{
		printf("%s %s %s = %d\n", left, oper, right, ydiff(atoi(left),atoi(right)));
	}

	if (oper[0] == '+')
	{

		printf("%s %s %s = %d\n", left, oper, right, ysum(atoi(left),atoi(right)));
	}
}
