#include "KillHandler.h"
#include <stdlib.h>
#include <cstdlib>

KillHandler::KillHandler(){
    milieu = Milieu::getInstance();
}

KillHandler::~KillHandler(){
    
}

bool KillHandler::kill(Bestiole bestiole){
    if (bestiole.getAge() >= bestiole.getAgeLimite()) {
        milieu->removeMember(bestiole);
    }

    //Check for collision with other bestioles
    std::vector<Bestiole> listeBestioles = milieu->getBestioles();
    
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); it++) {
        if (it != bestiole and it.x == bestiole.x and it.y == bestiole.y) {
            if (rand() > 0.75) {
                milieu->removeMember(bestiole);
                milieu->removeMember(it);
            }
            else {
                bestiole.orientation = -bestiole.orientation;
                bestiole2.orientation = -bestiole2.orientation;
            }
        }
    }
}

void KillHandler::killExt(int idBestiole){
    listeBestioles = milieu->getBestioles;
    bestiole = listeBestioles[0];
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); it++) {
        if (idBestiole == it.id) {
            bestiole = it;
        }
    }
    milieu->removeMember(bestiole);
}
