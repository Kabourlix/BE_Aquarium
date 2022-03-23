#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
   //Dealing with arguments
   int nbBestiole;
   float ratios[4]; //Multiple, Grégaire, Kamikaze, Peureuse
   if(argc > 6){
      cout << "Too many arguments." << argc << "were given while 5 are expected." << endl;
      return 0;
   }else if (argc < 6){
      cout << "Too few arguments." << argc << "were given while 5 are expected." << endl;
      return 0;
   }else{
      nbBestiole = atoi(argv[1]);
      
      for(int i = 0; i < 4; i++){
         ratios[i] = atof(argv[i+2]);
      }
      
   }

   Aquarium       ecosysteme( 640, 480, 30 , ratios);
   
   //Multiple, Gregaire, Kamikaze, Peureuse, Prevoyante
   ecosysteme.createInitialPopulation( ratios, nbBestiole);

   
   ecosysteme.run();

   
   return 0;

}
