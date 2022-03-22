#ifndef _STRATKAMIKAZE_H_
#define _STRATKAMIKAZE_H_

#include "BestioleStrategy.h"

class Bestiole;
class StratKamikaze : public BestioleStrategy
{
	private :
		static const std::string NAME;
	public : 
		StratKamikaze();
		virtual ~StratKamikaze();

		virtual void action(Bestiole bestiole) const;
		virtual inline std::string getName() const{return NAME;};
};

#endif
