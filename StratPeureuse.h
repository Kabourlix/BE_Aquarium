#ifndef _STRATPEUREUSE_H_
#define _STRATPEUREUSE_H_

#include "BestioleStrategy.h"

class StratPeureuse : public BestioleStrategy
{
	private :
		static const std::string NAME;
	
	public : 
		StratPeureuse();
		virtual ~StratPeureuse();

		virtual void action(Bestiole bestiole) const;
		virtual inline std::string getName() const{return NAME;};
};

#endif
