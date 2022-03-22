#include "Milieu.h"
#include "Ears.h"
#include <cstdlib>
#include <cmath>
#include <math.h>

Eyes::Eyes( const Eyes& eyes )
{
    
};

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
    if (b2->getX() >= b1->getX() and b2->getX() <= this->distance) {
        return ((b2->getY() >= -b1->getX()*tan(this->angle) and b2->getY() <= b1->getX()*tan(this->angle)) && (rand()/RAND_MAX <= thi->probaDetection));
    }
    return false;

};



void Eyes::setProbaDetection(float probDetec) {
    if (probDetec >= GAMMA_EYES_MIN && probDetec <= GAMMA_EYES_MAX) {
        probaDetection = probDetec;
    }      
};

void Eyes::setAngle(float ang) {
    if (ang >= ANGLE_MIN && ang <= ANGLE_MAX) {
        angle = ang;
    }
};

void Eyes::setDistance(float dist) {
    if (dist >= 0) {
        distance = dist;
    }
};
