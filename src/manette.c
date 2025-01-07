#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <SDL2/SDL.h>

#define MOTOR1A 3 //GPIO 22
#define MOTOR1B 2 //GPIO 27
#define MOTOR1EN 23 //GPIO 13

#define MOTOR2A 0 //GPIO 17
#define MOTOR2B 21 //GPIO 5
#define MOTOR2EN 26 //GPIO 12

void initializePins() {
    wiringPiSetup();

    pinMode(MOTOR1EN, PWM_OUTPUT);
    pinMode(MOTOR1A, OUTPUT);
    pinMode(MOTOR2B, OUTPUT);

    pinMode(MOTOR2EN, PWM_OUTPUT);
    pinMode(MOTOR2A, OUTPUT);
    pinMode(MOTOR2B, OUTPUT);
}

void controlMotor(int speed,int directionDD,int directionGD,float degreVirage){
    if (direction GD = -1) {
        digitalWrite(MOTOR1A, (directionDD == 1) ? HIGH : LOW);
        digitalWrite(MOTOR1B, (directionDD == -1) ? HIGH : LOW);
        pwmWrite(MOTOR1EN, (1-degreVirage)*vitesse*0.9);

        digitalWrite(MOTOR2A, (directionDD == 1) ? HIGH : LOW);
        digitalWrite(MOTOR2B, (directionDD == -1) ? HIGH : LOW);
        pwmWrite(MOTOR2EN, vitesse);
    } else {
        digitalWrite(MOTOR1A, (directionDD == 1) ? HIGH : LOW);
        digitalWrite(MOTOR1B, (directionDD == -1) ? HIGH : LOW);
        pwmWrite(MOTOR1EN, vitesse*0.9);

        digitalWrite(MOTOR2A, (directionDD == 1) ? HIGH : LOW);
        digitalWrite(MOTOR2B, (directionDD == -1) ? HIGH : LOW);
        pwmWrite(MOTOR2EN, vitesse*(1-degreVirage));
    }
}

int main() {
    initializePins();

    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(400);
    pwmSetRange(1024);

    if (SDL_Init(SDL_INIT_JOYSTICK) < 0) {
        fprintf(stderr, "Erreur d'initialisation SDL: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Joystick *joystick = SDL_JoystickOpen(0);
    if (!joystick) {
        fprintf(stderr, "Impossible d'ouvrir le joystick: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    int quit = 0;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_JOYAXISMOTION:
                    // Axe X du joystick gauche
                    if (event.jaxis.axis == SDL_CONTROLLER_AXIS_LEFTX) {
                        int directionGD = (event.jaxis.value > 0) ? 1 : -1;
                        float degreVirage = abs((float)(event.jaxis.value) / 32767);
                    }
                    
                    //RT
                    if (event.jaxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT && abs(event.jaxis.value)> 1000) {
                        int speed = (event.jaxis.value + 32767) * 1024 / 65535; 
                        int directionDD = 1;
                    }

                    //LT
                    if (event.jaxis.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT && abs(event.jaxis.value) >1000) {
                        int speed = (event.jaxis.value + 32767) * 1024 / 65535; 
                        int directionDD = -1;
                    }
                    break;

                case SDL_JOYBUTTONDOWN:
                    //Start
                    if (event.jbutton.button == SDL_CONTROLLER_BUTTON_START) {
                        quit = 1;
                    }
                    break;

                default:
                    break;
            }
        }
        controlMotor(speed,directionDD,directionGD,degreVirage);
    }

    SDL_JoystickClose(joystick);
    SDL_Quit();

    return 0;
}
