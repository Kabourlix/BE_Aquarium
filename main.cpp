#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );
   
   //Multiple, Gregaire, Kamikaze, Peureuse, Prevoyante
   float ratios[] = { 0.4, 0.2, 0.2 , 0.1, 0.1}; 
   ecosysteme.createInitialPopulation( ratios, 20);

   
   ecosysteme.run();


   return 0;

}
