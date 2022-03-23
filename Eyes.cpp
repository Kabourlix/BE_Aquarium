#include "Milieu.h"
#include "Eyes.h"
#include <cstdlib>
#include <cmath>
#include <math.h>


Eyes::Eyes( const Eyes& eyes)
{
    probaDetection = eyes.probaDetection;
    distance = eyes.distance;
    angle = eyes.angle;
}

Eyes::Eyes( float _probaDetection, float _angle, float _distance )
{
    probaDetection = _probaDetection;
    angle = _angle;
    distance = _distance;
};

Eyes::~Eyes( void )
{

};

bool Eyes::detection(Bestiole * b1,Bestiole * b2)
{   
    cout << "TESTD" << endl;
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