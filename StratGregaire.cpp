#ifndef _STRATGREGAIRE
#define _STRATGREGAIRE

#include "StratGregaire.h"

const std::string  StratGregaire::NAME = "Gregaire";

void StratGregaire::action(Bestiole b){
    std::vector<Bestiole> neighbors = b.getNearbyNeighbor();
    if (neighbors.size() >= 1)
    {double meanOrientation = 0;
    for ( std::vector<Bestiole>::iterator it = neighbors.begin() ; it != neighbors.end() ; ++it )
        {
            meanOrientation = meanOrientation + b.getOrientation();
        }
    meanOrientation = meanOrientation/neighbors.size();
    b.setOrientation(meanOrientation);
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
