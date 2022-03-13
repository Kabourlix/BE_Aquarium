#ifndef _STRATKAMIKAZE_H_
#define _STRATKAMIKAZE_H_

#include "BestioleStrategy.h"

class StratKamikaze : public BestioleStrategy
{
	
	public : 
		StratKamikaze();
		~StratKamikaze();

		void action(const Milieu & milieu, Bestiole bestiole);
}

#endif