CXX=g++

OBJ:=banker.o card.o dealer.o main.o player.o

FLAG:=-Wall -O3 -s
INC:=
LIB:=
EXE:=blackjack

all:
	$(CXX) -c *.cpp
	$(CXX) $(OBJ) -o $(EXE) $(FLAG)
	rm -r $(OBJ)    
clean:
	rm -r $(OBJ)
	rm -r $(EXE)
