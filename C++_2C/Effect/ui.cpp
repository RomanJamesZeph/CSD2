#include "ui.h"


std::string UI::retrieveUserInput(std::string selectionOptions[], int numOptions)
{
    // show user the allowed options
    std::cout << "Please enter your selection (leave empty for random). You can choose from: ";
    for(int i = 0; i < numOptions - 1; i++) {
        std::cout << selectionOptions[i] << ", ";
    }
    // print last option outside forloop to end with an .
    std::cout << selectionOptions[numOptions - 1] << "." << std::endl;
    // retrieve and return choice
    std::string selection = "";
    std::getline(std::cin, selection);
    return selection;
}

int UI::retrieveUserSelection(std::string selectionOptions[], int numOptions)
{
  std::string selection = "";
  while(true) 
  {
    // let user choose from the allowed options
    selection = retrieveUserInput(selectionOptions, numOptions);

    // check if the selection is among the available option
	  for(int i=0; i<numOptions; ++i) 
      {
	      if(selection == selectionOptions[i]) 
        {
		      return i;
	      }
        // if the selection is empty choose a random selection
        else if(selection.empty())
        {
          srand(time(0)); 
          int randomSelection = rand() % numOptions;
          return randomSelection;
        }
	    }
  // if we end up here, this means the selection is not correct,
  // so log a message to user to try again
  std::cout << "Incorrect selection, please try again"  << std::endl;
  } // while
  return -1; // should never be reached
} // retrieveUserSelection()


float UI::retrieveValueInRangeFloat(std::string name, float min, float max)
{
  std::string input;
  float value = 0;
  bool notInRange = true;

  while(notInRange) {
    std::cout << "Please enter a " << name << " value between " << min << " and " << max << " (leave empty for random)." << std::endl;
    std::getline(std::cin, input);
    
    // if the input is empty choose a random value
    if (input.empty())
    {
      // formula to create random floating-point number in the range [min, max] created using ChatGPT
      float value = min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
      return value;
    }
    // validate if input string can be transformed into a float
    else try {
      value = std::stof(input);
      // validate range
      if(value >= min && value <= max) 
      {
        notInRange = false;
      } 
      else 
      {
        // value not in range
        std::cout << "Value out of range, please try again." << std::endl;
      }
    }
    catch (const std::exception& e) 
    {
      // no float as input
      std::cout << "Invalid input, expecting a number."
        << std::endl;
    }
  } // while not in range

  return value;
} // retrieveValueInRange()

int UI::retrieveValueInRangeInt(std::string name, int min, int max)
{
  std::string input;
  int value = 0;
  bool notInRange = true;

  while(notInRange) {
    std::cout << "Please enter a " << name << " value between " << min << " and " << max << " (leave empty for random)." << std::endl;
    std::getline(std::cin, input);
    
    // if the input is empty choose a random value
    if (input.empty())
    {
      // formula to create random int-point number in the range [min, max] created using ChatGPT
      int value = min + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / (max - min)));
      return value;
    }
    // validate if input string can be transformed into a int
    else try {
      value = std::stof(input);
      // validate range
      if(value >= min && value <= max) 
      {
        notInRange = false;
      } 
      else 
      {
        // value not in range
        std::cout << "Value out of range, please try again." << std::endl;
      }
    }
    catch (const std::exception& e) 
    {
      // no float as input
      std::cout << "Invalid input, expecting a number."
        << std::endl;
    }
  } // while not in range

  return value;
} // retrieveValueInRange()