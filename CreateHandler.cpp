#include "CreateHandler.h"



CreateHandler::CreateHandler() {

	milieu = Milieu::getInstance();
	fact = new ConcreteFactory(*milieu);
};


CreateHandler::~CreateHandler(void){
	delete fact;
};



void CreateHandler::spontaneousCreate(){
	milieu->addMember(fact->createBestiole(*milieu));
};

void CreateHandler::cloneCreate(const Bestiole & bestiole){
	milieu->addMember(fact->cloneBestiole(*milieu,bestiole));
};

void CreateHandler::extCreate(int nb) {
	for (int i = 0; i< nb; i++) {
		milieu->addMember(fact->createExtBestiole(*milieu));
	}
};




