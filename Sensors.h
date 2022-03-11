#ifndef _SENSORS_H_
#define _SENSORS_H_

#include "Bestiole.h"


class Sensors
{
	protected : 
	
	float detectionCapacity;
	float angle; // Carefull with the borns of the values angle and distance
	float distance;

	public :

	virtual ~Sensors();
	virtual bool detection(Bestiole bestiole1,Bestiole bestiole2)=0;
};

#endif