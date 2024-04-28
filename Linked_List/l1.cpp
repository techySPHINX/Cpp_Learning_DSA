#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

int main() {
    vector<int> arr = {2, 3, 4, 5};

    Node* head = new Node(arr[0], nullptr);
    Node* current = head;
    Node* temp = head;

    for (int i = 1; i < arr.size(); ++i) {
        current->next = new Node(arr[i], nullptr);
        current = current->next;
    }

    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;  // Move to the next node
    }

    return 0;
}
