#ifndef ARRAY__ARRAY_ARRAY_GENERIC_DEBUG_H
#define ARRAY__ARRAY_ARRAY_GENERIC_DEBUG_H

#include "ArrayGenericDefinition.h"


#include "Fundamental/SizeConstants.h"


#include "Debug/Debug.h"

#ifndef ArrayFormat
#define ArrayFormat "%p { Location = %p, Size = %z }"
#endif //ArrayFormat

#ifndef ArrayArgs
#define ArrayArgs(p_array) &(p_array), (p_array).Location, (p_array).Size
#endif //ArrayArgs

#define ValidateArray(p_array)\
    if((p_array).Location == NULL)                                              \
    {                                                                           \
        DaLibrary_Assert(                                                       \
            (p_array).Size == SIZE_MINIMUM,                                     \
            "Array " ArrayFormat " has null location without a minimum size",   \
            ArrayArgs((p_array))                                                \
        );                                                                      \
    }

#define ValidateArrayPointer(p_arrayPointer)\
    {                                               \
        DaLibrary_Assume((p_arrayPointer) != NULL); \
        ValidateArray(*(p_arrayPointer));           \
    }

#define ValidIndexInArray(p_index, p_array)\
    {                                                                   \
        ValidateArray(p_array);                                         \
        DaLibrary_Assert(                                               \
            (p_index) < (p_array).Size,                                 \
            "Index %z is invalid in array " ArrayFormat, &(p_index),    \
            ArrayArgs(p_array)                                          \
        );                                                              \
    }

#endif //ARRAY__ARRAY_ARRAY_GENERIC_DEBUG_H