#ifndef LED_DRIVER_H
#define LED_DRIVER_H


/*============================================================================*/
/* Inclusions */
/*============================================================================*/
/* Realized interfaces */
#include "LED_Driving.h"


/* Required interfaces */
#include "Discrete_Output.h"


/* Inner objects */
#include "Class_Blinker.h"


/*============================================================================*/
/* Component_Type */
/*============================================================================*/
typedef struct {

    /* Required interfaces */
    const Discrete_Output* LED_Pin;
    
    /* Inner objects */
    const Class_Blinker* My_Blinker;

} LED_Driver;


/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void LED_Driver__Cyclic( const LED_Driver* Me );


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void LED_Driver__LED_Command__Switch_On( const LED_Driver* Me );
void LED_Driver__LED_Command__Switch_Off( const LED_Driver* Me );
void LED_Driver__LED_Command__Blink(
    const LED_Driver* Me,
    uint16_t period,
    uint16_t on_time );


/*============================================================================*/
/* Received event from inner objects */
/*============================================================================*/  
void LED_Driver__My_Blinker__Off_Phase_Ended( const LED_Driver* Me );
void LED_Driver__My_Blinker__On_Phase_Ended( const LED_Driver* Me );


#endif