
#include "StratGregaire.h"

StratGregaire::StratGregaire() {
    NAME = "Gregaire";
};


void StratGregaire::action(Bestiole b, Milieu & monMilieu ) const{
    //Check for nearby bestioles (i.e. visible)
    std::vector<Bestiole> neighbors = b.getNearbyNeighbor(monMilieu);
    if (neighbors.size() >= 1)
    {
        //Compute mean orientation of neighbors
        double meanOrientation = 0;
        for ( std::vector<Bestiole>::iterator it = neighbors.begin() ; it != neighbors.end() ; ++it )
            {
                meanOrientation = meanOrientation + b.getOrientation();
            }
        meanOrientation = meanOrientation/neighbors.size();

        //Set as its own orientation
        b.setOrientation(meanOrientation);
    }
}