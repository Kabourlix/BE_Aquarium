#ifndef _STRATPREVOYANTE_H_
#define _STRATPREVOYANTE_H_

#include "BestioleStrategy.h"

class StratPrevoyante : public BestioleStrategy
{
	
	public : 
		StratPrevoyante();
		~StratPrevoyante();

		void action(const Milieu & milieu, Bestiole bestiole);
}

#endif