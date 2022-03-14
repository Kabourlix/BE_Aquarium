#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Bestiole.h"


class Factory
{
	public : 
	
		virtual ~Factory();

		virtual Bestiole cloneBestiole(const Milieu & milieu,const Bestiole & bestiole)=0;

		virtual Bestiole createBestiole(const Milieu & milieu)=0;

		virtual Bestiole createExtBestiole(const Milieu & milieu)=0;

};

#endif