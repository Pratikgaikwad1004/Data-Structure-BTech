#include <iostream>
using namespace std;

// Create Node
struct Node
{
    int data;
    struct Node *next;
};

// Declare head as a global variable
struct Node *head = NULL;

// Insert element
struct Node *insert(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    ptr->next = head;
    if (head != NULL)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    else
    {
        ptr->next = ptr;
    }
    head = ptr;
    return head;
}

// Insert at first
struct Node *insertatfirst(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    ptr->next = head;
    do
    {
        p = p->next;
    } while (p->next != head);
    p->next = ptr;
    return head;
}

// Insert at last
struct Node *insertatlast(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    do
    {
        p = p->next;
    } while (p->next != head);
    p->next = ptr;
    ptr->next = head;
    return head;
}

// Insert at index
struct Node *insertatindex(int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    struct Node *q = head;
    int i = 0;
    do
    {
        q = q->next;
        p = p->next;
    } while (i != index - 1);
    q->next = ptr;
    ptr->next = p;
    return head;
}

// Insert after node
struct Node *insertafternode(int data, int node_data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    struct Node *q = head;
    do
    {
        q = q->next;
        p = p->next;
    } while (q->data != node_data);
    q->next = ptr;
    ptr->next = p;
    return head;
}

// Delete first node
struct Node *deletefirstnode()
{
    struct Node *p = head;
    struct Node *q = head->next;
    do
    {
        p = p->next;
    } while (p->next != head);
    p->next = head->next;
    cout << "Deleting element: " << head->data << endl;
    free(head);
    head = p->next;
    cout << "Deleted Successfully" << endl;
    return head;
}

// Delete last node
struct Node *deletelastnode()
{
    struct Node *p = head->next;
    struct Node *q = head;
    do
    {
        q = q->next;
        p = p->next;
    } while (p->next != head);
    q->next = head;
    cout << "Deleting element: " << p->data << endl;
    free(p);
    cout << "Deleted Successfully" << endl;
    return head;
}

// Delete a node with it's value
struct Node *deleteperticularnode(int data)
{
    struct Node *p = head->next;
    struct Node *q = head;
    while (p->data != data && p->next != head)
    {
        p = p->next;
        q = q->next;
    }
    if (p->data == data)
    {
        q->next = p->next;
        cout << p->data << " Deleted successfully" << endl;
        free(p);
    }
    else
    {
        cout << data << " not found" << endl;
    }
    return head;
}

// Display linked list
void display()
{
    struct Node *ptr;
    ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
}
int main()
{
    int n, x, j, wish, f, index;
    do
    {
        cout << "1. Create\n2. Insert at first\n3. Insert at last\n4. Insert at index\n5. Insert after node\n6. Delete first node\n7. Delete last node\n8. Delete node with it's value\n9. Display" << endl;
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
            cout << "Enter node data where you want to insert: " << endl;
            cin >> index;
            cout << "Enter Node : " << endl;
            cin >> f;
            insertafternode(f, index);
            break;
        case 6:
            deletefirstnode();
            break;
        case 7:
            deletelastnode();
            break;
        case 8:
            cout << "Enter node value you want to delete - " << endl;
            cin >> index;
            deleteperticularnode(index);
            break;
        case 9:
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