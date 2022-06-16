#include<iostream>
using namespace std;

typedef int element;

typedef struct Node
{
    element data;
    struct Node *left, *right;
}Node;

Node* makeNode(element item)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    
    return newNode;
}

void fillTree(Node* root, Node* l, Node* r)
{
    root->left = l;
    root->right = r;
}
                     
void preorder(Node *root)
{
    if(root != NULL)
    {
        cout << "("<<root->data<<") ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << "("<<root->data<<") ";
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << "("<<root->data<<") ";
    }
}

int main()
{
   Node *node[7], *root;
    
   for(int i=0; i<7; ++i) {
      node[i] = makeNode(i+1);
   }

   root = node[0];

    fillTree(root, node[1], node[2]);
    fillTree(node[1], node[3], nullptr);
    fillTree(node[2], node[4], node[5]);
    fillTree(node[3], NULL, NULL);
    fillTree(node[4], NULL, node[6]);
    fillTree(node[5], NULL, NULL);
    fillTree(node[6], NULL, NULL);
    
    cout << "===preorder===\n";
    preorder(root);
    cout << "\n===inorder===\n";
    inorder(root);
    cout << "\n===postorder===\n";
    postorder(root);
}
