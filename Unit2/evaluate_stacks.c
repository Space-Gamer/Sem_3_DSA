#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 10

#define a 5
#define b 7
#define c 3
#define d 13
#define e 25
#define f 0

void push(char);
char pop();
char peep();

void con_post(char[], char[]);

void con_pre(char[], char[]);

int eval(char[]);

char s[MAX];
int top;
int s_int[MAX]; // For evaluate stack
int top1=-1;

int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX];
    top = -1;
    push('#');
    printf("Enter infix expression to be evaluated: ");
    scanf("%s",infix);
    con_post(infix,postfix);
    printf("\nPostfix of the expression is: %s",postfix);
    con_pre(infix,prefix);
    printf("\nPrefix of the expression is: %s",prefix);
    printf("\nResult of the expression: %d",eval(postfix));
}

int input_prec(char ch)
{
	 switch(ch)
	 {
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 3;
	case '^': return 6;
	case '(': return 9;
	case ')': return 0;
	default : return 7;
		 }
}

int stack_prec(char ch)
{
	 switch(ch)
	 {
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 4;
	case '^': return 5;
	case '(': return 0;
	case '#': return -1;
	default : return 8;
	}
}

int var_subs(char ch)
{
    if ('0'<=ch && ch<='9')
    {
        return (ch - '0');
    }
    switch (ch)
    {
    case 'a':
        return a;
    case 'b':
        return b;
    case 'c':
        return c;
    case 'd':
        return d;
    case 'e':
        return e;
    case 'f':
        return f;
    default:
        return 1;
    }
}

void push(char ch)
{
    s[++top] = ch;
}

char pop()
{
    return s[top--];
}

char peep()
{
    return s[top];
}

void strrrev(char str[])
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void con_post(char infix[], char postfix[])
{
    int i=0,j=0;

    while (infix[i] != '\0')
    {
        while (input_prec(infix[i]) < stack_prec(peep()))
        {
            postfix[j++] = pop();
        }
        if (input_prec(infix[i]) != stack_prec(peep()))
        {
            push(infix[i]);
        }
        else
        {
            pop();
        }
        i++;
    }

    while (peep() != '#')
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void con_pre(char infix[], char prefix[])
{
    int i=0,j=0;
    char temp;
    strrrev(infix);
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
        i++;
    }
    con_post(infix,prefix);
    strrrev(prefix);
}

void push_int(int ch)
{
    s_int[++top1] = ch;
}

int pop_int()
{
    return s_int[top1--];
}

int eval(char postfix[])
{
    int i=0;
    char ch;
    
    while (postfix[i] != '\0')
    {
        ch = postfix[i];
        int res,x,y;
        if (('0'<=ch && ch<='9') || ('a'<=ch && ch<='f'))
        {
            push_int(var_subs(ch));
        }
        else
        {
            x = pop_int();
            y = pop_int();
            switch (ch)
            {
            case '+':
                res = y + x;
                break;
            case '-':
                res = y - x;
                break;
            case '*':
                res = y * x;
                break;
            case '/':
                res = y / x;
                break;
            case '^':
                res = pow(x, y);
                break;
            default:
                break;
            }
            push_int(res);
        }
        i++;
    }
    return pop_int();
}