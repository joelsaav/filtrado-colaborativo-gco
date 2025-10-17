#include <iostream>

#include "../include/recommender-system.h"
#include "../include/tools.h"

int main(int argc, char* argv[]) {
  CommandLineArgs args = CheckArguments(argc, argv);

  std::string matrixFile = args.matrixFile;
  int metric = args.metric;
  int numNeighbors = args.numNeighbors;
  int predictionType = args.predictionType;

  RecommenderSystem rs(matrixFile, metric, numNeighbors, predictionType);
  rs.Recommend();
  std::cout << rs << std::endl;
  
  return 0;
}