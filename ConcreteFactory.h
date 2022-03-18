#ifndef _CONCRETEFACTORY_H_
#define _CONCRETEFACTORY_H_

#include "Factory.h"
#include <iostream>


class ConcreteFactory : public Factory
{
	
	public : 
		ConcreteFactory();
		~ConcreteFactory();

		virtual Bestiole createBestiole();
		virtual Bestiole cloneBestiole();
		virtual Bestiole createExtBestiole();
};

#endif