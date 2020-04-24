#include "LED_Driver.h"

/*============================================================================*/
/* Component_Operations */
/*============================================================================*/
void LED_Driver__Cyclic( const LED_Driver* Me )
{
    Class_Triggered_Timer__Tick( Me->My_Blinker->My_Timer );
}


/*============================================================================*/
/* Realized interfaces */
/*============================================================================*/
void LED_Driver__LED_Command__Switch_On( const LED_Driver* Me )
{
    /* Switch on the LED */
    Me->LED_Pin->Set_Level( IO_LEVEL_HIGH );
    Class_Blinker__Stop( Me->My_Blinker );
}
/*----------------------------------------------------------------------------*/
void LED_Driver__LED_Command__Switch_Off( const LED_Driver* Me )
{
    /* Switch off the LED */
    Me->LED_Pin->Set_Level( IO_LEVEL_LOW );
    Class_Blinker__Stop( Me->My_Blinker );
}
/*----------------------------------------------------------------------------*/
void LED_Driver__LED_Command__Blink(
    const LED_Driver* Me,
    uint16_t period,
    uint16_t on_time )
{
    uint16_t off_time = 0;

    /* Consistency check */
    if( period >= on_time )
    {
        /* Compute "off" time */
        off_time = period - on_time;

        /* Start its_blinker */
        Class_Blinker__Start( 
            Me->My_Blinker,
            0 /* infinite blinkink */,
            on_time,
            off_time );
        /* Switch on the LED */
        Me->LED_Pin->Set_Level( IO_LEVEL_HIGH );
    }
    else
    {
        /* period < on_time -> problem in caller, do nothing */
    }    
}


/*============================================================================*/
/* Received event from inner objects */
/*============================================================================*/  
void LED_Driver__My_Blinker__Off_Phase_Ended( const LED_Driver* Me )
{
    /* Switch on the LED */
    Me->LED_Pin->Set_Level( IO_LEVEL_HIGH );
}
/*----------------------------------------------------------------------------*/
void LED_Driver__My_Blinker__On_Phase_Ended( const LED_Driver* Me )
{
    /* Switch off the LED */
    Me->LED_Pin->Set_Level( IO_LEVEL_LOW );
}