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

		Bestiole createBestiole(Milieu & milieu);
		Bestiole cloneBestiole(Milieu & milieu, Bestiole bestiole);
}

#endif