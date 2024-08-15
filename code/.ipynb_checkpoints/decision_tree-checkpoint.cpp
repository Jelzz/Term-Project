#include "decision_tree.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// deallocating the tree memory
void deleteTree(node* root) {
    if (root == nullptr) {
        return; // Base case: empty tree
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

// initialize node
node* init_node(string feature, int threshold){
    node* new_node = new node;    
    new_node->feature = feature;
    new_node->threshold = threshold;
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->value = NULL;
    return new_node;
}

// add node
void add_node(node*& root, string feature, int threshold){
    // assume decision tree only has one branch to the right, all "yes"
    // this means every time we add a new decision node, it will be added at the bottom of the tree

    // if root is null (tree has no nodes yet), create root & it's children
    if (root == nullptr){
        root = init_node(feature, threshold);
        root->left = init_node("", NULL);
        root->left->value = false;

        root->right = init_node("", NULL);
        root->right->value = true;
        return;
    }

    // if root is not null, traverse to the deepest node
    node* cursor = root;
    node* parent;
    while (cursor->feature != ""){
        parent = cursor;
        cursor = cursor->right;
    }

    // reset parent's value to null
    parent->value = NULL;

    // update the right node to the values given
    node* new_node = parent->right;
    new_node->feature = feature;
    new_node->threshold = threshold;
    new_node->value == NULL;
    
    // add children to the right node
    new_node->left = init_node("", NULL);
    new_node->right = init_node("", NULL);
    new_node->right->value = true;
}

// prune node
void prune_node(node* root, string feature, int threshold){
    // if root is the only node
    if (root->right->feature == "" && root->left->feature == ""){
        // delete left & right nodes, set root to null
        delete root->left;
        delete root->right;
        delete root;
        root = nullptr;
        return;
    }

    // find the node & it's parent
    node* parent = root;
    root = root->right;
    if (root->feature == feature && root->threshold == threshold){
        parent->right = root->right;
        delete root->left;
        delete root;
        root = nullptr;
    }

    // TO DO: remove node when it's in the middle of the tree?
}

// traverse decision tree
bool traverse(node* root);

// evaluate test set

// print tree

// calculate depth of tree
int depth(node* root){
    int depth = 0;
    node* cursor = root;

    while (cursor->feature != ""){
        depth += 1;
        cursor = cursor->right;
    }
    return depth;
}

// count the number of nodes
int count_nodes(node* root);