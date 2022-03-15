#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include <vector>
#include "BestioleStrategy.h"
#include "Accessory.h"
#include "Sensors.h"

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   static const bool       MULTIPLE;

   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   BestioleStrategy  *bestioleStrat;
   std::vector<Accessory>   listeAccessories;
   std::vector<Sensors>   listeSensors;

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   Bestiole( int identite_, int x_, int y_, double orientation_, double vitesse_, BestioleStrategy  *bestioleStrat_, std::vector<Accessory> listeAccessories_, std::vector<Sensors>   listeSensors_ )

   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

   inline int getIdentite() const {return identite;};
   inline int getX() const {return x;};
   inline int getY() const {return y;};
   inline double getOrientation() const {return orientation;};
   inline double getVitesse() const {return vitesse;};
   inline bool getMultiple() const {return MULTIPLE;};
   inline BestioleStrategy *getStrat() const {return BestioleStrat;};
   inline std::vector<Accessory> getAccessories() const {return listeAccessories;};
   inline void setStrategy(const BestioleStrategy & newStrat){*bestioleStrat = newStrat;};
   inline void setOrientation(double newOrientation){orientation = newOrientation;};
   inline void setVitesse(double newVitesse){vitesse = newVitesse;};
   
   std::vector<Bestiole> getNearbyNeighbor();
   Bestiole getNearestBestiole();
   bool detect(const Bestiole & b ) const;
};

#endif
