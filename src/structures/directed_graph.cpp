// Trent Julich

#include <vector>

bool GraphNode

struct GraphNode 
{
  int value;
  std::vector<GraphNode*> neighbors;
};

int main(int argc, char* argv[]) {

  GraphNode first, second, third;

  first.value = 1;
  second.value = 2;
  third.value = 3;

  std::vector<GraphNode*> firstNeighbors = {&second, &third};
  std::vector<GraphNode*> secondNeighbors = {&first};
  std::vector<GraphNode*> thirdNeighbors = {&first, &second};

  first.neighbors = firstNeighbors;
  second.neighbors = secondNeighbors;
  third.neighbors = thirdNeighbors;



  return 0;
}