#ifndef GENERIC__INTERFACES_GENERIC_GENERIC_DEBUG_H
#define GENERIC__INTERFACES_GENERIC_GENERIC_DEBUG_H 

#include "Debug/Debug.h"
#include "GenericManagerDefinition.h"

#ifndef GenericManagerFormat
#define GenericManagerFormat "%p = { State = %p, "\
    "ComputeFromArrayAsOffsetLocationsFromArrayAsLocationsFromArrayAsPositiveOffsetsUsingGenericManager = %%FUNCTION_POINTER, " \
    "ComputeFromArrayAsOffsetLocationsFromArrayAsLocationsFromArrayAsNegativeOffsetsUsingGenericManager = %%FUNCTION_POINTER, " \
    "MoveFromArrayFromArrayUsingGenericManager = %%FUNCTION_POINTER, "                                                          \
    "SwapFromArrayFromArrayUsingGenericManager = %%FUNCTION_POINTER }"
#endif //GenericManagerFormat

#ifndef GenericManagerArgs
#define GenericManagerArgs(p_manager) &(p_manager), (p_manager).State, \
    (p_manager).ComputeFromArrayAsOffsetLocationsFromArrayAsLocationsFromArrayAsPositiveOffsetsUsingGenericManager, \
    (p_manager).ComputeFromArrayAsOffsetLocationsFromArrayAsLocationsFromArrayAsNegativeOffsetsUsingGenericManager, \
    (p_manager).MoveFromArrayFromArrayUsingGenericManager,                                                          \
    (p_manager).SwapFromArrayFromArrayUsingGenericManager
#endif //GenericManagerArgs

#define ValidateGenericManager(p_manager)\
    DaLibrary_Assert(                                                                                                   \
        p_manager->ComputeFromArrayAsOffsetLocationsFromArrayAsLocationsFromArrayAsPositiveOffsetsUsingGenericManager   \
        !=                                                                                                              \
        NULL,                                                                                                           \
        "A valid generic manager may not have any of its functions be null. "                                           \
        "Generic manager " GenericManagerFormat " does not confrom to this.",                                           \
        GenericManagerArgs(*p_manager)                                                                                  \
    );                                                                                                                  \
    DaLibrary_Assert(                                                                                                   \
        p_manager->ComputeFromArrayAsOffsetLocationsFromArrayAsLocationsFromArrayAsNegativeOffsetsUsingGenericManager   \
        !=                                                                                                              \
        NULL,                                                                                                           \
        "A valid generic manager may not have any of its functions be null. "                                           \
        "Generic manager " GenericManagerFormat " does not confrom to this.",                                           \
        GenericManagerArgs(*p_manager)                                                                                  \
    );                                                                                                                  \
    DaLibrary_Assert(                                                                                                   \
        p_manager->MoveFromArrayFromArrayUsingGenericManager != NULL,                                                   \
        "A valid generic manager may not have any of its functions be null. "                                           \
        "Generic manager " GenericManagerFormat " does not confrom to this.",                                           \
        GenericManagerArgs(*p_manager)                                                                                  \
    );                                                                                                                  \
    DaLibrary_Assert(                                                                                                   \
        p_manager->SwapFromArrayFromArrayUsingGenericManager != NULL,                                                   \
        "A valid generic manager may not have any of its functions be null. "                                           \
        "Generic manager " GenericManagerFormat " does not confrom to this.",                                           \
        GenericManagerArgs(*p_manager)                                                                                  \
    );

#define ValidateGenericManagerPointer(p_manager)\
    {                                           \
        ValidPointer(p_manager);                \
        ValidateGenericManager(*(p_manager));   \
    }

#endif //GENERIC__INTERFACES_GENERIC_GENERIC_DEBUG_H