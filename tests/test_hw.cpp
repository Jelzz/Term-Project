#include "../code/decision_tree.h"
#include <gtest/gtest.h>

#include <vector>
#include <iostream>
#include <string>

TEST(DecisionTreeTest, InitNode){

// Create nodes with different feature and threshold values
  node* n1 = init_node("feature1", 10);
  node* n2 = init_node("feature2", 20);

  // Check if nodes are initialized correctly
  EXPECT_EQ(n1->feature, "feature1");
  EXPECT_EQ(n1->threshold, 10);
  EXPECT_EQ(n2->feature, "feature2");
  EXPECT_EQ(n2->threshold, 20);

  // delete nodes
  deleteTree(n1);
  delete n2;
  n2 = nullptr;
}

TEST(DecisionTreeTest, AddNode){

  // Add 2 nodes to an empty tree
  node* root = nullptr;
  add_node(root, "feature1", 10);
  add_node(root, "feature2", 20);

  // Check if nodes are added correctly
  EXPECT_EQ(root->feature, "feature1");
  EXPECT_EQ(root->threshold, 10);
  EXPECT_EQ(root->right->feature, "feature2");
  EXPECT_EQ(root->right->threshold, 20);
  EXPECT_EQ(root->left->value, false);
  EXPECT_EQ(root->right->right->value, true);

  // delete nodes
  deleteTree(root);
}

TEST(DecisionTreeTest, PruneNode){
  // Add 2 nodes to an empty tree
  node* root = nullptr;
  add_node(root, "feature1", 10);
  add_node(root, "feature2", 20);

  // Remove feature2 node
  prune_node(root, "feature2", 20);

  // Check if node was pruned correctly
  EXPECT_EQ(root->feature, "feature1");
  EXPECT_EQ(root->threshold, 10);
  EXPECT_EQ(root->right->feature, "");
  EXPECT_EQ(root->right->threshold, NULL);
  EXPECT_EQ(root->right->value, true);
  EXPECT_EQ(root->left->value, false);

  // delete nodes
  deleteTree(root);
}

TEST(DecisionTreeTest, Depth){
  // Add 2 nodes to an empty tree
  node* root = nullptr;
  add_node(root, "feature1", 10);
  add_node(root, "feature2", 20);

  // Calculate depth
  int d = depth(root);
  EXPECT_EQ(d,2);
 
  // delete nodes
  deleteTree(root);
}

TEST(DecisionTreeTest, Traverse){
  // Add 2 nodes to an empty tree
  node* root = nullptr;
  add_node(root, "feature1", 10);
  add_node(root, "feature2", 20);

  // Create a player 
  player Smith;
  Smith.features["feature1"] = 15;
  Smith.features["feature2"] = 25;

  // Traverse the tree
  bool goal = traverse(root, Smith);
  EXPECT_EQ(goal, true);

  // Create a player 
  player Rodman;
  Rodman.features["feature1"] = 15;
  Rodman.features["feature2"] = 5;

  // Traverse the tree
  bool goal2 = traverse(root, Rodman);
  EXPECT_EQ(goal2, false);
 
  // delete nodes
  deleteTree(root);
}

// for my project: do a demo to check the number of nodes & depth, and then remove a node, then see if it's more accurate