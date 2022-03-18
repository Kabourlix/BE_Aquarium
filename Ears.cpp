#include "Milieu.h"
#include "Ears.h"
#include <cstdlib>
#include <cmath>

Ears::Ears( const Ears& ears)
{
    this -> probaDetection = ears.probaDetection;
    this -> distance = ears.distance;
}

Ears::Ears( float probaDetection, float distance)
{
    this -> probaDetection = probaDetection;
    this -> distance = distance;
}
Ears::~Ears( void )
{

}

bool Ears::detection(const Bestiole * b1, const Bestiole * b2)
{
    double dist;
    dist = b1->sqrDist(*b2); //TODO : vérifier l'intérêt des références.
    return ((dist <= this->distance*this->distance) && (rand()/RAND_MAX <= this->probaDetection));
}
