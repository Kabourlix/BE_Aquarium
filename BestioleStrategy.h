#ifndef _BESTIOLESTRATEGY_H_
#define _BESTIOLESTRATEGY_H_

#include <iostream>
#include <vector>

#include "Bestiole.h"

class BestioleStrategy
{
	public : 
		virtual ~BestioleStrategy()=0;
		virtual void action(Bestiole bestiole) const =0;
		virtual inline std::string getName() const =0;
};

#endif