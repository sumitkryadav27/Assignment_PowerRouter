#include<bits/stdc++.h>
using namespace std;

// Node structure
class Node{
public:
    int data;
    Node* next;

    // Default constructor
    Node(){
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Function to find middle element
int getMiddle( Node * head){

    if (head == NULL) {
        return -1;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

int main(){
    
    // Create linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    cout << "The middle element is " << getMiddle(head) << endl;

}