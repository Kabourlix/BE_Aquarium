#ifndef _STRATKAMIKAZE_H_
#define _STRATKAMIKAZE_H_

#include "BestioleStrategy.h"

class StratKamikaze
{
	private :
		static const std::string name;
	public : 
		StratKamikaze();
		~StratKamikaze();

		void action(Bestiole bestiole);
};

#endif
