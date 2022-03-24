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
   if(b1->sqrDist(b2) < distance*distance){ // On est dans le rayon
        //Calcul de l'angle entre les deux bestioles
        float deltax = b2->getX() - b1->getX();
        float deltay = b2->getY() - b1->getY();
        float new_angle = atan (deltay/deltax);
        if (deltax <0)
        {
            new_angle += M_PI;
        }
        
        //On regarde si la bestiole est dans la bonne portion de cercle
        if(abs(new_angle - angle) < angle)
        {
            if((rand()%100) < probaDetection*100)
            {
                return true;
            }
        }
   }
   return false;

}



void Eyes::setProbaDetection(float probDetec) {
    probaDetection = probDetec;     
};

void Eyes::setAngle(float ang) {
    angle = ang;
};

void Eyes::setDistance(float dist) {
    distance = dist;
};