#include "KillHandler.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <stdlib.h>
#include <cstdlib>

KillHandler::KillHandler(){
}

KillHandler::~KillHandler(){
    
}

bool KillHandler::kill(Bestiole& bestiole, Milieu * monMilieu){
    if (bestiole.getAge() >= bestiole.getAgeLimite()) {
        monMilieu-> removeMember(bestiole);
    }

    //Check for collision with other bestioles
    Bestiole collidedBestiole = monMilieu->checkCollision(bestiole);
    // TODO : si pas collision -> checkCollision ne renvoie rien -> donc créer une bestiole "NULL" (NULL ne marche pas on l'a déjà testé)
    //        Ensuite vérifier si colidiedBestiol n'est pas la bestiole "NULL" 
    //        Sinon détruire colidiedBestiole et ne pas rentrer dans la boucle if rand else
    // TODO : corriger méthode checkCollision dans Milieu (ligne 110) pour renvoyer une bestioleNULL si non collision
    // if (collidedBestiole != BestioleNULL) {
        if(rand()> 0.75){ // We kill the bestioles
            monMilieu -> removeMember(bestiole);
            monMilieu -> removeMember(collidedBestiole);
        }
    
        else{ // Otherwise we just move them away
            bestiole.setOrientation(-bestiole.getOrientation());
            collidedBestiole.setOrientation(-collidedBestiole.getOrientation());
        }
    //}
    //else {
    //    delete collidedBestiole;
    //}
}


void KillHandler::killExt(int idBestiole, Milieu * monMilieu){
    monMilieu -> removeMember(idBestiole);
}
