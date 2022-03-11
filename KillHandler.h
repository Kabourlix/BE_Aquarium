#ifndef _KILLHANDLER_H_
#define _KILLHANDLER_H_

#include "Milieu.h"
#include "Bestiole.h"


class KillHandler 
{
	public : 
	KillHandler();
	~KillHandler();

	void kill(const Milieu & milieu,Bestiole bestiole);

	void killExt(const Milieu & milieu,Bestiole bestiole);

}

#endif