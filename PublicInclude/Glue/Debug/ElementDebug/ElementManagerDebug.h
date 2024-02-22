#ifndef ELEMENT_MANAGER__INTERFACES_ELEMENT_MANAGER_ELEMENT_MANAGER_DEBUG_H
#define ELEMENT_MANAGER__INTERFACES_ELEMENT_MANAGER_ELEMENT_MANAGER_DEBUG_H 

#include "Debug/Debug.h"

#ifndef ElementManagerFormat
#define ElementManagerFormat \
    "%p = "                                                                                                                         \
    "{ "                                                                                                                            \
    "State = %p, "                                                                                                                  \
    "ComputeUsingSequenceAsBooleanEqualityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager = %%FUNCTION_POINTER, " \
    "ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager = %%FUNCTION_POINTER" \
    " }"
#endif //ElementManagerFormat

#ifndef ElementManagerArgs
#define ElementManagerArgs(p_manager)\
    &(p_manager), (p_manager).State,                                                                                    \
    (p_manager).ComputeUsingSequenceAsBooleanEqualityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager, \
    (p_manager).ComputeUsingSequenceAsBooleanInequalityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager
#endif //ElementManagerArgs

#define ValidElementManager(p_manager)\
    ValidPointer(                                                                                                           \
        (p_manager).ComputeUsingSequenceAsBooleanEqualityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager  \
    )

#define FullFeaturedElementManager(p_manager)\
    ValidElementManager(p_manager)                                                                                          \
    &&                                                                                                                      \
    ValidPointer(                                                                                                           \
        (p_manager).ComputeUsingSequenceAsBooleanEqualityUsingSequenceAsElementsUsingSequenceAsElementsUsingElementManager  \
    )

#endif //ELEMENT_MANAGER__INTERFACES_ELEMENT_MANAGER_ELEMENT_MANAGER_DEBUG_H