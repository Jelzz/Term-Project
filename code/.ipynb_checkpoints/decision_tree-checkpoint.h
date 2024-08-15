#ifndef DECISION_TREE_H__
#define DECISION_TREE_H__

#include <vector>
#include <iostream>
#include <string>

using namespace std;

// define the node structure
struct node {
    string feature;
    int threshold;
    node* left;
    node* right;
    bool value;

    ~node() {
        // cout << "Destructor called for node with feature: " << feature << ", and value: " << value << endl;
    }
};

struct player {
    string name;
    int minPlayed;
    int gamesPlayed;
    int goals;
}

// deallocating memory for the tree
void deleteTree(node* root);

// initialize node
node* init_node(string feature, int threshold);

// add node
void add_node(node*& root, string feature, int threshold);

// prune node
void prune_node(node* root, string feature, int threshold);

// traverse decision tree
bool traverse(node* root);

// evaluate test set

// print tree

// calculate depth of tree
int depth(node* root);

// count the number of nodes
int count_nodes(node* root);

#endif // DECISION_TREE_H__