// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template <typename T>
class BST {
 private:
    struct NODE {
        T word;
        int count;
        NODE* left, * right;
    };
    NODE* root;
    NODE* addNODE(NODE* root, const T& word) {
        if (root == nullptr) {
            root = new NODE;
            root->word = word;
            root->left = root->right = nullptr;
            root->count = 1;
        } else if (root->word > word) {
            root->left = addNODE(root->left, word);
        } else if (root->word < word) {
            root->right = addNODE(root->right, word);
        } else {
            root->count++;
        }
        return root;
    }
    int heightTree(NODE* root) {
        if (root == nullptr) return 0;
        return std::max(heightTree(root->left), heightTree(root->right)) + 1;
    }
    NODE* searchTree(NODE* root, const T& word) {
        if (root == nullptr || root->word == word)
            return root;
        if (word < root->word)
            return searchTree(root->left, word);
        return searchTree(root->right, word);
    }

 public:
    BST() : root(nullptr) {}
    void add(const T& word) { root = addNODE(root, word); }
    int depth() { return heightTree(root) - 1; }
    int search(const T& word) {
        NODE* cur = searchTree(root, word);
        if (cur == nullptr) {
            return 0;
        } else {
            return cur->count;
        }
    }
};
#endif  // INCLUDE_BST_H_
