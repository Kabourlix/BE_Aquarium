#ifndef _STRATGREGAIRE_H_
#define _STRATGREGAIRE_H_

#include "BestioleStrategy.h"

class StratGregaire : public BestioleStrategy
{
	
	public : 
		StratGregaire();
		~StratGregaire();

		virtual void action(const Milieu & milieu, Bestiole bestiole);
}

#endif