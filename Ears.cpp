#include "Milieu.h"
#include "Ears.h"
#include <cstdlib>
#include <cmath>

Ears::Ears( const Ears& ears)
{
    cout << "Construct par copie de Ears" << endl;
    probaDetection = ears.probaDetection;
    distance = ears.distance;
}

Ears::Ears( float _probaDetection, float _distance)
{
    cout << "Construct par defaut de Ears" << endl;
    probaDetection = _probaDetection;
    distance = _distance;
}
Ears::~Ears( void )
{
    cout << "Destruct de Ears" << endl;
}

bool Ears::detection(const Bestiole * b1, const Bestiole * b2)
{
    double dist;
    dist = b1->sqrDist(*b2); //TODO : vérifier l'intérêt des références.
    return ((dist <= distance*distance) && (rand()/RAND_MAX <= probaDetection));
}