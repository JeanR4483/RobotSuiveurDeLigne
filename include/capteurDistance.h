#ifndef __CAPTEURDISTANCE__
#define __CAPTEURDISTANCE__

#define        AF_BASE    64
#define        AF_RS                (AF_BASE + 0)
#define        AF_RW                (AF_BASE + 1)
#define        AF_E                 (AF_BASE + 2)
#define        AF_LED               (AF_BASE + 3)

#define        AF_DB4               (AF_BASE + 4)
#define        AF_DB5               (AF_BASE + 5)
#define        AF_DB6               (AF_BASE + 6)
#define        AF_DB7               (AF_BASE + 7)

#define  Trig    4		// GPIO 23
#define  Echo    5		// GPIO 24
#define  BuzzerPin 25	// GPIO 26

void ultraInit(void);

void buzzerOn(void);

void buzzerOff(void);

float disMeasure(void);

#endif