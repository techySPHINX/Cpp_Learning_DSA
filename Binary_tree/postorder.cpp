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
//using two stack
class Solution
{
public:
    vector<int> postorderTraversal(Node *root)
    {
        vector<int> postorder;
        stack<Node *> s1, s2;
        s1.push(root);

        if (root == NULL)
        {
            return postorder;
        }
        Node *node = root;

        while (!s1.empty())

        {
            root = s1.top();
            s1.pop();
            s2.push(root);
            if(root -> left != NULL){
                s1.push(root -> left);
            }
             if(root -> right != NULL){
                s1.push(root -> right);
            }
        }
        while (!s2.empty())
        {
            postorder.push_back(s2.top()->val);
            s2.top();
        }
        return postorder;
    }
};
