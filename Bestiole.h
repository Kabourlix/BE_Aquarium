#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include <vector>
#include "Accessory.h"
#include "Sensors.h"

using namespace std;



class Milieu;
class BestioleStrategy;

class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;
   //Milieu* milieu;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   int               age;
   int               ageLimite;
   bool              multiple;

   const BestioleStrategy * bestioleStrat;
   std::vector<Accessory*>   listeAccessories;
   std::vector<Sensors*>   listeSensors;
   //! Attention à ce type, je ne suis pas sûr que ça marche.
   T*                couleur;

private :
   void bouge( int xLim, int yLim );

public :     
   // -------- CONSTRUCTEUR ET DESTRUCTEUR --------
   Bestiole(); // Constructeur par defaut
   Bestiole( const Bestiole & b, int id); // Constructeur de copies
   Bestiole( int identite_, int x_, int y_, 
            double orientation_, double vitesse_, 
            const BestioleStrategy  *bestioleStrat_, 
            std::vector<Accessory*> listeAccessories_, 
            std::vector<Sensors*>   listeSensors_ , 
            T couleur_, int age_, int ageLimite_, bool multiple_);

   ~Bestiole();                              // Destructeur
   // ---------------------------------------------


   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );


   // -------- ACCESSEURS --------
   inline int getIdentite() const {return identite;};
   inline int getX() const {return x;};
   inline int getY() const {return y;};
   inline double getOrientation() const {return orientation;};
   inline double getVitesse() const {return vitesse;};
   inline int getAge() const {return age;};
   inline int getAgeLimite() const {return ageLimite;};
   inline bool getMultiple() const {return multiple;};
   inline const BestioleStrategy * getStrat() const {return bestioleStrat;};
   inline std::vector<Accessory*> getAccessories() const {return listeAccessories;};
   inline void setStrategy(const BestioleStrategy * newStrat){bestioleStrat = newStrat;};
   inline void setOrientation(double newOrientation){orientation = newOrientation;};
   inline void setVitesse(double newVitesse){vitesse = newVitesse;};
   // -----------------------------------

   std::vector<Bestiole> getNearbyNeighbor(Milieu & monMilieu);
   Bestiole getNearestBestiole(Milieu & monMilieu);

   bool checkCollision(const Bestiole & b);


   bool detect(const Bestiole *b ) const;
   void updateAge();


   inline float dist( const Bestiole & b ) const{
      return sqrt( (b.getX()-x)*(b.getX()-x) + (b.getY()-y)*(b.getY()-y) );
   };
   inline float sqrDist( const Bestiole & b ) const{
      return (b.getX()-x)*(b.getX()-x) + (b.getY()-y)*(b.getY()-y);
   };
};

#endif