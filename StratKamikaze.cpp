#ifndef _STRATKAMIKAZE
#define _STRATKAMIKAZE

#include "StratKamikaze.h"
#include <cmath>
#include <cstdlib>



StratKamikaze::StratKamikaze() {
    NAME = "Kamikaze";
};

void StratKamikaze::action(Bestiole b, Milieu & monMilieu ) const{
    // Check if there is any nearby Bestiole detected :
    if (b.getNearbyNeighbor(monMilieu).size()>0)
    {
        // Define the orientation of the bestiole such as it will be directed towards the current position of the nearest bestiole
        // à voir si position bestiole vraiment donné par x,y 
        b.setOrientation( signbit(b.getNearestBestiole(monMilieu).getX() - b.getX())*M_PI + atan( (b.getNearestBestiole(monMilieu).getY() - b.getY()) / (b.getNearestBestiole(monMilieu).getX() - b.getX()) ) );
    }
}

#endif
