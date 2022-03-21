#ifndef _SENSORS_H_
#define _SENSORS_H_

class Bestiole;


class Sensors
{
	protected : 
	
	float probaDetection;
	float angle; // Carefull with the borns of the values angle and distance
	float distance;

	public :
	Sensors();
	virtual ~Sensors();
	virtual bool detection(const Bestiole *bestiole1,const Bestiole *bestiole2)=0;
	inline virtual std::string getName() const =0;
};

#endif
