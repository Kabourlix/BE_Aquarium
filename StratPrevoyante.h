#ifndef _STRATPREVOYANTE_H_
#define _STRATPREVOYANTE_H_

#include "BestioleStrategy.h"

class StratPrevoyante: public BestioleStrategy
{
	private :
		std::string NAME;
	
	public : 
		StratPrevoyante();
		virtual ~StratPrevoyante();

		virtual void action(Bestiole bestiole) const;
		virtual inline std::string getName() const{return NAME;};
};

#endif
