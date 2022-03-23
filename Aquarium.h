#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;


class Milieu;


class Aquarium : public CImgDisplay
{

private :
   Milieu*        flotte;

   int            delay;
   //Function to initalize a pop with argument an array of ratios
   
public :
   Aquarium( int width, int height, int _delay , float _ratio[]);
   ~Aquarium( void );

   Milieu & getMilieu( void ) { return *flotte; }

   void createInitialPopulation( float ratios[], int nbBestiole );

   void run( void );

};


#endif
