#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned char c;
    unsigned int i;
    unsigned short s;

	/* char */
	c = ~0;
	c >>= 1;
	printf("signed char:   %4d,           %4d\n",-c-1,c);
	printf("SCHAR_MIN:     %4d, SCHAR_MAX %4d\n",SCHAR_MIN,SCHAR_MAX);
	printf("unsigned char: %4d,           %4d\n",0,c*2+1);
	printf("UCHAR_MAX:                    %4d\n",UCHAR_MAX);
	putchar('\n');

    /* int */
	i = ~0;
	i >>= 1;
	printf("signed int:   %11d,           %11d\n",-i-1,i);
	printf("INT_MIN:      %11d,   INT_MAX %11d\n",INT_MIN,INT_MAX);
	printf("unsigned int: %11u,           %11u\n",0,i*2+1);
	printf("UINT_MAX:                     %11u\n",UINT_MAX);
	putchar('\n');

    /* short */
	s = ~0;
	s >>= 1;
	printf("signed short:   %4d,           %4d\n",-s-1,s);
	printf("SHORT_MIN:      %4d,   INT_MAX %4d\n",SHRT_MIN,SHRT_MAX);
	printf("unsigned short: %4u,           %4u\n",0,s*2+1);
	printf("USHRT_MAX:                     %4u\n",USHRT_MAX);
	putchar('\n');

    /* etc */
}
