#include "Milieu.h"



#include <cstdlib>
#include <ctime>





const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   singleton = NULL;
   cout << "const Milieu" << endl;
   //Create an instance of each strat and add it to the stratVector
   stratVector.push_back(new StratGregaire());
   stratVector.push_back(new StratKamikaze());
   stratVector.push_back(new StratPeureuse());
   //stratVector.push_back(new StratPrevoyante());
   
   //Initialiaze the createHandler and killHandler
   createHandler = new CreateHandler(this);
   killHandler   = new KillHandler();

   std::srand( time(NULL) );

   pasDeTemps = 0;
   ageFile.open("data/age.csv");
   popFile.open("data/pop.csv");

   popFile << "id,temps,type,number," << "\n";
   ageFile << "type,id,age" << "\n";


}


Milieu::~Milieu( void )
{
   ageFile.close();
   popFile.close();
   //Go through listBestioles and delete them.
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it )
   {
      (*it)->~Bestiole();
   }

   //Delete classes dealt by Milieu
   delete createHandler;
   delete killHandler;

   //Lastly, delete the only instance of the class
   delete singleton; 
   cout << "Milieu & dependencies have been destroyed." << endl;

}



Milieu* Milieu::getInstance(int _width, int _height){
   if(singleton == NULL){ // If it doesn't exist, create it.
      singleton = new Milieu(_width, _height);
   }
   
   return singleton; //Return the pointer to the singleton.
}


void Milieu::step( void )
{
   createHandler->spontaneousCreate(this);
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      if(killHandler->kill(*it, this)) break;
      popFile << (*it)->getIdentite() << "," << pasDeTemps << "," << (*it)->getStrat()->getName() << "," << 1 << "\n";
      //createHandler->cloneCreate(this, *it);

      (*it)->action( this );
      (*it)->draw( *this );
   }
   pasDeTemps++; // for


}


void Milieu::removeMember(Bestiole * b){
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      //! This might cause error when b is null.
      if((*it) == b){ //When we find it, we delete it and leave.
         
         ageFile << b->getStrat()->getName() << "," << b->getIdentite() << "," << b->getAge() << "\n";

         listeBestioles.erase(it);
         // We delete the bestiole since it is not in the list anymore.
         delete b;

         return; //Stop the function.
      }
   }
   //Print an error message if the bestiole is not found.
   cout << "Error: Bestiole with id " << b->getIdentite() << " not found." << endl;
}

void Milieu::removeMember(int idBestiole){
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      if ((*it)->getIdentite() == idBestiole){
         listeBestioles.erase(it);
         delete &*it;
         return;
      }
   }
   //Print an error message if the bestiole is not found.
   cout << "Error: Bestiole with id " << idBestiole << " not found." << endl;
}

Bestiole* Milieu::checkCollision(Bestiole* b){
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      if((*it) != b && b->checkCollision(*it)){ 
         return *it;
      }
   }
   return nullptr;
}

int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == **it) && b.jeTeVois(**it) )
         ++nb;

   return nb;

}


StratPtr Milieu::getStrategy(std::string name){
   for(std::vector<StratPtr>::iterator it = stratVector.begin(); it != stratVector.end(); ++it){
      if((*it)->getName() == name){
         return *it;
      }
   }
   std::cout << "incorrect strategy name -> A strategy has been chosen by default" ;
   return stratVector[1];
}  

StratPtr Milieu::getStrategy(int index){
   return stratVector[index];
}

StratPtr Milieu::getRandomStrategy(std::string previousStrat){
   //get a random int between 0 and 3 included
   int random = std::rand() % 3;
   StratPtr toReturn = stratVector[random];
   while(toReturn->getName() == previousStrat){
      random = std::rand() % 3;
      toReturn = stratVector[random];
   }
   return toReturn;
}


void Milieu::addMember(Bestiole * b) 
{ 
   listeBestioles.push_back(b); listeBestioles.back()->initCoords(width, height); 
}