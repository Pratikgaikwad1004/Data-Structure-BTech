#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
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
        return top;
    }
}
int pop()
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
        return x;
    }
}
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