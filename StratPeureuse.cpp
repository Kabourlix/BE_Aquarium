#ifndef _STRATPEUREUSE
#define _STRATPEUREUSE

#include "StratPeureuse.h"
#include <cmath>

StratPeureuse::StratPeureuse() {
    NAME = "Peureuse";
};



void StratPeureuse::action(Bestiole * b, Milieu * monMilieu ) const {
    if (b->getNearbyNeighbor(monMilieu).size() >= 2)
    {
        if(b->getVitesse() == b->getInitVitesse()) // On ne les fait changer d'orientation que la première fois qu'il y a trop d'ennemis
        {
        b->setOrientation( M_PI + b->getOrientation());
        }
        b->setVitesse(b->getVitesse() + 2); //Accélération de 2 pixel/seconde^2 (il faudrait en faire un paramètre de la bestiole)
    }
    else
    {
        if(b->getVitesse() != b->getInitVitesse()){
            b->setVitesse(b->getInitVitesse());
        }
    }
}

#endif
