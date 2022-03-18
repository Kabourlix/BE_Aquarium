#include "KillHandler.h"
#include <stdlib.h>
#include <cstdlib>

KillHandler::KillHandler(){
    
}

KillHandler::~KillHandler(){
    
}

void KillHandler::kill(const Milieu & milieu,Bestiole bestiole){
    if (bestiole.age >= bestiole.ageLimite) {
        milieu.removeMemeber(bestiole);
    }
    listeBestioles = milieu.listeBestioles;
    
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); it++) {
        if (it != bestiole and it.cumulX == bestiole.cumulX and it.cumulY == bestiole.cumulY) {
            if (rand() > 0.75) {
                milieu.removeMemeber(bestiole);
                milieu.removeMemeber(it);
            }
            else {
                bestiole.orientation = -bestiole.orientation;
                bestiole2.orientation = -bestiole2.orientation;
            }
        }
    }
}

void KillHandler::killExt(const Milieu & milieu, int idBestiole){
    listeBestioles = milieu.listeBestioles;
    bestiole = listeBestioles[0];
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); it++) {
        if (idBestiole == it.id) {
            bestiole = it;
        }
    }
    milieu.removeMemeber(bestiole);
}
