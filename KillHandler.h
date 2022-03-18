#ifndef _KILLHANDLER_H_
#define _KILLHANDLER_H_

#include "Milieu.h"
#include "Bestiole.h"


class KillHandler 
{
    private :
    Milieu * milieu;
    
	public : 
	KillHandler();
	~KillHandler();

	void kill(Bestiole bestiole);

	void killExt(Bestiole bestiole);

}

#endif
