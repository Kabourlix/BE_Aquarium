#include "Milieu.h"
#include "Ears.h"
#include <cstdlib>
#include <cmath>
#include <math.h>

Eyes::Eyes( const Eyes& eyes )
{
    
}

Eyes::Eyes( float probaDetection, float angle, float distance )
{
    this -> probaDetection = probaDetection;
    this -> angle = angle;
    this -> distance = distance;
}

Eyes::~Eyes( void )
{

}

bool Eyes::detection(Bestiole & b1,Bestiole & b2)
{
    if (b2.x >= b1.x and b2.x <= this->distance) {
        return ((b2.y >= -b1.x*tan(this->angle) and b2.y <= b1.x*tan(this->angle)) && (rand()/RAND_MAX <= thi->probaDetection));
    }
    return false

}

float Eyes::getProbaDetection() {
    return this -> probaDetection;
}

float Eyes::getAngle() {
    return this -> angle;
}

float Eyes::getDistance() {
    return this -> distance;
}

void Eyes::setProbaDetection(float probDetec) {
    if (probDetec >= GAMMA_EYES_MIN and probDetec <= GAMMA_EYES_MAX)
        this -> probaDetection = probDetec;
}

void Eyes::setAngle(float ang) {
    if (ang >= ANGLE_MIN and ang <= ANGLE_MAX)
        this -> angle = ang;
}

void Eyes::setDistance(float dist) {
    if (dist >= 0)
        this -> distance = dist;
}
