#include <iostream>
#include <thread>
#include <type_traits>
#include "math.h"
#include "synth.h"
#include "oscillator.h"
#include "sine.h"
#include "square.h"
#include "triangle.h"
#include "audioToFile.h"
#include "callback.h"
#include "jack_module.h"
#include "ui.h"

#define WRITE_TO_FILE 0


int main(int argc, char **argv) {
  auto callback = CustomCallback{};
  auto jackModule = JackModule{callback};

#if WRITE_TO_FILE
  AudioToFile audioToFile;
  audioToFile.write(callback);
#else

  jackModule.init(1, 1);

  std::cout << "\n\nType 'quit' to exit\n";
  bool running = true;
  while (running) {
    switch (std::cin.get()) 
    {
      case 'q':
        running = false;
        break;
    }
  }
#endif
  // end the program
  return 0;
} // main()