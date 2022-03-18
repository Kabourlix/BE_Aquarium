#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
   //Dealing with arguments
   if(argc > 11){
      cout << "Too many arguments." << (argc-1/2) << "were given while 5 are expected." << endl;
   }
   //TODO : à finir.


   Aquarium       ecosysteme( 640, 480, 30 );
   
   //Multiple, Gregaire, Kamikaze, Peureuse, Prevoyante
   float ratios[] = { 0.4, 0.2, 0.2 , 0.1, 0.1}; 
   ecosysteme.createInitialPopulation( ratios, 20);

   
   ecosysteme.run();


   return 0;

}
