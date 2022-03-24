#ifndef _EYES_H_
#define _EYES_H_

#include "Sensors.h"

class Eyes : public Sensors

{

	public :
		//Eyes(const Sensors& eyes); //TODO : Poser la question aux profs ça me parait chelou. 
		Eyes(const Eyes& eyes);
        Eyes(float probaDetection, float angle, float distance);
		virtual ~Eyes();
		virtual bool detection(Bestiole * bestiole1,Bestiole * bestiole2);
        virtual inline std::string getName() const {return "Eyes";};
		inline float getProbaDetection() {return probaDetection;};
		inline virtual float getAngle() {return angle;};
		inline virtual float getDistance() {return distance;};
		void setProbaDetection(float ang);
		void setAngle(float probDetec);
		void setDistance(float dist);



};

#endif
