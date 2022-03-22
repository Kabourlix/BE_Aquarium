#ifndef _CREATEHANDLER_H_
#define _CREATEHANDLER_H_

class Milieu;
#include "ConcreteFactory.h"

class CreateHandler 
{
	private :
		ConcreteFactory * fact;
	public : 
		CreateHandler(Milieu * milieu);
		~CreateHandler();

		void spontaneousCreate(Milieu * milieu);

		void cloneCreate(Milieu * milieu, const Bestiole& bestiole);

		void extCreate(int nb, Milieu * milieu);
};

#endif