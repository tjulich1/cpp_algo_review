#include "../structures/tree_node.hpp"

#include<iostream>

/*
  Function to find the leftmost child of the rootNode.
*/
TreeNode* FindLeftmost(TreeNode& rootNode)
{
  if (!rootNode.left)
  {
    return &rootNode;
  }

  TreeNode *temp = rootNode.left;

  while (temp->left)
  {
    temp = temp->left;
  }
  return temp;
}

/*
  Function which returns the node that succeeds startNode following an in order traversal.
*/
TreeNode* NextNode(TreeNode &startNode) 
{
  TreeNode* successor = nullptr;
  if (startNode.right)
  {
    successor = FindLeftmost(*(startNode.right));
  } else 
  {
    TreeNode* temp = &startNode;
    TreeNode* tempParent = startNode.parent;
    
    while (tempParent != nullptr && temp != tempParent->left)
    {
      temp = tempParent;
      tempParent = tempParent->parent;
    }
    successor = tempParent;
  }
  return successor;
}

int main(int argc, char* argv[])
{
  
  TreeNode* ll = new TreeNode(1);
  TreeNode* l = new TreeNode(2, ll, nullptr);
  ll->parent = l;

  TreeNode* rl = new TreeNode(4);
  TreeNode* r = new TreeNode(5, rl, nullptr);
  rl->parent = r;

  TreeNode* root = new TreeNode(3, l, r);
  l->parent = root;
  r->parent = root;

  std::cout<<"Next value: "<<NextNode(*root)->value<<std::endl;

  delete ll;
  delete l;
  delete r;
  delete root;

  return 0;
}