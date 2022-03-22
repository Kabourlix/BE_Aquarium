#ifndef _STRATKAMIKAZE
#define _STRATKAMIKAZE

#include "StratKamikaze.h"
#include <cmath>
#include <cstdlib>

const std::string  StratGregaire::NAME = "Kamikaze";

void StratKamikaze::action(Bestiole b){
    // Check if there is any nearby Bestiole detected :
    if (b.getNearbyNeighbor().size()>0)
    {
        // Define the orientation of the bestiole such as it will be directed towards the current position of the nearest bestiole
        // à voir si position bestiole vraiment donné par x,y 
        b.setOrientation( signbit(b.getNearestBestiole().getX() - b.getX())*M_PI + atan( (b.getNearestBestiole().getY() - b.getY()) / (b.getNearestBestiole().getX() - b.getX()) ) );
    }
}

#endif
