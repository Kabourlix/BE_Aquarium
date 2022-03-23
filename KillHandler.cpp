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
        std::cout << "Kill dû à l'age. Elle avait " << bestiole->getAge() << "ans et son age limite est " << bestiole->getAgeLimite() << std::endl;
        monMilieu-> removeMember(bestiole);
        return true;
    }

    //Check for collision with other bestioles
    Bestiole* collidedBestiole = monMilieu->checkCollision(bestiole);
    
    //Print bestiole and collidedBestiole positions
    std::cout << "Bestiole " << bestiole->getIdentite() << " is at (" << bestiole->getX() << "," << bestiole->getY() << ")."<< std::endl;
    //std::cout << "Collided bestiole " << collidedBestiole->getIdentite() << " is at (" << collidedBestiole->getX() << "," << collidedBestiole->getY() << ")."<< std::endl;
    
    if (collidedBestiole != nullptr) {
        cout << "We get in the collided != nullptr" << endl;
        if(rand()> 0.0){ // We kill the bestioles
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
    //else {
    //    delete collidedBestiole;
    //}
}


void KillHandler::killExt(int idBestiole, Milieu * monMilieu){
    monMilieu -> removeMember(idBestiole);
}