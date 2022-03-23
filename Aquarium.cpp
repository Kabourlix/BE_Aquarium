#include "Aquarium.h"

#include "Milieu.h"



Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   //flotte->getInstance( width, height );
   flotte = new Milieu(width, height);
   flotte->singleton = flotte; 
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}


void Aquarium::createInitialPopulation( float ratios[], int nbBestiole )
   {
      cout << " TEST"  << endl;

      std::string toDisp = "ratios : ";
      //Go through each ratio and get the associated proportion of the population.
      for ( int i = 0; i < nbBestiole; ++i )
      {
         int nb = (int)(ratios[i] * nbBestiole);
         //bool multiple = (i == 0); //Multiple has to be the first ratio.
         for ( int j = 0; j < nb; ++j )
         {
            //Create a new bestiole with the associated strategy.
            cout << " TEST" << i+j  << endl;
            BestioleStrategy* strat = flotte->getStrategy(i);
            cout << " TEST" << i+j  << endl;
            toDisp += strat->getName() + " a " + std::to_string(ratios[i]*100) + "%, ";
            cout << " TEST" << i+j  << endl;
            std::vector<Accessory*> accessories;
            cout << " TEST" << i+j  << endl;
            std::vector<Sensors*> sensors;
            cout << " TEST" << i+j  << endl;
            Bestiole* b = new Bestiole(i+j, 
                                       0,
                                       0,
                                       3.14/3,
                                       30., 
                                       strat,
                                       accessories, 
                                       sensors,
                                       0,
                                       300,
                                       false);
            
                                       //TODO : add the correct constructor.
            //Add it to the ecosystem.
            std::cout <<  b  << std::endl;
            flotte->addMember(*b);
         }
      }
      cout << "Initialize population with" + std::to_string(nbBestiole) + " bestioles." << endl;
      cout << toDisp << endl;

   }

void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }

      flotte->step();
      display( *flotte );

      wait( delay );

   } 

   

}