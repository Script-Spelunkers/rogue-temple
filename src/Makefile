SFML_INCLUDE= C:\SFML-2.5.1\include
SFML_LINK_LIB= C:\SFML-2.5.1/lib
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system

rog: gameengine.o main.o playingstate.o baseentity.o boundingbox.o aabbintersector.o
	g++ -Wall gameengine.o main.o playingstate.o baseentity.o boundingbox.o aabbintersector.o -o rog -L $(SFML_LINK_LIB) -lsfml-graphics -lsfml-window -lsfml-system

gameengine.o:
	g++ -c gameengine.cpp -I $(SFML_INCLUDE)

main.o: main.cpp
	g++ -c main.cpp -I $(SFML_INCLUDE)

playingstate.o: playingstate.cpp
	g++ -c playingstate.cpp -I $(SFML_INCLUDE)

baseentity.o: baseentity.cpp
	g++ -c baseentity.cpp -I $(SFML_INCLUDE)

boundingbox.o: boundingbox.cpp
	g++ -c boundingbox.cpp -I $(SFML_INCLUDE)

aabbintersector.o: aabbintersector.cpp
	g++ -c aabbintersector.cpp -I $(SFML_INCLUDE)


clean:
	rm *.o rog.exe