#ifndef BST_H
#define BST_H

#include <iostream>

//a single BST node, just key + left/right pointers
template <typename T>
class BSTNode {
public:
    T key;
    BSTNode<T>* left;
    BSTNode<T>* right;

    BSTNode(T val) {
        key = val;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BinarySearchTree {
private:
    BSTNode<T>* root;

    //recursive helper that finds the right spot and inserts
    BSTNode<T>* insertHelper(BSTNode<T>* node, T val) {
        if (node == nullptr) {
            return new BSTNode<T>(val);
        }
        if (val < node->key) {
            node->left = insertHelper(node->left, val);
        } else {
            node->right = insertHelper(node->right, val);
        }
        return node;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(T val) {
        root = insertHelper(root, val);
    }

    BSTNode<T>* getRoot() {
        return root;
    }
};

//pre order: node, left, right
template <typename T>
void preOrder(BSTNode<T>* node) {
    if (node == nullptr) return;
    std::cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

//in order: left, node, right
template <typename T>
void inOrder(BSTNode<T>* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    std::cout << node->key << " ";
    inOrder(node->right);
}

//post order: left, right, node
template <typename T>
void postOrder(BSTNode<T>* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->key << " ";
}

#endif
