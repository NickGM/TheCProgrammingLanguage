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

unsigned setBits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = ~(~0<<n);
    return (x & ~(mask<<(p+1-n))|((y & mask)<<(p+1-n)));
}

int main()
{
    unsigned int x, y;

        printf("%s", "Enter a nonnegative int x: " );
        scanf("%u", &x);
        printf("%s", "Enter a nonnegative int y: " );
        scanf("%u", &y);


        displayBits(x);

        displayBits(setBits(x, 4, 3, y));

    }
