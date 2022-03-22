#include "Milieu.h"
#include "Ears.h"
#include <cstdlib>
#include <cmath>
#include <math.h>


Eyes::Eyes( float probaDetection, float angle, float distance )
{
    probaDetection = probaDetection;
    angle = angle;
    distance = distance;
};

Eyes::~Eyes( void )
{

};

bool Eyes::detection(Bestiole * b1,Bestiole * b2)
{
    if (b2->getX() >= b1->getX() and b2->getX() <= distance) {
        return ((b2->getY() >= -b1->getX()*tan(angle) and b2->getY() <= b1->getX()*tan(angle)) && (rand()/RAND_MAX <= probaDetection));
    }
    return false;

};



void Eyes::setProbaDetection(float probDetec) {
    probaDetection = probDetec;     
};

void Eyes::setAngle(float ang) {
    angle = ang;
};

void Eyes::setDistance(float dist) {
    distance = dist;
};
