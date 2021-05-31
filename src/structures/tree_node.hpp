#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

struct TreeNode {
  int value;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int pValue) 
  {
    value = pValue;
    left = 0;
    right = 0;
  }

  TreeNode(int pValue, TreeNode* pLeft, TreeNode* pRight) 
  {
    value = pValue;
    left = pLeft;
    right = pRight;
  }
};

#endif