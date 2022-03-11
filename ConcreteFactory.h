#ifndef _CONCRETEFACTORY_H_
#define _CONCRETEFACTORY_H_

#include "Factory.h"


class ConcreteFactory : public Factory
{
	
	public : 
		ConcreteFactory();
		~ConcreteFactory();

		Bestiole createBestiole();
		Bestiole cloneBestiole();
}

#endif