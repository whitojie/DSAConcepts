//
// Created by whito on 10/25/2024.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Binary Search Tree

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
        else if(root->right != nullptr){ // find a successor to replace this node
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

int BST::predecessor(Node *root) { // find greatest value below the left child of this root node
    root = root->left;
    while(root->right != nullptr){
        root = root->right;
    }
    return root->data;
}
