#include "Milieu.h"
#include "Ears.h"
#include <cstdlib>
#include <cmath>

Ears::Ears( const Ears& ears)
{
    probaDetection = ears.probaDetection;
    distance = ears.distance;
}

Ears::Ears( float _probaDetection, float _distance)
{
    probaDetection = _probaDetection;
    distance = _distance;
}
Ears::~Ears( void )
{

}

bool Ears::detection(const Bestiole * b1, const Bestiole * b2)
{
    double dist;
    dist = b1->sqrDist(*b2); //TODO : vérifier l'intérêt des références.
    return ((dist <= distance*distance) && (rand()/RAND_MAX <= probaDetection));
}