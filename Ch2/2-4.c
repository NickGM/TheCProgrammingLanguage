#include <stdio.h>

void squeeze_char(char s[], int c)
{
    int i,j;
    for(i=j=0;s[i]!='\0';i++)
        if(s[i]!=c)
        {
          s[j++]=s[i];
          printf("%c", s[i]);
        }
    s[j]='\0';
    printf("%c", '\n');
}

int squeeze(char s1[], char s2[])
{
    int i;
    for(i=0;s2[i]!='\0';i++)
        squeeze_char(s1,s2[i]);
}

int main()
{
    char s1[]="tester";
    char s2[]="hellot";

    squeeze(s1,s2);
}
