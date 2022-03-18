#ifndef __EXTERNALEVENTS_H__
#define __EXTERNALEVENTS_H__


/*This class should deal with the providing function 
working on the system and called from external events.
*/

class ExternalEvents
{
    private :
        static ExternalEvents* listener;
        ExternalEvents();

public:
    static ExternalEvents *getInstance();
    ~ExternalEvents();

    void KillBestiole(const int* id);
    void CreateBestiole(const int* id);
    void CreateBestiole(const int* id, const int* x, const int* y);
};

#endif

//TODO : Demander au prof pour la gestion des événements
//TODO : J'ai l'impression qu'il faut tout faire (pattern Observer, file de message etc ...)