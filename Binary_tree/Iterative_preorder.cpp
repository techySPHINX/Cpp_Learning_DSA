#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> preOrderTraversal(Node *root)
    {
        vector<int> preOrder;
        if (root == NULL)
        {
            return preOrder;
        }
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            root = s.top();
            s.pop();
            preOrder.push_back(root -> val);
            if(root -> right ! = NULL) {
                s.push(root -> right);
            }
             if(root -> left ! = NULL) {
                s.push(root -> left);
            }
        }
        return preOrder;
    }
};