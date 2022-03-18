#include "ExternalEvents.h"

using Ext = ExternalEvents; 

Ext::ExternalEvents(){

}

Ext::~ExternalEvents(){

    delete listener;
}

Ext* Ext::getInstance(){
    if(Ext::listener == nullptr){ //TODO : vérifier si ça génère un problème
        Ext::listener = new Ext();
    }

    return Ext::listener;
}
