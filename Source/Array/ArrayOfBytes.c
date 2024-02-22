#include "Array/ArrayOfBytes.h"
#include "Array/ArrayGenericDebug.h"

struct ArrayOfBytes CreateArrayOfBytesFromArray(struct Array p_array)
{
    ValidateArray(p_array);
    return (struct ArrayOfBytes) { (Byte*)p_array.Location, p_array.Size };
}
struct Array CreateArrayFromArrayOfBytes(struct ArrayOfBytes p_array)
{
    ValidateArray(p_array);
    return (struct Array) { (void*)p_array.Location, p_array.Size };
}