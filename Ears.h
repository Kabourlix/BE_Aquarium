#ifndef _EARS_H_
#define _EARS_H_

#include "Sensors.h"

class Ears : public Sensors
{

	public :
        float detectionCapacity;
        float distance;
    
        Ears( const Ears& ears);
		Ears(float detectionCapacity, float distance);
		~Ears();
		bool detection(Bestiole bestiole1,Bestiole bestiole2);
}

#endif
