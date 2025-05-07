Dungeon: main.o Game.o Room.o Entity.o Fighter.o Dragon.o Goblin.o Player.o Sorcerer.o
	g++ main.o Game.o Room.o Entity.o Fighter.o Dragon.o Goblin.o Player.o Sorcerer.o -o Dungeon

main.o: main.cpp Game.h Entity.h Room.h Monster.h Dragon.h Player.h Goblin.h Sorcerer.h Fighter.h
	g++ -c main.cpp

Game.o: Game.cpp Game.h Entity.h Room.h Monster.h Dragon.h Player.h Goblin.h Sorcerer.h Fighter.h MyException.h
	g++ -c Game.cpp

Room.o: Room.cpp Room.h Entity.h Monster.h Dragon.h Player.h Goblin.h MyException.h
	g++ -c Room.cpp

Entity.o: Entity.cpp Entity.h
	g++ -c Entity.cpp

Fighter.o: Fighter.cpp Fighter.h Player.h Entity.h Goblin.h Monster.h Dragon.h
	g++ -c Fighter.cpp

Dragon.o: Dragon.cpp Dragon.h Monster.h Entity.h Player.h
	g++ -c Dragon.cpp

Goblin.o: Goblin.cpp Goblin.h Monster.h Entity.h Player.h
	g++ -c Goblin.cpp

Player.o: Player.cpp Player.h Entity.h
	g++ -c Player.cpp

Sorcerer.o: Sorcerer.cpp Sorcerer.h Player.h Entity.h Goblin.h Monster.h Dragon.h
	g++ -c Sorcerer.cpp

clean:
	rm -f *.o Dungeon
