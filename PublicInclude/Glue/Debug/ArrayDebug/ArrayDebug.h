#ifndef ARRAY_DEBUG__GLUE_DEBUG_ARRAY_DEBUG_ARRAY_DEBUG_H
#define ARRAY_DEBUG__GLUE_DEBUG_ARRAY_DEBUG_ARRAY_DEBUG_H 

#ifndef ArrayFormat
#define ArrayFormat "%p = { Location = %p, Size = %zi }"
#endif //ArrayFormat

#ifndef ArrayArgs(p_array)
#define ArrayArgs(p_array) &(p_array), (p_array).Location, (p_array).Size
#endif //ArrayArgs(p_array)

#define ValidArray(p_array, p_type) 1//TODO:

#endif //ARRAY_DEBUG__GLUE_DEBUG_ARRAY_DEBUG_ARRAY_DEBUG_H