#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
    int data;
    struct dnode *left;
    struct dnode *right;
}dnode;

typedef struct list
{
    struct dnode *head;
    struct dnode *tail;
}list_t;

void insert_front(list_t* list, int data)
{
    struct dnode *new;
    new = (struct dnode*) malloc(sizeof(struct dnode*));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    if (list->head == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        new->right = list->head;
        list->head->left = new;
        list->head = new;
    }
}

void insert_back(list_t* list, int data)
{
    struct dnode *new;
    new = (struct dnode*) malloc(sizeof(struct dnode*));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    if (list->head == NULL)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        list->tail->right = new;
        new->left = list->tail;
        list->tail = new;
    }
}

void insert_after(list_t* list, int data, int prev)
{
    struct dnode *new;
    new = (struct dnode*) malloc(sizeof(struct dnode*));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    if (list->head == NULL)
    {
        printf("Can't do key instertion in empty list.\n");
        return;
    }
    else
    {
        struct dnode *cur;
        cur = list->head;
        while (cur->right!=NULL && cur->data != prev)
        {
            cur = cur->right;
        }
        if (cur->data == prev)
        {
            new->right = cur->right;
            cur->right->left = new;
            cur->right = new;
            new->left = cur;
        }
        else
        {
            printf("Key not found.\n");
        }
    }
}

int delete_front(list_t* list)
{
    if (list->head == NULL)
    {
        printf("List empty!\n");
        return -1;
    }
    else
    {
        int data = list->head->data;
        struct dnode *temp = list->head;
        list->head = list->head->right;
        free(temp);
        return data;
    }
}

int delete_back(list_t* list)
{
    if (list->head == NULL)
    {
        printf("List empty!\n");
        return -1;
    }
    else
    {
        int data = list->tail->data;
        struct dnode *temp = list->tail;
        list->tail = list->tail->left;
        free(temp);
        return data;
    }
}

void delete_node(list_t* list, int data)
{
    if (list->head == NULL)
    {
        printf("Can't delete from empty list.\n");
        return;
    }
    else
    {
        struct dnode *cur;
        cur = list->head;
        while (cur->right!=NULL && cur->data != data)
        {
            cur = cur->right;
        }
        if (cur->data == data)
        {
            cur->left->right = cur->right;
            cur->right->left = cur->left;
            free(cur);
        }
        else
        {
            printf("Key not found.\n");
        }
    }
}

struct dnode* search(list_t* list, int data)
{
    if (list->head == NULL)
    {
        printf("Can't search in empty list.\n");
        return NULL;
    }
    else
    {
        struct dnode *cur;
        cur = list->head;
        while (cur->right!=NULL && cur->data != data)
        {
            cur = cur->right;
        }
        if (cur->data == data)
        {
            return cur;
        }
        else
        {
            printf("Key not found.\n");
            return NULL;
        }
    }
}