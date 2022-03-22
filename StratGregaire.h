#ifndef _STRATGREGAIRE_H_
#define _STRATGREGAIRE_H_

#include "BestioleStrategy.h"
#include <string> 

class StratGregaire : public BestioleStrategy
{	
	private :
		static const std::string NAME;
	
	public : 
		StratGregaire();
		virtual ~StratGregaire();

		virtual void action(Bestiole bestiole) const;
		
		virtual inline std::string getName() const{return NAME;};
};

#endif
