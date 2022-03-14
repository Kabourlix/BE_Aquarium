#include "CreateHandler.h"



CreateHandler::CreateHandler(Milieu & milieu) {
	fact = new ConcreteFactory(const Milieu & milieu);
};


CreateHandler::~CreateHandler(void){
	delete fact;
};



void CreateHandler::createBestiole(Milieu & milieu){
	milieu.addMembers(fact.createBestiole(const Milieu & milieu));
};

void CreateHandler::cloneBestiole(Milieu & milieu, const Bestiole & bestiole){
	milieu.addMembers(fact.cloneBestiole(const Milieu & milieu, const Bestiole & bestiole));
};

void CreateHandler::extCreate(Milieu & milieu, int nb) {
	for (int i = 0; i< nb; i++) {
		milieu.addMembers(fact.createExtBestiole(const Milieu & milieu));
	}
};




