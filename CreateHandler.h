#ifndef _CREATEHANDLER_H_
#define _CREATEHANDLER_H_

#include "Milieu.h"
#include "ConcreteFactory.h"

class CreateHandler 
{
	private :
		ConcreteFactory * fact;
	public : 
		CreateHandler();
		~CreateHandler();

		void spontaneousCreate(Milieu & milieu);

		void cloneCreate(Milieu & milieu,Bestiole bestiole);

		void extCreate(Milieu & milieu, int nb);
}

#endif