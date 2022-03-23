#include "Aquarium.h"

#include "Milieu.h"



Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   std::cout << "const Aquarium" << endl;

   //flotte->getInstance( width, height );
   flotte = new Milieu(width, height);
   flotte->singleton = flotte; 
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   std::cout << "dest Aquarium" << endl;

}


void Aquarium::createInitialPopulation( float ratios[], int nbBestiole )
   {
      std::cout << " Creation Of initiale Pop"  << endl;

      std::string toDisp = "ratios : ";
      //Go through each ratio and get the associated proportion of the population.
      for ( int i = 0; i < 4; ++i )
      {
         int nb = (int)(ratios[i] * nbBestiole);
         bool multiple = (i == 0); //Multiple has to be the first ratio.
         for ( int j = 0; j < nb; ++j )
         {
            //Create a new bestiole with the associated strategy.
            BestioleStrategy* strat;
            if (multiple) {
               strat = flotte->getStrategy(0);
            } else {
               strat = flotte->getStrategy(i-1);
            }
            
            std::cout <<  strat->getName() << endl;
            //toDisp += strat->getName() + " a " + std::to_string(ratios[i]*100) + "%, ";
            std::vector<Accessory*> accessories;
            std::vector<Sensors*> sensors;
            sensors.push_back(new Ears(1,20));
            Bestiole* b = new Bestiole(i+j, 
                                       0,
                                       0,
                                       3.14/3,
                                       10., 
                                       strat,
                                       accessories, 
                                       sensors,
                                       0,
                                       300,
                                       multiple);
            
            //TODO : add the correct constructor.
                                       
            //Add it to the ecosystem.
            flotte->addMember(b);
         }
      }
      std::cout << "Initialize population with" + std::to_string(nbBestiole) + " bestioles." << endl;
      //cout << toDisp << endl;

   }

void Aquarium::run( void )
{

   std::cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         std::cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         std::cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }

      flotte->step();
      display( *flotte );

      wait( delay );

   } 

   

}