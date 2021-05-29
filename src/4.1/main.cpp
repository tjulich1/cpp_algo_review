// Trent Julich ~ 28 May 2021

#include <iostream>
#include <vector>
#include <queue>

struct GraphNode 
{
  int value;
  std::vector<GraphNode*> neighbors;
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
    visitQueue.pop();

    for (int i = 0; i < currentNode->neighbors.size(); i++) {
      std::cout << "i: " << i << std::endl;
      if (currentNode->neighbors[i] == pEnd) {
        found = true;
        break;
      }
      visitQueue.push(currentNode->neighbors[i]);
    }
  }
  return found;
}

int main(int argc, char* argv[]) 
{
  int status = 0;

  GraphNode first, second, third, fourth;

  first.value = 1;
  second.value = 2;
  third.value = 3;

  std::vector<GraphNode*> firstNeighbors = {&second, &third};
  std::vector<GraphNode*> secondNeighbors = {&first};
  std::vector<GraphNode*> thirdNeighbors = {&first, &second};

  first.neighbors = firstNeighbors;
  second.neighbors = secondNeighbors;
  third.neighbors = thirdNeighbors;

  std::cout<<"Path exists? "<<Solution(&second, &fourth)<<std::endl;

  return status;
}
