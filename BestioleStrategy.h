#ifndef _BESTIOLESTRATEGY_H_
#define _BESTIOLESTRATEGY_H_

class Bestiole;

class BestioleStrategy
{
	public : 
		BestioleStrategy();
		virtual ~BestioleStrategy();
		virtual void action(Bestiole bestiole) const =0;
		virtual std::string getName() const =0;
};

#endif