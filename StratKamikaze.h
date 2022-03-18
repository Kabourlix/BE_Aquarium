#ifndef _STRATKAMIKAZE_H_
#define _STRATKAMIKAZE_H_

#include "BestioleStrategy.h"

class StratKamikaze
{
	private :
		static const std::string NAME;
	public : 
		StratKamikaze();
		~StratKamikaze();

		void action(Bestiole bestiole);
		inline std::string getName() const{return NAME;};
};

#endif
