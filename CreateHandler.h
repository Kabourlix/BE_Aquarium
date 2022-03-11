#ifndef _CREATEHANDLER_H_
#define _CREATEHANDLER_H_

#include "Milieu.h"
#include "Bestiole.h"


class CreateHandler 
{
	public : 
	CreateHandler();
	~CreateHandler();

	void spontaneousCreate(Milieu & milieu);

	void cloneCreate(Milieu & milieu,Bestiole bestiole);

	void extCreate(Milieu & milieu);
}

#endif