#ifndef MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_DEBUG_H
#define MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_DEBUG_H

#include "Debug/Debug.h"

#ifndef MemoryManagerFormat
#define MemoryManagerFormat\
    "%p = "                                                 \
    "{ State = %p, AllocateFunction = %%FUNCTION_POINTER, " \
    "ReSizeForwardFunction = %%FUNCTION_POINTER, "          \
    "ReSizeBackwardFunction = %%FUNCTION_POINTER, "         \
    "RePermissionFunction = %%FUNCTION_POINTER, "           \
    "DeallocateFunction = %%FUNCTION_POINTER }"
#endif //MemoryManagerFormat

#ifndef MemoryManagerArgs(p_manager)
#define MemoryManagerArgs(p_manager)\
    (p_manager).State,                                                                                                              \
    (p_manager).AllocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictnessCallbackOnFailure,                                  \
    (p_manager).ReSizeUsingMemoryAsSizeForwardUsingMemoryManagerFromSizeAsNewSizeFromMemoryManagerStrictnessCallbackOnFailure,    \
    (p_manager).ReSizeUsingMemoryAsLocationBackwardUsingMemoryManagerFromSizeAsNewSizeFromMemoryManagerStrictnessCallbackOnFailure, \
    (p_manager).RePermissionUsingMemoryUsingMemoryManagerFromMemoryPermissionsFromMemoryManagerStrictnessCallbackOnFailure,         \
    (p_manager).DeallocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictness
#endif //MemoryManagerArgs

#define ValidateMemoryManager(p_manager)\
    {                                                                                                                                       \
        DaLibrary_Assert(                                                                                                                   \
            (p_manager).AllocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictnessCallbackOnFailure                                   \
            !=                                                                                                                              \
            NULL,                                                                                                                           \
            "A valid memory manager interface may not have any of its functions be "                                                        \
            "null. Memory manager " MemoryManagerFormat " is not valid",                                                                    \
            MemoryManagerArgs(p_manager)                                                                                                    \
        );                                                                                                                                  \
        DaLibrary_Assert(                                                                                                                   \
            (p_manager).ReSizeUsingMemoryAsSizeForwardUsingMemoryManagerFromSizeAsNewSizeFromMemoryManagerStrictnessCallbackOnFailure     \
            !=                                                                                                                              \
            NULL,                                                                                                                           \
            "A valid memory manager interface may not have any of its functions be "                                                        \
            "null. Memory manager " MemoryManagerFormat " is not valid",                                                                    \
            MemoryManagerArgs(p_manager)                                                                                                    \
        );                                                                                                                                  \
        DaLibrary_Assert(                                                                                                                   \
            (p_manager).ReSizeUsingMemoryAsLocationBackwardUsingMemoryManagerFromSizeAsNewSizeFromMemoryManagerStrictnessCallbackOnFailure  \
            !=                                                                                                                              \
            NULL,                                                                                                                           \
            "A valid memory manager interface may not have any of its functions be "                                                        \
            "null. Memory manager " MemoryManagerFormat " is not valid",                                                                    \
            MemoryManagerArgs(p_manager)                                                                                                    \
        );                                                                                                                                  \
        DaLibrary_Assert(                                                                                                                   \
            (p_manager).RePermissionUsingMemoryUsingMemoryManagerFromMemoryPermissionsFromMemoryManagerStrictnessCallbackOnFailure          \
            !=                                                                                                                              \
            NULL,                                                                                                                           \
            "A valid memory manager interface may not have any of its functions be "                                                        \
            "null. Memory manager " MemoryManagerFormat " is not valid",                                                                    \
            MemoryManagerArgs(p_manager)                                                                                                    \
        );                                                                                                                                  \
        DaLibrary_Assert(                                                                                                                   \
            (p_manager).DeallocateUsingMemoryUsingMemoryManagerFromMemoryManagerStrictness                                                  \
            !=                                                                                                                              \
            NULL,                                                                                                                           \
            "A valid memory manager interface may not have any of its functions be "                                                        \
            "null. Memory manager " MemoryManagerFormat " is not valid",                                                                    \
            MemoryManagerArgs(p_manager)                                                                                                    \
        );                                                                                                                                  \
    }

#define ValidateMemoryManagerPointer(p_manager)\
    {                                           \
        DaLibrary_Assume((p_manager) != NULL);  \
        ValidateMemoryManager(*(p_manager));    \
    }

#endif //MEMORY_MANAGER__INTERFACES_MEMORY_MANAGER_MEMORY_MANAGER_DEBUG_H