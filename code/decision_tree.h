#ifndef DECISION_TREE_H__
#define DECISION_TREE_H__

#include <vector>
#include <iostream>
#include <string>
#include <map>

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

// creating a player structure for holding stats. we'll ingest this from the data file into a vector
struct player {
    string name;
    map <string, int> features; // using a map to hold the feature (string), and value (int)
    bool prediction; // this stores a prediction of whether or not a player scored more than 2 goals during the season
};

// deallocating memory for the tree
void deleteTree(node* root);

// initialize node
node* init_node(string feature, int threshold);

// add node
void add_node(node*& root, string feature, int threshold);

// prune node
void prune_node(node* root, string feature, int threshold);

// traverse decision tree
bool traverse(node* root, player p);

// calculate depth of tree
int depth(node* root);

// count the number of nodes
int count_nodes(node* root);

#endif // DECISION_TREE_H__