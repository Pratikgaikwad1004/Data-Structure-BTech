#include <iostream>
using namespace std;

// Create Node
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

// Declare head as a global variable
struct Node *head = NULL;

// Insert in linked list
struct Node *insert(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    if (head != NULL)
    {
        head->prev = ptr;
        head = ptr;
    }
    head = ptr;
    return head;
}

// Insert at first
struct Node *insertatfirst(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head = ptr;
    return head;
}

// Insert at last
struct Node *insertatlast(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Insert at index
struct Node *insertatindex(int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;
    return head;
}

// Delete first node
struct Node *deletefirstnode()
{
    struct Node *ptr = head;
    head = head->next;
    head->prev = NULL;
    cout << ptr->data << " Successfully deleted" << endl;
    free(ptr);
    return head;
}

// Delete last node
struct Node *deletelastnode()
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    q->next = NULL;
    cout << p->data << " Successfully Deleted" << endl;
    free(p);
    return head;
}

// Delete node with value
struct Node *deleteperticularnode(int node_data)
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->data != node_data)
    {
        p = p->next;
        q = q->next;
    }
    q->next = p->next;
    cout << p->data << " Successfully Deleted" << endl;
    free(p);
    return head;
}

// Display linked list
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
        cout << "1. Create\n2. Insert at first\n3. Insert at last\n4. Insert at index\n5. Delete first node\n6. Delete last node\n7. Delete node with it's value\n8. Display" << endl;
        cout << "Enter your choice : " << endl;
        cin >> j;
        switch (j)
        {
        case 1:
            cout << "Enter the number of node you want to create - " << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter " << i + 1 << " Node - " << endl;
                cin >> x;
                insert(x);
            }
            break;
        case 2:
            cout << "Enter Node - " << endl;
            cin >> f;
            insertatfirst(f);
            break;
        case 3:
            cout << "Enter Node - " << endl;
            cin >> f;
            insertatlast(f);
            break;
        case 4:
            cout << "Enter index where you want to insert: " << endl;
            cin >> index;
            cout << "Enter Node : " << endl;
            cin >> f;
            insertatindex(f, index);
            break;
        case 5:
            deletefirstnode();
            break;
        case 6:
            deletelastnode();
            break;
        case 7:
            cout << "Enter index of node you want to delete - "<<endl;
            cin >> index;
            deleteperticularnode(index);
            break;
        case 8:
            cout << "The linked list is: " << endl;
            display();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "\nPress 0 to continue or press 1 to exit : " << endl;
        cin >> wish;
    } while (wish == 0);
    return 0;
}