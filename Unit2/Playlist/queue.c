#include <stdio.h>
#include <stdlib.h>
#include "dll.c"

// struct dnode
// {
//     int data;
//     struct dnode *left;
//     struct dnode *right;
// };

// typedef struct list
// {
//     struct dnode *head;
//     struct dnode *tail;
// }queue_t;

// typedef list_t queue_t;
#define queue_t list_t

void enqueue(queue_t* queue, int data)
{
    insert_back(queue, data);
}

int dequeue(queue_t* q)
{
    return delete_front(q);
}

int front(queue_t* q)
{
    if (q->head == NULL)
    {
        return -1;
    }
    else
    {
        return q->head->data;
    }
}