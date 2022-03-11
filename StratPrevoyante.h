#ifndef _STRATPREVOYANTE_H_
#define _STRATPREVOYANTE_H_

class StratPrevoyante
{
	
	public : 
		StratPrevoyante();
		~StratPrevoyante();

		void action(const Milieu & milieu, Bestiole bestiole);
}

#endif