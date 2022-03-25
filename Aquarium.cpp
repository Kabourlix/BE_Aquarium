#include "Aquarium.h"

#include "Milieu.h"



Aquarium::Aquarium( int width, int height, int _delay , float ratio[]) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   std::cout << "const Aquarium" << endl;

   //flotte->getInstance( width, height );
   flotte = new Milieu(width, height, ratio);
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
            std::vector<Accessory*> accessories;
            std::vector<Sensors*> sensors;
            int eye = rand() % 2;
            int ear = rand() % 2;
            if(eye){
               float probaDetection = static_cast<double>( rand() )/RAND_MAX*1.0;
               float angle = static_cast<double>( rand() )/RAND_MAX*(2*M_PI-M_PI) + M_PI;
               float distanceEyes = static_cast<double>( rand() )/RAND_MAX*(30.) + 20.;
               sensors.push_back(new Eyes(probaDetection, angle, distanceEyes));
            }
            if(ear){
               float detectionCapacity = static_cast<double>( (rand()%100)/100 )*1.;
               float distanceEars = static_cast<double>( (rand()%100)/100 )*(30.) + 20.;
               sensors.push_back(new Ears(detectionCapacity, distanceEars));
            }
            int x = rand() % flotte->getWidth();
            int y = rand() % flotte->getHeight();
            float orientation = static_cast<double>( rand() )/RAND_MAX *(M_PI*2); // Compris entre 0 et 2 pi
            float vitesse = static_cast<double>( rand() )/RAND_MAX * 10.0; // Compris entre 0 et 10.0
            int ageMax = rand()%500;
            Bestiole* b = new Bestiole(i+j, 
                                       x,
                                       y,
                                       orientation,
                                       vitesse, 
                                       strat,
                                       accessories, 
                                       sensors,
                                       0,
                                       1000,
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
         //Si la touche c est pressée, on crée une bestiole avec createExt
         if ( key() == 'c' )
         {
            flotte->createExt(1);
         }
         if ( is_keyESC() ) close();
      }

      flotte->step();
      display( *flotte );

      wait( delay );

   } 

   

}