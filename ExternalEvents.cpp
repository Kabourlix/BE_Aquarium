#include "ExternalEvents.h"

using Ext = ExternalEvents; 

Ext::ExternalEvents(){

}

Ext::~ExternalEvents(){

    delete listener;
}

Ext* Ext::getInstance(){
    if(Ext::listener == NULL){
        Ext::listener = new Ext();
    }

    return Ext::listener;
}
