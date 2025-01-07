#include <wiringPi.h>
#include <pcf8574.h>
#include <lcd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "capteurDistance.h"

void ultraInit(void)  // initialisation des GPIO pour le capteur de distance
{  
    pinMode(Echo, INPUT);  
    pinMode(Trig, OUTPUT);  
}  

void buzzerOn(void){
    digitalWrite(BuzzerPin, HIGH);  // active le buzzer
}

void buzzerOff(void){
	digitalWrite(BuzzerPin, LOW);  // désactive le buzzer
}

float disMeasure(void)  
{  
    printf("debut fonction \n");
    struct timeval tv1;  
    struct timeval tv2;  
    long start, stop;  
    float dis;  

    digitalWrite(Trig, LOW);  
    delayMicroseconds(2);  

    digitalWrite(Trig, HIGH);  //produce a pluse
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);  

    while(!(digitalRead(Echo) == 1));  
    gettimeofday(&tv1, NULL);           //current time

    while(!(digitalRead(Echo) == 0));  
    gettimeofday(&tv2, NULL);           //current time  

    start = tv1.tv_sec * 1000000 + tv1.tv_usec;
    stop  = tv2.tv_sec * 1000000 + tv2.tv_usec;  

    dis = (float)(stop - start) / 1000000 * 34000 / 2;  //count the distance
    printf("fin fonction \n");
    return dis;
}  
