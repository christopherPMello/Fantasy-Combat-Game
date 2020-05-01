###
### @file - Fight Combat Game Tournament makefile
### @author - Christopher Mello
### @description - Makefile for the Fight Combat Game program
###

#
# fight Combat Game Tournament
#

output: main.o Menu.o Character.o Vampire.o Barbarian.o Blue_Men.o Medusa.o Harry_Potter.o GamePlay.o BattleField.o Queue.o QueueNode.o
	g++ main.o Menu.o Character.o Vampire.o Barbarian.o Blue_Men.o Medusa.o  Harry_Potter.o GamePlay.o BattleField.o Queue.o QueueNode.o -std=c++11 -o output

main.o: main.cpp
	g++ -c main.cpp -std=c++11

Menu.o: Menu.cpp
	g++ -c Menu.cpp -std=c++11

Character.o: Character.cpp
	g++ -c Character.cpp -std=c++11

Vampire.o: Vampire.cpp
	g++ -c Vampire.cpp -std=c++11

Barbarian.o: Barbarian.cpp
	g++ -c Barbarian.cpp -std=c++11

Blue_Men.o: Blue_Men.cpp
	g++ -c Blue_Men.cpp -std=c++11

Medusa.o: Medusa.cpp
	g++ -c Medusa.cpp -std=c++11

Harry_Potter.o: Harry_Potter.cpp
	g++ -c Harry_Potter.cpp -std=c++11

GamePlay.o: GamePlay.cpp
	g++ -c GamePlay.cpp -std=c++11

BattleField.o: BattleField.cpp
	g++ -c BattleField.cpp -std=c++11

Queue.o: Queue.cpp
	g++ -c Queue.cpp -std=c++11

QueueNode.o: QueueNode.cpp
	g++ -c QueueNode.cpp -std=c++11

clean:
	rm *.o output

