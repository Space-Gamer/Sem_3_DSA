#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void insert(int[], int*, int*, int);
void display(int[], int, int);
void delete(int[], int*, int*);

void main()
{

    int x, n, ch;
    int queue[MAX], front, rear;
    front = rear = -1;
    while(1)
    {
        printf("\n\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&x);
            insert(queue, &front, &rear, x);
            break;
        case 2:
            printf("Deleting the front element...\n");
            delete(queue, &front, &rear);
            break;
        case 3:
            display(queue, front, rear);
            break;
        default:
            exit(1);
            break;
        }
    }
}

void insert(int q[], int *f, int *r, int ele)
{
    if (*r == MAX-1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (*f == -1)
        {
            *f = 0;
        }
        (*r)++;
        q[*r] = ele;
    }
}

void display(int q[], int f, int r)
{
    if (f == -1 && r == -1)
    {
        printf("Stack Empty!\n");
    }
    else
    {
        for (int i=f;i<=r;i++)
        {
            printf("%d ",q[i]);
        }
    }
}

void delete(int q[], int *f, int *r)
{
    if (*f == -1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Deleted %d\n",q[*f]);
        (*f)++;
        if (*f == MAX)
        {
            *f = *r = -1;
        }
    }
}