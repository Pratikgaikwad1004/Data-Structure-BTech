#include <iostream>
using namespace std;

// Create structure
struct Node
{
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

// Insert in second linked list
struct Node *insert2(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head2;
    ptr->data = data;
    ptr->next = head2;
    if (head2 != NULL)
    {
        while (p->next != head2)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    else
    {
        ptr->next = ptr;
    }
    head2 = ptr;
    return head2;
}

// Insert at first
struct Node *insertatfirst(int data, int ll)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
        struct Node *p = ll == 1 ? head : head2;
        ptr->next = (ll == 1 ? head : head2);
        do
        {
            p = p->next;
        } while (p->next != (ll == 1 ? head : head2));
        p->next = ptr;
    return head;
    return head2;
}

// Insert at last
struct Node *insertatlast(int data, int ll)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = ll == 1 ? head : head2;
    do
    {
        p = p->next;
    } while (p->next != (ll == 1 ? head : head2));
    p->next = ptr;
    ptr->next = (ll == 1 ? head : head2);

    return head2;
    return head;
}

// Insert after node
struct Node *insertafternode(int data, int node_data, int ll)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = ll == 1 ? head->next: head2->next;
    struct Node *q = ll == 1 ? head : head2;
    do
    {
        q = q->next;
        p = p->next;
    } while (q->data != node_data);
    q->next = ptr;
    ptr->next = p;
    return head;
    return head2;
}

// Delete first node
struct Node *deletefirstnode(int ll)
{
    struct Node *p = ll == 1 ? head : head2;
    struct Node *q = ll == 1 ? head->next : head2->next;
    do
    {
        p = p->next;
    } while (p->next != (ll == 1 ? head : head2));
    p->next = ll == 1 ? head->next : head2->next;
    int deletedData = ll == 1 ? head->data : head2->data;
    cout << "Deleting element: " << deletedData << endl;
    free(ll == 1 ? head : head2);
    ll == 1 ? head = p->next : head2 = p->next;
    cout << "Deleted Successfully" << endl;
    return head;
    return head2;
}

// Delete last node
struct Node *deletelastnode(int ll)
{
    struct Node *p = ll == 1 ? head->next : head2->next;
    struct Node *q = ll == 1 ? head : head2;
    do
    {
        q = q->next;
        p = p->next;
    } while (p->next != (ll == 1 ? head : head2));
    ll == 1 ? q->next = head : q->next = head2;
    cout << "Deleting element: " << p->data << endl;
    free(p);
    cout << "Deleted Successfully" << endl;
    return head;
    return head2;
}

// Delete a node with it's value
struct Node *deleteperticularnode(int data, int ll)
{
    struct Node *p = ll == 1 ? head->next : head2->next;
    struct Node *q = ll == 1 ? head : head2;
    while (p->data != data && p->next != (ll == 1 ? head : head2))
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
    return head2;
}

// Concatenate two linked list
struct Node * concatenate(){
    struct Node *p = head;
    struct Node *q = head2;
    do
    {
        p = p->next;
    } while (p->next != head);
    p->next = head2;
    do
    {
        q = q->next;
    } while (q->next != head2);
    q->next = head;
    return head;
}

// Reverse linked list
struct Node * reverse(int ll){
    struct Node *p = NULL;
    struct Node *ptr = ll == 1 ? head : head2;
    struct Node *n = NULL;
    do
    {
        n = ptr->next;
        ptr->next = p;
        p = ptr;
        ptr = n;
    } while (ptr != (ll == 1 ? head : head2));
    
    ll == 1 ? head->next = p : head2->next = p;
    ll == 1 ? head = p : head2 = p;
    return head;
    return head2;
}

// Display first linked list
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

// Display second linked list
void display2()
{
    struct Node *ptr;
    ptr = head2;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head2);
}

int main()
{
    int n, x, j, wish, f, index, c;
    do
    {
        cout << "1. Create first linked list\n2. Create second linked list\n3. Insert at first\n4. Insert at last\n5. Insert after node\n6. Delete first node\n7. Delete last node\n8. Delete node with it's value\n9. Concatenate first and second linked list\n10. Reverse linked list\n11. Display first linked list\n12. Display second linked list" << endl;
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
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            cout << "Enter Node - " << endl;
            cin >> f;
            insertatfirst(f, c);
            break;
        case 4:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            cout << "Enter Node - " << endl;
            cin >> f;
            insertatlast(f, c);
            break;
        case 5:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            cout << "Enter node data where you want to insert: " << endl;
            cin >> index;
            cout << "Enter Node - " << endl;
            cin >> f;
            insertafternode(f, index, c);
            break;
        case 6:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            deletefirstnode(c);
            break;
        case 7:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            deletelastnode(c);
            break;
        case 8:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            cout << "Enter node position you want to delete - " << endl;
            cin >> index;
            deleteperticularnode(index, c);
            break;
        case 9:
            concatenate();
            break;
        case 10:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            reverse(c);
            break;
        case 11:
            cout << "The first linked list is: " << endl;
            display();
            break;
        case 12:
            cout << "\nThe second linked list is: " << endl;
            display2();
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