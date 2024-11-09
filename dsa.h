//
// Created by whito on 10/25/2024.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Binary Search Tree

struct Node {
    Node* left;
    Node* right;
    int data;

    explicit Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST();
    void insert(Node* node);
    void display();
    bool search(int data);
    void remove(int data);

private:
    Node* insertHelper(Node* root, Node* node);
    void displayHelper(Node* root);
    bool searchHelper(Node* root, int data);
    Node* removeHelper(Node* root, int data);
    int successor(Node* root);
    int predecessor(Node* root);
};

BST::BST(){
    root = nullptr;
}

void BST::insert(Node* node){
    root = insertHelper(root, node);
}
Node* BST::insertHelper(Node* root, Node* node) {
    int data = node->data;
    //if we found an empty spot where new node should be inserted
    if (root == nullptr){
        return node;
    }
    // if the data of new node is less than the root data, put it to the left
    else if (data < root->data){
        root->left = insertHelper(root->left, node);
    }
    //if data of new node is greater than root, put it to the right
    else{
        root->right = insertHelper(root->right, node);
    }
    return root;
}

void BST::display() {
    displayHelper(root);
}
void BST::displayHelper(Node *root) {
    if (root != nullptr){
        displayHelper(root->left);
        cout << root->data << endl;
        displayHelper(root->right);

    }
}

bool BST::search(int data) {
    return searchHelper(root, data);
}
bool BST::searchHelper(Node *root, int data) {
    //if not found, return false???
    if (root != nullptr){
        cout << "Could not be found lols" << endl;
        return false;
    }
    // if the data in root is the data being searched for, its there
    else if(root->data == data){
        return true;
    }
    //if data in root is greater than data being searched, recursively search left until data is found
    else if (root->data > data){
        return searchHelper(root->left, data);
    }
    // if data in root is less, recursively read right data until found
    else{
        return searchHelper(root->right, data);
    }
}

void BST::remove(int data) {
    if (search(data)){
        removeHelper(root, data);
    }
    else{
        cout << data << " could not be found." << endl;
    }
}
Node* BST::removeHelper(Node *root, int data) {
    if(root == nullptr){
        return root;
    }
    else if (data < root->data){
        root->left = removeHelper(root->left, data);
    }
    else if (data > root->data){
        root->right = removeHelper(root->right, data);
    }
    else{
        if(root->left == nullptr && root->right == nullptr){
            root = nullptr;
        }
        else if(root->right != nullptr){ //find a successor to replace this node
            root->data = successor(root);
            root->right = removeHelper(root->right, root->data);
        }
        else{ // find predecessor to replace node
            root->data = predecessor(root);
            root->left = removeHelper(root->left, root->data);
        }
    }
    return root;
}

int BST::successor(Node *root) { // find least value below right child of this root node
    root = root->right;
    while(root->left != nullptr){
        root = root->left;
    }
    return root->data;
}

int BST::predecessor(Node *root) { //find greatest value below the left child of this root node
    root = root->left;
    while(root->right != nullptr){
        root = root->right;
    }
    return root->data;
}

*/

// LINKED LIST: SINGLE //

/*A linked list is a linear data structure that allows the users to store
  data in non-contiguous memory locations. A linked list is defined as a
  collection of nodes where each node consists of two members which
  represents its value and a next pointer which stores the address for
  the next node. */

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