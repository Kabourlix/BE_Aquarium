#ifndef _STRATPEUREUSE
#define _STRATPEUREUSE

#include "StratPeureuse.h"
#include <cmath>

const std::string  StratGregaire::NAME = "Peureuse";

void StratPeureuse::action(Bestiole b){
    int time = 0;
    if (time==0)
    {
        std::vector<Bestiole> neighbors = b.getNearbyNeighbor();
        if (neighbors.size() >= 5)
        {
            b.setOrientation( M_PI + b.getOrientation());
            b.setVitesse(b.getVitesse()*2);
            time = time + 1;
        }
    }
    if (time<5){time = time+1;} 
    else 
    { 
        time = 0; 
        b.setVitesse(b.getVitesse()/2);
    }
     if (b.getMultiple())
    {double rdm = rand();
        if(rdm< 0.25){b.setStrategy(Milieu::getInstance()->getStrategy("Gregaire"))}
        if((0.25<=rdm) && (rdm< 0.5)){b.setStrategy(Milieu::getInstance()->getStrategy("Peureuse"))}
        if((0.5<=rdm) && (rdm< 0.75)){b.setStrategy(Milieu::getInstance()->getStrategy("Prevoyante"))}
        if(0.75<=rdm){b.setStrategy(Milieu::getInstance()->getStrategy("Kamikaze"))}
    }
}

#endif
