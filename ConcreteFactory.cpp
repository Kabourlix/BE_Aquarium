#include "ConcreteFactory.h"
#include <random>
#include "Accessory.h"
#include "Eyes.h"
#include "Ears.h"

int MIN = 0;
int MAX = 100;


ConcreteFactory::ConcreteFactory(const Milieu & milieu) {
	nbBestiole = milieu.getListeBestiole().size()
	propGregaire, propPeureuse, propKamikaze, propPrevoyante, propMultiple =0, 0, 0, 0, 0;
	for (Bestiole bestiole : milieu.getListeBestiole()) {
		if (bestiole.getMutliple()) {
			++propMultiple;
		} else { if  (*(bestiole.getStrat()) -> getName() == "Gregaire") {
				++propGregaire;
		} else { if (*(bestiole.getStrat()) -> getName() == "Peureuse") {
					++propPeureuse;
		} else { if (*(bestiole.getStrat()) -> getName() == "Kamikaze") {
					++propKamikaze;
		} else { if (*(bestiole.getStrat()) -> getName() == "Prevoyante") {
					++propPrevoyante;
						}
					}
				}
			}
		}
	}			
	propPrevoyante /= nbBestiole;
	propGregaire /= nbBestiole;
	propKamikaze /= nbBestiole;
	propPeureuse /= nbBestiole
	propMultiple /= nbBestiole;
};


ConcreteFactory::~ConcreteFactory(void){
	delete nbBestiole;
	delete propMultiple;
	delete propPeureuse;
	delete propKamikaze;
	delete propGregaire;
	delete propPrevoyante;
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
};

Bestiole ConcreteFactory::cloneBestiole(const Milieu & milieu, const Bestiole & bestiole){
	return new Bestiole(bestiole);
};

Bestiole ConcreteFactory::createExtBestiole(const Milieu & milieu) {
	return new Bestiole(bestiole);
};