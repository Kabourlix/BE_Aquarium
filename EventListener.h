#ifndef __EVENTLISTENER_H__
#define __EVENTLISTENER_H__

#include "CreateHandler.h"
#include "KillHandler.h"
#include <stdio.h>

//[event_receiver(native)]
class EventListener
{
private:
    CreateHandler * createHandler;
    KillHandler * killHandler;

public:
    EventListener(/* args */);
    ~EventListener();



    



};

#endif