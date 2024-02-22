#ifndef INTEGER_RANGE__INTEGER_RANGE_INTEGER_RANGE_DEBUG_H
#define INTEGER_RANGE__INTEGER_RANGE_INTEGER_RANGE_DEBUG_H 

#include "Debug/Debug.h"
#include "IntegerRangeDefinition.h"

#define ValidateIntegerRange(p_range, p_manager) //TODO

#define ValidateIntegerRangePointer(p_range, p_manager)\
    {                                               \
        DaLibrary_Assume((p_range) != NULL);        \
        ValidateIntegerRange(*(p_range), p_manager);\
    }

#endif //INTEGER_RANGE__INTEGER_RANGE_INTEGER_RANGE_DEBUG_H