#ifndef _KILLHANDLER_H_
#define _KILLHANDLER_H_

class Milieu;
class Bestiole;


class KillHandler 
{

	public : 
		KillHandler();
		~KillHandler();

		bool kill(Bestiole* bestiole, Milieu * monMilieu);

		void killExt(int idBestiole, Milieu * monMilieu);

};

#endif