// Trent Julich ~ 31 May 2021

#include <iostream>

#include "../structures/tree_node.hpp"

/*
  Function which takes a binary tree, and returns true if it is a BST,
  i.e. all values to the left of the current node are smaller, and all 
  values to the right of the current node are larger.
*/
bool Validate(TreeNode* root) 
{
  bool valid = true;

  if ((root->left && root->left->value > root->value) ||
    (valid && root->right && root->right->value < root->value))
  {
    valid = false;
  } 
  else 
  {
    if (root->left) 
    {
      valid = Validate(root->left);
    }
    if (root->right)
    {
      valid = valid && Validate(root->right);
    }
  }
  return valid;
}

int main(int argc, char* argv[]) 
{
    TreeNode* lr = new TreeNode(3);   
    TreeNode* ll = new TreeNode(1);
    TreeNode* l = new TreeNode(2, ll, lr);

    TreeNode* rl = new TreeNode(5);
    TreeNode* rr = new TreeNode(7);
    TreeNode* r = new TreeNode(6, rl, rr);

    TreeNode* root = new TreeNode(4, r, l);

    std::cout<<"Valid tree? "<<Validate(root)<<std::endl;

    delete lr;
    delete ll;
    delete l;
    delete rl;
    delete rr;
    delete r;
    delete root;

    return 0;
}