#ifndef TOOLS_H_
#define TOOLS_H_

#include <iostream>

struct CommandLineArgs {
  std::string matrixFile;
  int metric;
  int numNeighbors;
  int predictionType;
};

void ErrorOutput();
void HelpOutput();
CommandLineArgs CheckArguments(int argc, char *argv[]);


#endif