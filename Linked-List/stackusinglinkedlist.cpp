#include <iostream>
using namespace std;

// Structure for linked list
struct Node
{
    int data;
    struct Node *next;
};

// Declare global variable top
struct Node *top = NULL;

// Checks stack is empty or not if empty it returns true if not empty it returns false
int isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Checks stack is full or not if full it returns true if not full it returns false
int isFull()
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Push the element in stack
struct Node *push(int data)
{
    if (isFull())
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->next = top;
        top = p;
    }
        return top;
}

// Pop element from stack
void pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        struct Node *p = top;
        top = top->next;
        int x = p->data;
        free(p);
        cout<<"Deleted element is: "<<x<<endl;
    }
}

// Display stack elements
void display()
{
    struct Node *ptr;
    ptr = top;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    int ch, data, wish;
    do
    {
        cout << "1. Push\n2. Pop\n3. isFull\n4. isEmpty\n5. Display" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter data: " << endl;
            cin >> data;
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (isFull())
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            break;
        case 4:
            if (isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;
        case 5:
            cout << "Stack is: " << endl;
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