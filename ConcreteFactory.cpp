#include "ConcreteFactory.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>

int MIN = 0;
int MAX = 100;


ConcreteFactory::ConcreteFactory(const Milieu & milieu) {
	nbBestiole = milieu.getListeBestiole().size()
	id = nbBestiole + 1;
	float propGregaire;
	float propPeureuse;
	float propKamikaze;
	float propPrevoyante;

};


ConcreteFactory::~ConcreteFactory(void){
	delete nbBestiole;
	delete id;
};



Bestiole ConcreteFactory::createBestiole(const Milieu & milieu){
	    
	std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<float> distr(MIN, MAX);
    float randomVariable = distr(eng)/MAX;

	int x = std::rand() % xLim;
	int y = std::rand() % yLim;
   	double orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   	double vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

    if (randomVariable <= propGregaire) {

		 // Gregaire
		 BestioleStrategy* bestioleStrat = milieu.getStrategy("Gregaire");

    } else { if (randomVariable <= propKamikaze) {

		// Kamikaze
		BestioleStrategy* bestioleStrat = milieu.getStrategy("Kamikaze");

    } else { if (randomVariable <= propPeureuse) {

		// Peureuse
		BestioleStrategy* bestioleStrat = milieu.getStrategy("Peureuse");

    } else { if (randomVariable <= propPrevoyante) {

		// Prevoyante
		BestioleStrategy* bestioleStrat = milieu.getStrategy("Prevoyante");

    } else {
		
		// multiple
		BestioleStrategy* bestioleStrat = milieu.getRandomStrategy();

    			}
   			 }
		}
    }
	id++;

	Sensor *eyes = new Eyes(float probaDetection, float angle, float distance);
	Sensor *ears = new Ears(float detectionCapacity, float distance);

	std::vector<Sensors*> sensorVector;
	sensorVector.push_back(*eyes);
	sensorVector.push_back(*ears);

	Accessory *nageoires = new accessory(std::string name, float coeffSpeed,float coeffRes,float hidingCapacity);
	Accessory *carapace = new accessory(std::string name, float coeffSpeed,float coeffRes,float hidingCapacity);
	Accessory *camouflage = new accessory(std::string name, float coeffSpeed,float coeffRes,float hidingCapacity);

	std::vector<Accessory*> accessoryVector;
	accessoryVector.push_back(*nageoires);
	accessoryVector.push_back(*carapace);
	accessoryVector.push_back(*camouflage);
	
	return new Bestiole(id, 
						x,
						y, 
						orientation,
						vitesse, 
						bestioleStrat,
						accessoryVector, 
						sensorVector);
};

Bestiole ConcreteFactory::cloneBestiole(const Milieu & milieu, const Bestiole & bestiole){
	Bestiole bestioleCloned = new Bestiole(bestiole);
	id++;
	return bestioleCloned;
};

Bestiole ConcreteFactory::createExtBestiole(const Milieu & milieu) {
	return ConcreteFactory;;createBestiole(milieu);
};