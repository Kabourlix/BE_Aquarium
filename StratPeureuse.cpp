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
}

#endif
