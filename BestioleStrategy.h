#ifndef _BESTIOLESTRATEGY_H_
#define _BESTIOLESTRATEGY_H_

#include "Bestiole.h"

class BestioleStrategy
{
	public : 
		virtual ~BestioleStrategy();
		virtual void action(Bestiole bestiole) const =0;
		virtual std::string getName() const =0;
};

#endif