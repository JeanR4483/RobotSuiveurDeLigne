#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include "Moteur.h"

void avancer(int vitesse) {
    digitalWrite(MOTOR1A, HIGH);
    digitalWrite(MOTOR1B, LOW);
    pwmWrite(MOTOR1EN, vitesse*0.9);

    digitalWrite(MOTOR2A, HIGH);
    digitalWrite(MOTOR2B, LOW);
    pwmWrite(MOTOR2EN, vitesse);
}

void arreter() {
    digitalWrite(MOTOR1A, LOW);
    digitalWrite(MOTOR1B, LOW);
    pwmWrite(MOTOR1EN, 0);

    digitalWrite(MOTOR2A, LOW);
    digitalWrite(MOTOR2B, LOW);
    pwmWrite(MOTOR2EN, 0);
}

void reculer(int vitesse) {
    digitalWrite(MOTOR1A, LOW);
    digitalWrite(MOTOR1B, HIGH);
    pwmWrite(MOTOR1EN, vitesse*0.9);

    digitalWrite(MOTOR2A, LOW);
    digitalWrite(MOTOR2B, HIGH);
    pwmWrite(MOTOR2EN, vitesse);
}

void tournerADroite(int vitesse) {
    digitalWrite(MOTOR1A, LOW);
    digitalWrite(MOTOR1B, HIGH);
    pwmWrite(MOTOR1EN, 0.8*vitesse*0.9);

    digitalWrite(MOTOR2A, HIGH);
    digitalWrite(MOTOR2B, LOW);
    pwmWrite(MOTOR2EN, vitesse);
}

void tournerAGauche(int vitesse) {
    digitalWrite(MOTOR1A, HIGH);
    digitalWrite(MOTOR1B, LOW);
    pwmWrite(MOTOR1EN, vitesse*0.9);

    digitalWrite(MOTOR2A, LOW);
    digitalWrite(MOTOR2B, HIGH);
    pwmWrite(MOTOR2EN, 0.8*vitesse);
}

