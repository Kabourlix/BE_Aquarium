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
}

#endif
