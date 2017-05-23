#ifndef _USER_H_
#define _USER_H_
/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

#include <xc.h>

#define SLAVE_COUNT     96
#define LEM_COUNT       4
#define IGNITION        PORTBbits.RB10
#define OFF             0
#define ON              1
#define RELAY           PORTBbits.RB11
#define SLEEP_LED       PORTBbits.RB15
#define ERROR_LED       PORTBbits.RB14
#define BUZZER          PORTBbits.RB13
#define SLEEP_LED_TRIS  TRISBbits.TRISB15
#define ERROR_LED_TRIS  TRISBbits.TRISB14
#define BUZZER_LED_TRIS TRISBbits.TRISB13

enum SystemStatus {
    WORKING = 0, 
    SLEEPING = 1
};

enum boolean {
    FALSE = 0,
    TRUE = 1
};

typedef struct{
    char address;
	unsigned short voltage;
    enum boolean temperature_active;
    unsigned short temperature;
    enum boolean balance_active;
} SLAVE;

typedef struct{
    char address;
	signed long current;
    enum boolean branch_connected;
} LEM;

typedef struct{
	SLAVE slaves[SLAVE_COUNT];
    LEM lems[LEM_COUNT];
    unsigned int soh;
    unsigned int soc;
} BMS;

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

void InitApp(void);             /* I/O and Peripheral Initialization */
void CheckIgnition(void);       /* Status (working/sleeping changing */
void TurnOnRelay(void);         /* Turns on relay */
void TurnOffRelay(void);        /* Turns off relay */
void TurnOnErrorLed(void);      /* Turns on error LED */
void TurnOffErrorLed(void);     /* Turns off error LED */
void TurnOnBuzzer(void);        /* Turns on buzzer */
void TurnOffBuzzer(void);       /* Turns off buzzer */
void GetMeasurements(void);     
void Evaluate(void);            /* Evaluates BMS status */
void DoActions(void);         

#endif /*_USER_H_*/
