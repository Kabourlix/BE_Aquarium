#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Bestiole.h"


class Factory
{
	public : 
	
	virtual ~Factory();

	virtual Bestiole cloneBestiole(Bestiole bestiole)=0;

	virtual Bestiole createBestiole()=0;

	virtual Bestiole createExtBestiole()=0;

};

#endif