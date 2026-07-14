// How to define Doubly Linked List in C++
#include <bits/stdc++.h>
using namespace std;

// Class representing a node in Doubly Linked List
class Node {
public:
    // Stores data of the node
    int data;

    // Pointer to the next node
    Node* next;

    // Pointer to the previous node
    Node* prev;

    // Constructor when data, next and prev are provided
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    // Constructor when only data is provided
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

int main() {
    // Initializing an array to create nodes
    vector<int> arr = {2, 5, 8, 7};

    // Creating the head node of the doubly linked list
    Node* head = new Node(arr[0]);

    // Printing the address of the head node
    cout << head << '\n';

    // Printing the data stored in head node
    cout << head->data << '\n';

    return 0;
}
