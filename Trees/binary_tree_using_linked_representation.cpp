#include <iostream>
using namespace std;

// Structure
struct Node
{
    struct Node *left;
    char data;
    struct Node *right;
};
// Create variable for root node;
struct Node *root = NULL;

// Create node
struct Node *createnode(char data)
{
    if (root == NULL)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        root = new_node;
        cout << "Root node created: " << root->data << endl;
        return root;
    }
    else
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        struct Node *p = root;
        char choice;
        while (1)
        {

            cout << "Enter l for insert left side of " << p->data << " and r for right side of " << p->data << endl;
            cin >> choice;
            if (choice == 'l')
            {
                if (p->left == NULL)
                {
                    p->left = new_node;
                    break;
                }
                else
                {
                    p = p->left;
                }
            }
            else
            {
                if (p->right == NULL)
                {
                    p->right = new_node;
                    break;
                }
                else
                {
                    p = p->right;
                }
            }
        }
    }
    return root;
}

// Preorder traversal
void preOrder(struct Node *r)
{
    if (r != NULL)
    {
        cout << r->data << " ";
        preOrder(r->left);
        preOrder(r->right);
    }
}

// Inorder traversal
void InOrder(struct Node *r)
{
    if (r != NULL)
    {
        InOrder(r->left);
        cout << r->data << " ";
        InOrder(r->right);
    }
}

// Postorder traversal
void PostOrder(struct Node *r)
{
    if (r != NULL)
    {
        PostOrder(r->left);
        PostOrder(r->right);
        cout << r->data << " ";
    }
}

int main()
{

    int wish, ch, n;
    char data;
    do
    {
        cout << "1. Create tree\n2. Preorder traversal\n3. Inorder traversal\n4. Postorder traversal" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the number of node you want to create - " << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter node - " << endl;
                cin >> data;
                createnode(data);
            }
            break;
        case 2:
            preOrder(root);
            break;
        case 3:
            InOrder(root);
            break;
        case 4:
            PostOrder(root);
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
