#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

// struct node *new;
// struct node *cur;
// struct node *prev;
// struct node *list;

struct node* frontins();
// void backins();
// void ordins();
void display();
// void frontdelete();
// void backdelete();
// void posins();
// void posdelete();

void main()
{
    struct node *list;
    list = NULL;
    while (1)
    {
        printf("\n\n\n1.Front Insertion\n2.Back Insertion\n3.Positional Insertion\n4.Ordered Insertion\n5.Display\n6.Front delete\n7.Back delete\n8.Position delete\n\nEnter your choice: ");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            list = frontins(list);
            break;
        // case 2:
        //     backins();
        //     break;
        // case 3:
        //     posins();
        //     break;
        // case 4:
        //     ordins();
        //     break;
        case 5:
            display(list);
            break;
        // case 6:
        //     frontdelete();
        //     break;
        // case 7:
        //     backdelete();
        //     break;
        // case 8:
        //     posdelete();
        //     break;
        default:
            exit(1);
            break;
        }
    }
    
    // list = NULL;
    // for (int i=0;i<3;i++)
    // {
    //   frontins();  
    // }
    // display();
    // printf("\n%d",list->info);
}

struct node* frontins(struct node* list)
{
        struct node *new;
        int x;
        printf("Enter data:\n");
        scanf("%d",&x);
        new = (struct node*) malloc(sizeof(struct node*));
        new->info = x;
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

void display(struct node* list)
{
    if (list==NULL)
    {
        printf("List is empty");
        return;
    }
    printf("Contents of list are: ");
    struct node *cur;
    cur = list;
    while(cur != NULL)
    {
        printf("%d %p\n",cur->info,cur->next); 
        cur = cur->next;
    }
}

// void backins()
// {
//     int x;
//     printf("Enter data:\n");
//     scanf("%d",&x);
//     new = (struct node*) malloc(sizeof(struct node*));
//     new->info = x;
//     new->next = NULL;
//     if (list == NULL)
//     {
//         list = new;
//     }
//     else
//     {
//         cur = list;
//         while(cur->next != NULL)
//         {
//             cur = cur->next;
//         }
//         cur->next = new;
//         cur = NULL; 
//     }
// }

// void posins()
// {
//     int pos,x;
//     printf("\nEnter position to be inserted: ");
//     scanf("%d",&pos);
//     printf("\nEnter data to be inserted: ");
//     scanf("%d",&x);
//     new = (struct node*) malloc(sizeof(struct node*));
//     new->info = x;
//     new->next = NULL;
//     if (list==NULL && pos==1)
//     {
//         list = new;
//     }
//     else if (list==NULL)
//     {
//         printf("\nInvalid postion.");
//         return;
//     }
//     else
//     {
//         int cur_pos=1;
//         prev = NULL;
//         cur = list;
//         while(cur_pos<pos)
//         {
//             // printf("%d %d",pos,cur_pos);
            
//             if (cur->next==NULL && pos>(cur_pos+1))
//             {
//                 printf("\nInvalid postion");
//                 return;
//             }
//             else
//             {
//                 prev = cur;
//                 cur = cur->next;
//                 cur_pos++;
//             }
//         }
//         if (prev==NULL && pos==1)
//             {
//                 new->next = list;
//                 list = new;
//                 return;
//             }
//         new->next = prev->next;
//         prev->next = new;
//     }
// }

// void ordins()
// {
//     int x;
//     printf("\nEnter data to be inserted: ");
//     scanf("%d",&x);
//     new = (struct node*) malloc(sizeof(struct node*));
//     new->info = x;
//     new->next = NULL;
//     prev = NULL;
//     cur = NULL;
//     if (list==NULL)
//     {
//         list = new;
//         return;
//     }
//     else
//     {
//         prev = NULL;
//         cur = list;
//         while (cur!=NULL && cur->info < new->info)
//         {
//             prev = cur;
//             cur = cur->next;
//         }
//         if (prev == NULL)
//         {
//             new->next = list;
//             list = new;
//         }
//         else
//         {
//             new->next = prev->next; 
//             prev->next = new;
//         }
//     }

// }

// void frontdelete()
// {
//     if (list==NULL)
//     printf("List is empty");
//     else
//     {
//         cur = list;
//         list = list->next;
//         printf("Deleted %d",cur->info);
//         free(cur);
//         cur = NULL;
//     }
// }

// void backdelete()
// {
//     if (list==NULL)
//     printf("Empty list");
//     else
//     {
//         prev = NULL;
//         cur = list;
//         while (cur->next!=NULL)
//         {
//             prev = cur;
//             cur = cur->next;
//         }
//         if (prev==NULL)
//         {
//             printf("Deleted %d",list->info);
//             free(list);
//             list = NULL;
//         }
//         else
//         {
//             prev->next = NULL;
//             printf("Deleted %d",cur->info);
//             free(cur);
//             cur = NULL;
//             prev = NULL;
//         }
//     }
// }

// void posdelete()
// {
//     int pos,x;
//     printf("\nEnter position to be deleted: ");
//     scanf("%d",&pos);
//     if (list == NULL)
//     {
//         printf("\nList empty");
//     }
//     else if (list->next==NULL && pos!=1)
//     {
//         printf("\nInvalid postion");
//     }
//     else if (pos==1)
//     {
//         cur = list;
//         list = list->next;
//         printf("Deleted %d",cur->info);
//         free(cur);
//         cur = NULL;
//         return;
//     }
//     else
//     {
//         prev = NULL;
//         cur = list;
//         int cur_pos=1;
//         while (cur!=NULL)
//         {
//             if (cur_pos==pos)
//             {

//                 printf("Deleted %d",cur->info);
//                 prev->next = cur->next;
//                 free(cur);
//                 cur = NULL;
//                 return;
                
//             }
//             else
//             {
//                 cur_pos++;
//                 prev = cur;
//                 cur = cur->next;
//             }
//         }
//         printf("Invalid position");
//         return;
//     }
// }