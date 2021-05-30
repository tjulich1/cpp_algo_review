#include <iostream>

struct TreeNode 
{
  int value;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int pValue) 
  {
    value = pValue;
  }

  TreeNode(int pValue, TreeNode* pLeft, TreeNode* pRight) 
  {
    value = pValue;
    left = pLeft;
    right = pRight;
  }  
};

bool isBalanced(TreeNode* root) 
{
  bool grandChildren = false;
  if (root->left && (root->left->left || root->left->right)) { grandChildren = true; }
  if (root->right && (root->right->left || root->right->right)) { grandChildren = true; }
  if (!(root->left && root->right) && grandChildren) { return false; }
  else if (!grandChildren) { return true; }
  return isBalanced(root->left) && isBalanced(root->right);
}

int main(int argc, char* argv[]) 
{
  TreeNode* leftGrand = new TreeNode(5);
  TreeNode* rightGrand = new TreeNode(6, leftGrand, nullptr);

  TreeNode* left = new TreeNode(2, leftGrand, rightGrand);
  TreeNode* right = new TreeNode(4, nullptr, rightGrand);
  TreeNode* root = new TreeNode(4, left, right);

  std::cout<<"Balanced: "<<isBalanced(root)<<std::endl;
  
  return 0;
}