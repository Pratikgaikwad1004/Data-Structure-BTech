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
        cout << "1. Create\n2. Display" << endl;
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