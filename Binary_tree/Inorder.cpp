#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#include <stack>

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
    vector<int> InorderTraversal(Node *root)
    {
        vector<int> inorder;
        stack<Node *> s;
        if (root == NULL)
        {
            return inorder;
        }
        Node *node = root;

        while (true)
        {
            if (node != NULL)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                if (s.empty() == true)
                    break;
                node = s.top();
                s.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};
