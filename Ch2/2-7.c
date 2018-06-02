#include <stdio.h>

void displayBits(unsigned int value)
{
    unsigned int c;
    unsigned int displayMask=1<<31;

    printf("%10u = ", value);

    for(c=1;c<=32;++c)
    {
        putchar(value & displayMask? '1':'0');
        value<<=1;

        if(c%8 == 0)
        {
            putchar(' ');
        }
    }
    putchar('\n');
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = (~(~0<<n))<<(p+1-n);
    return x^mask;
}

int main()
{
    unsigned int x;

        printf("%s", "Enter a nonnegative int: " );
        scanf("%u", &x);

        displayBits(x);

        displayBits(invert(x, 4, 3));

    }
