#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void printlist(Node *head)
{
    if (head == nullptr)
    {
        cout << "Empty list." << endl;
    }
    Node *temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {2, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    return 0;
}
