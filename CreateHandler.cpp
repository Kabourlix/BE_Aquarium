#include "CreateHandler.h"
#include "Milieu.h"



CreateHandler::CreateHandler(Milieu * milieu) {

	fact = new ConcreteFactory(milieu);
};


CreateHandler::~CreateHandler(void){
	delete fact;
};



void CreateHandler::spontaneousCreate(Milieu * milieu){
	milieu->addMember(fact->createBestiole());
};

void CreateHandler::cloneCreate(Milieu * milieu, const Bestiole & bestiole){
	milieu->addMember(fact->cloneBestiole(bestiole));
};

void CreateHandler::extCreate(int nb, Milieu * milieu) {
	for (int i = 0; i< nb; i++) {
		milieu->addMember(fact->createExtBestiole());
	}
};




