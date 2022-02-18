#include <iostream>
using namespace std;

// Structure
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

// Global variable
struct Node *head = NULL;
struct Node *head2 = NULL;

// Insert in first linked list
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

// Insert in second linked list
struct Node *insert2(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head2;
    if (head2 != NULL)
    {
        head2->prev = ptr;
        head2 = ptr;
    }
    head2 = ptr;
    return head;
}

// Insert at first
struct Node *insertatfirst(int data, int ll)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = ll == 1 ? head : head2;
    ll == 1 ? head = ptr : head2 = ptr;
    return head;
    return head2;
}

// Insert at last
struct Node *insertatlast(int data, int ll)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = ll == 1 ? head : head2;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
    return head2;
}

// Insert at index
struct Node *insertatindex(int data, int index, int ll)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = ll == 1 ? head : head2;
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
    return head2;
}

// Delete first node
struct Node *deletefirstnode(int ll)
{
    struct Node *ptr = ll == 1 ? head : head2;
    ll == 1 ? head = head->next : head2 = head2->next;
    ll == 1 ? head->prev = NULL : head2->prev = NULL;
    cout << ptr->data << " Successfully deleted" << endl;
    free(ptr);
    return head;
    return head2;
}

// Delete last node
struct Node *deletelastnode(int ll)
{
    struct Node *p = ll == 1 ? head->next : head2->next;
    struct Node *q = ll == 1 ? head : head2;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    q->next = NULL;
    cout << p->data << " Successfully Deleted" << endl;
    free(p);
    return head;
    return head2;
}

// Delete node with value
struct Node *deleteperticularnode(int node_data, int ll)
{
    struct Node *p = ll == 1 ? head->next : head2->next;
    struct Node *q = ll == 1 ? head : head2;
    while (p->data != node_data)
    {
        p = p->next;
        q = q->next;
    }
    q->next = p->next;
    cout << p->data << " Successfully Deleted" << endl;
    free(p);
    return head;
    return head2;
}

struct Node * concatenate(){
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = head2;
    return head;
}

// Display first linked list
void display(int ll)
{
    struct Node *ptr;
    ptr = ll == 1 ? head : head2;
    ll == 1 ? cout << "First linked list is: " : cout << "Second linked list is: ";
    while (ptr != NULL)
    {
        ll == 1 ? cout << ptr->data << " " : cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    int n, x, j, wish, f, index, c;
    do
    {
        cout << "1. Create first linked list\n2. Create second linked list\n3. Insert at first position\n4. Insert at last position\n5. Insert at index position\n6. Delete first node\n7. Delete last node\n8. Delete node with value\n9. Concatenate linked list\n10. Display" << endl;
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
            cout << "Enter the number of node you want to create - " << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter " << i + 1 << " Node - " << endl;
                cin >> x;
                insert2(x);
            }
            break;
        case 3:
            cout << "Enter 1 for insert in first linked list or enter 2 for insert in second linked list: " << endl;
            cin >> c;
            cout << "Enter Node - " << endl;
            cin >> f;
            insertatfirst(f, c);
            break;
        case 4:
            cout << "Enter 1 for insert in first linked list or enter 2 for insert in second linked list: " << endl;
            cin >> c;
            cout << "Enter Node - " << endl;
            cin >> f;
            insertatlast(f, c);
            break;
        case 5:
            cout << "Enter 1 for insert in first linked list or enter 2 for insert in second linked list: " << endl;
            cin >> c;
            cout << "Enter index where you want to insert: " << endl;
            cin >> index;
            cout << "Enter Node - " << endl;
            cin >> f;
            insertatindex(f, index, c);
            break;
        case 6:
            cout << "Enter 1 for delete node from first linked list or enter 2 for second linked list: " << endl;
            cin >> c;
            deletefirstnode(c);
            break;
        case 7:
            cout << "Enter 1 for delete node from first linked list or enter 2 for second linked list: " << endl;
            cin >> c;
            deletelastnode(c);
            break;
        case 8:
            cout << "Enter 1 for delete node from first linked list or enter 2 for second linked list: " << endl;
            cin >> c;
            cout << "Enter node data - ";
            cin>>index;
            deleteperticularnode(index, c);
            break;
        case 9:
            concatenate();
            break;
        case 10:
            cout << "Enter 1 for display first linked list or enter 2 for display second linked list: " << endl;
            cin >> c;
            display(c);
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