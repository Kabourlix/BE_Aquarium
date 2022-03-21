#include "CreateHandler.h"
#include "Milieu.h"



CreateHandler::CreateHandler() {

	milieu = Milieu::getInstance();
	fact = new ConcreteFactory();
};


CreateHandler::~CreateHandler(void){
	delete fact;
};



void CreateHandler::spontaneousCreate(){
	milieu->addMember(fact->createBestiole());
};

void CreateHandler::cloneCreate(const Bestiole & bestiole){
	milieu->addMember(fact->cloneBestiole(bestiole));
};

void CreateHandler::extCreate(int nb) {
	for (int i = 0; i< nb; i++) {
		milieu->addMember(fact->createExtBestiole());
	}
};




