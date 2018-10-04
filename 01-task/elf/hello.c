#include <stdio.h>

#define TEST 10

void bar()
{
	printf("bar\n");
}

void foo()
{
	printf("foo\n");
	bar();
}

void main()
{
	int a = TEST;
	printf("%d\n", a);
	printf("hello\n");
	foo();
}
