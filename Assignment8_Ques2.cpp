#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int data) {
    if (!root) {
        root = new Node{data, nullptr, nullptr};
        return root;
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchNonRec(Node* root, int key) {
    while (root) {
        if (key == root->data) return root;
        root = (key < root->data) ? root->left : root->right;
    }
    return nullptr;
}

Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* curr = searchRec(root, key);
    if (!curr) return nullptr;

    if (curr->right)
        return minNode(curr->right);

    Node* succ = nullptr;
    Node* ancestor = root;
    while (ancestor != curr) {
        if (key < ancestor->data) {
            succ = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* curr = searchRec(root, key);
    if (!curr) return nullptr;

    if (curr->left)
        return maxNode(curr->left);

    Node* pred = nullptr;
    Node* ancestor = root;
    while (ancestor != curr) {
        if (key > ancestor->data) {
            pred = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return pred;
}

int main() {
    Node* root = nullptr;
    int a[] = {20, 8, 22, 4, 12, 10, 14};
    for (int x : a) root = insert(root, x);

    int key = 12;

    Node* sr = searchRec(root, key);
    Node* snr = searchNonRec(root, key);
    cout << "Search Recursive: " << (sr ? "Found" : "Not Found") << endl;
    cout << "Search Non-Recursive: " << (snr ? "Found" : "Not Found") << endl;

    cout << "Min: " << minNode(root)->data << endl;
    cout << "Max: " << maxNode(root)->data << endl;

    Node* succ = inorderSuccessor(root, key);
    cout << "Inorder Successor of " << key << ": " << (succ ? to_string(succ->data) : "None") << endl;

    Node* pred = inorderPredecessor(root, key);
    cout << "Inorder Predecessor of " << key << ": " << (pred ? to_string(pred->data) : "None") << endl;

    return 0;
}
