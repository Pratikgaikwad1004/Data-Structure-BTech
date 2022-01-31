#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insert(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}
struct Node * InsertAtFirst(int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return ptr;
}
struct Node * InsertInBetween(int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node * InsertAtEnd(int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;

    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node * InsertAfterNode(int prevNode, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while (p->data != prevNode)
    {
        p = p->next;

    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct Node * DeleteFirstNode(){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node * DeleteInBetween(int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);       
    return head;
}
struct Node * DeleteLastNode(){
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);       
    return head;
}
struct Node * DeleteNodeWithValue(int data){
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != data && q->next!=NULL)
    {
        p = p->next;
        q = q->next;

    }
    if (q->data == data)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
void display()
{
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    int n, x, j, wish, f, index;
    do
    {
    cout << "1. Create\n2. Insert at first\n3. Insert in between\n4. Insert at end\n5. Insert after node\n6. Delete first node\n7. Delete in between\n8. Delete last node\n9. Delete given node\n10. Display"<<endl;
    cout << "Enter your choice : "<<endl;
    cin >> j;
    switch (j)
    {
    case 1:
        cout << "Enter the number of node you want to create - "<<endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter " << i + 1 << " Node - "<<endl;
            cin >> x;
            insert(x);
        }
        break;
    case 2:
        cout << "Enter Node - "<<endl;
        cin >> f;
        InsertAtFirst(f);
        break;
    case 3:
        cout << "Enter index where you want to insert: "<<endl;
        cin>>index;
        cout<< "Enter Node : "<<endl;
        cin>>f;
        InsertInBetween(f, index);
        break;
    case 4:
        cout << "Enter Node - "<<endl;
        cin >> f;
        InsertAtEnd(f);
        break;
    case 5:
        cout << "Enter previous node: "<<endl;
        cin>>index;
        cout<< "Enter Node : "<<endl;
        cin>>f;
        InsertAfterNode(index, f);
        break;
    case 6:
        DeleteFirstNode();
        break;
    case 7:
        cout << "Enter index of node you want to delete - "<<endl;
        cin >> index;
        DeleteInBetween(index);
        break;
    case 8:
        DeleteLastNode();
        break;
    case 9:
        cout << "Enter node value you want to delete - "<<endl;
        cin >> index;
        DeleteNodeWithValue(index);
        break;
    case 10:
        cout << "The linked list is: "<<endl;
        display();
        break;
    default:
        cout<<"Invalid choice"<<endl;
        break;
    }
    cout<<"\nPress 0 to continue or press 1 to exit : "<<endl;
    cin>>wish;
} while (wish == 0);
    return 0;
}