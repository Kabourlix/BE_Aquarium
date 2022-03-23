#include "KillHandler.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <stdlib.h>
#include <cstdlib>

KillHandler::KillHandler(){
}

KillHandler::~KillHandler(){
    
}

bool KillHandler::kill(Bestiole* bestiole, Milieu * monMilieu){
    if (bestiole->getAge() >= bestiole->getAgeLimite()) {
        monMilieu-> removeMember(bestiole);
        return true;
    }

    //Check for collision with other bestioles
    Bestiole* collidedBestiole = monMilieu->checkCollision(bestiole);
    
    if (collidedBestiole != nullptr) {
        if((rand()%100)> 50){ // We kill the bestioles
            monMilieu -> removeMember(bestiole);
            monMilieu -> removeMember(collidedBestiole);
            return true;
        }
    
        else{ // Otherwise we just move them away
            bestiole->setOrientation(-bestiole->getOrientation());
            collidedBestiole->setOrientation(-collidedBestiole->getOrientation());
            return false;
        }
    }
    return false;
}


void KillHandler::killExt(int idBestiole, Milieu * monMilieu){
    monMilieu -> removeMember(idBestiole);
}