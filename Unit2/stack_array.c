#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct stack
{
    int list[SIZE];
    int top;
}st;

void push(int*, int*, int);
void pop(int*, int*, int*);
void display(int*, int);

int main()
{
    int list[SIZE];
    int top=-1;
    int ch;
    // printf("Enter the number of elements");
    while (1)
    {
        printf("\n\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            int x;
            scanf("%d",&x);
            push(list, &top, x);
            break;
        case 2:
            printf("Popping top most element...\n");
            int y=-1;
            pop(list, &top, &y);
            if (y!=-1)
            {
                printf("The deleted element is: %d",y);
            }
            break;
        case 3:
            display(list, top);
            break;
        default:
            exit(1);
            break;
        }
    }
}

void push(int *arr, int *top, int ele)
{
    if (*top == SIZE-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        (*top)++;
        arr[*top] = ele;
    }
}

void pop(int *arr, int *top, int *ele)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        *ele = arr[*top];
        (*top)--;
    }
}

void display(int *arr, int top)
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Stack is: ");
        for (int i=top;i>=0;i--)
        {
            printf("%d ", arr[i]);
        }
    }
}