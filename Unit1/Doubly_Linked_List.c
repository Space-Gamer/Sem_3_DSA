// Code not completed

#include <stdio.h>
#include <stdlib.h>

struct dnode
{
    int info;
    struct dnode *left;
    struct dnode *right;
};

struct dnode *frontins();
struct dnode *backins();
// void ordins();
void display();
// void frontdelete();
// void backdelete();
struct dnode *succins();
struct dnode *keydelete();


void main()
{
    struct dnode *dlist;
    dlist = NULL;
    while (1)
    {
        printf("\n\n\n1.Front Insertion\n2.Back Insertion\n3.Successor Insertion\n4.Ordered Insertion\n5.Display\n6.Front delete\n7.Back delete\n8.Key deletion\n\nEnter your choice: ");
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            dlist = frontins(dlist);
            // printf("main DLIST=> %p %p %p\n",dlist->left, &dlist, dlist->right);
            break;
        case 2:
            dlist = backins(dlist);
            break;
        case 3:
            dlist = succins(dlist);
            break;
        // case 4:
        //     ordins();
        //     break;
        case 5:
            display(dlist);
            break;
        // case 6:
        //     frontdelete();
        //     break;
        // case 7:
        //     backdelete();
        //     break;
        case 8:
            dlist = keydelete(dlist);
            break;
        default:
            exit(1);
            break;
        }
    }
}

struct dnode *frontins(struct dnode *dlist)
{
    // printf("Before changing=> %p %p %p\n",dlist->left, dlist, dlist->right);
    int x;
    printf("Enter data:\n");
    scanf("%d",&x);
    struct dnode *new;
    new = (struct dnode*) malloc(sizeof(struct dnode*));
    new->info = x;
    new->left = NULL;
    new->right = NULL;
    if (dlist == NULL)
    {
        dlist = new;
        // printf("%p %p %p\n",dlist->left, &dlist, dlist->right);
    }
    else
    {
        // printf("Before changing=> %p %p %p\n",dlist->left, dlist, dlist->right);
        // printf("New Node=> %p %p %p\n",new->left, new, new->right);
        new->right = dlist;
        dlist->left = new;
        dlist = new;
    }
    // printf("DLIST=> %p %p %p\n",dlist->left, &dlist, dlist->right);
    return dlist;
}

struct dnode *backins(struct dnode *dlist)
{
    int x;
    printf("Enter data:\n");
    scanf("%d",&x);
    struct dnode *new;
    new = (struct dnode*) malloc(sizeof(struct dnode*));
    new->info = x;
    new->left = NULL;
    new->right = NULL;
    if (dlist==NULL)
    {
        dlist = new;
    }
    else
    {
        struct dnode *cur;
        cur = dlist;
        while (cur->right!=NULL)
        {
            cur = cur->right;
        }
        cur->right = new;
        new->left = cur;
    }
    return dlist;
}

void display(struct dnode *dlist)
{
    if (dlist==NULL)
    {
        printf("List empty!\n");
    }
    else
    {
        struct dnode *cur;
        cur = dlist;
        while(cur->right!=NULL)
        {
            // printf("%d %p\n",cur->info, cur->right);
            printf("%d ",cur->info);
            cur = cur->right;
        }
        printf("%d\nReverse order:\n",cur->info);
        while(cur->left!=NULL)
        {
            printf("%d ",cur->info);
            cur = cur->left;
        }
        printf("%d\n",cur->info);
    }
}

struct dnode *succins(struct dnode *dlist)
{
    if (dlist == NULL)
    {
        printf("Can't do key instertion in empty list.\n");
        return dlist;
    }
    int x,k;
    printf("Enter data:\n");
    scanf("%d",&x);
    struct dnode *new;
    new = (struct dnode*) malloc(sizeof(struct dnode*));
    new->info = x;
    new->left = NULL;
    new->right = NULL;
    printf("Enter successor key: ");
    scanf("%d",&k);
    struct dnode *cur;
    cur = dlist;
    while (cur->info!=k)
    {
        if (cur->right==NULL)
        {
            printf("Key not found!\n");
            return dlist;
        }
        else
        cur = cur->right;
    }
    if (cur->left==NULL)
    {
        new->right = dlist;
        dlist->left = new;
        dlist = new;
        return dlist;
    }
    else
    {
        new->right = cur;
        new->left = cur->left;
        cur->left->right = new;
        cur->left = new;
    }
    return dlist;

}

struct dnode *keydelete(struct dnode* dlist)
{
    if (dlist==NULL)
    {
        printf("\nList is empty!");
        return dlist;
    }
    int x;
    printf("\nEnter key to be deleted:");
    scanf("%d",&x);
    struct dnode *cur;
    cur = dlist;
    while(cur->info!=x)
    {
        if (cur->right==NULL)
        {
            printf("Key not found!\n");
            return dlist;
        }
        else
        cur = cur->right;
    }
    if (cur->left == NULL && cur->right != NULL)
    {
        cur->right->left = NULL;
        dlist = cur->right;
        printf("Deleted %d",cur->info);
        free(cur);
        cur = NULL;
    }
    else if (cur->left == NULL && cur->right == NULL)
    {
        
    }
    else if (cur->right == NULL)
    {
        cur->left->right = NULL;
        printf("Deleted %d",cur->info);
        free(cur);
        cur = NULL;
    }
    else
    {
        cur->right->left = cur->left;
        cur->left->right = cur->right;
        printf("Deleted %d",cur->info);
        free(cur);
        cur = NULL;
    }
    return dlist;
}