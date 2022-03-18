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
		virtual bool detection(const Bestiole * bestiole1, const Bestiole * bestiole2);

		inline float getProbaDetection() {
			return this -> probaDetection;
		}
		inline float getDistance() {
			return this -> distance;
		}

		inline void setDistance(float dist) {
			if (dist >= 0)
				this -> distance = dist;
		}

		inline virtual std::string getName() const {return "Ears";};

};

#endif
