#ifndef LED_DRIVING_H
#define LED_DRIVING_H

/* Data type */
#include <stdint.h>

/*============================================================================*/
/* Client_Server_Interface */
/*============================================================================*/
typedef struct {
    void (*Switch_On) ( void );
    void (*Switch_Off) ( void );
    void (*Blink) ( uint16_t period, uint16_t on_time );
} LED_Driving;

#endif