#ifndef _STRATKAMIKAZE
#define _STRATKAMIKAZE

#include "StratKamikaze.h"
#include <cmath>
#include <cstdlib>



StratKamikaze::StratKamikaze() {
    NAME = "Kamikaze";
};

void StratKamikaze::action(Bestiole * b, Milieu * monMilieu ) const{
    // Check if there is any nearby Bestiole detected :
    float deltax;
    float deltay;
    float new_angle;
    if (b->getNearbyNeighbor(monMilieu).size()>0)
    {
        deltax = (*(b->getNearbyNeighbor(monMilieu)).begin()) ->getX() - (b -> getX());
        deltay = (*(b->getNearbyNeighbor(monMilieu)).begin()) ->getY() - (b -> getY());
        new_angle = atan (deltay/deltax) * 180 / M_PI;
        if (deltax >0 && deltay < 0) {
            new_angle = -new_angle;
        } else { if (deltax <0 && deltay < 0) {
            new_angle = -new_angle - M_PI/2;
        } else { if (deltax <0 && deltay > 0)
            new_angle = new_angle + M_PI/2;
        }
        }
        b -> setOrientation(new_angle);
    }

}

#endif