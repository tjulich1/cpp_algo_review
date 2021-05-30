#include <vector>
#include <iostream> 

struct TreeNode 
{
  int value;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int pValue, TreeNode* pLeft, TreeNode* pRight) {
    value = pValue;
    left = pLeft;
    right = pRight;
  }
};

void Traverse(TreeNode* root) 
{
  std::cout<<"Root value: "<<root->value<<std::endl;
  if (root->left) 
  {
    std::cout<<"Left value: "<<root->left->value<<std::endl;
  }
  if (root->right)
  {
    std::cout<<"Right value: "<<root->right->value<<std::endl;
  }
  if (root->left) 
  {
    Traverse(root->left);
  }
  if (root->right) 
  {
    Traverse(root->right);
  }

}

TreeNode* BuildTree(std::vector<int> &values) 
{
  int size = values.size();
  TreeNode* root = new TreeNode(-1, nullptr, nullptr);
  switch(size) {
    case 0: 
    {
      break;
    }
    case 1:
    {
      root->value = values[0];
      break;
    }
    case 2:
    {
      root->value = values[1];
      TreeNode* left = new TreeNode(values[0], nullptr, nullptr);
      root->left = left;
      break;
    }
    case 3:
    {
      root->value = values[1];
      TreeNode* right = new TreeNode(values[2], nullptr, nullptr);
      TreeNode* left = new TreeNode(values[0], nullptr, nullptr);      
      root->left = left;
      root->right = right;
      break;
    }
    default:
    {
      root->value = values[size/2];
      std::vector<int> leftValues(values.begin(), values.begin() + size/2);
      std::vector<int> rightValues(values.begin() + (size/2) + 1, values.end());
      TreeNode* left = BuildTree(leftValues);
      TreeNode* right = BuildTree(rightValues);
      root->left = left;
      root->right = right;
      break;
    }
  }
  return root;
}

int main(int argc, char* argv[]) 
{
  std::vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  TreeNode* tree = BuildTree(values);

  std::cout << "Finished" << std::endl;

  Traverse(tree);

  return 0;
} 