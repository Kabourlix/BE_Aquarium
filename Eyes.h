#ifndef _EYES_H_
#define _EYES_H_

#include "Sensors.h"

class Eyes : public Sensors
{

	public :
		Eyes(const Sensors& eyes); //TODO : Poser la question aux profs ça me parait chelou.
        Eyes(float probaDetection, float angle, float distance);
		virtual ~Eyes();
		virtual bool detection(const Bestiole * bestiole1, const Bestiole * bestiole2);
        inline virtual std::string getName() const {return "Eyes";};
};

#endif
