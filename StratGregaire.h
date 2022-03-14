#ifndef _STRATGREGAIRE_H_
#define _STRATGREGAIRE_H_

#include "BestioleStrategy.h"
# include <string> 

class StratGregaire
{	
	private :
		static const std::string name;
	
	public : 
		StratGregaire();
		~StratGregaire();

		void action(Bestiole bestiole);
};

#endif
