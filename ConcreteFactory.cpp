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
		BestioleStrategy* bestioleStrat = milieu.getStrategy();

    			}
   			 }
		}
    }
	id++;

	return new Bestiole(id, 
						x,
						y, 
						orientation,
						vitesse, 
						bestioleStrat,
						std::vector<Accessory*> listeAccessories_, 
						std::vector<Sensors*>   listeSensors_ );
};

Bestiole ConcreteFactory::cloneBestiole(const Milieu & milieu, const Bestiole & bestiole){
	Bestiole bestioleCloned = new Bestiole(bestiole);
	id++;
	return bestioleCloned;
};

Bestiole ConcreteFactory::createExtBestiole(const Milieu & milieu) {
	id++;
	return new Bestiole(bestiole);
};