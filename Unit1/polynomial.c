#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node* inp_poly();
struct node* eval_poly();
void disp_poly();

int main()
{
    struct node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    printf("\nInput polynomial 1:\n");
    poly1 = inp_poly(poly1);
    printf("\nInput polynomial 2:\n");
    poly2 = inp_poly(poly2);
    poly3 = eval_poly(poly1, poly2, poly3);
    disp_poly(poly1);
    printf(" + ");
    disp_poly(poly2);
    printf(" = ");
    disp_poly(poly3);
}

struct node* inp_poly(struct node* poly)
{
    printf("\nEnter neagtive exponent to stop entering.\n");
    while (1)
    {
        struct node* new;
        new = (struct node*) malloc(sizeof(struct node*));
        new->next = NULL;
        printf("\nEnter coeffecient and exponent: ");
        scanf("%d %d", &new->coeff, &new->exp);
        if (new->exp<0)
        {
            break;
        }
        else
        {
            if (poly==NULL)
            {
                poly = new;
            }
            else
            {
                struct node* cur;
                struct node* prev=NULL;
                cur = poly;
                while((cur->exp > new->exp) && (cur->next != NULL))
                {
                    prev = cur;
                    cur = cur->next;
                }
                if (cur == poly && cur->exp < new->exp)
                {
                    new->next = poly;
                    poly = new;
                }
                else if (cur->exp == new->exp)
                {
                    cur->coeff = cur->coeff + new->coeff;
                }
                else if (cur->exp < new->exp)
                {
                    new->next = prev->next;
                    prev->next = new;
                }
                else
                {
                    new->next = cur->next;
                    cur->next = new;
                }
            }
        }
        printf("Entered polynomial: ");
        disp_poly(poly);
    }
    return poly;
}

struct node* eval_poly(struct node* poly1, struct node* poly2, struct node* poly3)
{
    int max_pow = (poly1->exp > poly2->exp) ? poly1->exp : poly2->exp;
    struct node *cur1 = poly1, *cur2 = poly2, *cur3 = poly3;
    for (int i=max_pow;i>=0;i--)
    {
        struct node* new;
        new = (struct node*) malloc(sizeof(struct node*));
        new->next = NULL;
        new->coeff = 0;
        new->exp = i;
        if (cur1 == NULL && cur2 == NULL)
        {
            break;
        }
        else if (cur1 == NULL)
        {
            cur3->next = cur2;
            break;
        }
        else if (cur2 == NULL)
        {
            cur3->next = cur1;
            break;
        }
        if (cur1->exp == i)
        {
            new->coeff += cur1->coeff;
            cur1 = cur1->next;
        }
        if (cur2->exp == i)
        {
            new->coeff += cur2->coeff;
            cur2 = cur2->next;
        }
        if (cur3 == NULL)
        {
            poly3 = new;
            cur3 = poly3;
        }
        else
        {
            cur3->next = new;
            cur3 = cur3->next;
        }
    }
    return poly3;
}

void disp_poly(struct node* poly)
{
    printf("%d(x^%d)",poly->coeff,poly->exp);
    struct node* cur;
    cur = poly->next;
    while (cur != NULL)
    {
        if (cur->coeff>=0)
        {
            if (cur->exp == 0)
            {
                printf("+%d",cur->coeff);
            }
            else
            {
                printf("+%d(x^%d)",cur->coeff,cur->exp);
            }
        }
        else
        {
            if (cur->exp == 0)
            {
                printf("%d",cur->coeff);
            }
            else
            {
                printf("%d(x^%d)",cur->coeff,cur->exp);
            }
        }
        cur = cur->next;
    }
}