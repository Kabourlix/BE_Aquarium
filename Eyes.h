#ifndef _EYES_H_
#define _EYES_H_

#include "Sensors.h"

class Eyes : public Sensors

{
	private :
		float probaDetection;
    	float angle;
    	float distance;

	public :
		Eyes(const Sensors& eyes); //TODO : Poser la question aux profs ça me parait chelou.
        Eyes(float probaDetection, float angle, float distance);
		virtual ~Eyes();
		virtual bool detection(const Bestiole * bestiole1, const Bestiole * bestiole2);
        virtual inline std::string getName() const {return "Eyes";};
		inline float getProbaDetection() {return probaDetection;};
		inline float getAngle() {return angle;};
		inline float getDistance() {return distance;};
		void Eyes::setProbaDetection(float ang);
		void Eyes::setAngle(float probDetec);
		void Eyes::setDistance(float dist);



};

#endif
