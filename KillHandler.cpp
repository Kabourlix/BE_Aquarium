#include "KillHandler.h"
#include <stdlib.h>
#include <cstdlib>

KillHandler::KillHandler(){
    milieu = Milieu::getInstance();
}

KillHandler::~KillHandler(){
    
}

bool KillHandler::kill(Bestiole& bestiole){
    if (bestiole.getAge() >= bestiole.getAgeLimite()) {
        milieu->removeMember(bestiole);
    }

    //Check for collision with other bestioles
    Bestiole collidedBestiole = milieu->checkCollision(bestiole);
    if(rand()> 0.75){ // We kill the bestioles
        milieu->removeMember(bestiole);
        milieu->removeMember(collidedBestiole);
    }
    else{ // Otherwise we just move them away
        bestiole.setOrientation(-bestiole.getOrientation());
        collidedBestiole.setOrientation(-collidedBestiole.getOrientation());
    }
    }


void KillHandler::killExt(int idBestiole){
    milieu->removeMember(idBestiole);
}
