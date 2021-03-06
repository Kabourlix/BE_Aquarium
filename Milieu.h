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

#include <fstream>

using StratPtr = BestioleStrategy*;


using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   
   
   
   std::vector<StratPtr> stratVector;

   CreateHandler * createHandler;
   KillHandler   * killHandler;
   std::ofstream ageFile;
   std::ofstream popFile;
   int pasDeTemps;

   

public :
   std::vector<Bestiole*>   listeBestioles;
   
   Milieu( int _width, int _height , float ratio[]);
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember(Bestiole * b );
   void removeMember(Bestiole * b);
   void removeMember(int idBestiole);
   Bestiole * checkCollision(Bestiole* b);
   
   int nbVoisins( const Bestiole & b );



   StratPtr getStrategy(std::string name);
   StratPtr getStrategy(int index);
   StratPtr getRandomStrategy(std::string previousStrat);
   inline CreateHandler getCreateHandler() {return *createHandler;};

   inline std::vector<Bestiole*> getBestioles(void) { return listeBestioles; };
   
   void createExt(int amount);


   float propMult;
   float propGreg;
   float propKam;
   float propPeureuse;
};


#endif