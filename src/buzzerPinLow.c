#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define  BuzzerPin 25

void main(){
	
	if (wiringPiSetup() == -1) {
        fprintf(stderr, "Erreur lors de l'initialisation de wiringPi.\n");
        exit(EXIT_FAILURE);
    }
	pinMode(BuzzerPin,OUTPUT);
	digitalWrite(BuzzerPin, LOW);
}
