#include "ConcreteFactory.h"
#include <random>
#include "Accessory.h"
#include "Eyes.h"
#include "Ears.h"

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
	nbBestiole = milieu.getListeBestiole().lenght();
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<float> distr(MIN, MAX);
    float randomVariable = distr(eng)/MAX;
    if (randomVariable <= propGregaire) {

		 // Gregaire

    	return new Bestiole(int identite_, 
							int x_,
							int y_, 
							double orientation_,
							double vitesse_, 
							BestioleStrategy  *bestioleStrat_,
							std::vector<Accessory*> listeAccessories_, 
							std::vector<Sensors*>   listeSensors_ )

    } else { if (randomVariable <= propKamikaze) {

		// Kamikaze

    	return new Bestiole(int identite_, 
							int x_,
							int y_, 
							double orientation_,
							double vitesse_, 
							BestioleStrategy  *bestioleStrat_,
							std::vector<Accessory*> listeAccessories_, 
							std::vector<Sensors*>   listeSensors_ )

    } else { if (randomVariable <= propPeureuse) {

		// Peureuse

    	return new Bestiole(int identite_, 
							int x_,
							int y_, 
							double orientation_,
							double vitesse_, 
							BestioleStrategy  *bestioleStrat_,
							std::vector<Accessory*> listeAccessories_, 
							std::vector<Sensors*>   listeSensors_ )

    } else { if (randomVariable <= propPrevoyante) {

		// Prevoyante

    	return new Bestiole(int identite_, 
							int x_,
							int y_, 
							double orientation_,
							double vitesse_, 
							BestioleStrategy  *bestioleStrat_,
							std::vector<Accessory*> listeAccessories_, 
							std::vector<Sensors*>   listeSensors_ )

    } else {
		
		// multiple

    	return new Bestiole(int identite_, 
							int x_,
							int y_, 
							double orientation_,
							double vitesse_, 
							BestioleStrategy  *bestioleStrat_,
							std::vector<Accessory*> listeAccessories_, 
							std::vector<Sensors*>   listeSensors_ )
    			}
   			 }
		}
    }
	id++;
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