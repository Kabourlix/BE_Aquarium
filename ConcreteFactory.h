#ifndef _CONCRETEFACTORY_H_
#define _CONCRETEFACTORY_H_

#include "Factory.h"


class ConcreteFactory : public Factory
{
	private:
		float propGregaire;
		float propPeureuse;
		float propKamikaze;
		float propPrevoyante;
		float propMultiple;
		int nbBestiole;
	
	public : 
		ConcreteFactory(Milieu & milieu);
		~ConcreteFactory();

		Bestiole createBestiole(const Milieu & milieu);
		Bestiole cloneBestiole(const Milieu & milieu, const Bestiole & bestiole);
		Bestiole createExtBestiole(const Milieu & milieu);
}

#endif