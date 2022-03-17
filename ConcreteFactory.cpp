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

    	return new Bestiole() // Gregaire

    } else { if (randomVariable <= propKamikaze) {

    	return new Bestiole() // Kamikaze

    } else { if (randomVariable <= propPeureuse) {

    	return new Bestiole() // Peureuse

    } else { if (randomVariable <= propPrevoyante) {

    	return new Bestiole() // Prevoyante

    } else {
    	return new Bestiole() // multiple
    			}
   			 }
		}
    }
	id++;
};

Bestiole ConcreteFactory::cloneBestiole(const Milieu & milieu, const Bestiole & bestiole){
	id++;
	return new Bestiole(bestiole);
};

Bestiole ConcreteFactory::createExtBestiole(const Milieu & milieu) {
	id++;
	return new Bestiole(bestiole);
};