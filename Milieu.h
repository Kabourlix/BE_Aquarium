#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "BestioleStrategy.h"
#include <iostream>
#include <vector>

#include "StratGregaire.h"
#include "StratKamikaze.h"
#include "StratPrevoyante.h"
#include "StratPeureuse.h"

#include "CreateHandler.h"
#include "KillHandler.h"

using StratPtr = BestioleStrategy*;


using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bestiole>   listeBestioles;
   Milieu( int _width, int _height );
   static Milieu*         singleton;
   std::vector<StratPtr> stratVector;

   CreateHandler * createHandler;
   KillHandler   * killHandler;

public :

   static Milieu* getInstance(int _width = 640, int _height = 480); // Initialize the Milieu safely.
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height); }
   void removeMember(Bestiole & b);
   void removeMember(int idBestiole);
   Bestiole & checkCollision(Bestiole& b);
   
   int nbVoisins( const Bestiole & b );



   StratPtr getStrategy(std::string name);
   StratPtr getStrategy(int index);
   StratPtr getRandomStrategy(std::string previousStrat);

   inline std::vector<Bestiole> getBestioles(void) { return listeBestioles; };
   


};


#endif
