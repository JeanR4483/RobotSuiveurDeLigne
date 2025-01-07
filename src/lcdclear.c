#include <wiringPi.h>
#include <pcf8574.h>
#include <lcd.h>

#include <stdio.h>
#include <stdlib.h>

#define        AF_BASE    64
#define        AF_RS                (AF_BASE + 0)
#define        AF_RW                (AF_BASE + 1)
#define        AF_E                 (AF_BASE + 2)
#define        AF_LED               (AF_BASE + 3)

#define        AF_DB4               (AF_BASE + 4)
#define        AF_DB5               (AF_BASE + 5)
#define        AF_DB6               (AF_BASE + 6)
#define        AF_DB7               (AF_BASE + 7)

// Global lcd handle:
static int lcdHandle;

int main(void)
{   
    wiringPiSetup();

    pcf8574Setup(AF_BASE,0x27); //pcf8574 I2C address
    
    // initialisation de l'écran lcd avec le module ic2
    
    lcdHandle = lcdInit (2, 16, 4, AF_RS, AF_E, AF_DB4,AF_DB5,AF_DB6,AF_DB7, 0,0,0,0) ;
    
    if (lcdHandle < 0)
    {
        fprintf (stderr, "lcdInit failed\n") ;
        exit (EXIT_FAILURE) ;
    }
    
    for(int i=0;i<8;i++)
          pinMode(AF_BASE+i,OUTPUT);
    digitalWrite(AF_LED,1);
    digitalWrite(AF_RW,0);
    
    // fin de l'initialisation

    lcdClear(lcdHandle);
    
    return 0; 
}
	

