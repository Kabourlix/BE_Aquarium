#ifndef _CONCRETEFACTORY_H_
#define _CONCRETEFACTORY_H_

 #include "Factory.h"
 #include "Accessory.h"
 #include "BestioleStrategy.h"
 #include "Eyes.h"
 #include "Ears.h"


 class ConcreteFactory : public Factory
 {
 	private:
 		int id;
 		int nbBestiole;
 		float propGregaire;
 		float propPeureuse;
 		float propKamikaze;
 		float propPrevoyante;

 		static const int 		MIN;
 		static const int 		MAX;
 		static const float		MAX_VITESSE;
 		static const float		LIMITE_VUE;
 		static const float		MAX_PROB_DETECTION;
 		static const float		MAX_ANGLE;
 		static const float		MAX_DIST_EYES;
 		static const float		MAX_DETEC_CAPA;
 		static const float		MAX_DIST_EARS;
 		static const float		MIN_ANGLE;
 		static const float		MIN_DIST_EYES;
 		static const float		MIN_DIST_EARS;
 		static const float		MAX_COEF_SPEED;
 		static const float		MAX_COEF_RES;
 		static const float		MAX_COEF_CAMOUFLAGE;

		static const float 		xLim;
		static const float 		yLim;

 	public : 
 		ConcreteFactory(Milieu * singleton);
 		virtual ~ConcreteFactory();
 		virtual Bestiole cloneBestiole(const Bestiole & bestiole);
 		virtual Bestiole createBestiole();
 		virtual Bestiole createExtBestiole();


 		Sensors* createEars();
 		Sensors* createEyes();
 		Accessory* createNageoire();
 		Accessory* createCamouflage();
 		Accessory* createCarapace();
 };

 #endif