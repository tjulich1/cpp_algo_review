// Trent Julich ~ 28 May 2021

#include <iostream>
#include <vector>
#include <queue>

struct GraphNode 
{
  int value;
  std::vector<GraphNode*> neighbors;
  bool visited = false;
};

// Determine if path from A -> B exists in graph.
bool Solution(GraphNode* pStart, GraphNode* pEnd) 
{
  bool found = false;

  std::queue<GraphNode*> visitQueue;

  visitQueue.push(pStart);

  while (!visitQueue.empty() && !found) 
  {
    GraphNode* currentNode = visitQueue.front();
    
    currentNode->visited = true;
    visitQueue.pop();

    for (int i = 0; i < currentNode->neighbors.size(); i++) {
      if (!currentNode->neighbors[i]->visited) {
        visitQueue.push(currentNode->neighbors[i]);
      }      
      if (currentNode->neighbors[i] == pEnd) {
        found = true;
        break;
      }
    }
  }
  return found;
}

int main(int argc, char* argv[]) 
{
  int status = 0;

  std::vector<GraphNode*> nodes;

  for (int i = 0; i < 6; i++) {
    std::cout << "Making node: " << i << std::endl;
    GraphNode* tempNode = new GraphNode();
    tempNode->value = i+1;
    nodes.push_back(tempNode);
  }

  std::vector<GraphNode*> firstNeighbors = {nodes[1]};
  std::vector<GraphNode*> secondNeighbors = {nodes[2], nodes[3]};
  std::vector<GraphNode*> thirdNeighbors = {nodes[4]};
  std::vector<GraphNode*> fourthNeighbors = {nodes[4]};
  std::vector<GraphNode*> sixthNeighbors = {nodes[0], nodes[4]};

  nodes[0]->neighbors = firstNeighbors;
  nodes[1]->neighbors = secondNeighbors;
  nodes[2]->neighbors = thirdNeighbors;
  nodes[3]->neighbors = fourthNeighbors;
  nodes[5]->neighbors = sixthNeighbors;

  int start = 6;
  int end = 1;

  std::cout << "Start node: "<<start<<" End node: "<<end<<" Connected: "<<
    Solution(nodes[start-1], nodes[end-1])<<std::endl;

  return status;
}
