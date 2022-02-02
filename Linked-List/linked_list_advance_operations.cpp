#include <iostream>
using namespace std;

// Created Structure
struct Node
{
    int data;
    struct Node *next;
};

// Head node
struct Node *head = NULL;
struct Node *head2 = NULL;

// Insert data first in linked list
void insert(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

// Insert data in second linked list
void insert2(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head2;
    head2 = new_node;
}

// Inserting node at 1st position
struct Node *InsertAtFirst(int data, int ll)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ll == 1)
    {
        ptr->data = data;
        ptr->next = head;
        head = ptr;
    }
    else
    {
        ptr->data = data;
        ptr->next = head2;
        head2 = ptr;
    }
    return ptr;
}

// Inserting node index wise
struct Node *InsertInBetween(int data, int index, int ll)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ll == 1)
    {
        struct Node *p = head;
        int i = 0;
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
    }
    else
    {
        struct Node *p = head2;
        int i = 0;
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
    }
    return head2;
    return head;
}

// Inserting node at the end of linked list
struct Node *InsertAtEnd(int data, int ll)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ll == 1)
    {
        struct Node *p = head;
        ptr->data = data;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
    }
    else
    {
        struct Node *p = head2;
        ptr->data = data;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
    }
    return head2;
    return head;
}

// Inserting node after a perticular node
struct Node *InsertAfterNode(int prevNode, int data, int ll)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ll == 1)
    {
        struct Node *p = head;
        ptr->data = data;
        while (p->data != prevNode)
        {
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    else
    {
        struct Node *p = head2;
        ptr->data = data;
        while (p->data != prevNode)
        {
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return head2;
    return head;
}

// Delete first node
struct Node *DeleteFirstNode(int ll)
{
    if (ll == 1)
    {
        struct Node *ptr = head;
        head = head->next;
        free(ptr);
    }
    else
    {
        struct Node *ptr = head2;
        head2 = head2->next;
        free(ptr);
    }
    return head2;
    return head;
}

// Delete node index wise
struct Node *DeleteInBetween(int index, int ll)
{
    if (ll == 1)
    {
        struct Node *p = head;
        struct Node *q = head->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
    }
    else
    {
        struct Node *p = head2;
        struct Node *q = head2->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
    }
    return head2;
    return head;
}

// Delete last node
struct Node *DeleteLastNode(int ll)
{
    if (ll == 1)
    {
        struct Node *p = head;
        struct Node *q = head->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
    }
    else
    {
        struct Node *p = head2;
        struct Node *q = head2->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
    }
    return head2;
    return head;
}

// Delete a perticular node using it's value
struct Node *DeleteNodeWithValue(int data, int ll)
{
    if (ll == 1)
    {
        struct Node *p = head;
        struct Node *q = head->next;
        while (q->data != data && q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        if (q->data == data)
        {
            p->next = q->next;
            free(q);
        }
    }
    else
    {
        struct Node *p = head2;
        struct Node *q = head2->next;
        while (q->data != data && q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        if (q->data == data)
        {
            p->next = q->next;
            free(q);
        }
    }
    return head2;
    return head;
}

// Reverse linked list
/* Function to reverse the linked list */
static void reverse(int ll)
{
    if (ll == 1)
    {
        struct Node *p = NULL;
        struct Node *ptr = head;
        struct Node *n = NULL;
        while (ptr != NULL)
        {
            // Store next
            n = ptr->next;

            // Reverse current node's pointer
            ptr->next = p;

            // Move pointers one position ahead.
            p = ptr;
            ptr = n;
        }
        head = p;
    }
    else
    {
        struct Node *p = NULL;
        struct Node *ptr = head2;
        struct Node *n = NULL;
        while (ptr != NULL)
        {
            // Store next
            n = ptr->next;

            // Reverse current node's pointer
            ptr->next = p;

            // Move pointers one position ahead.
            p = ptr;
            ptr = n;
        }
        head2 = p;
    }
}

// Merge linked list
struct Node *merge()
{
    struct Node *ptr = head;

    // finding the lat node of first linked list
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = head2;
    return head;
}

// Display first linked list
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
// Display second linked list
void display2()
{
    struct Node *ptr;
    ptr = head2;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    int n, x, j, wish, f, index, c;
    int e = 0;
    do
    {
        cout << "\n\n1. Create first linked list\n2. Create second linked list\n3. Insert at first\n4. Insert in between\n5. Insert at end\n6. Insert after node\n7. Delete first node\n8. Delete in between\n9. Delete last node\n10. Delete given node\n11. Reverse linked list\n12. Concatenate first and second linked list\n13. Display first linked list\n14. Display second linked list\n15. Exit" << endl;
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
            InsertAtFirst(f, c);
            break;
        case 4:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            cout << "Enter index where you want to insert: " << endl;
            cin >> index;
            cout << "Enter Node : " << endl;
            cin >> f;
            InsertInBetween(f, index, c);
            break;
        case 5:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            cout << "Enter Node - " << endl;
            cin >> f;
            InsertAtEnd(f, c);
            break;
        case 6:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            cout << "Enter previous node: " << endl;
            cin >> index;
            cout << "Enter Node : " << endl;
            cin >> f;
            InsertAfterNode(index, f, c);
            break;
        case 7:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            DeleteFirstNode(c);
            break;
        case 8:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            cout << "Enter index of node you want to delete - " << endl;
            cin >> index;
            DeleteInBetween(index, c);
            break;
        case 9:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            DeleteLastNode(c);
            break;
        case 10:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            cout << "Enter node value you want to delete - " << endl;
            cin >> index;
            DeleteNodeWithValue(index, c);
            break;
        case 11:
            cout << "Enter 1 for change first linked list or enter 2 for change in second linked list: " << endl;
            cin >> c;
            reverse(c);
            break;
        case 12:
            merge();
            break;
        case 13:
            cout << "First linked list is: " << endl;
            display();
            break;
        case 14:
            cout << "Second linked list is: " << endl;
            display2();
            break;
        case 15:
            e = 1;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        if (e)
        {
            cout << "\nPress 0 to continue or press 1 to exit : " << endl;
            cin >> wish;
        }
    } while (wish == 0);
    return 0;
}