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

// Create BST
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

            if (new_node->data < p->data)
            {
                if (p->left == NULL)
                {
                    p->left = new_node;
                    cout << new_node->data << " Inserted at left of " << p->data << endl;
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
                    cout << new_node->data << " Inserted at rignt of " << p->data << endl;
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

// Insert in BST
struct Node *insert(int data)
{
    if (root == NULL)
    {
        cout<<"Root node is empty please create root node first"<<endl;
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

            if (new_node->data < p->data)
            {
                if (p->left == NULL)
                {
                    p->left = new_node;
                    cout << new_node->data << " Inserted at left of " << p->data << endl;
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
                    cout << new_node->data << " Inserted at rignt of " << p->data << endl;
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

// Insert in BST
struct Node *search(int data)
{
    if (root == NULL)
    {
        cout<<"Root node is empty please create root node first"<<endl;
        return root;
    }
    else
    {
        struct Node *p = root;
        char choice;
        while (1)
        {
            if (root->data == data)
            {
                cout << data << " is a root node" << endl;
                break;
            }
            else if (data < p->data)
            {
                if (p->left == NULL)
                {
                    cout << "Root node dosen't have child"<<endl;
                    break;
                }
                else
                {
                    p = p->left;
                    if (p->data == data || p->left == NULL)
                    {
                        cout << p->data << " found in tree";
                        break;
                    }
                     
                }
            }
            else
            {
                if (p->right == NULL)
                {
                    cout << "Node not found"<<endl;
                    break;
                }
                else
                {
                    p = p->right;
                    if (p->data == data)
                    {
                        cout << p->data << " found in tree";
                        break;
                    }
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
        cout << "1. Create tree\n2. Insert in tree\n3. Search in tree\n4. Delete from tree\n5. Preorder traversal\n6. Inorder traversal\n7. Postorder traversal" << endl;
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
            cout << "Enter node - " << endl;
            cin >> data;
            insert(data);
            break;
        case 3:
            cout << "Enter node - " << endl;
            cin >> data;
            search(data);
            break;
        case 4:

            break;
        case 5:
            cout << "Preorder Traversal" << endl;
            preOrder(root);
            break;
        case 6:
            cout << "Inorder traversal" << endl;
            InOrder(root);
            break;
        case 7:
            cout << "Postorder Traversal" << endl;
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