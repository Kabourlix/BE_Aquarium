#include "ConcreteFactory.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Milieu.h"


const int 		ConcreteFactory::MIN = 0;
const int 		ConcreteFactory::MAX = 100;
const float		ConcreteFactory::MAX_VITESSE = 10.;
const float		ConcreteFactory::LIMITE_VUE = 30.;
const float		ConcreteFactory::MAX_PROB_DETECTION = 1.;
const float		ConcreteFactory::MAX_ANGLE = 2.*M_PI;
const float		ConcreteFactory::MAX_DIST_EYES = 50.;
const float		ConcreteFactory::MAX_DETEC_CAPA = 1.;
const float		ConcreteFactory::MAX_DIST_EARS = 40.;
const float		ConcreteFactory::MIN_ANGLE = M_PI;
const float		ConcreteFactory::MIN_DIST_EYES = 20.;
const float		ConcreteFactory::MIN_DIST_EARS = 20.;
const float		ConcreteFactory::MAX_COEF_SPEED = 1.;
const float		ConcreteFactory::MAX_COEF_RES = 1.;
const float		ConcreteFactory::MAX_COEF_CAMOUFLAGE = 1.;


ConcreteFactory::ConcreteFactory() {
	milieu = Milieu::getInstance();
	nbBestiole = milieu->getBestioles().size();
	id = nbBestiole + 1;
	float propGregaire;
	float propPeureuse;
	float propKamikaze;
	float propPrevoyante;

};


ConcreteFactory::~ConcreteFactory(void){
};



Bestiole ConcreteFactory::createBestiole(){
	    
	std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<float> distr(MIN, MAX);
    float randomVariable = distr(eng)/MAX;

	//POSITION
	//TODO : Définir xLim et yLim
	int x = std::rand() % xLim;
	int y = std::rand() % yLim;

	//SPEED AND ORENTATION
   	double orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   	double vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

	BestioleStrategy* bestioleStrat;
	T * couleur;
	couleur = new T[ 3 ];
	// MULTIPLE
	bool multiple = False;


	// STRATEGY
    if (randomVariable <= propGregaire) {
		 // Gregaire Rouge
		bestioleStrat = milieu->getStrategy("Gregaire");
		couleur[ 0 ] = 255;
  		couleur[ 1 ] = 0;
   		couleur[ 2 ] = 0;
    } else { if (randomVariable <= propKamikaze) {
		// Kamikaze Orange
		bestioleStrat = milieu->getStrategy("Kamikaze");
		couleur[ 0 ] = 255;
  		couleur[ 1 ] = 165;
   		couleur[ 2 ] = 0;
    } else { if (randomVariable <= propPeureuse) {
		// Peureuse Bleu
		bestioleStrat = milieu->getStrategy("Peureuse");
		couleur[ 0 ] = 255;
  		couleur[ 1 ] = 255;
   		couleur[ 2 ] = 0;
    } else { if (randomVariable <= propPrevoyante) {
		// Prevoyante Verte
		bestioleStrat = milieu->getStrategy("Prevoyante");
		couleur[ 0 ] = 152;
  		couleur[ 1 ] = 251; 	
   		couleur[ 2 ] = 152;
    } else {	
		// Multiple Noire
		bestioleStrat = milieu->getRandomStrategy(bestioleStrat->getName());
		couleur[ 0 ] = 0;
  		couleur[ 1 ] = 0;
   		couleur[ 2 ] = 0;
		multiple = true;
    			}
   			 }
		}
    }
 

	// SENSORS
	std::vector<Sensors*> sensorVector;
	int eyes = rand() % 2;
	int ears = rand() % 2;
	if (eyes) {
		sensorVector.push_back(this -> createEars());
	};
	if (ears) {
		sensorVector.push_back(this -> createEars());
	};


	// ACCESOIRIES
	std::vector<Accessory*> accessoryVector;
	int nageoires = rand() % 2;
	int carapace = rand() % 2;
	int camouflage = rand() % 2;
	if (nageoires) {
		accessoryVector.push_back(this -> createNageoire());
	};
	if (carapace) {
		accessoryVector.push_back(this -> createCarapace());
	};
	if (camouflage) {
		accessoryVector.push_back(this -> createCamouflage());
	};

	//AGE
	int age;
	age = 0;
	int ageLimite;
	ageLimite = static_cast<int>( rand() )/RAND_MAX*(300-100) + 100;


	// BESTIOLE
	Bestiole bestiole = new Bestiole(id, 
						x,
						y, 
						orientation,
						vitesse, 
						bestioleStrat,
						accessoryVector, 
						sensorVector
						couleur,
						age,
						limiteAge,
						multiple);
	
	id++;
	return bestiole;
};

Bestiole ConcreteFactory::cloneBestiole(const Bestiole & bestiole){
	Bestiole bestioleCloned = new Bestiole(bestiole, id);
	id++;
	return bestioleCloned;
};

Bestiole ConcreteFactory::createExtBestiole() {
	return this->createBestiole();
};


Sensors* ConcreteFactory::createEyes(){
	float probaDetection = static_cast<double>( rand() )/RAND_MAX*MAX_PROB_DETECTION;
	float angle = static_cast<double>( rand() )/RAND_MAX*(MAX_ANGLE-MIN_ANGLE) + MIN_ANGLE;
	float distanceEyes = static_cast<double>( rand() )/RAND_MAX*(MAX_DIST_EYES-MIN_DIST_EYES) + MIN_DIST_EYES;
	Sensors *eyes = new Eyes(probaDetection, angle, distanceEyes);
	return eyes;
	
};

Sensors* ConcreteFactory::createEars(){
	float detectionCapacity = static_cast<double>( rand() )/RAND_MAX*MAX_DETEC_CAPA;
	float distanceEars = static_cast<double>( rand() )/RAND_MAX*(MAX_DIST_EARS-MIN_DIST_EARS) + MIN_DIST_EARS;
	Sensors *ears = new Ears(detectionCapacity, distanceEars);
	return ears;
};


Accessory ConcreteFactory::createNageoire(){
	float coeffSpeed = static_cast<double>( rand() )/RAND_MAX*MAX_COEF_SPEED;
	Accessory *nageoires = new Accessory("nageoires", coeffSpeed, 0 , 0);
	return *nageoires;
};


Accessory ConcreteFactory::createCamouflage(){
	float hidingCapacity = static_cast<double>( rand() )/RAND_MAX*MAX_COEF_CAMOUFLAGE;
	Accessory *camouflage = new Accessory("camouflage", 0, 0, hidingCapacity);
	return *camouflage;
};

Accessory ConcreteFactory::createCarapace(){
	float coeffRes = static_cast<double>( rand() )/RAND_MAX*MAX_COEF_RES;
	Accessory *carapace = new Accessory("carapace", 0, coeffRes, 0);
	return *carapace;
};
