#ifndef _STRATPEUREUSE_H_
#define _STRATPEUREUSE_H_

#include "BestioleStrategy.h"

class StratPeureuse : public BestioleStrategy
{
	
	public : 
		StratPeureuse();
		~StratPeureuse();

		void action(const Milieu & milieu, Bestiole bestiole);
}

#endif