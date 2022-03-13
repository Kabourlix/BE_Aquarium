#ifndef _BESTIOLESTRATEGY_H_
#define _BESTIOLESTRATEGY_H_

class Milieu;
class Bestiole;

class BestioleStrategy
{
	public : 
		BestioleStrategy(std::string name);
		virtual ~BestioleStrategy();

		std::string getName();
		
		virtual void action(const Milieu & milieu,Bestiole bestiole)=0;

};
#endif