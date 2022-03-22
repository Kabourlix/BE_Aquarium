#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;


Bestiole::Bestiole( void )
{

   identite = ++next;
   milieu = Milieu::getInstance();
   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   
}


Bestiole::Bestiole( const Bestiole & b , int id)
{

   identite = id;
   milieu = Milieu::getInstance();

   cout << "const Bestiole (" << identite << ") par copie de " << b.getIdentite() << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   age = b.age;
   ageLimite = b.ageLimite;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );
   bestioleStrat = b.bestioleStrat; //Reference to the strat
   //Copying the accessories
   for(std::vector<Accessory*>::const_iterator it = b.listeAccessories.cbegin(); it != b.listeAccessories.cend(); ++it){
      listeAccessories.push_back(new Accessory(**it));
   }

   /*for(std::vector<Sensors*>::const_iterator it = b.listeSensors.cbegin(); it != b.listeSensors.cend(); ++it){
      //Get the type of the current item
      if((**it).getName() == "Eyes"){
         listeSensors.push_back(new Eyes(**it));
      }else{
         listeSensors.push_back(new Ears(**it));
      }
   }*/

   multiple = b.multiple;

}


Bestiole::Bestiole( int identite_, int x_, int y_, double orientation_, double vitesse_, const BestioleStrategy  *bestioleStrat_, std::vector<Accessory*> listeAccessories_, std::vector<Sensors*>   listeSensors_, T couleur_ , int age_, int ageLimite_, bool multiple_)
{

   identite =  identite_;
   milieu = Milieu::getInstance();
   x = x_;
   y = y_;
   cumulX = cumulY = 0.;
   orientation = orientation_;
   vitesse = vitesse_;
   age = age_;
   ageLimite = ageLimite_;
   bestioleStrat = bestioleStrat_;
   listeAccessories = listeAccessories_ ;
   listeSensors = listeSensors_;
   couleur = &couleur_;
   multiple = multiple_;

}


Bestiole::~Bestiole( void )
{

   delete[] couleur;
   
   for ( std::vector<Accessory*>::iterator it = listeAccessories.begin() ; it != listeAccessories.end() ; ++it )
   { 
      delete * it;
      *it=nullptr;
   }
   for ( std::vector<Sensors*>::iterator it = listeSensors.begin() ; it != listeSensors.end() ; ++it )
   { 
      delete * it;
      *it=nullptr;
   }

   cout << "dest of Bestiole id : " << identite << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}


void Bestiole::action( Milieu & monMilieu )
{  
   this->updateAge();
   if (multiple) {
      if (rand()<0.25) {
         this->setStrategy(Milieu::getInstance()->getRandomStrategy(bestioleStrat->getName()));
      }
   }
   //Execute bestioleStrat (const pointer) action
   bestioleStrat->action(*this);
   bouge( monMilieu.getWidth(), monMilieu.getHeight() );

}


void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;

   //TODO : Vérifier comment régler l'erreur
   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;

   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

bool Bestiole::detect(const Bestiole *b) const
{ bool detected = false;
// Potentiellement un problème à l'itération sur listeSensors, une histoire de const mais je ne sais pas trop pourquoi
   for ( std::vector<Sensors*>::const_iterator it = listeSensors.cbegin() ; it != listeSensors.cend() ; ++it )
   {
      if ((*it)->detection(this,b)){ detected = true; }
   }
  return detected;
}

std::vector<Bestiole> Bestiole::getNearbyNeighbor() 
{ std::vector<Bestiole> neighbors;
   for ( std::vector<Bestiole>::iterator it = milieu->getBestioles().begin() ; it != milieu->getBestioles().end() ; ++it )
   { if (!(*this == *it) && this->detect(static_cast<Bestiole*>( &(*it) ) ))
      {
         neighbors.push_back(*it);
      }
   }
   return neighbors;
}

// Attention n'appeler cette méthode que si getNearbyNeighbor() ne renvoie pas une liste vide.
Bestiole Bestiole::getNearestBestiole()
{ Bestiole nearestBestiole;
  double currentMinDist2 = 0; 
  int n = 0;
   for ( std::vector<Bestiole>::iterator it = milieu->getBestioles().begin() ; it != milieu->getBestioles().end() ; ++it )
   { if (!(*this == *it) && this->detect(static_cast<Bestiole*>( &(*it) )))
      { 
         if ( n==0 || (pow(((*this).x-(*it).x),2)+pow(((*this).y-(*it).y),2) ) < currentMinDist2)
         {
            nearestBestiole = *it;
            currentMinDist2 = pow(((*this).x-(*it).x),2)+pow(((*this).y-(*it).y),2);
            n = 1;
         }
      }
   }
   if (n==1) { return nearestBestiole;}
}

bool Bestiole::checkCollision(const Bestiole & b)
{
   return ( this->sqrDist(b) <= 0.01*0.01 );
}



void Bestiole::updateAge()
{
   age = age +1;
}
;
