#include "Milieu.h"
#include "Ears.h"
#include <cstdlib>
#include <cmath>

Ears::Ears( const Ears& ears)
{

}

Ears::Ears( float probaDetection, float distance)
{
    this -> probaDetection = probaDetection;
    this -> distance = distance;
}
Ears::~Ears( void )
{

}

bool Ears::detection(Bestiole & b1,Bestiole & b2)
{
    double dist;
    dist = (b1.x-b2.x)*(b1.x-b2.x) + (b1.y-b2.y)*(b1.y-b2.y);
    return ((dist <= this->distance*this->distance) && (rand()/RAND_MAX <= this->probaDetection));
}

float Ears::getProbaDetection() {
    return this -> probaDetection;
}

float Ears::getDistance() {
    return this -> distance;
}

void Ears::setProbaDetection(float probDetec) {
    if (probDetec >= 0 and probDetec <= 2*3.14)
        this -> probaDetection = probDetec;
}

void Ears::setDistance(float dist) {
    if (dist >= 0)
        this -> distance = dist;
}
