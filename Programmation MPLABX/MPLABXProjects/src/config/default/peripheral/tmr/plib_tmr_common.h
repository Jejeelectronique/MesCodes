#ifndef PLIB_TMR_COMMON_H    // Guards against multiple inclusion
#define PLIB_TMR_COMMON_H

#include <stddef.h>

#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

// *****************************************************************************
/* TMR_CALLBACK

  Summary:
    Use to register a callback with the TMR.

  Description:
    When a match is asserted, a callback can be activated.
    Use TMR_CALLBACK as the function pointer to register the callback
    with the match.

  Remarks:
    The callback should look like:
      void callback(handle, context);
	Make sure the return value and parameters of the callback are correct.
*/

typedef void (*TMR_CALLBACK)(uint32_t status, uintptr_t context);

// *****************************************************************************

typedef struct
{
    /*TMR callback function happens on Period match*/
    TMR_CALLBACK callback_fn;
    /* - Client data (Event Context) that will be passed to callback */
    uintptr_t context;

}TMR_TIMER_OBJECT;

#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END

#endif //_PLIB_TMR_COMMON_H

