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

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

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

Node *insertHead(Node *head, int val)
{
    return new Node(val, head);
}

Node *insertEnd(Node *head, int val)
{
    if (head == nullptr)
    {
        return new Node(val);
    }
    Node *temp = head;
    Node *New = new Node(val);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = New;
    return head;
}

Node *insertkth(Node *head, int val, int k)
{
    if (head == nullptr && k == 1)
    {
        return new Node(val);
    }

    if (k == 1)
    {
        return new Node(val, head);
    }

    int listLength = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        listLength++;
        temp = temp->next;
    }

    if (k <= 0 || k > listLength)
    {
        cerr << "Error: Invalid insertion position (k must be between 1 and the list length)." << endl;
        return head;
    }

    temp = head;
    int count = 1;
    while (temp != nullptr && count < k)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr)
    {
        return insertEnd(head, val);
    }

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    printlist(head);
    std::cout << std::endl;
    head = insertHead(head, 100);
    printlist(head);
    std::cout << std::endl;
    head = insertEnd(head, 100);
    printlist(head);
    std::cout << std::endl;
    int k;
    cout << " Enter the node where you want t insert: " << endl;
    cin >> k;
    head = insertkth(head, 100, 2);
    printlist(head);
    return 0;
}
