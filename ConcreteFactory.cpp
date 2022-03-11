#include "ConcreteFactory.h"
#include <random>

int MIN = 0;
int MAX = 100;


ConcreteFactory::ConcreteFactory(Milieu & milieu) {
	nbBestiole = milieu.getListeBestiole().lenght()
	propGregaire, propPeureuse, propKamikaze, propPrevoyante, propMultiple =0, 0, 0, 0, 0;
	for (bestiole in milieu.getListeBestiole()) {
		if (bestiole.getMutliple()) {
			++propMultiple;
		} else { if  (bestiole.getStrat() instaceof StratGregaire) {
				++propGregaire;
		} else { if (bestiole.getStrat() instaceof StratPeureuse) {
					++propPeureuse;
			}
		} else { if (bestiole.getStrat() instaceof StratKamikaze) {
					++propKamikaze;
			}
		} else { if (bestiole.getStrat() instaceof StratPrevoyante) {
					++propPrevoyante;
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



Bestiole ConcreteFactory::createBestiole(Milieu & milieu);
{
	nbBestiole = milieu.getListeBestiole().lenght();
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<float> distr(MIN, MAX);
    float randomVariable = distr(eng)/MAX;
    if (randomVariable <= propGregaire) {

    	milieu.addMember(new Bestiole(nbBestiole, milieu.getStratGregaire, false, std::Vector<accessories>)) // Gregaire

    } else { if (randomVariable <= propKamikaze) {

    	milieu.addMember(new Bestiole(nbBestiole, milieu.getStratKamikaze, false, std::Vector<accessories>)) // Kamikaze

    } else { if (randomVariable <= propPeureuse) {

    	milieu.addMember(new Bestiole(nbBestiole, milieu.getStratPeureuse, false, std::Vector<accessories>)) // Peureuse

    } else { if (randomVariable <= propPrevoyante) {

    	milieu.addMember(new Bestiole(nbBestiole, milieu.getStratPrevoyante, false, std::Vector<accessories>)) // Prevoyante

    } else {
    	milieu.addMember(new Bestiole(nbBestiole, milieu.getStratMultiple, true, std::Vector<accessories>)) // multiple
    			}
   			 }
		}
    }
};

Bestiole ConcreteFactory::cloneBestiole()
{

};