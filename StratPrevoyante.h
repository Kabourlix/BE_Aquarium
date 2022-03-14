#ifndef _STRATPREVOYANTE_H_
#define _STRATPREVOYANTE_H_

#include "BestioleStrategy.h"

class StratPrevoyante
{
	private :
		static const std::string NAME;
	
	public : 
		StratPrevoyante();
		~StratPrevoyante();

		void action(Bestiole bestiole);
		inline std::string getNale() const{return NAME};;
};

#endif
