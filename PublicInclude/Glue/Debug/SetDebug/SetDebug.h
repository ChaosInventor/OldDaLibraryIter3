#ifndef SET__INTERFACES_SET_SET_DEBUG_H
#define SET__INTERFACES_SET_SET_DEBUG_H 

#include "Debug/Debug.h"
#include "Interfaces/Set/SetDefinition.h"
#include "Glue/Debug/SequenceDebug/SequenceDebug.h"

#ifndef SetFormat
#define SetFormat \
    "%p = "                                                                                                             \
    "{ "                                                                                                                \
    "Elements = " SequenceFormat ", "                                                                                   \
    "ComputeUsingSequenceAsBooleansIsMemberUsingSequenceAsElementsUsingElementManagerUsingSet = %%FUNCTION_POINTER, "   \
    "ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet = %%FUNCTION_POINTER"  \
    " }"
#endif //SetFormat

#ifndef SetArgs
#define SetArgs(p_set)\
    &(p_set),                                                                                           \
    SequenceArgs((p_set).Elements),                                                                     \
    (p_set).ComputeUsingSequenceAsBooleansIsMemberUsingSequenceAsElementsUsingElementManagerUsingSet,   \
    (p_set).ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet
#endif //SetArgs

#define ValidSet(p_set)\
    ReversableSequence((p_set).Elements)                                                                \
    &&                                                                                                  \
    ValidFunctionPointer(                                                                               \
        (p_set).ComputeUsingSequenceAsBooleansIsMemberUsingSequenceAsElementsUsingElementManagerUsingSet\
    )

#define FullFeaturedSet(p_set)\
    ValidSet(p_set) && FullFeaturedSequence((p_set).Elements)                                               \
    &&                                                                                                      \
    ValidFunctionPointer(                                                                                   \
        (p_set).ComputeUsingSequenceAsBooleansIsNotMemberUsingSequenceAsElementsUsingElementManagerUsingSet \
    )

#endif //SET__INTERFACES_SET_SET_DEBUG_H