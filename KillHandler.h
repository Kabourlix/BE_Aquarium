#ifndef _KILLHANDLER_H_
#define _KILLHANDLER_H_

#include "Milieu.h"


class KillHandler 
{
	private:
		Milieu * milieu;

	public : 
		KillHandler();
		~KillHandler();

		bool kill(Bestiole& bestiole);

		void killExt(int idBestiole);

};

#endif