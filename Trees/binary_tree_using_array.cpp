#include <iostream>
using namespace std;

// Array
char tree[10];

// Set root node
void root(char data)
{
    if (tree[0] != '\0')
    {
        cout << "Tree already had root node" << endl;
    }
    else
    {
        tree[0] = data;
        cout << "Now root node is: " << data << endl;
    }
}

// Set left node
void setleft(char data, int treeindex)
{
    if (tree[treeindex] == '\0')
    {
        cout << "\nCan't set child at index " << (treeindex * 2) + 1 << " , no parent found" << endl;
    }
    else
    {
        tree[(treeindex * 2) + 1] = data;
        cout << data << " Set at index " << (treeindex * 2) + 1;
    }
}

// Set right node
void setright(char data, int treeindex)
{
    if (tree[treeindex] == '\0')
    {
        cout << "\nCan't set child at index " << (treeindex * 2) + 2 << " , no parent found" << endl;
    }
    else
    {
        tree[(treeindex * 2) + 2] = data;
        cout << data << " Set at index " << (treeindex * 2) + 2;
    }
}

// Display
void display()
{
    for (int i = 0; i < 10; i++)
    {
        if (tree[i] != '\0')
            cout << tree[i];
        else
            cout << "-";
    }
}

int main()
{
    int wish, ch, treeindex;
    char data;
    do
    {
        cout << "1. Set root node\n2. Set left node\n3. Set right node\n4. Display" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter node - " << endl;
            cin >> data;
            root(data);
            break;
        case 2:
            cout << "Enter tree index: " << endl;
            cin >> treeindex;
            cout << "Enter node - " << endl;
            cin >> data;
            setleft(data, treeindex);
            break;
        case 3:
            cout << "Enter tree index: " << endl;
            cin >> treeindex;
            cout << "Enter node - " << endl;
            cin >> data;
            setright(data, treeindex);
            break;
        case 4:
            display();
            break;

        default:
            cout << "Invalid choice";
            break;
        }
        cout << "\nEnter 0 for continue and enter 1 for exit :" << endl;
        cin >> wish;
    } while (wish == 0);

    return 0;
}