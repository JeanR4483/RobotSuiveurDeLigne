#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "Suiveur.h"
#include "Moteur.h"

#define VITESSE 400

// Fonction pour initialiser les capteurs
void initGPIOSuiveur() {
    if (wiringPiSetup() == -1) {
        fprintf(stderr, "Erreur lors de l'initialisation de wiringPi.\n");
        exit(EXIT_FAILURE);
    }
    
    pinMode(CAPTEUR_GAUCHE_PIN, INPUT);
    pinMode(CAPTEUR_MILIEU_PIN, INPUT);
    pinMode(CAPTEUR_DROIT_PIN, INPUT);
    
    pinMode(MOTOR1A, OUTPUT);
	pinMode(MOTOR1B, OUTPUT);
	pinMode(MOTOR1EN, PWM_OUTPUT);
	pinMode(MOTOR2A, OUTPUT);
	pinMode(MOTOR2B, OUTPUT);
	pinMode(MOTOR2EN, PWM_OUTPUT);
}

// Fonction pour lire les valeurs des capteurs
void lireCapteurs(int *capteurGauche, int *capteurMilieu, int *capteurDroit) {
    *capteurGauche = digitalRead(CAPTEUR_GAUCHE_PIN);
    *capteurMilieu = digitalRead(CAPTEUR_MILIEU_PIN);
    *capteurDroit = digitalRead(CAPTEUR_DROIT_PIN);
}

// Fonction principale du suiveur de ligne
void suivreLigne() {
    int capteurGauche, capteurMilieu, capteurDroit;
    
    // Lire les valeurs des capteurs
        lireCapteurs(&capteurGauche, &capteurMilieu, &capteurDroit);

        // Logique de suivi de ligne
        if (capteurGauche == 0 && capteurMilieu == 0 && capteurDroit == 1) {
            // Tourner à gauche
	    tournerADroite(VITESSE);
            //while(capteurGauche ==  0){break;}
        //} else if (capteurGauche == 1 && capteurMilieu == 1 && capteurDroit == 1) {
            // Aller tout droit
          // avancer(VITESSE);
           // printf("Aller tout droit\n");
           // printf("%d,%d,%d\n",capteurGauche, capteurMilieu, capteurDroit);
        } else if (capteurGauche == 1 && capteurMilieu == 0 && capteurDroit == 0) {
            // Tourner à droite
            tournerAGauche(VITESSE);
            //while(capteurDroit == 0){break;}
        } else if (capteurGauche == 1 && capteurMilieu == 1 && capteurDroit == 0) {
            // Ajustement pour gauche
            tournerAGauche(VITESSE);
            while(capteurDroit == 0 && capteurGauche == 1){break;}
        } else if (capteurGauche == 0 && capteurMilieu == 1 && capteurDroit == 1) {
	    tournerADroite(VITESSE);
	    while(capteurGauche == 0 && capteurDroit == 1){break;}
        //} else if (capteurGauche == 0 && capteurMilieu == 0 && capteurDroit == 0) {
            // Ajustement pour tout droit
        } else if (capteurGauche == 0 && capteurMilieu == 1 && capteurDroit == 0) {
	    // Ajustement pour tout droit
	    avancer(VITESSE);
    	} //else if (capteurGauche == 1 && capteurMilieu == 0 && capteurDroit == 1) {
	//    avancer(VITESSE);
	//}
    
}


