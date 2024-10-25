#include "device.h"
#include "plib_tmr2.h"
#include "interrupts.h"


void TMR2_Initialize(void)
{
    /* Disable Timer */
    T2CONCLR = _T2CON_ON_MASK;

    /*
    SIDL = 0
    TCKPS =0
    T32   = 1
    TCS = 0
    */
    T2CONSET = 0x8;

    /* Clear counter */
    TMR2 = 0x0;

    /*Set period */
    PR2 = 6U;


}


void TMR2_Start(void)
{
    T2CONSET = _T2CON_ON_MASK;
}


void TMR2_Stop (void)
{
    T2CONCLR = _T2CON_ON_MASK;
}

void TMR2_PeriodSet(uint32_t period)
{
    PR2  = period;
}

uint32_t TMR2_PeriodGet(void)
{
    return PR2;
}

uint32_t TMR2_CounterGet(void)
{
    return (TMR2);
}


uint32_t TMR2_FrequencyGet(void)
{
    return (750000);
}



bool TMR2_PeriodHasExpired(void)
{
    bool status;
        status = (IFS0bits.T3IF != 0U);
        IFS0CLR = _IFS0_T3IF_MASK;

    return status;
}
