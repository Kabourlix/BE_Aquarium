#include "CreateHandler.h"
#include "Milieu.h"



CreateHandler::CreateHandler(Milieu * milieu) {

	fact = new ConcreteFactory(milieu);
};


CreateHandler::~CreateHandler(void){
	delete fact;
};



void CreateHandler::spontaneousCreate(Milieu * milieu){
	int nb = rand() % 100;
	if (nb < 10)
	{
		milieu->addMember(fact->createBestiole());
	}
};

void CreateHandler::cloneCreate(Milieu * milieu, Bestiole * bestiole){
	milieu->addMember(fact->cloneBestiole(*bestiole));
};

void CreateHandler::extCreate(int nb, Milieu * milieu) {
	for (int i = 0; i< nb; i++) {
		milieu->addMember(fact->createExtBestiole());
	}
};




