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

Node *removesHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
// without using third pointer
void removeHead(Node *&head)
{

    if (head == nullptr)
    {
        std::cout << "Error: List is empty." << std::endl;
        return;
    }

    head->data = head->next->data;
    head->next = head->next->next;

    delete head->next;
}
Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node *removekth(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cut = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cut++;
        if (cut == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {2, 3, 4, 5};
    Node* head = convertArr2LL(arr);
    printlist(head);
    int k;
    std::cout << "Enter a node to delete: ";
    std::cin >> k;
    head = removekth(head, k);
    printlist(head);
    return 0;
}
