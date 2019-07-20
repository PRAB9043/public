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

enum Single
{
    EXIT_LIST = 0,
    PRINT_LIST = 1,
    ADD_BEGIN = 2,
    INSERT_A_NODE = 3,
    DELETENODEFROMLIST = 4,
    DELETENODEANYPOSITION = 5,
    REVERSELIST = 6,
    RECURSIVEREVERSELIST = 7,
    FINDMIDDLENODE = 8,
    DELETEFROMLIST = 9
};
