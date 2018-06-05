#include <stdio.h>
#include <stdlib.h>

int expand(char s1[], char s2[])
{
    int i, j;
    char c;
    for(i=0,j=0; s1[i]!='\0'; ++i)
    {
        if (s1[i] == '-') {
            if (i == 0 || s1[i+1] == '\0') { //if leading or trailing zero, just copy it
                s2[j++] = s1[i];
            } else //otherwise we need to expand it
            {
                c = s1[i-1];
                while(s2[j-1]<s1[i+1])
                {
                    s2[j++]=++c;
                }
                ++i;
            }
        } else
        {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

int main(void)
{
    char s1[512] = "a-z";
    char s2[512];
    expand(s1, s2);
    printf("%s\n", s2);

}
