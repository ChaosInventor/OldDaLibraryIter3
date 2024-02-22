#ifndef ARRAY__ARRAY_ARRAY_GENERIC_FUNCTIONS_H
#define ARRAY__ARRAY_ARRAY_GENERIC_FUNCTIONS_H

#include "ArrayGenericDefinition.h"
#include "Fundamental/SizeDefinition.h"
#include "Fundamental/BooleanDefinition.h"

//TODO: Ones that use an index instead.

#define ForeachInArrayFirstType(p_array, p_elementName, p_type)\
    for(                                                                \
        p_type p_elementName = (p_type)(p_array).Location;              \
        p_elementName != (p_type)(p_array).Location + (p_array).Size;   \
        ++(p_elementName)                                               \
    )
#define ForeachInArrayLastType(p_array, p_elementName, p_type)\
    for(                                                                    \
        p_type p_elementName = (p_type)(p_array).Location + (p_array).Size; \
        p_elementName != (p_type)(p_array).Location;                        \
        --(p_elementName)                                                   \
    )


void CreateToArrayAsNull(struct Array* restrict p_array);
struct Array CreateArrayFromVoidPointerAsSingleItem(void*);


Size FindSizeAsLastIndexFromArray(struct Array p_array);


Boolean ArrayIsNull(struct Array p_array);

#endif //ARRAY__ARRAY_ARRAY_GENERIC_FUNCTIONS_H