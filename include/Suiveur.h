#ifndef __SUIVEUR_LIGNE__
#define __SUIVEUR_LIGNE__

// Broches GPIO pour les capteurs
#define CAPTEUR_GAUCHE_PIN  24 //GPIO 19
#define CAPTEUR_MILIEU_PIN  22 //GPIO 6
#define CAPTEUR_DROIT_PIN   27 //GPIO 16

// Fonction pour initialiser les capteurs
void initGPIOSuiveur();

// Fonction pour lire les valeurs des capteurs
void lireCapteurs(int *capteurGauche, int *capteurMilieu, int *capteurDroit);

// Fonction principale du suiveur de ligne
void suivreLigne();

#endif

