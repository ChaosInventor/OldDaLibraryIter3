#ifndef INTEGER_MANAGER__INTERFACES_INTEGER_MANAGER_INTEGER_MANAGER_DEBUG_H
#define INTEGER_MANAGER__INTERFACES_INTEGER_MANAGER_INTEGER_MANAGER_DEBUG_H

#include "Debug/Debug.h"

#define ValidateIntegerManager(p_intergerManager) //TODO: Implement

#define ValidateIntegerManagerPointer(p_integerManager)\
    {                                               \
        DaLibrary_Assume(p_integerManager != NULL); \
        ValidateIntegerManager(*(p_integerManager));\
    }

#endif //INTEGER_MANAGER__INTERFACES_INTEGER_MANAGER_INTEGER_MANAGER_DEBUG_H