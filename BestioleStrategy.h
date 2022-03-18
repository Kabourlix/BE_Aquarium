#ifndef _BESTIOLESTRATEGY_H_
#define _BESTIOLESTRATEGY_H_

#include "Bestiole.h"

class BestioleStrategy
{
	
	public : 

	virtual ~BestioleStrategy();
	
	virtual void action(Bestiole bestiole)=0;

};

#endif