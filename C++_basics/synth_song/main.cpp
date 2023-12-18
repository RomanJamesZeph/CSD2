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

int main(int argc, char **argv) {
  std::cout << "Welcome to R-J's C++ Synthesizer\n" << std::endl;
  auto callback = CustomCallback{};
  auto jackModule = JackModule{callback};

  AudioToFile audioToFile;
  audioToFile.write(callback);

  std::cout << "Playing random melody:" << std::endl;
  jackModule.init(1, 1);

  std::cout << "\n\nType 'q' to exit\n";
  bool running = true;
  while (running) {
    switch (std::cin.get()) 
    {
      case 'q':
        running = false;
        break;
    }
  }
  std::cout << "ending program" << std::endl;
  return 0;
}