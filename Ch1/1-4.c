#include <stdio.h>

/*print fahrenheit-celcius conversion table */

int main()
{
    float fahr, celsius;
    int upper, lower, step;

    lower = -30;
    upper = 60;
    step = 10;

    celsius = lower;
    printf("%s", "Celsius to Fahrenheit conversion table:\n");

    while(celsius<=upper)
    {
        fahr=((9.0/5.0)*(celsius))+32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius+=step;
    }
}
