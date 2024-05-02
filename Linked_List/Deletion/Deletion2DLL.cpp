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
    Node *prev;

    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *convertArr2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, mover);
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
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;

    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    Node *back = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    back = temp->prev;
    back->next = nullptr;
    temp->prev = nullptr;
    delete temp;

    return head;
}

Node *removekth(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cut = 0;
    Node *temp = head;
    Node *back = head;
    temp = temp->next;
    while (temp != NULL)
    {
        cut++;
        if (cut == k)
        {
            back->next = temp->next;
            temp->next->prev = back;
            free(temp);
            break;
        }
        back = temp;
        temp = temp->next;
    }
    return head;
}


//better approach with considering all edge cases
Node *removekthano(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    int cut = 0;
    Node *knode = head;
    while (knode != NULL)
    {
        cut++;
        if (cut == k)
        {
            break;
        }
        knode = knode->next;
    }
    Node *back = knode->prev;
    Node *front = knode->next;

    if (back == NULL && front == NULL)
    {
        return NULL;
    }
    else if (back == NULL)
    {
        return removeTail(head);
    }
    else if (front == NULL)
    {
        return removesHead(head);
    }
    else
    {
        back->next = front;
        front->prev = back;

        knode -> next =nullptr;
        knode -> prev =nullptr;
        delete knode;
        return head;
    }
}

int main()
{
    vector<int> arr = {2, 3, 4, 5};
    Node *head = convertArr2DLL(arr);
    printlist(head);
    std::cout << std::endl;
    head = removekthano(head,2);
    printlist(head);
    return 0;
}
