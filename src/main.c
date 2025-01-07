#include <wiringPi.h>
#include <pcf8574.h>
#include <lcd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "Moteur.h"
#include "Suiveur.h"
#include "capteurDistance.h"

#define DistanceMin 15  // en cm

int main(void){
    
    /* ----- début initialisation ----- */

    int i;
	wiringPiSetup();

        /*init ecran lcd et module I2C*/
    pcf8574Setup(AF_BASE,0x27); //pcf8574 I2C address
    
    int lcdHandle = lcdInit (2, 16, 4, AF_RS, AF_E, AF_DB4,AF_DB5,AF_DB6,AF_DB7, 0,0,0,0) ;
    if (lcdHandle < 0){
        exit (EXIT_FAILURE) ;
    }
    
    for(i=0;i<8;i++)
          pinMode(AF_BASE+i,OUTPUT);
    digitalWrite(AF_LED,1);
    digitalWrite(AF_RW,0);

    char buffer[20];
	lcdPosition(lcdHandle, 0, 0);
	
        /*init capteur ultrason*/
    ultraInit();

        /*init buzzer*/
	pinMode(BuzzerPin,OUTPUT);

        /*init suiveurs de ligne*/
    initGPIOSuiveur();

    /* ----- fin initialisation ----- */

    /*programme principal : */

    float d;

    while(1){
        
        d = disMeasure();

        if (d<DistanceMin){     // si obstacle detecté : buzzer activé, moteurs arrêtés, distance affichée
		buzzerOn();
		arreter();
            	snprintf(buffer, sizeof(buffer), "Obstacle à %.2f cm", d);
		lcdPuts(lcdHandle, buffer);
		delay(100);
		lcdClear(lcdHandle);
	} else {                // si aucun obstacle : buzzer éteint, on choisi une direction
		buzzerOff();
        	suivreLigne();
        }
    }

    return 0;
}
