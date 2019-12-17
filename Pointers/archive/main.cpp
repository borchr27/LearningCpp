// LINKED LISTS, NODES, AND POINTERS
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *link;
};

typedef Node* nodePtr;
void insert(nodePtr& head, int data);

int main()
{
   nodePtr head;
   head = new Node;
    head->data = 20;
    head->link = NULL;


    insert (head, 30);
    nodePtr tmp;
    tmp = head;

    while(tmp->link != NULL)
    {
        cout << tmp->data << endl;
        tmp = tmp->link;
    }
    return 0;
}

// POINTER EXAMPLE
/*
int main(){
    int v1 = 0;
    int *p1;
    p1 = &v1;
    cout << v1 << " and pointer is " << *p1 << endl;
    *p1 = 42;
    cout << v1 << " and pointer is " << *p1 << endl;

}

*/
