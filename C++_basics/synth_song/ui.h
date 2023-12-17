#ifndef _UI_H_
#define _UI_H_
#include <iostream>
#include <string>

class UI
{
public:
  int retrieveUserSelection(std::string selectionOptions[], int numOptions);
  float retrieveValueInRange(std::string name, float min, float max);
private:
  std::string retrieveUserInput(std::string selectionOptions[], int numOptions);
};

#endif