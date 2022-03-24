#ifndef _STRATKAMIKAZE
#define _STRATKAMIKAZE

#include "StratKamikaze.h"
#include <cmath>
#include <cstdlib>



StratKamikaze::StratKamikaze() {
    NAME = "Kamikaze";
};

/*void StratKamikaze::action(Bestiole * b, Milieu * monMilieu ) const{
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

}*/

void StratKamikaze::action(Bestiole * b, Milieu * monMilieu) const{
    //On initialise une distance infinie"
    std::vector<Bestiole *> neighbors = b->getNearbyNeighbor(monMilieu);
    if(neighbors.size() == 0){
        return;
    }
    float distanceMin = std::numeric_limits<float>::infinity();
    Bestiole * bestioleProche = nullptr;
    
    for(std::vector<Bestiole*>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
    {
        //On calcule la distance entre la Bestiole et le voisin
        float distance = b->sqrDist(*it); 
        //Si la distance est inférieure à la distance actuelle, on la remplace
        if(distance < distanceMin)
        {
            distanceMin = distance;
            bestioleProche = *it;
        }
    }
    if(bestioleProche != nullptr){
        //On calcule la nouvelle orientation
        float deltax = bestioleProche->getX() - b->getX();
        float deltay = bestioleProche->getY() - b->getY();
        float new_angle = atan (deltay/deltax);
        if (deltax <0) 
        {
            new_angle += M_PI;
        }
        b -> setOrientation(-new_angle);
    }
}



#endif