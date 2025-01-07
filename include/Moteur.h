#ifndef __MOTEUR__
#define __MOTEUR__

#define MOTOR1A 3 //GPIO 22
#define MOTOR1B 2 //GPIO 27
#define MOTOR1EN 23 //GPIO 13

#define MOTOR2A 0 //GPIO 17
#define MOTOR2B 21 //GPIO 5
#define MOTOR2EN 26 //GPIO 12

void avancer(int vitesse);

void arreter();

void reculer(int vitesse);

void tournerAGauche(int vitesse);

void tournerADroite(int vitesse);

#endif
