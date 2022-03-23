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



//TODO : Penser à modifier le constructeur pour définir les probas de création de bestiole
ConcreteFactory::ConcreteFactory(Milieu * singleton) {
	milieu = singleton;
	nbBestiole = milieu->getBestioles().size();
	id = nbBestiole + 1;

	propGregaire= 30; 
	propPeureuse = 30;
	propKamikaze = 20; 

};


ConcreteFactory::~ConcreteFactory(void){
};



Bestiole* ConcreteFactory::createBestiole(){
	    
	float randomVariable = std::rand()%100;

	//POSITION
	int xLim = milieu->getWidth();
	int yLim = milieu->getHeight();
	int x = std::rand() % xLim;
	int y = std::rand() % yLim;

	//SPEED AND ORENTATION
   	double orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   	double vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

	BestioleStrategy* bestioleStrat = nullptr;
	// MULTIPLE
	bool multiple = False;

	// STRATEGY
    if (randomVariable <= propGregaire) 
	{
		 // Gregaire Rouge
		bestioleStrat = milieu->getStrategy("Gregaire");


    } else if (randomVariable <= propGregaire + propKamikaze) 
	{
		// Kamikaze Orange
		bestioleStrat = milieu->getStrategy("Kamikaze");

    } else if (randomVariable <= propGregaire + propKamikaze + propPeureuse) 
	{
		// Peureuse Bleu
		bestioleStrat = milieu->getStrategy("Peureuse");

    } else 
	{	
		// Multiple Noire
		bestioleStrat = milieu->getRandomStrategy(" bisous ");

		multiple = true;
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
	std::vector<Accessory*> accessoryVector; //! Never initialized, might be a problem
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
	int age(0);
	int ageLimite = rand() % 500;


	// Return the bestiole to be created.
	return new Bestiole(id++, 
						x,
						y, 
						orientation,
						vitesse, 
						bestioleStrat,
						accessoryVector, 
						sensorVector,
						age,
						ageLimite,
						multiple);
	
};

Bestiole* ConcreteFactory::cloneBestiole(const Bestiole & bestiole){
	return new Bestiole(bestiole);
};

Bestiole* ConcreteFactory::createExtBestiole() {
	return this->createBestiole();
};


Sensors* ConcreteFactory::createEyes(){
	//Define the parameters of the eyes
	float probaDetection = static_cast<double>( rand() )/RAND_MAX*MAX_PROB_DETECTION;
	float angle = static_cast<double>( rand() )/RAND_MAX*(MAX_ANGLE-MIN_ANGLE) + MIN_ANGLE;
	float distanceEyes = static_cast<double>( rand() )/RAND_MAX*(MAX_DIST_EYES-MIN_DIST_EYES) + MIN_DIST_EYES;

	return new Eyes(probaDetection, angle, distanceEyes);
	
};

Sensors* ConcreteFactory::createEars(){
	float detectionCapacity = static_cast<double>( rand() )/RAND_MAX*MAX_DETEC_CAPA;
	float distanceEars = static_cast<double>( rand() )/RAND_MAX*(MAX_DIST_EARS-MIN_DIST_EARS) + MIN_DIST_EARS;
	return new Ears(detectionCapacity, distanceEars);
};


Accessory* ConcreteFactory::createNageoire(){
	float coeffSpeed = static_cast<double>( rand() )/RAND_MAX*MAX_COEF_SPEED;
	return new Accessory("nageoires", coeffSpeed, 0 , 0);
};


Accessory* ConcreteFactory::createCamouflage(){
	float hidingCapacity = static_cast<double>( rand() )/RAND_MAX*MAX_COEF_CAMOUFLAGE;
	return new Accessory("camouflage", 0, 0, hidingCapacity);
};

Accessory* ConcreteFactory::createCarapace(){
	float coeffRes = static_cast<double>( rand() )/RAND_MAX*MAX_COEF_RES;
	return new Accessory("carapace", 0, coeffRes, 0);
};
