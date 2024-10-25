#ifndef PLIB_TMR2_H
#define PLIB_TMR2_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "device.h"
#include "plib_tmr_common.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

void TMR2_Initialize(void);

void TMR2_Start(void);

void TMR2_Stop(void);

void TMR2_PeriodSet(uint32_t period);

uint32_t TMR2_PeriodGet(void);

uint32_t TMR2_CounterGet(void);

uint32_t TMR2_FrequencyGet(void);


bool TMR2_PeriodHasExpired(void);


#ifdef __cplusplus  // Provide C++ Compatibility

    }
#endif
// DOM-IGNORE-END

#endif /* PLIB_TMR2_H */
