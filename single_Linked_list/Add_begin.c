#include <stdio.h>
#include <stdlib.h>
typedef struct st
{
    int node;
    struct st * next;
}ST;

ST *hptr = NULL;
void print_list(ST *ptr);
void add_begin(ST **ptr);

int  main()
{
    int ele;
    printf("Enter the element...\n");
    scanf("%d",&ele);
    int i;
    for(i = 0 ;i < ele; i++)
        add_begin(&hptr);
    print(hptr);
    return 0;
}
void print(ST *ptr)
{
    while(ptr)
    {
        printf("%d ",ptr->node);
        ptr = ptr->next;
    }
    printf("\n");
}
void add_begin(ST **ptr)
{
    ST *temp = (ST *)malloc(sizeof(ST));
    ST *temp1;
    printf("Insert the node...\n");
    scanf("%d",&temp->node);
    if(*ptr == 0)
    {
        temp->next = *ptr;
        *ptr = temp;
    }
    else
    {
        temp1 = *ptr ;
        while(temp1->next != NULL)
            temp1= temp1->next;
        temp->next = temp1->next;
        temp1->next = temp;

    }
}
