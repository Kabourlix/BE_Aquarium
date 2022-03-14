#ifndef _STRATPEUREUSE_H_
#define _STRATPEUREUSE_H_

#include "BestioleStrategy.h"

class StratPeureuse
{
	private :
		static const std::string name;
	
	public : 
		StratPeureuse();
		~StratPeureuse();

		void action(Bestiole bestiole);
};

#endif
