#ifndef _EARS_H_
#define _EARS_H_

#include "Sensors.h"

class Ears : public Sensors
{

	private :
		float probaDetection;
    	float distance;
	public :
		Ears(const Ears& ears);
        Ears( const Sensors& ears); //TODO : Poser la question aux profs ça me parait chelou.
		Ears(float detectionCapacity, float distance);
		~Ears();
		virtual bool detection(const Bestiole * bestiole1, const Bestiole * bestiole2);

		inline void setDistance(float dist) {distance = dist;};

		inline virtual std::string getName() const {return "Ears";};
		inline float getProbaDetection() {return probaDetection;};
		inline float getDistance() {return distance;};

};

#endif
