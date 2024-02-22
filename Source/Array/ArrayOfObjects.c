#include "Array/ArrayOfObjects.h"
#include "Array/ArrayGenericDebug.h"

struct ArrayOfObjects CreateArrayOfObjectsFromArray(struct Array p_array)
{
    ValidateArray(p_array);
    return (struct ArrayOfObjects) { (void**)p_array.Location, p_array.Size };
}
struct Array CreateArrayFromArrayOfObjects(struct ArrayOfObjects p_array)
{
    ValidateArray(p_array);
    return (struct Array) { (void*)p_array.Location, p_array.Size };
}