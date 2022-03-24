#ifndef _EARS_H_
#define _EARS_H_

#include "Sensors.h"

class Ears : public Sensors
{

	public :
		Ears(const Ears& ears);
        Ears( const Sensors& ears); //TODO : Poser la question aux profs ça me parait chelou.
		Ears(float detectionCapacity, float distance);
		virtual ~Ears();
		virtual bool detection(Bestiole * bestiole1,Bestiole * bestiole2);

		inline void setDistance(float dist) {distance = dist;};

		inline virtual std::string getName() const {return "Ears";};
		inline float getProbaDetection() {return probaDetection;};
		inline virtual float getDistance() {return distance;};
		inline virtual float getAngle(){return angle;};

};

#endif
