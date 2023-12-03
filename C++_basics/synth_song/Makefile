# Makefile changed to C++11 standards using CHATGPT

CXXFLAGS = -std=c++11 -Wall -Wextra

synth: main.o sine.o square.o triangular.o oscillator.o writeToFile.o
	g++ $^ -o $@

main.o: main.cpp
	g++ $(CXXFLAGS) -c $<

sine.o: sine.cpp
	g++ $(CXXFLAGS) -c $<

square.o: square.cpp
	g++ $(CXXFLAGS) -c $<

triangular.o: triangular.cpp
	g++ $(CXXFLAGS) -c $<

oscillator.o: oscillator.cpp
	g++ $(CXXFLAGS) -c $<

writeToFile.o: writeToFile.cpp
	g++ $(CXXFLAGS) -c $<

clean:
	rm -f *.o synth

