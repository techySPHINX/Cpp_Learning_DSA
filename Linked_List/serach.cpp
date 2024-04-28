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

    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
        next = next1;
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

int checkIfPresent(Node *head, int val)
{

    if (head == nullptr)
    {
        cout << "Empty list." << endl;
        return 0;
    }
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == val)
            return 1;
        
        temp = temp->next;

    }
    return 0;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    Node *temp = head;
    int val;

    std::cout << "Enter a val to find: ";
    std::cin >> val;

    printlist(head);
    std::cout << std::endl;
    cout << checkIfPresent(head, val);

    return 0;
}
