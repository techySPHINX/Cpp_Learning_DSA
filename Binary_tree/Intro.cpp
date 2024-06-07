#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// definition of binary tree code
struct Node
{
    int val;
    Node *left;
    Node *right;

    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    std::cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->val << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    std::cout << root->val << " ";
    inOrder(root->right);
}

int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    preOrder(root);
    std::cout << " " << std::endl;
    postOrder(root);
    std::cout << " " << std::endl;
    inOrder(root);
    std::cout << " " << std::endl;
}