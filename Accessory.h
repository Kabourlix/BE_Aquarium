#ifndef _ACCESSORY_H_
#define _ACCESSORY_H_

#include "Bestiole.h"
#include <string>

class Accessory
{
	private :
		std::string name;
		float coeffSpeed;
		float coeffRes;
		float hidingCapacity;

	
	public : 
		Accessory(std::string name, float coeffSpeed,float coeffRes,float hidingCapacity);
		Accessory(const Accessory & accessory);
		~Accessory();
		inline std::string getName() const {return name;};
		inline float getcoeffSpeed() const {return coeffSpeed;};
		inline float getcoeffRes() const {return coeffRes;};
		inline float gethidingCapacity() const {return hidingCapacity;};


};

#endif