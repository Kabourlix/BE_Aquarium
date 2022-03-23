#ifndef _STRATPEUREUSE
#define _STRATPEUREUSE

#include "StratPeureuse.h"
#include <cmath>

StratPeureuse::StratPeureuse() {
    NAME = "Peureuse";
};



void StratPeureuse::action(Bestiole * b, Milieu * monMilieu ) const {
    if (b->getNearbyNeighbor(monMilieu).size() >= 3)
    {
        b->setOrientation( M_PI + b->getOrientation());
        //b->setVitesse(b->getVitesse()*2);
    }
}

#endif
