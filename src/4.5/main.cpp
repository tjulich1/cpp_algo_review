// Trent Julich ~ 31 May 2021

#include <iostream>

#include "../structures/tree_node.hpp"

/*
  Function which takes a binary tree, and returns true if it is a BST,
  i.e. all values to the left of the current node are smaller, and all 
  values to the right of the current node are larger.
*/
bool Validate(TreeNode* root, int min, int max) 
{
  bool valid = true;

  // Check that the current node is above the min.
  if (min != NULL && root->value <= min)
  {
    valid = false;
  }
  
  // Check that the current node is below the max.
  if (max != NULL && root->value > max)
  {
    valid = false;
  }

  // Validate the left branch of the tree.
  if (valid && root->left) 
  {
    valid = Validate(root->left, min, root->value);
  }

  // Validate the right branch of the tree.
  if (valid && root->right)
  {
    valid = Validate(root->right, root->value, max);
  }

  return valid;
}

int main(int argc, char* argv[]) 
{
    TreeNode* lr = new TreeNode(4);   
    TreeNode* ll = new TreeNode(1);
    TreeNode* l = new TreeNode(2, ll, lr);

    // TreeNode* rl = new TreeNode(5);
    // TreeNode* rr = new TreeNode(7);
    // TreeNode* r = new TreeNode(6, rl, rr);

    TreeNode* root = new TreeNode(5, l, nullptr);

    std::cout<<"Valid tree? "<<Validate(root, NULL, NULL)<<std::endl;

    delete lr;
    delete ll;
    delete l;

    // delete rl;
    // delete rr;
    // delete r;
    
    delete root;

    return 0;
}