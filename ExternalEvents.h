#ifndef __EXTERNALEVENTS_H__
#define __EXTERNALEVENTS_H__

#include "EventListener.h"

/*This class should deal with the providing function 
working on the system and called from external events.
*/

class ExternalEvents
{
private:
    EventListener* eventListener;
public:
    ExternalEvents(/* args */);
    ~ExternalEvents();

    void KillBestiole(const int* id);
    void CreateBestiole(const int* id);
    void CreateBestiole(const int* id, const int* x, const int* y);
};

#endif

//TODO : Demander au prof pour la gestion des événements
//TODO : J'ai l'impression qu'il faut tout faire (pattern Observer, file de message etc ...)