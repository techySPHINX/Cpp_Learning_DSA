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

int main()
{
    vector<int> arr = {2, 3, 4, 5};
    Node *head = convertArr2LL(arr);
    Node* temp = head;
    int count = 0;
   

    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next; 
        count++;
        
    }
    std::cout << std::endl;
    std::cout << "The Length of given Linked List:" << count << std::endl;
    return 0;
}
