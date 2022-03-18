#ifndef _CREATEHANDLER_H_
#define _CREATEHANDLER_H_

#include "Milieu.h"
#include "ConcreteFactory.h"

class CreateHandler 
{
	private :
		Milieu * milieu;
		ConcreteFactory * fact;
	public : 
		CreateHandler();
		~CreateHandler();

		void spontaneousCreate();

		void cloneCreate(const Bestiole& bestiole);

		void extCreate(int nb);
}

#endif