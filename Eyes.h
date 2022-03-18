#ifndef _EYES_H_
#define _EYES_H_

#include "Sensors.h"

class Eyes : public Sensors
{

	public :
        float detectionCapacity;
        float angle; // Carefull with the borns of the values angle and distance
        float distance;
		Eyes(const Eyes& eyes);
        Eyes(float probaDetection, float angle, float distance);
		~Eyes();
		virtual bool detection(Bestiole bestiole1,Bestiole bestiole2);
};

#endif
