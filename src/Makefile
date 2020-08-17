SFML_INCLUDE= C:\SFML-2.5.1\include
SFML_LINK_LIB= C:\SFML-2.5.1/lib
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system

rog: gameengine.o main.o playingstate.o physics_intersector.o
	g++ -Wall gameengine.o main.o playingstate.o physics_intersector.o -o rog -L $(SFML_LINK_LIB) -lsfml-graphics -lsfml-window -lsfml-system

gameengine.o:
	g++ -c gameengine.cpp -I $(SFML_INCLUDE)

main.o: main.cpp
	g++ -c main.cpp -I $(SFML_INCLUDE)

playingstate.o: playingstate.cpp
	g++ -c playingstate.cpp -I $(SFML_INCLUDE)

physics_intersector.o: physics_intersector.cpp
	g++ -c physics_intersector.cpp -I $(SFML_INCLUDE)

clean:
	rm *.o rog.exe