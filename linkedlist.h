#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LINKED LIST: SINGLE //

/*

  A linked list is a linear data structure that allows the users to store
  data in non-contiguous memory locations. A linked list is defined as a
  collection of nodes where each node consists of two members which
  represents its value and a next pointer which stores the address for
  the next node.

*/

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    Node* head;
public:
    LinkedList() : head(NULL) {} // head is initialized as null

    void insertAtBegin(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(int position);
    void display();
};

void LinkedList::insertAtBegin(int value) {
    //creates a new node
    Node* newNode = new Node();
    //give new node a new value and the next value after new node will be the head
    newNode->data = value;
    newNode->next = head;
    //setting the head to new node changes the head
    head = newNode;
}

void LinkedList::insertAtEnd(int value) {
    // creates new node
    Node* newNode = new Node();
    //give new node a new value and the next value after new node will be the head
    newNode->data = value;
    newNode->next = head;
    //if no head, head will be the newNode
    if (!head){
        head = newNode;
        return;
    }
    //traverse through the whole list till you get to the end
    Node* temp = head;
    while (temp->next){
        temp = temp->next;
    }
    //important: update the temp node to be the next newNode
    temp->next = newNode;
}

void LinkedList::insertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Position should be >= 1." << endl;
        return;
    }

    if (position == 1) {
        insertAtBegin(value);
        return;
    }
    Node* newNode = new Node();
    //give new node a new value and the next value after new node will be the head
    newNode->data = value;

    Node* temp = head;
    //traverse through list until you reach node BEFORE desired position
    // && temp is there bc traversal stops is temp is nullptr when input greater than list size occurs
    for (int i = 1; i < position - 1 && temp; i++) {
        //go to the next node
        temp = temp->next;
    }
    //if position is out of range, print error message
    if (!temp) {
        cout << "Position out of range." << endl;
        delete newNode;
        return;
    }

    // Insert the new node at the desired position
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::deleteFromBeginning() {
    //if head is nullptr, aint nothing there
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    /*temp becomes the new head, move the head details to the next limit, then delete temp*/
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteFromEnd() {
    //if head is nullptr, aint nothing there
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    //if next is nullptr
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
}