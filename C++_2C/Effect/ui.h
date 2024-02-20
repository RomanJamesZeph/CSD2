/*
 * Utility code for validating user input
 *
 * Available checks and queries:
 * - expected numeric
 * - value within range
 * - string selection
 */
#ifndef _UI_H_
#define _UI_H_
#include <iostream>
#include <string>

class UI
{
public:
  int retrieveUserSelection(std::string selectionOptions[], int numOptions);
  float retrieveValueInRangeFloat(std::string name, float min, float max);
  int retrieveValueInRangeInt(std::string name, int min, int max);
private:
  std::string retrieveUserInput(std::string selectionOptions[], int numOptions);
};

#endif