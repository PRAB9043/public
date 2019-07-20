/* Adding a node from beginning
* i/p : 1->2->3->4->5
* o/p : 1->2->3->4->5
*/

#include <iostream>
using namespace std;

typedef struct st
{
    int node;
    struct st * next;
}ST;

ST *hptr = NULL;
void print_list(ST *ptr);
void add_begin(ST **ptr);
void insert_a_node(ST **ptr);
void DeleteNodeFromList(ST **ptr);
void DeleteNodeAnyPosition(ST **ptr);
void ReverseList(ST **ptr);
void RecursiveReverseList(ST **ptr);
void FindMiddleNode(ST **ptr);
void DeleteFromLast(ST **ptr);

int  main()
{
    int ele;
    cout<<"Enter the element...\n";
    cin>>ele;
    int i;
    for(i = 0 ;i < ele; i++)
        add_begin(&hptr);
    print_list(hptr);
    insert_a_node(&hptr);
    cout<<"****************After insert a node...***************\n";
    print_list(hptr);
    DeleteNodeFromList(&hptr);
    cout<<"****************After Delete a node from List ************\n";
    print_list(hptr);
    DeleteNodeAnyPosition(&hptr);
    cout<<"****************After Delete a node from any position ************\n";
    print_list(hptr);
    ReverseList(&hptr);
    cout<<"****************After Reverse a List ************\n";
    print_list(hptr);
    RecursiveReverseList(&hptr);
    cout<<"****************After Recursive Reverse a List ************\n";
    print_list(hptr);
    FindMiddleNode(&hptr);
    DeleteFromLast(&hptr);
    cout<<"****************After Delete a node from last position ************\n";
    print_list(hptr);
    return 0;
}
void DeleteFromLast(ST **ptr)
{
    ST *D_next,*D_prev, *temp;
    int position;
    cout<<"Enter the last position you want to delete a node...\n";
    cin>>position;
    D_next = D_prev = *ptr;
    int i=0;
    while(i++ <position)
        D_next = D_next->next;
    while(D_next->next)
    {
        D_prev = D_prev->next;
        D_next = D_next->next;
    }
    temp = D_prev->next;
    D_prev->next = temp->next;
    cout<<"delete a node from last position and find a node from last position are "<<temp->node<<endl;
    delete temp;
    temp = NULL;
}
void FindMiddleNode(ST **ptr)
{
    ST *temp,*temp1;
    temp  = temp1 = *ptr;
    while(temp1 != NULL && temp1->next != NULL)
    {
        temp1 = temp1->next->next;
        temp = temp->next;
    }
    cout<<temp->node<<" Number are middle node from the list"<<endl;
}
void print_list(ST *ptr)
{
    while(ptr)
    {
        cout<<ptr->node<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}
void add_begin(ST **ptr)
{
    ST *temp = new ST;
    ST *temp1;
    cout<<"Insert the node...\n";
    cin>>temp->node;
    if((*ptr == 0) || (temp->node < (*ptr)->node))
    {
        temp->next = *ptr;
        *ptr = temp;
    }
    else
    {
        temp1 = *ptr ;
        while((temp1->next != NULL) && (temp1->next->node < temp->node))
            temp1= temp1->next;
        temp->next = temp1->next;
        temp1->next = temp;
    }
}
void insert_a_node(ST **ptr)
{
    int node,position;
    cout<<"Enter the node you want to insert...\n";
    cin>>node;
    cout<<"Enter the position you want to insert the node...\n";
    cin>>position;
    ST *temp = new ST;
    temp->node = node;
    if(position == 0)
    {
        temp->next = *ptr;
        *ptr = temp;
        return;
    }
    else
    {
        int tempVar = 1;
        ST *temp1 = *ptr;
        while(temp1->next != NULL && (tempVar < position-1))
        {
            tempVar++;
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}
void DeleteNodeFromList(ST **ptr)
{
    ST *temp = *ptr;
    ST *temp1;
    int node;
    cout<<"Enter the node you want to delete a from the list...\n";
    cin>>node;

    while(temp)
    {
        if(temp->node == node)
        {
            if(temp->node == (*ptr)->node)
            {
                *ptr = (*ptr)->next;
                delete temp;
                temp = NULL;
                return;
            }
            else{
                temp1->next = temp->next;
                delete temp;
                temp = NULL;
                return;
            }
        }
        temp1 = temp;
        temp = temp->next;
    }
}
void DeleteNodeAnyPosition(ST **ptr)
{
    int position;
    cout<<"Enter the position you want to delete node...\n";
    cin>>position;
    ST *temp = *ptr;
    if(position == 0)
    {
        *ptr = temp->next;
        delete temp;
        temp = NULL;
        return;
    }
    else{
        int tempVar = 1;
        while(tempVar < (position - 1))
        {
            tempVar++;
            temp = temp->next;
        }
        ST *temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
        temp1 = NULL;
    }
}
void ReverseList(ST **ptr)
{
    ST *next = NULL, *prev = NULL;
    while(*ptr != NULL)
    {
        next = (*ptr)->next;
        (*ptr)->next = prev;
        prev = *ptr;
        *ptr = next;
    }
    *ptr = prev;
}
void RecursiveReverseList(ST **ptr)
{
    static ST *next = NULL, *prev = NULL;
    if(*ptr != NULL)
    {
        next = (*ptr)->next;
        (*ptr)->next = prev;
        prev = *ptr;
        *ptr = next;
        RecursiveReverseList(ptr);
    }
    else{
        *ptr = prev;
    }
}
