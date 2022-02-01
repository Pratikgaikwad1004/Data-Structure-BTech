#include <iostream>
using namespace std;

// Create structure
struct Node
{
    int data;
    struct Node *next;
};

// Declare two global variable for front and rear
struct Node *front = NULL;
struct Node *rear = NULL;

// Function for enqueue operation
void enqueue(int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        p->data = data;
        p->next = NULL;
        if (front == NULL)
        {
            front = rear = p;
        }
        else
        {
            rear->next = p;
            rear = p;
        }
    }
}

// Dequeue element from queue
void dequeue()
{
    struct Node *ptr = front;
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        front = front->next;
        int element = ptr->data;
        free(ptr);
        if (!element)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            cout << "Dequeued element is: " << element << endl;
        }
    }
}

// Display queue
void display()
{
    struct Node *ptr;
    ptr = front;
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
        cout << "1. Enqueue\n2. Dequeue\n3. Display" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter data: " << endl;
            cin >> data;
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            cout << "Queue elements are: " << endl;
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