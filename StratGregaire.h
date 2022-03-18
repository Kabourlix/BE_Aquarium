#ifndef _STRATGREGAIRE_H_
#define _STRATGREGAIRE_H_

#include "BestioleStrategy.h"
# include <string> 

class StratGregaire
{	
	private :
		static const std::string NAME;
	
	public : 
		StratGregaire();
		~StratGregaire();

		void action(Bestiole bestiole);
		
		inline std::string getName() const{return NAME;};
};

#endif
