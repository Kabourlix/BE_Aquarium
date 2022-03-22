#ifndef _STRATGREGAIRE_H_
#define _STRATGREGAIRE_H_

#include "BestioleStrategy.h"
#include <string> 

class Bestiole;

class StratGregaire : public BestioleStrategy
{	
	private :
		std::string NAME;
	
	public : 
		StratGregaire();
		virtual ~StratGregaire() {};

		virtual void action(Bestiole bestiole, Milieu & monMilieu ) const;
		
		virtual inline std::string getName() const{return NAME;};
};

#endif
