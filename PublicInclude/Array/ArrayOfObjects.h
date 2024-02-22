#ifndef ARRAY__ARRAY_ARRAY_OF_OBJECTS_H
#define ARRAY__ARRAY_ARRAY_OF_OBJECTS_H

#include "Fundamental/SizeDefinition.h"
#include "ArrayGenericDefinition.h"

struct ArrayOfObjects
{

    void** Location;
    Size Size;

};

struct ArrayOfObjects CreateArrayOfObjectsFromArray(struct Array p_array);
struct Array CreateArrayFromArrayOfObjects(struct ArrayOfObjects p_array);

#endif //ARRAY__ARRAY_ARRAY_OF_OBJECTS_H