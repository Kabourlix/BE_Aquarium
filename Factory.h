#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Bestiole.h"


class Factory
{
	protected :
		Milieu * milieu;
	public : 
	
		virtual ~Factory() =0;

		virtual Bestiole cloneBestiole(const Bestiole & bestiole)=0;

		virtual Bestiole createBestiole()=0;

		virtual Bestiole createExtBestiole()=0;

};

#endif