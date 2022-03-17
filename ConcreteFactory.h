#ifndef _CONCRETEFACTORY_H_
#define _CONCRETEFACTORY_H_

#include "Factory.h"
#include "Accessory.h"
#include "BestioleStrategy.h"
#include "Eyes.h"
#include "Ears.h"


class ConcreteFactory : public Factory
{
	private:
		int id;
		int nbBestiole;
		float propGregaire;
		float propPeureuse;
		float propKamikaze;
		float propPrevoyante;
	
	public : 
		ConcreteFactory(Milieu & milieu);
		~ConcreteFactory();

		Bestiole createBestiole(const Milieu & milieu);
		Bestiole cloneBestiole(const Milieu & milieu, const Bestiole & bestiole);
		Bestiole createExtBestiole(const Milieu & milieu);
}

#endif