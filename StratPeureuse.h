#ifndef _STRATPEUREUSE_H_
#define _STRATPEUREUSE_H_

#include "BestioleStrategy.h"

class Bestiole;
class StratPeureuse : public BestioleStrategy
{
	private :
		std::string NAME;
	
	public : 
		StratPeureuse();
		virtual ~StratPeureuse() {};

		virtual void action(Bestiole bestiole, Milieu & monMilieu ) const;
		virtual inline std::string getName() const{return NAME;};
};

#endif
