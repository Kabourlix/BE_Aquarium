all: main.o Aquarium.o Bestiole.o Milieu.o StratGregaire.o StratKamikaze.o StratPeureuse.o  KillHandler.o CreateHandler.o ConcreteFactory.o Eyes.o Ears.o Milieu.o -I . -I /opt/X11/include -L /opt/X11/lib -lX11 -lpthread
	g++ -Wall -std=c++11 -o main main.o Aquarium.o Bestiole.o Bestiole.o Milieu.o StratGregaire.o StratKamikaze.o StratPeureuse.o KillHandler.o CreateHandler.o ConcreteFactory.o Eyes.o Ears.o Milieu.o

main.o : main.cpp Aquarium.o Bestiole.o Milieu.o 
	g++ -Wall -std=c++11 -c main.cpp -I . -I /opt/X11/include -L /opt/X11/lib -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I . -I /opt/X11/include


Bestiole.o : Bestiole.h BestioleStrategy.h Accessory.h Sensors.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I . -I /opt/X11/include

Accessory.o : Accessory.h Accessory.cpp
	g++ -Wall -std=c++11  -c Accessory.cpp -I . -I /opt/X11/include




StratGregaire.o : StratGregaire.h StratGregaire.cpp
	g++ -Wall -std=c++11  -c StratGregaire.cpp -I . -I /opt/X11/include

StratKamikaze.o : StratKamikaze.h StratKamikaze.cpp
	g++ -Wall -std=c++11  -c StratKamikaze.cpp -I . -I /opt/X11/include

StratPeureuse.o : StratPeureuse.h StratPeureuse.cpp
	g++ -Wall -std=c++11  -c StratPeureuse.cpp -I . -I /opt/X11/include



KillHandler.o : KillHandler.h KillHandler.cpp
	g++ -Wall -std=c++11  -c KillHandler.cpp -I . -I /opt/X11/include

CreateHandler.o : CreateHandler.h ConcreteFactory.h CreateHandler.cpp
	g++ -Wall -std=c++11  -c CreateHandler.cpp -I . -I /opt/X11/include

ConcreteFactory.o : ConcreteFactory.h Factory.h Accessory.h BestioleStrategy.h Eyes.h Ears.h ConcreteFactory.cpp
	g++ -Wall -std=c++11  -c ConcreteFactory.cpp -I . -I /opt/X11/include

Eyes.o : Eyes.h Sensors.h Eyes.cpp
	g++ -Wall -std=c++11  -c Eyes.cpp -I . -I /opt/X11/include

Ears.o : Ears.h Sensors.h Ears.cpp
	g++ -Wall -std=c++11  -c Ears.cpp -I . -I /opt/X11/include

Milieu.o : Milieu.h Bestiole.h StratGregaire.h StratKamikaze.h StratPrevoyante.h StratPeureuse.h CreateHandler.h KillHandler.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I . -I /opt/X11/include

clean :
	rm -f main Aquarium.o Bestiole.o Milieu.o
