#ifndef _STRATPEUREUSE_H_
#define _STRATPEUREUSE_H_

#include "BestioleStrategy.h"

class StratPeureuse
{
	private :
		static const std::string NAME;
	
	public : 
		StratPeureuse();
		~StratPeureuse();

		void action(Bestiole bestiole);
		virtual inline std::string getName() const{return NAME;};
};

#endif
