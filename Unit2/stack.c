#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *ins();
struct node *del();
void display();

int main()
{
    struct node *list;
    list = NULL;
    while (1)
    {
        printf("\n\n\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n\nEnter your choice: ");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            int x;
            scanf("%d",&x);
            list = ins(list, x);
            break;
        case 2:
            printf("Popping top most element...\n");
            int y;
            list = del(list, &y);
            printf("The deleted element is: %d",y);
            break;
        case 3:
            display(list);
            break;
        default:
            exit(1);
            break;
        }
    }
}

struct node *ins(struct node *list, int ele)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->info = ele;
    new->next = NULL;
    if (list == NULL)
    {
        list = new;
    }
    else
    {
        new->next = list;
        list = new;
    }
    return list;
}

struct node *del(struct node *list, int *popped)
{
    if (list == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *cur;
        cur = list;
        list = list->next;
        *popped = cur->info;
        printf("Popped element is %d\n", *popped);
        free(cur);
    }
    return list;
}

void display(struct node *list)
{
    if (list == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *cur;
        cur = list;
        while (cur != NULL)
        {
            printf("%d ", cur->info);
            cur = cur->next;
        }
    }
}