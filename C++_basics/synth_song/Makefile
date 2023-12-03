# Makefile changed to C++11 standards using CHATGPT

CXXFLAGS = -std=c++11 -Wall -Wextra

synth: writeToFile.o oscillator.o sine.o main.o
	g++ $^ -o $@

writeToFile.o: writeToFile.cpp
	g++ $(CXXFLAGS) -c $<

oscillator.o: oscillator.cpp
	g++ $(CXXFLAGS) -c $<

sine.o: sine.cpp
	g++ $(CXXFLAGS) -c $<

main.o: main.cpp
	g++ $(CXXFLAGS) -c $<

clean:
	rm -f *.o synth
