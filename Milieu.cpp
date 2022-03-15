#include "Milieu.h"


#include <cstdlib>
#include <ctime>





const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;
   //Create an instance of each strat and add it to the stratVector
   stratVector.push_back(new StratGregaire());
   stratVector.push_back(new StratKamikaze());
   stratVector.push_back(new StratPeureuse());
   stratVector.push_back(new StratPrevoyante());
   
   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{
   //Go through listBestioles and delete them.
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it )
   {
      it->~Bestiole();
   }
   delete singleton; //Delete the only instance of the class.
   cout << "Milieu & dependencies have been destroyed." << endl;

}

Milieu* Milieu::getInstance(int _width = 640, int _height = 480){
   if(Milieu::singleton == NULL){ // If it doesn't exist, create it.
      Milieu::singleton = new Milieu(_width, _height);
   }
   
   return Milieu::singleton; //Return the pointer to the singleton.
}


void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      it->action( *this );
      it->draw( *this );

   } // for


}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}


StratPtr Milieu::getStrategy(std::string name){
   //TODO : Bien penser à ajouter le getName dans chaque strat.
   for(std::vector<StratPtr>::iterator it = stratVector.begin(); it != stratVector.end(); ++it){
      if((*it)->getName() == name){
         return *it;
      }
   }
}  

StratPtr Milieu::getStrategy(int index){
   return stratVector[index];
}

StratPtr Milieu::getRandomStrategy(std::string previousStrat){
   //get a random int between 0 and 3 included
   int random = std::rand() % 4;
   StratPtr toReturn = stratVector[random];
   while(toReturn->getName() == previousStrat){
      random = std::rand() % 4;
      toReturn = stratVector[random];
   }
   return toReturn;
}
