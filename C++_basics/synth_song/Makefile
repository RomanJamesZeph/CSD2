synth: writeToFile.o sine.o main.o
	g++ writeToFile.o sine.o main.o -o synth

writeToFile.o: writeToFile.cpp
	g++ -c writeToFile.cpp

sine.o: sine.cpp
	g++ -c sine.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.0 math