#include <stdio.h>

int bar(int b)
{
	printf("bar %d\n", b);
	return b;
}

int foo(int a)
{
	printf("foo %d\n", a);
	return bar(a+1);
}
	
void main(int argc, char *argv[])
{
	printf("hello %d\n", foo(argc));
}

