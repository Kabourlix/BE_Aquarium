#ifndef _CONCRETEFACTORY_H_
#define _CONCRETEFACTORY_H_

#include "Factory.h"


class ConcreteFactory : public Factory
{
	private:

	int id;
	int nbBestiole;
	
	public : 
		ConcreteFactory(Milieu & milieu);
		~ConcreteFactory();

		Bestiole createBestiole(const Milieu & milieu);
		Bestiole cloneBestiole(const Milieu & milieu, const Bestiole & bestiole);
		Bestiole createExtBestiole(const Milieu & milieu);
}

#endif