main : main.cpp Aquarium.o Bestiole.o Milieu.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o -I . -I /opt/X11/include -L /opt/X11/lib -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I . -I /opt/X11/include

Bestiole.o : Bestiole.h BestioleStrategy.h Accessory.h Sensors.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I . -I /opt/X11/include

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I . -I /opt/X11/include


clean :
	rm -f main Aquarium.o Bestiole.o Milieu.o
