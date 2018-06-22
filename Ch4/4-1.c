#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

int main()
{
    char line[MAXLINE];
    char pattern[] = "ould";

    while(getline(line, MAXLINE)>0)
         printf("%d\n",(strindex(line, pattern)));

}


int getline(char s[], int lim)
{
    int i=0;
    char c;
    while(--lim>0 && (c=getchar())!=EOF && c!= '\n')
        s[i++]=c;
    if(c=='\n')
        s[i++]=c;
    s[i]='\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;
    for(i=strlen(s)-strlen(t);i>=0;i--)
    {
        for(j=i, k=0;t[k]!='\0' && s[j]==t[k];j++, k++)
            ;
        if(k>0 && t[k]=='\0')
            return i;
    }
    return -1;
}
