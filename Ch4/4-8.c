#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MATHFUNC 'm'

int getop(char []);
void push(double);
double pop(void);
void clearStack(void);
void printTop(void);
void duplicateTop(void);
void swapTopTwo(void);
void doMathFunc(char []);
void ungets(char []);

main()
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s))!=EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case MATHFUNC:
                doMathFunc(s);
                break;
            case '+':
                push(pop()+pop());
                break;
            case '*':
                push(pop()*pop());
                break;
            case '-':
                op2=pop();
                push(pop()-op2);
                break;
            case '/':
                op2=pop();
                if(op2!=0.0)
                    push(pop()/op2);
                else
                    printf("error: zero divisor\n");
                break;
            /*provision for modulus*/
            case '%':
                if(op2!=0.0)
                    push(fmod(pop(),op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '?':
                printTop();
                break;
            case '#':
                duplicateTop();
                break;
            case '~':
                swapTopTwo();
                break;
            case '!':
                clearStack();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100
int sp=0; /*NB: NEXT free stack position */
double val[MAXVAL];

void push(double f)
{
    if (sp<MAXVAL)
        val[sp++]=f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void printTop(void)
{
    if(sp>0)
        printf("\t%.8g\n", val[sp-1]);
    else
        printf("stack is empty\n");
}

void duplicateTop(void)
{
    double temp = pop();
    push(temp);
    push(temp);
}

void swapTopTwo(void)
{
    double temp1 = pop();
    double temp2 = pop();
    push(temp1);
    push(temp2);
}

void clearStack(void)
{
    sp=0;
}

void doMathFunc(char s[])
{
    if(strcmp(s,"sin")==0)
        push(sin(pop()));
    else if(strcmp(s,"cos")==0)
        push(cos(pop()));
    else if(strcmp(s,"exp")==0)
        push(exp(pop()));
    else
      printf("%s is not a supported function.\n", s);
}


#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;
    while((s[0]=c=getch())==' '|| c=='\t')
        ;
    s[1]='\0';
    i=0;
    if(isalpha(c))
    {
        while(isalpha(s[++i]=c=getch()))
        ;
        s[i]='\0';
        if(c!=EOF)
            ungetch(c);
        return MATHFUNC;
    }
    if(!isdigit(c) && c!='.' && c!='-')
        return c;
    if(c =='-')
        if(isdigit(c=getch())||c=='.')
           s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }
    if(isdigit(c))
        while(isdigit(s[++i]=c=getch()))
            ;
    if(c=='.')
        while(isdigit(s[++i]=c=getch()))
    s[i]='\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#include <string.h>

void ungets(char s[])
{
    int len = strlen(s);
    while(len>0)
        ungetch(s[--len]);
}

#define BUFSIZE 100

char buf=0;

int getch(void)
{
    int temp;
    if(buf != 0)
        temp = buf;
    else
        temp = getchar();
    buf = 0;
    return temp;
}

void ungetch(int c)
{
    if(buf != 0)
        printf("buffer full");
    else
        buf = c;
}
