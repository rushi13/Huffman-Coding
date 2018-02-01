all : decoder encoder

decoder : decoder.cpp
	g++ -Wall -std=c++11 -o decoder decoder.cpp

encoder : huffman.cpp
	g++ -Wall -std=c++11 -o encoder huffman.cpp

clean :
	rm *.out decoder *.out encoder
