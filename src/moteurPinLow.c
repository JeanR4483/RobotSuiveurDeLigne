#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define MOTOR1A 3 //GPIO 22
#define MOTOR1B 2 //GPIO 27
#define MOTOR1EN 23 //GPIO 13

#define MOTOR2A 0 //GPIO 17
#define MOTOR2B 21 //GPIO 5
#define MOTOR2EN 26 //GPIO 12

void initGPIO() {
    if (wiringPiSetup() == -1) {
        fprintf(stderr, "Erreur lors de l'initialisation de wiringPi.\n");
        exit(EXIT_FAILURE);
    }
    
    pinMode(MOTOR1A, OUTPUT);
	pinMode(MOTOR1B, OUTPUT);
	pinMode(MOTOR1EN, PWM_OUTPUT);
	pinMode(MOTOR2A, OUTPUT);
	pinMode(MOTOR2B, OUTPUT);
	pinMode(MOTOR2EN, PWM_OUTPUT);
}

void resetGPIOS(){
	digitalWrite(MOTOR1A, LOW);
    digitalWrite(MOTOR1B, LOW);
    pwmWrite(MOTOR1EN, 0);

    digitalWrite(MOTOR2A, LOW);
    digitalWrite(MOTOR2B, LOW);
    pwmWrite(MOTOR2EN, 0);
}

void main(){
	
	initGPIO();
	resetGPIOS();
}
